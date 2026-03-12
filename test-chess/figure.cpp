#include "figure.h"
#include <algorithm>
#include <cassert>
#include <vector>


void Figure::move(const Point &new_pos)
{
    m_chessboard->m_board[x()][y()] = nullptr;
    m_old_coords.push(m_coord);
    m_coord = new_pos;
    if (m_chessboard->m_board[x()][y()] != nullptr) { // if there is a capture of opponent
        m_capured_figs.push(m_chessboard->m_board[x()][y()]);
        auto &enemy = ((m_color == COLOR::WHITE) ? m_chessboard->m_blacks : m_chessboard->m_whites);
        std::erase(enemy, m_chessboard->m_board[x()][y()]); // remove the fig from enemy's figs
    }
    m_chessboard->m_board[x()][y()] = this;
}

void Figure::undo()
{
    assert (m_old_coords.size() > 0);   // if contition fails, program exits with std::terminate
    if (!m_capured_figs.empty() && m_capured_figs.top()->x() == x() && m_capured_figs.top()->y() == y()) {
        m_chessboard->m_board[x()][y()] = m_capured_figs.top();
        auto &enemy = ((m_color == COLOR::WHITE) ? m_chessboard->m_blacks : m_chessboard->m_whites);
        enemy.push_back(m_capured_figs.top());
        m_capured_figs.pop();
    }
    else
        m_chessboard->m_board[x()][y()] = nullptr;
    m_coord = m_old_coords.top();
    m_old_coords.pop();
    m_chessboard->m_board[x()][y()] = this;
}

std::ostream &operator<<(std::ostream &os, const Figure &obj)
{
    os << ((obj.color() == WHITE) ? 10 + obj.type() : 20 + obj.type());
    return os;
}

std::vector<Point> King::get_moves() const
{
    std::vector<Point> mvs;
    
    for(int i = x() - 1; i <= x() + 1; i++)    
    {
        for(int j = y() - 1; j <= y() + 1; j++)
        {
            // std::cout << '[' << i << ',' << j << "] " << std::flush;
            if (x() == i && y() == j) continue;
            if (i < WIDTH && i >= 0 && j < HEIGHT && j >= 0)    // no out of board
            {
                if((m_chessboard->is_free(i , j) || m_chessboard->is_placed_oppenent_figure(i , j , m_color)) && !m_chessboard->is_under_attack(i, j , m_color))
                {
                    mvs.push_back({i , j});
                }
            }
        }
    }
    return mvs;
}


std::vector<Point> Rook::get_moves() const
{
    std::vector<Point> mvs;
    int temp_x = x();
    while (m_chessboard->is_free(++temp_x, y()) && temp_x < WIDTH)
        mvs.push_back({temp_x, y()});
    if (temp_x < WIDTH && m_chessboard->is_placed_oppenent_figure(temp_x , y() , m_color))     //if placed opponent figure add eat step
        mvs.push_back({temp_x, y()});                                         
    temp_x = x();
    while (m_chessboard->is_free(--temp_x, y()) && temp_x >= 0)
        mvs.push_back({temp_x, y()});
    if (temp_x >= 0 && m_chessboard->is_placed_oppenent_figure(temp_x , y() , m_color))     //if placed opponent figure add eat step
        mvs.push_back({temp_x, y()}); 
    int temp_y = y();
    while (m_chessboard->is_free(x() , ++temp_y) && temp_y < HEIGHT)
        mvs.push_back({x() , temp_y});
    if (temp_y < HEIGHT && m_chessboard->is_placed_oppenent_figure(x() , temp_y , m_color))     //if placed opponent figure add eat step
        mvs.push_back({x(), temp_y}); 
    temp_y = y();
    while (m_chessboard->is_free(x() , --temp_y) && temp_y >= 0)
        mvs.push_back({x() , temp_y});
    if (temp_y >= 0 && m_chessboard->is_placed_oppenent_figure(x() , temp_y , m_color))     //if placed opponent figure add eat step
        mvs.push_back({x(), temp_y}); 
    return mvs;
}

std::vector<Point> Bishop::get_moves() const
{
    std::vector<Point> mvs;

    int tx = x();
    int ty = y();

    // up-right
    tx = x(); ty = y();
    while (++tx < WIDTH && ++ty < HEIGHT && m_chessboard->is_free(tx, ty))
        mvs.push_back({tx, ty});
    if (tx < WIDTH && ty < HEIGHT && m_chessboard->is_placed_oppenent_figure(tx, ty, m_color))
        mvs.push_back({tx, ty});

    // up-left
    tx = x(); ty = y();
    while (--tx >= 0 && ++ty < HEIGHT && m_chessboard->is_free(tx, ty))
        mvs.push_back({tx, ty});
    if (tx >= 0 && ty < HEIGHT && m_chessboard->is_placed_oppenent_figure(tx, ty, m_color))
        mvs.push_back({tx, ty});

    // down-right
    tx = x(); ty = y();
    while (++tx < WIDTH && --ty >= 0 && m_chessboard->is_free(tx, ty))
        mvs.push_back({tx, ty});
    if (tx < WIDTH && ty >= 0 && m_chessboard->is_placed_oppenent_figure(tx, ty, m_color))
        mvs.push_back({tx, ty});

    // down-left
    tx = x(); ty = y();
    while (--tx >= 0 && --ty >= 0 && m_chessboard->is_free(tx, ty))
        mvs.push_back({tx, ty});
    if (tx >= 0 && ty >= 0 && m_chessboard->is_placed_oppenent_figure(tx, ty, m_color))
        mvs.push_back({tx, ty});

    return mvs;
}

std::vector<Point> Queen::get_moves() const
{
    std::vector<Point> mvs;

    Rook r({x(), y()}, m_color, m_chessboard);
    Bishop b({x(), y()}, m_color, m_chessboard);

    std::vector<Point> rook_moves = r.get_moves();
    std::vector<Point> bishop_moves = b.get_moves();

    mvs.insert(mvs.end(), rook_moves.begin(), rook_moves.end());
    mvs.insert(mvs.end(), bishop_moves.begin(), bishop_moves.end());

    return mvs;
}

std::vector<Point> Knight::get_moves() const
{
    std::vector<Point> mvs;

    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};

    for(int i = 0; i < 8; i++)
    {
        int nx = x() + dx[i];
        int ny = y() + dy[i];

        if(nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT)
        {
            if(m_chessboard->is_free(nx, ny) || m_chessboard->is_placed_oppenent_figure(nx, ny, m_color))
            {
                mvs.push_back({nx, ny});
            }
        }
    }

    return mvs;
}

std::vector<Point> WhitePawn::get_moves() const
{
    std::vector<Point> mvs;

    int nx = x() - 1;
    int ny = y();

    // forward 1
    if (nx >= 0 && m_chessboard->is_free(nx, ny))
    {
        mvs.push_back({nx, ny});

        // double move from start row
        if (x() == 6 && m_chessboard->is_free(nx - 1, ny))
        {
            mvs.push_back({nx - 1, ny});
        }
    }

    // capture left
    if (nx >= 0 && y() - 1 >= 0 &&
        m_chessboard->is_placed_oppenent_figure(nx, y() - 1, m_color))
    {
        mvs.push_back({nx, y() - 1});
    }

    // capture right
    if (nx >= 0 && y() + 1 < WIDTH &&
        m_chessboard->is_placed_oppenent_figure(nx, y() + 1, m_color))
    {
        mvs.push_back({nx, y() + 1});
    }

    return mvs;
}

std::vector<Point> BlackPawn::get_moves() const
{
    std::vector<Point> mvs;

    int nx = x() + 1;
    int ny = y();

    // forward 1
    if (nx < HEIGHT && m_chessboard->is_free(nx, ny))
    {
        mvs.push_back({nx, ny});

        // double move from start row
        if (x() == 1 && m_chessboard->is_free(nx + 1, ny))
        {
            mvs.push_back({nx + 1, ny});
        }
    }

    // capture left
    if (nx < HEIGHT && y() - 1 >= 0 &&
        m_chessboard->is_placed_oppenent_figure(nx, y() - 1, m_color))
    {
        mvs.push_back({nx, y() - 1});
    }

    // capture right
    if (nx < HEIGHT && y() + 1 < WIDTH &&
        m_chessboard->is_placed_oppenent_figure(nx, y() + 1, m_color))
    {
        mvs.push_back({nx, y() + 1});
    }

    return mvs;
}


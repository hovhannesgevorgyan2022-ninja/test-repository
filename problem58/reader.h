#ifndef READER_H
#define READER_H

class Reader{
    private:
        std::ifstream m_file;
    public:
        Reader() = delete;
        Reader(const std::string& filename);
        Matrix* read_matrix();
        Reader(const Reader& other) = delete;
        Reader& operator = (const Reader& other) = delete;
        ~Reader();
};

#endif
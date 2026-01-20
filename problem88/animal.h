#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    protected:
        int weight;

    public:    
        struct customhash {
            std::size_t operator() (const Animal& obj) const
            {
                return std::hash<int>{}(obj.getweight());
            }
        };


    public:
        Animal(int w);
        void sound();
        bool operator == (const Animal& obj) const;
        int getweight() const;
        ~Animal();
};

#endif
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    protected:
        int a;
        std::string name;
        bool x = true;

    public:
        Animal();
        void sound();
        ~Animal();
};

#endif
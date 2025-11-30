#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    public:
        Animal();
        Animal(Animal&& other);     //move
        Animal& operator = (Animal&& other);   //move assignment
        virtual void voice();
        virtual ~Animal();
};

#endif
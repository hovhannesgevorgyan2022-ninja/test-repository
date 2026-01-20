#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    protected:
        int weight;

    public:    
        struct AnimalCompare {
            bool operator()(const Animal& a, const Animal& b) const {
                return (a.getweight() < b.getweight());
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
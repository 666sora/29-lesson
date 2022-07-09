#include <iostream>
#include <string>
#include <vector>
#include <map>

class Talent {
public:
    virtual void descriptionAbility() = 0;
};

class SwimmingTalent : virtual public Talent {

public:
    virtual void descriptionAbility() {
        std::cout << "It can swim" << std::endl;
    }
};

class DancingTalent : virtual public Talent {

public:
    virtual void descriptionAbility() {
        std::cout << "It can dance" << std::endl;
    }
};

class CountingTalent : virtual public Talent {

public:
    virtual void descriptionAbility() {
        std::cout << "It can counting" << std::endl;
    }
}; 

class Dog {
    std::string name = "";

    std::vector<Talent*> talent;

public:
    void show_talents() {
        for (auto &t: talent) {
            t->descriptionAbility();
        }
    }

    void set_talent(Talent* inTalent) {
        talent.push_back(inTalent);
    }

    ~Dog() {
        for (auto &t: talent) {
            delete t;
        }
    }
};

int main() {
    Talent* swimmingTalent = new SwimmingTalent;
    Dog dog;
    dog.set_talent(swimmingTalent);
    dog.show_talents();
    Talent* dancingTalent = new DancingTalent; 
    dog.set_talent(dancingTalent);
    dog.show_talents();
    Talent* countingTalent = new CountingTalent;
    dog.set_talent(countingTalent);
    dog.show_talents();
}

/*
Возьмём решение из видео. Все наши животные могут мяукать и гавкать, 
то есть издавать звуки в соответствии со своим классом. Но что, если 
нужно добавить им новое поведение, например, научить плавать или стоять 
на задних лапах. Рассмотрим класс Dog: все собаки умеют лаять и бегать, 
а некоторые собаки умеют хорошо плавать. Чтобы добавить эти качества 
классу Dog, мы можем создать ещё один класс «плавающих» животных и 
наследовать от него наш класс. Но что, если не все собаки умеют хорошо 
плавать, а некоторые из них совсем не умеют плавать.Наша задача — 
построить класс Dog таким образом, чтобы к его объектам можно было 
выборочно добавлять новые умения, но при этом не менять поведение 
основного класса. Список умений будет вызываться с помощью метода show_talents().
*/
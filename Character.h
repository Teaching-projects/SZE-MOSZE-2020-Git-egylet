#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
class Character
{
protected:
    const std::string characterName;
    int characterHP;
    int characterDMG;


public:
   
    Character(const std::string name, const int hp, const int dmg);
    static Character parseUnit(const std::string& name);
    std::string getName() const;
    int getHP() const;
    int getDMG() const;
    void attack( Character& target) const ;
    bool isAlive() const ;
    friend std::ostream& operator<<(std::ostream& os, const Character& obj);
   


};


#endif

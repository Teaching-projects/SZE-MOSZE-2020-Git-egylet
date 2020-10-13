#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
class Character
{
    
public:
   
    Character(const std::string, const int, const int);
    static Character parseUnit(const std::string& name);
    std::string getName() const;
    int getHP() const;
    int getDMG() const;
    void attack( Character& target) const ;
    bool isAlive() const ;
    friend std::ostream& operator<<(std::ostream& os, const Character& obj);
   

private:
     const std::string characterName;
     int characterHP;
     const int characterDMG ;
     
};


#endif

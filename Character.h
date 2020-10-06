#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
class character
{
    
public:
   
    character(const std::string, const int, const int, const double);
    static character parseUnit(const std::string& name);
    std::string getName() const;
    int getHP() const;
    int getDMG() const;
	double getACD() const;
    bool isAlive() const ;
    void attack(character& player1, character& player2);
    friend std::ostream& operator<<(std::ostream& os, const character& obj);
   

private:
     const std::string characterName;
     int characterHP;
     const int characterDMG;
	 const double characterACD;
	 void hit(character& target);
     
};


#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
class character
{
public:
    character(const std::string, const int, const int);
    void setName(std::string);
    void setHP(int);
    void setDMG(int);
    void attack( character& target) ;
    void status() const ;
    bool isAlive() const ;
   
  

private:
     std::string characterName;
     int characterHP;
     int characterDMG ;
};


#endif

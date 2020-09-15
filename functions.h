#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
class character
{
public:
    character(std::string, int, int);
    void setName(std::string);
    void setHP(int);
    void setDMG(int);
    void attack( character& target);
    void status();
    bool isAlive();
   
  

private:
    std::string characterName;
    int characterHP;
    int characterDMG;
};


#endif

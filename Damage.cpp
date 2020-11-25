#include "Damage.h"

Damage::Damage
(
	int p,
    int m
	) : 
	physical(p),
    magical(m)	
{}

void Damage::setPhysical(int p) {
    physical = p;
}

void Damage::setMagical(int m){
    magical = m;
}

int Damage::getPhysical() const {
    return physical;
}

int Damage::getMagical() const {
    return magical;
}

Damage operator + (const Damage& dmg1, const Damage& dmg2){
    Damage dmgToReturn ((dmg1.physical + dmg2.physical), (dmg1.magical + dmg2.magical));
    return dmgToReturn;
}

Damage& operator += (Damage& dmg1, const Damage& dmg2){
    dmg1.physical += dmg2.physical;
    dmg1.magical += dmg2.magical;
    return dmg1;
}

Damage& operator *= (Damage& dmg1, const Damage& dmg2){
    dmg1.physical *= dmg2.physical;
    dmg1.magical *= dmg2.magical;
    return dmg1;
}

std::ostream& operator << (std::ostream& s, const Damage& dmg){
    s << std::endl << "Physical damage: " << dmg.physical << std::endl << "Magical damage: " << dmg.magical;
    return s;
}
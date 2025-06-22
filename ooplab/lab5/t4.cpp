#include <iostream>
#include <string>
using namespace std;
class Character{
    public:
    int health;
public:
void setHealth(int health){
    this-> health = health;
}
int getHealth(){
    return health;
}

};
class Attacker{
    public:
    virtual void attack()=0;
};
class Defender{
    public:
    virtual void defend()=0;
};
class MagicUser{
    public:
    virtual void magic()=0;
};
class Paladin : public Character , public Attacker , public Defender , public MagicUser{
    public:
void attack() override{
    cout << " Its time to attack!!! SIUUUUU " << endl;
}
void defend() override{
    cout << " I am defending !! Hold up " << endl;
}
void magic() override{
    cout << " A spell has been dropped to reduce ELECTRO's health " << endl;
}
};
int main(){
    Paladin p;
p.setHealth(100);
cout << " ELectro hass attacked us , lets Fight !" << endl;
cout << " Paladin Is With  US , Let him FIGHT!!" << endl;
p.attack();
p.defend();
p.setHealth(50);
cout << " Oh no , My Health is now " << p.getHealth() << " % " << endl;
p.magic();
cout << " Hurrah ! WE finally defeated THE ELECTRO!!!" << endl;

}
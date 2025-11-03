#include "Spirit.h"

// Construtor da classe Spirit

Spirit::spirit(int h, int s, int i, int sp, string n, string bt){

    hp = h;
    strength = s;
    intelligence = i;
    speed = sp;
    nature = sp;
    bodyType = bt;
}

/ Metodos get

int Spirit::getHp(){
    return hp;
}
int Spirit::getStrength(){
    return strength;
}
int Spirit::getIntelligence(){
    return intelligence;
}
int Spirit::getSpeed(){
    return speed;
}
string Spirit::getNature(){
    return nature;
}
string Spirit::getBodyType(){
    return bodytype;   
}

 Metodos set

void Spirit::setHp(int h){
    hp = h;
 }
void Spirit::setStrenggth(int s){
    strength = s;
}
void Spirit::setIntelligence(int i){
    intelligence = i;
}
void Spirit::setSpeed(int sp){
    speed = sp;
}
void Spirit::setNature(string n){
    nature = n;
}
void Spirit::setbodyType(steing bt){
    bodyType = bt;
}


#ifndef SPIRIT_H
#define SPIRIT_H

#include <string>
using namespace std;

class Spirit {

    public:
        //Atributos

        int hp;
        int  strength;
        int intelligence;
        int speed;

        string nature; // Natureza como(Fogo, poderes etc..)
        string bodyType;

        //Construtor
        Spirit(int h, int s, int i, int sp, string n, string bt);

        //Metdoso set
        void setHp(int h);
        void setStrength(int s);
        void setIntelligence(int i);
        void setSpeed(int sp);
        void setNature(string n);
        void setBodyType(string bt);

        //Metodos get
        int getHp();
        int getStrength();
        int getIntelligence();
        int getSpeed();
        string getNature();
        string getBodyType();


    };



  #endif
  
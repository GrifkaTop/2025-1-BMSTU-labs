#include "planet.hpp"


Planet::Planet() : name(nullptr), diametr(0), life(0), sattelite(0){}
Planet::~Planet() {
    delete[] name;
}



Planet::Planet( char* name_, int diametr_, int life_, int sattelite_){
    this->name =new char[strlen(name_)+1];
    strcpy(this->name, name_);
    this->diametr = diametr_;
    this->life = life_;
    this->sattelite = sattelite_;
}

Planet::Planet(const Planet &p){
    this->name = new char[strlen(p.name)+1];
    strcpy(this->name, p.name);
    this->diametr = p.diametr;
    this->life = p.life;
    this->sattelite = p.sattelite;
}
/// Перегрузка оперторов

bool Planet::operator < (const Planet& b){
    int  f = std::strcmp(this->name, b.name);
    //int f = 0;
    if (f == 0) {
        if (this->diametr == b.diametr){
            if (this->life == b.life){
                return this->sattelite < b.sattelite;
            }
            else return this->life < b.life;
        }
        else return this->diametr < b.diametr;
    }
    return f < 0;
}

bool Planet::operator== (const Planet& b){
    char* s1 = this->name;
    char* s2 = b.name;
    if (sizeof(s1) != sizeof(s2)){
        return 0;
    }
    for (int i = 0; i < sizeof(s1); i++){
        if (s1[i] == s2[i]) {
            continue;
        }
        return 0;
    }
    return 1;
}


void Planet::operator= (const Planet& b){
    name = new char[strlen(b.name + 1)];
    this->name = name;
    strcpy(this->name, b.name);
    this->diametr = b.diametr;
    this->sattelite = b.sattelite;
    this->life = b.life;
    return;
}
/*
 ????????
bool operator > (Planet& b){
    return !(this < b);
}
*/


// get и set
char* Planet::getName() { return name; }
int Planet::getDiametr() { return diametr; }
int Planet::getLife() { return life; }
int Planet::getSattelite() { return sattelite; }
void Planet::setName(char* name_) { 
    this->name =new char[strlen(name_)+1];
    strcpy(this->name, name_);
}
void Planet::setDiametr(int diametr_) { this->diametr = diametr_; }
void Planet::setLife(int life_) { this->life = life_; }
void Planet::setSattelite(int sattelite_) { this->sattelite = sattelite_; }

void Planet::setAll(char* name_, int diametr_, int life_, int sattelite_) {
    this->name =new char[strlen(name_)+1];
    strcpy(this->name, name_);
    this->diametr = diametr_;
    this->life = life_;
    this->sattelite = sattelite_;
}


bool Planet::compBase(Planet a, Planet b){
    return a<b;
}

bool Planet::compName(Planet a, Planet b){
    bool f = false;
    char* s1 = a.getName();
    char* s2 = b.getName();
    if (sizeof(s1) < sizeof(s2)){
        f = true;
    }
    for (int i = 0; i < min(sizeof(s1), sizeof(s2)); i++){
        if (s1[i] == s2[i]) {
            continue;
        }
        if (s1[i] > s2[i]) {
            f = true;
        }
        else {
            f = false;
        }
        break;
    }
    return f;
}

bool Planet::compDiametr(Planet a, Planet b) {
    return a.getDiametr() < b.getDiametr();
}

bool Planet::compLife(Planet a, Planet b) {
    return a.getLife() < b.getLife();
}

bool Planet::compSattelite(Planet a, Planet b) {
    return a.getSattelite() < b.getSattelite();
}

ostream& operator << (ostream& os, Planet& a) {
    return os << a.getName() << ' ' << a.getDiametr() << ' ' << a.getLife() << ' ' << a.getSattelite() << endl;
}

istream& operator >> (istream& in, Planet& a) {
    char* name_;// = new char[1000+1];
    int diametr_;
    int life_;
    int sattelite_;
    in >> name_ >> diametr_ >> life_ >> sattelite_;
    if (in){
        a.setAll(name_, diametr_, life_, sattelite_);
    }
    return in;
}

Planet read(){
    Planet a;
    cin >> a;
    return a;
}


/*
void Planet::srt(int type, bool r, Planet* arr, int size){
    bool (*comp) (Planet, Planet) = compBase;
    switch (type)
    {
    case ShortChoice::BASE:
        comp = compBase;
        break;
    case ShortChoice::NAME:  
        comp = Planet::compName;
        break;
    case ShortChoice::DIAMETR:
        comp = Planet::compDiametr;
        break;
    case ShortChoice::LIFE:
        comp = Planet::compLife;
        break;
    case ShortChoice::SATTELITE:
        comp = Planet::compSattelite;
        break;
    default:
        comp = Planet::compBase;
        break;
    }
    if (r)
        sort(arr + 0, arr + size, comp);
    else
        sort(arr + size, arr + 0, comp);
    return;
} */


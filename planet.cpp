#include "planet.hpp"


Planet::Planet() {}



Planet::Planet(char* name_, int diametr_, int life_, int sattelite_){
    this->name = name_;
    this->diametr = diametr_;
    this->life = life_;
    this->sattelite = sattelite_;
}
/// Перегрузка оперторов

bool Planet::operator < (const Planet& b){
    int f = -1;
    char* s1 = this->name;
    char* s2 = b.name;
    if (sizeof(s1) < sizeof(s2)){
        f = 1;
    }
    for (int i = 0; i < min(sizeof(s1), sizeof(s2)); i++){
        if (s1[i] == s2[i]) {
            continue;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
        else {
            return 0;
        }
        break;
    }
    if (f == -1) {
        if (this->diametr == b.diametr){
            if (this->life == b.life){
                return this->sattelite < b.sattelite;
            }
            else return this->life < b.life;
        }
        else return this->diametr < b.diametr;
    }
    else return f;
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

/* ????????
bool operator > (Planet& b){
    return !(this < b);
}
*/


// get и set
char* Planet::getName() { return name; }
int Planet::getDiametr() { return diametr; }
int Planet::getLife() { return life; }
int Planet::getSattelite() { return sattelite; }
void Planet::setName(char* name_) { this->name =  name_; }
void Planet::setDiametr(int diametr_) { this->diametr = diametr_; }
void Planet::setLife(int life_) { this->life = life_; }
void Planet::setSattelite(int sattelite_) { this->sattelite = sattelite_; }

void Planet::setAll(char* name_, int diametr_, int life_, int sattelite_) {
    this->name = name_;
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
    char* name_;
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


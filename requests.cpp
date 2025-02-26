#include <planet.hpp>

class Requests{
    private:
        int id_u;
        char* name;
        int diametr;
        int life;
        int sattelite;

    public: 
    // Конструктор и Деконструктор
        Requests() {}

        ~Planet() {
            delete name;
        }

        Planet(char* name_, int diametr_, int life_, int sattelite_){
            this->name = name_;
            this->diametr = diametr_;
            this->life = life_;
            this->sattelite = sattelite_;
        }
    /// Перегрузка оперторов
        
        bool operator < (Planet& b){
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

        bool operator == (Planet& b){
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
        ostream &operator << (ostream& os) {
            os << this->name << ' ' << this->diametr << ' ' << this->life << ' ' << this->sattelite << endl;
            return os;
        }
        istream& operator >> (istream& in) {
            in >> this->name >> diametr >> this->life >>this->sattelite;
            return in;
        }

    // get и set
        char* getName() { return name; }
        int getDiametr() { return diametr; }
        int getLife() { return life; }
        int getSattelite() { return sattelite; }
        void setName(char* name_) { this->name =  name_; }
        void setDiametr(int diametr_) { this->diametr = diametr_; }
        void setLife(int life_) { this->life = life_; }
        void setSattelite(int sattelite_) { this->sattelite = sattelite_; }
        
        void setAll(char* name_, int diametr_, int life_, int sattelite_) {
            this->name = name_;
            this->diametr = diametr_;
            this->life = life_;
            this->sattelite = sattelite_;
        }


        bool compBase(Planet a, Planet b){
            return a < b;
        }

        bool compName(Planet a, Planet b){
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

        bool compDiametr(Planet a, Planet b) {
            return a.getDiametr() < b.getDiametr();
        }

        bool compLife(Planet a, Planet b) {
            return a.getLife() < b.getLife();
        }

        bool compSattelite(Planet a, Planet b) {
            return a.getSattelite() < b.getSattelite();
        }

        enum ShortChoice: int{
            BASE = 0,
            NAME = 1,
            DIAMETR = 2,
            LIFE = 3,
            SATTELITE = 4
        };

        void srt(int type, bool r, Planet* arr, int size){
            auto comp = Planet::compBase;
            switch (type)
            {
            case BASE:
                comp = Planet::compBase;
                break;
            case NAME:  
                comp = Planet::compName;
                break;
            case DIAMETR:
                comp = Planet::compDiametr;
                break;
            case LIFE:
                comp = Planet::compLife;
                break;
            case SATTELITE:
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
        }
};

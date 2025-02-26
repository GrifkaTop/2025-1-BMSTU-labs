#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

class Planet{
    private:
        char* name;
        int diametr;
        int life;
        int sattelite;
    public:
        Planet();
        ~Planet();
        Planet(char* name_, int diametr_, int life_, int sattelite_);
        
        bool operator < (const Planet& b);
        bool operator== (const Planet& b);
        // bool operator > (Planet& b);
        
    
        char* getName();
        int getDiametr();
        int getLife();
        int getSattelite();
        void setName(char* name_);
        void setDiametr(int diametr_);
        void setLife(int life_);
        void setSattelite(int sattelite_);
        
        void setAll(char* name_, int diametr_, int life_, int sattelite_);

        static bool compBase(Planet a, Planet b);
        bool compName(Planet a, Planet b);
        bool compDiametr(Planet a, Planet b);
        bool compLife(Planet a, Planet b);
        bool compSattelite(Planet a, Planet b);


        enum ShortChoice: int{
            BASE = 0,
            NAME = 1,
            DIAMETR = 2,
            LIFE = 3,
            SATTELITE = 4
        };

        void srt( bool r, Planet* arr, int size);

        Planet read();

    };


ostream& operator << (ostream& os, Planet& a);
istream& operator >> (istream& in, Planet& a);
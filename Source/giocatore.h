#include "pc.h"
using namespace std;

class Giocatore
{
    private:
        int posx;
        int posy;
        void PosizionaCursore(int x, int y);        //movimento cursore terminale (windows only)
        char Immagine=4;
    public:
        Giocatore()
        {
            posx=0;
            posy=0;
        }
        void Mossa(CampoGioco &Mappa);

        void MovimentoCursore();

        void gotoxy(int x, int y);
};


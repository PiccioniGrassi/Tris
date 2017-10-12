#include <iostream>

using namespace std;

const int righe=5;
const int colonne=5;

class CampoGioco
{
    private:
        char campo[righe][colonne] =           //0 sta per vuoto, 1 sta per verticale, 2 sta per orizzontale, 3 sta per incrocio, 4 sta per giocatore e 5 sta per nemico
        {
            {0, 1, 0, 1, 0},
            {2, 3, 2, 3, 2},
            {0, 1, 0, 1, 0},
            {2, 3, 2, 3, 2},
            {0, 1, 0, 1, 0}
        };
        int campoPc[3][3] =
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
    public:
        void StampaChar(int x, int y);          //stampa dei vari movimenti
        void StampaMappa();             //stampa mappa
        int getValoreCampoPc(int x, int y);  //return dei valori della tabella del pc
        void setValore(char valore, int x, int y);       //set dei valori della tabella

        void gotoxy(int x, int y);      //movimento cursore terminale (windows only)

        char getValore(int x, int y);//return valore mappa
};

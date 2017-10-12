#include "giocatore.h"
#include "TrisIA.h"
using namespace std;

class GameController
{
    private:
        Giocatore Player;
        Pc MappaIA;
        TrisIA IA;
        CampoGioco Gioco;
        /*bool vittoria = false;
        bool Sconfitta = false;
        bool Pareggio = false;*/
    public:
        void Inizializza();
        void Partita();
        void Fine();
        void copiaMatrice(CampoGioco,int m1[][3]);
};

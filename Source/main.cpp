#include "gamecontroller.h"
#include "windows.h"
int main()
{

    GameController Partita;
    Partita.Inizializza();
    Partita.Partita();
    Partita.Fine();
    Sleep(2000);
}

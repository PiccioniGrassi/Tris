#include "pc.h"
using namespace std;

void Pc::Mossa(CampoGioco &Mappa, int x, int y)
{
    Mappa.setValore(Immagine, x*2, y*2);
}

#include <windows.h>
#include "giocatore.h"
#include <conio.h>

using namespace std;

void Giocatore::PosizionaCursore(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Giocatore::Mossa(CampoGioco &Mappa)
{
    bool scelto=false;
    while(!scelto)
    {
       if(GetAsyncKeyState(VK_SPACE)&&Mappa.getValore(posx,posy)!=5&&Mappa.getValore(posx,posy)!=4)
        {
            Mappa.setValore(Immagine, posx, posy);
            scelto=true;
            gotoxy(posx,posy);
        }else
            MovimentoCursore();
        Sleep(200);
    }
}

void Giocatore::MovimentoCursore()
{
    if(GetAsyncKeyState(VK_DOWN)&&posy+2<righe)
        posy=posy+2;
    else if(GetAsyncKeyState(VK_UP)&&posy-2>=0)
        posy=posy-2;
    else if(GetAsyncKeyState(VK_LEFT)&&posx-2>=0)
        posx=posx-2;
    else if(GetAsyncKeyState(VK_RIGHT)&&posx+2<colonne)
        posx=posx+2;
    gotoxy(posx, posy);
}

void Giocatore::gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

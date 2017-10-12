#include <iostream>
#include "campogioco.h"
#include <windows.h>

//codici ascii per il campo

const int Vuoto = 255;          //0
const int PareteVerticale = 179;            //1
const int PareteOrizzontale = 196;          //2
const int Incrocio = 197;           //3
const int Player = 79;       //cerchio 4
const int Nemico = 88;      //croce 5

using namespace std;

void CampoGioco::StampaMappa()
{
    for (int r=0; r<righe; r++)
    {
        for(int c=0; c<colonne; c++)
        {
            StampaChar(c,r);
        }
        cout<<endl;
    }
}

void CampoGioco::StampaChar(int x, int y)
{
    switch (campo[y][x])
            {
                case 0:
                    cout<<(char)Vuoto;
                    break;
                case 1:
                    cout<<(char)PareteVerticale;
                    break;
                case 2:
                    cout<<(char)PareteOrizzontale;
                    break;
                case 3:
                    cout<<(char)Incrocio;
                    break;
                case 4:
                    cout<<(char)Player;
                    break;
                case 5:
                    cout<<(char)Nemico;
                    break;
                default:
                        break;
            }
}

int CampoGioco::getValoreCampoPc(int x, int y)
{
    return campoPc[y][x];
}

char CampoGioco::getValore(int x, int y)
{
    return campo[y][x];
}

void CampoGioco::setValore(char valore, int x, int y)
{
    campo[y][x] = valore;
    gotoxy(x,y);
    StampaChar(x,y);
    x=x/2;
    y=y/2;
    campoPc[y][x] = (int)valore;
}

void CampoGioco::gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

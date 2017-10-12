#include "gamecontroller.h"
#include "windows.h"

using namespace std;

void GameController::Inizializza() //start partita
{
    Gioco.StampaMappa();
    Gioco.gotoxy(0,0);
}

void GameController::Partita() //ciclo gioco
{
    int matrice[3][3];//matrice da passare ad ia
    bool finito=false;
    while(!IA.isPartitaFinita(matrice))
    {
        Player.Mossa(Gioco);        //mossa giocatore
        copiaMatrice(Gioco,matrice);
        if(IA.isPartitaFinita(matrice))
            finito=true;
        else
        {
            Coordinate Pos = IA.calcolaCoordinateMossaMigliore(matrice);//mossa ia
            MappaIA.Mossa(Gioco, Pos.x, Pos.y);
            copiaMatrice(Gioco,matrice);
            if(IA.isPartitaFinita(matrice))
                finito=true;
        }
        Sleep(500);
    }
}

void GameController::copiaMatrice(CampoGioco m1, int m2[][3]){
        for(int y = 0; y < 3; y ++){
            for(int x = 0; x < 3; x++){
                m2[y][x] = m1.getValoreCampoPc(x,y);
            }
        }
    }

void GameController::Fine()
{
    Player.gotoxy(0,20);
    /*if(Vittoria)
        cout<<"Hai Vinto."<<endl;
    else if(Sconfitta)
        cout<<"Hai Perso."<<endl;
    else
        cout<<"Hai Pareggiato."<<endl;*/
    cout<<"Partita Terminata";

}

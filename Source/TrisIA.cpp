#include "TrisIA.h"
int valoreAssoluto(int n){
    if(n < 0)
        n = n * (-1);
    return n;
}
bool equazioneDirTris1(Coordinate pPosizione){
    return (pPosizione.x == 0);
}
bool equazioneDirTris2(Coordinate pPosizione){
    return (pPosizione.x == 1);
}
bool equazioneDirTris3(Coordinate pPosizione){
    return (pPosizione.x == 2);
}
bool equazioneDirTris4(Coordinate pPosizione){
    return (pPosizione.y == 0);
}
bool equazioneDirTris5(Coordinate pPosizione){
    return (pPosizione.y == 1);
}
bool equazioneDirTris6(Coordinate pPosizione){
    return (pPosizione.y == 2);
}
bool equazioneDirTris7(Coordinate pPosizione){
    return (pPosizione.y == pPosizione.x);
}
bool equazioneDirTris8(Coordinate pPosizione){
    return (valoreAssoluto(pPosizione.y - 2) == pPosizione.x);
}

int TrisIA::calcolaNumeroMossePossibili(int tabellaTris[][3]){
    int numeroMossePossibili = 0;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(tabellaTris[i][j] == 0)
                numeroMossePossibili ++;
        }
    }
    return numeroMossePossibili;
}
void TrisIA::calcolaMossePossibili(int tabellaTris[][3], Mossa pMosse[]){
    int indiceMossa = 0;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(tabellaTris[i][j] == 0){
                pMosse[indiceMossa].posizione.x = j;
                pMosse[indiceMossa].posizione.y = i;
                pMosse[indiceMossa].direzioniTrisAvversarioNegate = 0;
                int occorrenzeMassimeAvversarioNegate = 0;
                int occorrenzeMassimeIARafforzate = 0;
                for(int c = 0; c < 8; c ++){
                    if(DIREZIONI[c].equazioneDirezione(pMosse[indiceMossa].posizione)){
                        pMosse[indiceMossa].direzioniTrisAvversarioNegate ++;
                        if(DIREZIONI[c].occorenzeAvversario >= occorrenzeMassimeAvversarioNegate)
                            occorrenzeMassimeAvversarioNegate = DIREZIONI[c].occorenzeAvversario;
                        if(DIREZIONI[c].occorenzeIA >= occorrenzeMassimeIARafforzate)
                            occorrenzeMassimeIARafforzate = DIREZIONI[c].occorenzeIA;
                    }
                }
                pMosse[indiceMossa].occorrenzeTrisAvversarioNegate = occorrenzeMassimeAvversarioNegate;
                pMosse[indiceMossa].occorrenzeTrisIARafforzate = occorrenzeMassimeIARafforzate;
                indiceMossa ++;
            }
        }
    }
}
Mossa TrisIA::calcolaMossaMigliore(Mossa pMosse[], int numeroMosse){
    int indiceMossaMigliore = 0;
    int occorrenzeMassimeNemicheNegate = 0;
    int occorrenzeMassimeIARafforzate = 0;
    int direzioniMassimeAvversarioNegate = 0;
    for(int i = 0; i < numeroMosse; i ++){
        if(pMosse[i].occorrenzeTrisIARafforzate == 2){
            indiceMossaMigliore = i;
            i = numeroMosse;
        } else {
           if(pMosse[i].occorrenzeTrisAvversarioNegate > occorrenzeMassimeNemicheNegate){
                occorrenzeMassimeNemicheNegate = pMosse[i].occorrenzeTrisAvversarioNegate;
                occorrenzeMassimeIARafforzate = pMosse[i].occorrenzeTrisIARafforzate;
                direzioniMassimeAvversarioNegate = pMosse[i].direzioniTrisAvversarioNegate;
                indiceMossaMigliore = i;
            }else if(pMosse[i].occorrenzeTrisAvversarioNegate == occorrenzeMassimeNemicheNegate){
                if(pMosse[i].direzioniTrisAvversarioNegate > direzioniMassimeAvversarioNegate){
                    direzioniMassimeAvversarioNegate = pMosse[i].direzioniTrisAvversarioNegate;
                    occorrenzeMassimeIARafforzate = pMosse[i].occorrenzeTrisIARafforzate;
                    indiceMossaMigliore = i;
                }
                else if(pMosse[i].direzioniTrisAvversarioNegate == direzioniMassimeAvversarioNegate){
                    if(pMosse[i].occorrenzeTrisIARafforzate > occorrenzeMassimeIARafforzate){
                        occorrenzeMassimeIARafforzate = pMosse[i].occorrenzeTrisIARafforzate;
                        indiceMossaMigliore = i;
                    }
                }
            }
        }
    }
    return pMosse[indiceMossaMigliore];
}
void TrisIA::calcolaOccorrenzePerDirezione(int tabellaTris[][3]){
    Coordinate punto;
    for(int i = 0; i < 8; i ++){
        DIREZIONI[i].occorenzeAvversario = 0;
        DIREZIONI[i].occorenzeIA = 0;
    }
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            for(int d = 0; d < 8; d ++){
                punto.x = j;
                punto.y = i;
                if(DIREZIONI[d].equazioneDirezione(punto)){
                    if(tabellaTris[i][j] == 4)
                        DIREZIONI[d].occorenzeAvversario ++;
                    else if(tabellaTris[i][j] == 5)
                        DIREZIONI[d].occorenzeIA ++;
                }
            }
        }
    }
}

TrisIA::TrisIA(){
    DIREZIONI[0].equazioneDirezione = &equazioneDirTris1;
    DIREZIONI[1].equazioneDirezione = &equazioneDirTris2;
    DIREZIONI[2].equazioneDirezione = &equazioneDirTris3;
    DIREZIONI[3].equazioneDirezione = &equazioneDirTris4;
    DIREZIONI[4].equazioneDirezione = &equazioneDirTris5;
    DIREZIONI[5].equazioneDirezione = &equazioneDirTris6;
    DIREZIONI[6].equazioneDirezione = &equazioneDirTris7;
    DIREZIONI[7].equazioneDirezione = &equazioneDirTris8;

    for(int i = 0; i < 8; i ++){
        DIREZIONI[i].occorenzeAvversario = 0;
        DIREZIONI[i].occorenzeIA = 0;
    }
}
Coordinate TrisIA::calcolaCoordinateMossaMigliore(int tabellaTris[][3]){
    calcolaOccorrenzePerDirezione(tabellaTris);
    int numeroMossePossibili = calcolaNumeroMossePossibili(tabellaTris);
    Mossa mossePossibili[numeroMossePossibili];
    calcolaMossePossibili(tabellaTris, mossePossibili);
    return calcolaMossaMigliore(mossePossibili, numeroMossePossibili).posizione;
}
bool TrisIA::isPartitaFinita(int tabellaTris[][3]){
    calcolaOccorrenzePerDirezione(tabellaTris);
    bool partitaFinita = false;
    if(calcolaNumeroMossePossibili(tabellaTris) == 0)
        partitaFinita = true;
    for(int i = 0; i < 8; i ++){
        if(DIREZIONI[i].occorenzeAvversario == 3 || DIREZIONI[i].occorenzeIA == 3)
            partitaFinita = true;
    }
    return partitaFinita;
}




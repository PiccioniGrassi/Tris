#ifndef TRISIA
#define TRISIA
struct Coordinate{
    int x;
    int y;
};
struct Mossa{
    Coordinate posizione;
    int occorrenzeTrisAvversarioNegate;
    int occorrenzeTrisIARafforzate;
    int direzioniTrisAvversarioNegate;
};
struct DirezioneTris{
    bool (*equazioneDirezione)(Coordinate);
    int occorenzeAvversario;
    int occorenzeIA;
};
int valoreAssoluto(int n);
bool equazioneDirTris1(Coordinate pPosizione);
bool equazioneDirTris2(Coordinate pPosizione);
bool equazioneDirTris3(Coordinate pPosizione);
bool equazioneDirTris4(Coordinate pPosizione);
bool equazioneDirTris5(Coordinate pPosizione);
bool equazioneDirTris6(Coordinate pPosizione);
bool equazioneDirTris7(Coordinate pPosizione);
bool equazioneDirTris8(Coordinate pPosizione);
class TrisIA{
    public:
    DirezioneTris DIREZIONI[8];
    void calcolaMossePossibili(int tabellaTris[][3], Mossa pMosse[]);
    Mossa calcolaMossaMigliore(Mossa pMosse[], int numeroMosse);
    void calcolaOccorrenzePerDirezione(int tabellaTris[][3]);

    TrisIA();
    int calcolaNumeroMossePossibili(int tabellaTris[][3]);
    Coordinate calcolaCoordinateMossaMigliore(int tabellaTris[][3]);
    bool isPartitaFinita(int tabellaTris[][3]);
};
#endif // TRISIA

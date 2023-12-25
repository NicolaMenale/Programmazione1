//GESTIONE MAGAZZINO
/*LA FINALITà DEL PROGRAMMA è QUELLA DELLA GESTIONE DI UN MAGAZZINO NEL PERIODO DI UN INTERO ANNO. NEL PROGRAMMA RITROVIAMO 20 PRODOTTI CON NOME, SPECIFICA, CODICE IDENTIFICATIVO, QUANTITà E COSTO. IL PROGRAMMA, OLTRE A DOVER GESTIRE IL MAGAZZINO PER 365 GIORNI, PUò RICEVERE IN PARTICOLARE 3 INPUT E UN QUARTO INPUT CHE LO INTERROMPE. I 3 INPUT SONO:
 1)DATO UN GIORNO, SCELTO DALL'UTENTE, VA A VISUALIZZARE I PRODOTTI CHE ALLA FINE DELLA GIORNATA SONO SOTTO SCORTA, OVVERO MENO DI 5
 2)DATO UN GIORNO, VIENE CONTROLLATO SE I PRODOTTI SONO STATI ACQUISTATI ALMENO UNA VOLTA
 3)DATO IN INPUT IL CODICE DI UN PRODOTTO, VIENE VISUALIZZATO QUANTI NE SONO STATI VENDUTI IN UNA FINESTRA TEMPORALE DI 10GG (LE DUE DATE DI INIZIO E DI FINE VENGONO SCELTE DALL'UTENTE)*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//STRUCT CHE RACCHIUDE I NOMI DEI 12 MESI CHE VENGONO UTILIZZATI PER IL CONTATORE DEI GIORNI E DEI MESI ALL'INIZIO DELL'ESECUZIONE DEL PROGRAMMA
typedef struct Mesi{
    char *nome;
} Mesi;

//STRUCT DEI PRODOTTI CON TUTTE LE CARATTERISTICHE
typedef struct Prodotti {
    char *nome;
    char *specifica;
    int codice;
    int quantità;
    int prezzo;
} Prodotti;

//STRUCT UTILIZZATA DAI 20 PRODOTTI, PER CONTENERE IL NUMERO DEI PRODOTTI VENDUTI OGNI GIORNO
typedef struct ProdottiVenduti {
    int venduti[365];
} ProdottiVenduti;

//STRUCT UTILIZZATA DAI 20 PRODOTTI, PER CONTENERE IL NUMERO DEI PRODOTTI RIMANENTI ALLA FINE DI OGNI GIORNO
typedef struct ProdottiRimanenti {
    int rimanenti[365];
} ProdottiRimanenti;

//INIZIALIZZAZIONE FUNCTION PER VISUALIZZARE I PRODOTTI SOTTO SCORTA DI UN DETERMINATO GIORNO
void prodotto_sotto_scorta(int [], ProdottiRimanenti [], ProdottiVenduti [], Prodotti []);

//INIZIALIZZAZIONE FUNCTION PER VISUALIZZARE I PRODOTTI SOTTO SCORTA DI UN DETERMINATO GIORNO
void prodotto_acquistato(int [], ProdottiRimanenti [], ProdottiVenduti [], Prodotti []);

//INIZIALIZZAZIONE FUNCTION PER VISUALIZZARE IL NUMERO DI PRODOTTI TOTALI VENDUTI IN 10 GIORNI(SCELTI DALL'UTENTE)
void prodotti_venduti_10gg(int [], ProdottiRimanenti [], ProdottiVenduti [], Prodotti []);

//INIZIALIZZAZIONE FUNCTION CHE VISUALIZZA IL MENU E L'INSERIMENTO DEL COMANDO
int menu(int);

//INIZIALIZZAZIONE FUNCTION CHE UTILIZZA IL COMANDO INSERITO NELLA FUNCTION MENU PER OPERARE UNA DELLE 4 SCELTE POSSIBILI
void scelte(int, int [], ProdottiRimanenti [], ProdottiVenduti [], Prodotti []);

int main()
{
    ProdottiVenduti ProdottiVenduti[20];
    
    ProdottiRimanenti ProdottiRimanenti[20];
    
    Prodotti prodotto[20];
    prodotto[0].nome = "Workstation AMD (1)";
    prodotto[0].codice = 6586;
    prodotto[0].prezzo = 2500;
    prodotto[0].quantità = 20;
    prodotto[0].specifica = "128GB ram, 1TB storage";
    
    prodotto[1].nome = "Workstation AMD-2 (2)";
    prodotto[1].codice = 5869;
    prodotto[1].prezzo = 2750;
    prodotto[1].quantità = 15;
    prodotto[1].specifica = "128GB ram, 2TB storage";
    
    prodotto[2].nome = "Workstation Intel (3)";
    prodotto[2].codice = 7879;
    prodotto[2].prezzo = 2300;
    prodotto[2].quantità = 20;
    prodotto[2].specifica = "256GB ram, 1TB storage";
    
    prodotto[3].nome = "Workstation Intel-2 (4)";
    prodotto[3].codice = 8796;
    prodotto[3].prezzo = 1700;
    prodotto[3].quantità = 30;
    prodotto[3].specifica = "64GB ram, 1TB storage";
    
    prodotto[4].nome = "Portatile ASUS (5)";
    prodotto[4].codice = 5348;
    prodotto[4].prezzo = 1700;
    prodotto[4].quantità = 10;
    prodotto[4].specifica = "16GB ram, 1TB storage";
    
    prodotto[5].nome = "Pc Fisso NZXT (6)";
    prodotto[5].codice = 6898;
    prodotto[5].prezzo = 1200;
    prodotto[5].quantità = 10;
    prodotto[5].specifica = "32GB ram, 2TB storage";
    
    prodotto[6].nome = "Pc Fisso MSI (7)";
    prodotto[6].codice = 4375;
    prodotto[6].prezzo = 1150;
    prodotto[6].quantità = 50;
    prodotto[6].specifica = "16GB ram, 2TB storage";
    
    prodotto[7].nome = "IPhone 13 (8)";
    prodotto[7].codice = 6329;
    prodotto[7].prezzo = 1300;
    prodotto[7].quantità = 40;
    prodotto[7].specifica = "8GB ram, 1TB storage";
   
    prodotto[8].nome = "Portatile MSI (9)";
    prodotto[8].codice = 7571;
    prodotto[8].prezzo = 1000;
    prodotto[8].quantità = 30;
    prodotto[8].specifica = "16GB ram, 2TB storage";
    
    prodotto[9].nome = "Pc Fisso DELL (10)";
    prodotto[9].codice = 9063;
    prodotto[9].prezzo = 1450;
    prodotto[9].quantità = 35;
    prodotto[9].specifica = "8GB ram, 2TB storage";
    
    prodotto[10].nome = "Workstation Intel-3 (11)";
    prodotto[10].codice = 1437;
    prodotto[10].prezzo = 1950;
    prodotto[10].quantità = 45;
    prodotto[10].specifica = "64GB ram, 2TB storage";
    
    prodotto[11].nome = "Pc Fisso AMD (12)";
    prodotto[11].codice = 2538;
    prodotto[11].prezzo = 1500;
    prodotto[11].quantità = 40;
    prodotto[11].specifica = "32GB ram, 2TB storage";
    
    prodotto[12].nome = "Pc Fisso intel (13)";
    prodotto[12].codice = 7452;
    prodotto[12].prezzo = 900;
    prodotto[12].quantità = 70;
    prodotto[12].specifica = "16GB ram, 2TB storage";
    
    prodotto[13].nome = "Portatile ASUS (14)";
    prodotto[13].codice = 4365;
    prodotto[13].prezzo = 800;
    prodotto[13].quantità = 80;
    prodotto[13].specifica = "16GB ram, 1TB storage";
    
    prodotto[14].nome = "Tablet Samsung (15)";
    prodotto[14].codice = 2538;
    prodotto[14].prezzo = 700;
    prodotto[14].quantità = 90;
    prodotto[14].specifica = "4GB ram, 2TB storage";
    
    prodotto[15].nome = "Workstation AMD-3 (16)";
    prodotto[15].codice = 5629;
    prodotto[15].prezzo = 3000;
    prodotto[15].quantità = 10;
    prodotto[15].specifica = "128GB ram, 3TB storage";
    
    prodotto[16].nome = "Pc Fisso NZXT-2 (17)";
    prodotto[16].codice = 9754;
    prodotto[16].prezzo = 1400;
    prodotto[16].quantità = 100;
    prodotto[16].specifica = "16GB ram, 4TB storage";
    
    prodotto[17].nome = "Workstation Intel-4 (18)";
    prodotto[17].codice = 8931;
    prodotto[17].prezzo = 1650;
    prodotto[17].quantità = 70;
    prodotto[17].specifica = "64GB ram, 3TB storage";
    
    prodotto[18].nome = "Samsung S21 (19)";
    prodotto[18].codice = 4368;
    prodotto[18].prezzo = 1000;
    prodotto[18].quantità = 40;
    prodotto[18].specifica = "16GB ram, 1TB storage";
    
    prodotto[19].nome = "Workstation AMD-4 (20)";
    prodotto[19].codice = 3257;
    prodotto[19].prezzo = 3500;
    prodotto[19].quantità = 80;
    prodotto[19].specifica = "256GB ram, 4TB storage";
    
    Mesi giorniMesi[12];
    giorniMesi[0].nome="Gennaio";
    giorniMesi[1].nome="Febbraio";
    giorniMesi[2].nome="Marzo";
    giorniMesi[3].nome="Aprile";
    giorniMesi[4].nome="Maggio";
    giorniMesi[5].nome="Giugno";
    giorniMesi[6].nome="Luglio";
    giorniMesi[7].nome="Agosto";
    giorniMesi[8].nome="Settembre";
    giorniMesi[9].nome="Ottobre";
    giorniMesi[10].nome="Novembre";
    giorniMesi[11].nome="Dicembre";
 
    int i = 0, h = 0, j = 0;
    
    int quantità_iniziale[20] = {20, 15, 20, 30, 10, 10, 50, 40, 30, 35, 45, 40, 70, 80, 90, 10, 100, 70, 40, 80};

    int comando = 0, command;
    
    int mesi2[13]={-1, 30, 57, 88, 118, 149, 179, 210, 241, 271, 302, 332, 363};
 
    srand(time(NULL));
    

    //COSTRUTTO UTILIZZATO DAL PROGRAMMA PER VENDERE I PRODOTTI E AGGIUNGERNE IN CASO DI SCARSE SCORTE. IL BLOCCO DI ISTRUZIONI, ALL'INIZIO, MOSTRA IL GIORNO, IL MESE E LA QUANTITà DEL PRODOTTO SPECIFICO DISPONIBILE ALL'INIZIO DI OGNI GIORNATA, IN SEGUITO UN GENERATORE DI NUMERI CASUALI, CHE VA DA 0 ALLA QUANTITà DI PRODOTTO DISPONIBILE ALL'INIZIO DI QUELLA DETERMINATA GIORNATA, GENERA IL NUMERO DI PRODOTTI CHE VERRANNO VENDUTI E LO INSERISCE NELLA STRUCT "PRODOTTIVENDUTI" PER RICORDARE LA VENDITA IN QUEL SPECIFICO GIORNO. INFINNE ABBIAMO IL SALVATAGGIO DEI PRODOTTI RIMANENTI A FINE GIORNATA NELLA STRUCT "PRODOTTIRIMANENTI", IN MODO TALE CHE LA QUANTITà DEI PRODOTTI DEL GIORNO DOPO SIANO EQUIVALENTI AI RIMANENTI DEL GIORNO PRIMA
    
    for (h=0; h<365; h++) {
    for (i=0; i<20; i++) {
    for (j=0; j<12; j++) {
            if (h>mesi2[j] && h<mesi2[j+1]+1) {
         //printf("[Giorno %d]-%d-%s\n",h+1, (h-mesi2[j]), giorniMesi[j].nome);
        }
    }
        //printf("Prodotti.quantita: %d\n", prodotto[i].quantità);
        ProdottiVenduti[i].venduti[h] = 0 + rand()%prodotto[i].quantità;
        ProdottiRimanenti[i].rimanenti[h] = prodotto[i].quantità - ProdottiVenduti[i].venduti[h];
        prodotto[i].quantità = ProdottiRimanenti[i].rimanenti[h];
        
        if (prodotto[i].quantità < 3) {
            prodotto[i].quantità = quantità_iniziale[i];
        };

        //printf("P%d %s: Venduti = %d Rimanenti = %d\n\n", i+1, prodotto[i].nome, ProdottiVenduti[i].venduti[h], ProdottiRimanenti[i].rimanenti[h]);
    }
    }
    
    command = menu(comando);
    scelte(command, mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
    
    return 0;
}

//FUNCTION "MENU" CHE STAMPA IL MENU E CHE UTILIZZA UNA SCANF PER PERMETTE ALL'UTENTE DI SCEGLIRERE UNO DEI 4 COMANDI. IL NUMERO VERRà ASSOCIATO AD UN'ALTRA VARIABILE (COMMAND) CHE VERRà USATA DALLA FUNCTION SCELTE
int menu(int comando)
{
    printf("---------------------------------------------------------\n");
    printf("                    Lista dei comandi\n");
    printf("[1] Prodotti Sotto Scorta\n");
    printf("[2] Acquisto Prodotto\n");
    printf("[3] Numero di Prodotti Venduti in 10gg\n");
    printf("[4] Chiudere il Programma\n");
    printf("---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
    printf("                    Digitare Comando\n");
    scanf("%d", &comando);
    printf("---------------------------------------------------------\n");
    return comando;
}

//FUNCTION "SCELTE": FUNCTION CHE HA COME SCOPO QUELLO DI ATTIVARE UNA DELLE ALTRE 3 FUNCTION DEL PROGRAMMA IN BASE AL NUMERO SCELTO DALL'UTENTE ALL'AVVIO DEL PROGRAMMA (1 A 3).
//UTILIZZA COME INPUT:
//-command = COMANDO SCELTO DALL'UTENTE E UTILIZZATO DAL PROGRAMMA IN UNO SWITCH PER UTILIZZARE UNA DELLE 3 FUNCTION
//-mesi[] = ARRAY CHE INDICA IL PRIMO GIORNO DI OGNI MESE DELL'ANNO CONTANDO I GIORNI DA 0 A 364
//-ProdottiRimanenti[] = STRUCT DEI PRODOTTI RIMANENTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-ProdottiVenduti[] = STRUCT DEI PRODOTTI VENDUTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-prodotto[] = STRUCT DEI PRODOTTI
//GLI ULTIMI 4 INPUT A LORO VOLTA SONO INPUT DELLE ALTRE 3 FUNCTION
void scelte(int command, int mesi2[], ProdottiRimanenti ProdottiRimanenti[], ProdottiVenduti ProdottiVenduti[], Prodotti prodotto[])
{
    int comando = 0;
    switch (command) {
        case 1:
            prodotto_sotto_scorta(mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
            break;
            
        case 2:
            prodotto_acquistato(mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
            break;
            
        case 3:
            prodotti_venduti_10gg(mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
            break;
            
        case 4:
            printf("Chiusura Programma...\n---------------------------------------------------------\n");
            break;
            
        default: printf("\nComando Errato\n");
            command = menu(comando);
            scelte(command, mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
            break;
    }
}

//FUNCTION "PRODOTTO SOTTO SCORTA": FUNCTION CHE HA COME SCOPO QUELLO DI, IN BASE AD UNA DATA SCELTA DALL'UTENTE, VISUALIZZARE I PRODOTTI, A FINE GIORNATA, CHE HANNO UNA QUANTITà MINORE DI 5.
//UTILIZZA COME INPUT:
//-mesi[] = ARRAY CHE INDICA IL PRIMO GIORNO DI OGNI MESE DELL'ANNO CONTANDO I GIORNI DA 0 A 364
//-ProdottiRimanenti[] = STRUCT DEI PRODOTTI RIMANENTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-ProdottiVenduti[] = STRUCT DEI PRODOTTI VENDUTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-prodotto[] = STRUCT DEI PRODOTTI
//I 4 INPUT A LORO VOLTA SONO INPUT DELLE FUNCTION "MENU" E "SCELTE"
void prodotto_sotto_scorta(int mesi2[], ProdottiRimanenti ProdottiRimanenti[], ProdottiVenduti ProdottiVenduti[], Prodotti prodotto[])
{
    int i, g, giorno, mese, comando = 0, command = 0;
    
    printf("---------------------------------------------------------\n");
    printf("                  Prodotto Sotto Scorta\n");
    printf("Digitare Giorno (es. 20): ");
    scanf("%d", &giorno);
    printf("Digitare mese (es. 3): ");
    scanf("%d", &mese);
    for (g = mese; g == mese; g++) {
        for (i = 0; i < 20; i++) {
             
            if (ProdottiRimanenti[i].rimanenti[giorno + mesi2[g-1]] < 5) {
                printf("\n[%s]", prodotto[i].nome);
            }
        }
    }
    printf("\n---------------------------------------------------------\n");
    command = menu(comando);
    scelte(command, mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);}


//FUNCTION "PRODOTTO ACQUISTATO": FUNCTION CHE HA COME SCOPO QUELLO DI, IN BASE AD UNA DATA SCELTA DALL'UTENTE, VISUALIZZARE I PRODOTTI, A FINE GIORNATA, CHE NON SONO STATI VENDUTI.
//UTILIZZA COME INPUT:
//-mesi[] = ARRAY CHE INDICA IL PRIMO GIORNO DI OGNI MESE DELL'ANNO CONTANDO I GIORNI DA 0 A 364
//-ProdottiRimanenti[] = STRUCT DEI PRODOTTI RIMANENTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-ProdottiVenduti[] = STRUCT DEI PRODOTTI VENDUTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-prodotto[] = STRUCT DEI PRODOTTI
//I 4 INPUT A LORO VOLTA SONO INPUT DELLE FUNCTION "MENU" E "SCELTE"
void prodotto_acquistato(int mesi2[], ProdottiRimanenti ProdottiRimanenti[], ProdottiVenduti ProdottiVenduti[], Prodotti prodotto[])
{
    int i, g, giorno, mese, command = 0, comando = 0;
    
    printf("---------------------------------------------------------\n");
    printf("                    Acquisto Prodotto\n");
    printf("Digitare Giorno (es. 20): ");
    scanf("%d", &giorno);
    printf("Digitare mese (es. 3): ");
    scanf("%d", &mese);
    
    for (g = mese; g == mese; g++) {
        for (i = 0; i < 20; i++) {
            if (ProdottiVenduti[i].venduti[giorno + mesi2[g-1]] == 0 ) {
                printf("\n[%s]", prodotto[i].nome);
            }
            
        }
    }
    printf("\n---------------------------------------------------------\n");
    command = menu(comando);
    scelte(command, mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
}


//FUNCTION "PRODOTI VENDUTI 10GG": FUNCTION CHE HA COME SCOPO QUELLO DI, IN BASE A DUE DATE SCELTE DALL'UTENTE, VISUALIZZARE LE VENDITE DI UN PRODOTTO, SCELTO TRAMITE CODICE IDENTIFICATIVO, IN 10 GIORNI.
//UTILIZZA COME INPUT:
//-mesi[] = ARRAY CHE INDICA IL PRIMO GIORNO DI OGNI MESE DELL'ANNO CONTANDO I GIORNI DA 0 A 364
//-ProdottiRimanenti[] = STRUCT DEI PRODOTTI RIMANENTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-ProdottiVenduti[] = STRUCT DEI PRODOTTI VENDUTI (PER PRODOTTO) ALLA FINE DI OGNI GIORNO
//-prodotto[] = STRUCT DEI PRODOTTI
//I 4 INPUT A LORO VOLTA SONO INPUT DELLE FUNCTION "MENU" E "SCELTE"
void prodotti_venduti_10gg(int mesi2[], ProdottiRimanenti ProdottiRimanenti[], ProdottiVenduti ProdottiVenduti[], Prodotti prodotto[])
{
    int i, g, j, giorno, mese, giorno2, mese2, codice, venduti = 0, comando = 0, command = 0;
    
    printf("---------------------------------------------------------\n");
    printf("               Prodotti Venduti in 10gg\n");
    for (i = 0; i < 20; i++) {
        printf("Prodotto %d: %s Codice: %d\n", i+1, prodotto[i].nome, prodotto[i].codice);
    }
    printf("Digitare Codice Prodotto: \n");
    scanf("%d",&codice);
    printf("Digitare Data (Massimo 10gg)\n");
    printf("Digitare Giorno Data Inizio (es. 20): ");
    scanf("%d", &giorno);
    printf("Digitare Mese Data Inizio (es. 3): ");
    scanf("%d", &mese);
    printf("Digitare Giorno Data Fine (es. 20): ");
    scanf("%d", &giorno2);
    printf("Digitare Mese Data Fine (es. 3): ");
    scanf("%d", &mese2);
    for (i = 0; i<20; i++) {
        if (codice == prodotto[i].codice) {
                for (g = mese; g == mese; g++) {
                    for (j = 0; j < 10; j++) {
                    venduti = venduti + ProdottiVenduti[i].venduti[giorno + mesi2[g-1] + j];
                    }
                }
                printf("\n%s: Venduti %d Prodotti\n", prodotto[i].nome, venduti);
        }
    }
    printf("---------------------------------------------------------\n");
    
    command = menu(comando);
    scelte(command, mesi2, ProdottiRimanenti, ProdottiVenduti, prodotto);
}

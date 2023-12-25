
//IL PROGRAMMA è UNA SIMULAZIONE DI UNA CORSA TRA 3 BICICLETTE. LA PARTICOLARITà DI QUESTO PROGRAMMA è CHE LE BICI VANNO AVANTI A TURNO, SPOSTANDOSI PER UN MASSIMO DI 3 POSIZIONI (DA 1 A 3) E GUADAGNANDO 10 SECONDI A SPOSTAMENTO, NEL PERCOSRSO RITROVIAMO ANCHE 4 SALITE E 4 DISCESE, CHE RISPETTIVAMENTE, COMPORTANO IL GUADAGNO DI PIù TEMPO E MENO TEMPO IN BASE ALLA POSIZIONE IN CUI LA BICI SI MUOVE SULLA SALITA O SULLA DISCESA.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

//STRUCT DELLE BICI FORMATO DA 4 CARATTERISTICHE: NOME, POSIZIONE, TEMPO E GIRI
typedef struct biciclette {
    char *nome;
    int posizioni;
    int tempo;
    int giri;
} corridori;

int main(){
    int posizione = 0, posizioneSD = 0;
    int salita[4] = {9,33,57,91};
    int discesa[4] ={21,43,72,101};
    int salita0[4] = {12,36,60,94};
    int discesa0[4] ={24,46,75,104};
    int TempoVincitore;

    int i=0; //=posizione delle bici;
    int j=0; //=cambio a turno delle bici;
    int g=0; //contatore posizione while interni;
    int h=0; //contatore salite e discese;
    
    corridori bici[3];
    srand(time(NULL));
    
    bici[0].tempo=0;
    bici[0].posizioni=0;
    bici[0].nome="BICI1";
    bici[0].giri=0;

    bici[1].tempo=0;
    bici[1].posizioni=0;
    bici[1].nome="BICI2";
    bici[1].giri=0;
    
    bici[2].tempo=0;
    bici[2].posizioni=0;
    bici[2].nome="BICI3";
    bici[2].giri=0;

    char verticale3= '|';
    char orizzontale= '_';
    
    
    //DISEGNO 1 DEL PERCORSO
    printf("%22c_____\n", orizzontale);
    printf("%21c %6c\n", verticale3, verticale3);
    printf("%21c %6c\n", verticale3, verticale3);
    printf("%21c %6c\n", verticale3, verticale3);
    printf("%21c %6c\n", verticale3, verticale3);
    printf("%21c %6c\n", verticale3, verticale3);
    printf("%9c___________| %6c____",orizzontale, verticale3);
    printf("\n%8c%25c\n%8c%25c______\n", verticale3, verticale3, verticale3, verticale3);
    printf("%8c%32c\n", verticale3, verticale3);
    printf(" ______|%32c\n", verticale3);
    printf("|%39c\n", verticale3);
    printf("|%33c_____|\n", orizzontale);
    printf("|______%26c\n", verticale3);
    printf("%8c%25c\n", verticale3, verticale3);
    printf("%8c%25c\n", verticale3, verticale3);
    printf("%8c%25c\n", verticale3, verticale3);
    printf("%8c__________%12c__%c\n", verticale3, orizzontale, verticale3);
    printf("%19c%10c\n", verticale3, verticale3);
    printf("%19c%10c\n", verticale3, verticale3);
    printf("%19c%10c\n", verticale3, verticale3);
    printf("%19c%10c\n", verticale3, verticale3);
    printf("%19c%10c\n", verticale3, verticale3);
    printf("%19c_________%1c\n\n", verticale3, verticale3);

 
    //DISEGNO 2 DEL PERCORSO
    printf("%14c_____ %8c___ %10c________ %16c__\n", orizzontale, orizzontale, orizzontale, orizzontale);
    printf("%13c %6c %6c %4c %8c %9c %14c %3c\n", verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3);
    printf("%13c %6c %6c %4c %8c %9c %14c %3c\n", verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3);
    printf("%13c %6c %6c %4c %8c %9c %14c %3c\n", verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3);
    printf("%13c %6c %6c %4c %8c %9c %14c %3c\n", verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3);
    printf("%13c %6c %6c %4c %8c %9c %14c %3c\n", verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3, verticale3);
    printf("____________| %6c______| %4c________| %9c______________| %3c____\n\n", verticale3, verticale3, verticale3, verticale3);


 
 //PRIMO BLOCCO DI ISTRUZIONI CHE PERMETTE IL MOVIMENTO, A TURNO, DELLE BICI PER UN MASSIMO DI 3 POSIZIONI, GRAZIE AD UN GENERATORE DI NUMERI PSEUDO-CASUALI, ANDANDO ANCHE AD AUMENTARE I GIRI DELLE SINGOLE BICI ED EVITARE DI AUMENTARE IL CONTATORE POSIZIONE, DELLA SINGOLA BICI, QUANDO UNA BICI FINISCE DI COMPIERE I 20 GIRI E LE ALTRE CONTINUANO
    do {
            for (h=0; h<4; h++) {
                for (j=0; j<3; j++) {
                    posizione = 1 + rand()%3;
                    for (i=posizione;i<=posizione; i++) {
                        if (!(bici[j].posizioni + i >= 115 && bici[j].giri == 19)){
                        bici[j].tempo = bici[j].tempo + 10;
                        bici[j].posizioni = bici[j].posizioni + i;
                        }
                        else { bici[j].posizioni = 114; }
                        
                        if (bici[j].posizioni>=115) {
                            bici[j].giri++;
                            
                            bici[j].posizioni = bici[j].posizioni - 115;
                        }
                        printf("%s Posizioni:%d\n", bici[j].nome, bici[j].posizioni);
                        printf("%s Tempo:%d\n", bici[j].nome, bici[j].tempo);
                        printf("%s Giri:%d\n", bici[j].nome, bici[j].giri);
 
 
//SECONDO BLOCCO DI ISTRUZIONI SI ATTIVA QUANDO LA SINGOLA BICI è IN PROSSIMITà DI UNA SALITA CHE, A DIFFERENZA DEL PRIMO BLOCCO DI ISTRUZIONI, IN BASE AL POSIZIONAMENTO SULLA SALITA, IL TEMPO AUMENTA DI 10 SECONDI + UNA DETERMINATA QUANTITà DI SECONDI
 
                        while (bici[j].posizioni > salita[h] && bici[j].posizioni < salita[h]+10){
                            posizioneSD = 1 + rand()%3;
                            
                            for (g=posizioneSD; g<=posizioneSD; g++) {
                                printf("i:%d\n", g);
                        
                                bici[j].posizioni = bici[j].posizioni + g;
                                printf("Salita%d %s Posizione:%d\n", h+1, bici[j].nome, bici[j].posizioni);
                        
                                if (bici[j].posizioni >= salita[h]+10) {
                                    bici[j].tempo = bici[j].tempo + 10;
                                    printf("Salita%d %s Tempo:%d\n", h+1, bici[j].nome, bici[j].tempo);
                                    
                                }
                                else {bici[j].tempo = bici[j].tempo + ( 10 + (bici[j].posizioni - salita0[h]));
                                    printf("Salita%d %s Tempo:%d\n", h+1, bici[j].nome, bici[j].tempo);
                                    
                                }
                            }
                
                        }
                        
 
 //TERZO BLOCCO DI ISTRUZIONI SI ATTIVA QUANDO LA SINGOLA BICI è IN PROSSIMITà DI UNA DISCESA CHE, A DIFFERENZA DEL SECONDO BLOCCO DI ISTRUZIONI, IN BASE AL POSIZIONAMENTO SULLA DISCESA, IL TEMPO AUMENTA DI 10 SECONDI - UNA DETERMINATA QUANTITà DI SECONDI
 
                        while (bici[j].posizioni>discesa[h] && bici[j].posizioni<discesa[h]+10){
                            posizioneSD = 1 + rand()%3;
                            for (g=posizioneSD; g<=posizioneSD; g++) {
                                printf("i:%d\n", g);
                        
                                bici[j].posizioni = bici[j].posizioni + g;
                                printf("Discesa%d %s Posizioni:%d\n", h+1, bici[j].nome, bici[j].posizioni);
                        
                                if (bici[j].posizioni >= discesa[h]+10)
                                {
                                    bici[j].tempo = bici[j].tempo + 10;
                                    printf("Discesa%d %s Tempo:%d\n", h+1, bici[j].nome, bici[j].tempo);
                                    
                                }
                                else {bici[j].tempo = bici[j].tempo + ( 10 - (bici[j].posizioni - discesa0[h]));
                                    printf("Discesa%d %s Tempo:%d\n", h+1, bici[j].nome, bici[j].tempo);
                                }
                                
                            }
                            
                        }
                        
                    }
                }
                
            }
            
    } while ((bici[0].giri != 19 || bici[0].posizioni != 114) || (bici[1].giri != 19 || bici[1].posizioni != 114) || (bici[2].giri != 19 || bici[2].posizioni != 114));
    
 
 
 //BLOCCO ISTRUZIONI CHE VA A VISUALIZZARE IL VINCITORE TRA LE 3 BICI
 
    printf("GiriB1 = %d \n", bici[0].giri);
    printf("GiriB2 = %d \n", bici[1].giri);
    printf("GiriB3 = %d \n", bici[2].giri);
    
    if (bici[0].tempo < bici[1].tempo && bici[0].tempo < bici[2].tempo) {
        TempoVincitore = bici[0].tempo;
        printf("\nVincitore: %s\nTempo Vincitore: %d\n", bici[0].nome, TempoVincitore);
    }
    
    if (bici[1].tempo < bici[0].tempo && bici[1].tempo < bici[2].tempo) {
        TempoVincitore = bici[1].tempo;
        printf("\nVincitore: %s\nTempo Vincitore: %d\n", bici[1].nome, TempoVincitore);
    }
    
    if (bici[2].tempo < bici[1].tempo && bici[2].tempo < bici[0].tempo) {
        TempoVincitore = bici[2].tempo;
        printf("\nVincitore: %s\nTempo Vincitore: %d\n", bici[2].nome, TempoVincitore);
    }
    
    return 0;
}

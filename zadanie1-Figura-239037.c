#include <stdio.h>

int main() {
    // indeks do wypelniania sciezki przejsc
    int i = 0;
    int coin;
    //Zmienna reprezentująca aktualny stan
    int actualState = 0;
    //Tablica przejśc automatu gdzie pierwszy indeks to numer stanu, a drugi to przejscie do koljenego stanu
    // w zależności o nominale wrzuconej monety
    // gdzie wartość pod indeksem 0 to wrzucenie monety o nominale 1
    // gdzie wartość pod indeksem 1 to wrzucenie monety o nominale 2
    // gdzie wartość pod indeksem 2 to wrzucenie monety o nominale 5
    int stateTable[14][3]={
            {1, 2, 3},
            {2, 7, 6},
            {7, 9, 4},
            {6, 4, 10},
            {8, 5, 12},
            {5, 5, 5},
            {4, 8, 11},
            {9, 3, 8},
            {5, 10, 13},
            {3, 6, 5},
            {10, 10, 10},
            {11, 11, 11},
            {12, 12, 12},
            {13, 13, 13}
    };


    // sciezka jaka pokonal automat
    int statePath[14];
    // zmienna do obsługi programu
    int endOfProgram = 0;
    // wypelnienie sciezki pierwszym stanem q0
    statePath[i] = 0;

    printf( "\n Aktualny stan to q%d", actualState);
    //glówna pętla programu
    while(endOfProgram == 0) {
        //Mechanizm wrzucania monet do automatu
        printf( "\n Wrzuc monete o nominale 1, 2 lub 5 jako liczbe:");
        scanf("%d", &coin);
        if(coin == 1 || coin == 2 || coin == 5) {
            //inkrementacja indeksu do ściezki przejść
            i = i + 1;
            // w zależność od nominału wrzuconej monety sprawdź w tablicy przejśc do jakiego stanu przejść
            // przejdź do tego stanu
            // następnie dodaj ten stan do scieżki jaką pokonał automat
            switch (coin) {
                case 1:
                    actualState = stateTable[actualState][0];
                    statePath[i] = actualState;
                    break;
                case 2:
                    actualState = stateTable[actualState][1];
                    statePath[i] = actualState;
                    break;
                case 5:
                    actualState = stateTable[actualState][2];
                    statePath[i] = actualState;
                    break;
            }
            // Pokazanie jaką monetę wrzucono i jaki jest aktualny stan
            printf( "\n Wrzuciles: %d, aktualny stan to q%d", coin, actualState);
            // Sprawdzenie czy autmoat znajduje się w stanie akceptującym
            if(actualState == 5 || actualState == 10 || actualState == 11 || actualState == 12 || actualState == 13) {
                // jeśli tak automat sprawdza w jakim stanie akceptującym się znajduje
                // w zależność od stanu akceptującego w jakim automat się znajduje wydaje bilet i resztę
                // następnie wypisuje scieżke jaką pokonał automat
                int n;
                switch (actualState) {
                    case 5:
                        printf( "\n Wydano bilet, a reszta rowna jest %d", 0);
                        printf( "\n Stan koncowy to q%d", actualState);
                        printf( "\n Sciezka jaka pokonal");
                        printf( "\n");
                        for(n = 0; n<=i; n++) {
                            printf( "q%d ", statePath[n]);
                            if (n!=i){
                                printf( "-> ");
                            }
                        }
                        printf( "\n");
                        endOfProgram = 1;
                        break;
                    case 10:
                        printf( "\n Wydano bilet, a reszta rowna jest %d", 1);
                        printf( "\n Stan koncowy to q%d", actualState);
                        printf( "\n Sciezka jaka pokonal");
                        printf( "\n");
                        for(n = 0; n<=i; n++) {
                            printf( "q%d ", statePath[n]);
                            if (n!=i){
                                printf( "-> ");
                            }
                        }
                        printf( "\n");
                        endOfProgram = 1;
                        break;
                    case 11:
                        printf( "\n Wydano bilet, a reszta rowna jest %d", 2);
                        printf( "\n Stan koncowy to q%d", actualState);
                        printf( "\n Sciezka jaka pokonal");
                        printf( "\n");
                        for(n = 0; n<=i; n++) {
                            printf( "q%d ", statePath[n]);
                            if (n!=i){
                                printf( "-> ");
                            }
                        }
                        printf( "\n");
                        endOfProgram = 1;
                        break;
                    case 12:
                        printf( "\n Wydano bilet, a reszta rowna jest %d", 3);
                        printf( "\n Stan koncowy to q%d", actualState);
                        printf( "\n Sciezka jaka pokonal");
                        printf( "\n");
                        for(n = 0; n<=i; n++) {
                            printf( "q%d ", statePath[n]);
                            if (n!=i){
                                printf( "-> ");
                            }
                        }
                        printf( "\n");
                        endOfProgram = 1;
                        break;
                    case 13:
                        printf( "\n Wydano bilet, a reszta rowna jest %d", 4);
                        printf( "\n Stan koncowy to q%d", actualState);
                        printf( "\n Sciezka jaka pokonal");
                        printf( "\n");
                        for(n = 0; n<=i; n++) {
                            printf( "q%d ", statePath[n]);
                            if (n!=i){
                                printf( "-> ");
                            }
                        }
                        printf( "\n");
                        endOfProgram = 1;
                        break;
                }
            }
        }

    }

    return 0;
}

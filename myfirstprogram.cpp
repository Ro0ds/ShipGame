#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    int shipCount = 0;
    
    //Create an empty table of ships
    int ships[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    //Generate random number from 0 to 1 to fill the table with five ships
 

    //start the logic to insert random chips in the table
    for(int linha = 0; linha < sizeof(ships); linha++){
        for (int coluna = 0; coluna < sizeof(ships); coluna++){
            int rng = rand() % 2;

            if(rng == 0 || rng < 0){
                continue;
            }
            else{
                if(ships[linha][coluna] == 1){
                continue;
            }
                else if(ships[linha][coluna] == 0){
                    if(shipCount <= 4){
                        ships[linha][coluna] = rng;
                        shipCount++;
                    }
                }
            }
        }
    }

    //Start the logic of the game
    string input;
    int hits = 0;
    int numberOfTurns = 0;

    while (hits <= 4){
        int linha, coluna;

        cout << "Seleciona as coordenadas\n";
        cout << "Escolha uma linha de 0 a 3: ";
        cin >> linha;

        cout << "Escolha uma coluna de 0 a 3: ";
        cin >> coluna;

        if(ships[linha][coluna]){
            ships[linha][coluna] = 0;
            hits++;

            cout << "Hit! " << (5-hits) << " left.\n\n";
        }
        else{
            cout << "Missed\n\n";
        }

        numberOfTurns++;
    }

    cout << "Victory!\n";
    cout << "You won in " << numberOfTurns << " turns!";
   
    return 0;
}
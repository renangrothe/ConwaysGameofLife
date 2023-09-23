/*#######################################################
This program provides a simple implementation of Conway's
Game of Life, displayed in the terminal.
#######################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 200

typedef struct ttable {
    int matrix[RANGE+2][RANGE+2];
    int t;
} table;

void random (int mtx[RANGE + 2][RANGE + 2]);

void init (int mtx[RANGE+2][RANGE+2]);

void copymtx (int mtx[RANGE+2][RANGE+2], int newmtx[RANGE+2][RANGE+2]);

void computegame (int mtx[RANGE+2][RANGE+2]);

void print (int mtx[RANGE+2][RANGE+2]);

int main () {

    table game;
    int action;

    init(game.matrix);
    game.t = 0;

    while (game.t >= 0) {
        
        print(game.matrix);
        printf("Enter a number greater than 0 to advance time by one step, or less than or equal to 0 to exit.\n");
        scanf("%d", &action);
        
        if(action > 0) 
            game.t++;
        else {
            printf("The program advanced %d steps.\n", game.t);
            game.t = -1;
        }
        computegame(game.matrix);

    }


    return(0);
}

void fillrandom (int mtx[RANGE + 2][RANGE + 2]) {

    time_t t;

    srand((unsigned) time(&t));

    for(int i = 1 ; i < RANGE + 1 ; i++){
        for(int j = 1 ; j < RANGE + 1 ; j++){
            mtx[i][j] = rand() % 2;
        }
    }

    return;
}

void init (int mtx[RANGE+2][RANGE+2]) {
    
    for(int i = 0 ; i < RANGE+2 ; i++)
        for(int j = 0 ; j < RANGE+2 ; j++)
            if(mtx[i][j] > 45000)
                mtx[i][j] = 1;
            else   
                mtx[i][j] = 0;
    for(int i = 0 ; i < RANGE + 2 ; i++) {
        mtx[0][i] = 0;
        mtx[i][0] = 0;
        mtx[RANGE + 1][i] = 0;
        mtx[i][RANGE + 1] = 0;
    }

    fillrandom(mtx);
    
    return;
}

void copymtx (int mtx[RANGE+2][RANGE+2], int newmtx[RANGE+2][RANGE+2]){

    for(int i = 1 ; i < RANGE + 1 ; i++){
        for(int j = 1 ; j < RANGE + 1 ; j++){
            mtx[i][j] = newmtx[i][j];
        }
    }

    return;
}

void computegame (int mtx[RANGE+2][RANGE+2]) {

    int newmtx[RANGE+2][RANGE+2];
    int neighbours = 0;

    for(int i = 1 ; i < RANGE + 1 ; i++){ 
        for(int j = 1 ; j < RANGE + 1 ; j++){
            
            for(int k = -1 ; k <= 1 ; k++){
                for(int l = -1 ; l <= 1 ; l++){
                    if (k == 0 && l == 0) 
                        continue; 
                    neighbours += mtx[i+k][j+l];
                }
            }

            if(mtx[i][j] == 1){
                if(neighbours < 2 || neighbours > 3)
                    newmtx[i][j] = 0;
                else
                    newmtx[i][j] = 1;
            }
            else if(mtx[i][j] == 0){
                if(neighbours == 3)
                    newmtx[i][j] = 1;
                else
                    newmtx[i][j] = 0;
            }
            neighbours = 0;
        }

    }

    copymtx(mtx, newmtx);

    return;
}

void print (int mtx[RANGE+2][RANGE+2]) {

    for(int i = 1 ; i < RANGE + 1 ; i++){
        for(int j = 1 ; j < RANGE + 1 ; j++){
            if(mtx[i][j])
                printf("@");
            else
                printf(" ");
        }
        printf("\n");   
    }

    return;
}

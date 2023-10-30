#include <stdio.h>
#include <stdlib.h>
#define N 512 // Definim la constant N igual a 512

float Mat[N][N];
float MatDD[N][N];
float V1[N], V2[N], V3[N];

void InitData(){
    int i, j;
    srand(4422543);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));

            if ((abs(i - j) <= 3) && (i != j)) {
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (rand() / (1.0 * RAND_MAX));
            } else if (i == j) {
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (10000.0 * (rand() / (1.0 * RAND_MAX)));
            } else {
                MatDD[i][j] = 0.0;
            }
        }
    }

    for (i = 0; i < N; i++) {
        V1[i] = (i < N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V2[i] = (i >= N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V3[i] = (((i * j) % 5) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
    }
}

void PrintVect(float vect[N], int from, int numel) {
    if (from < 0 || from >= N || numel <= 0 || from + numel > N) {
        printf("Error: Índex fora dels límits del vector.\n");
        return;
    }

    printf("Vector elements from position %d to %d:\n", from, from + numel - 1);
    for (int i = from; i < from + numel; i++) {
        printf("%.2f ", vect[i]);
    }
    printf("\n");
}

void PrintRow(float Mat[N][N], int row, int from, int numel) {
    if (row < 0 || row >= N || from < 0 || from >= N || numel <= 0 || from + numel > N) {
        printf("Paràmetres incorrectes\n");
        return;
    }

    for (int i = from; i < from + numel; i++) {
        printf("%.2f ", Mat[row][i]);
    }

    printf("\n");
}

void MultEscalar(float vect[N], float vectres[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vectres[i] = alfa * vect[i];
    }
}

int main() {
    InitData(); // Inicialitzem les dades, com s'ha proporcionat en la pregunta

    // Exemple d'ús de la funció PrintVect
    PrintVect(V1, 0, 10); // Mostra 20 elements del vector V1, començant des de la posició 10
    PrintVect(V1, 256, 10);
 
    printf("Des de 0 a 9 de la fila 0\n");
    PrintRow(Mat,0,0,10);
    printf("Des de 0 a 9 de la fila 100\n");
    PrintRow(Mat,100,0,10);   
	
    float ResultVector[N];
    float Scalar = 2.0;
    MultEscalar(V1, ResultVector, Scalar);
    printf("Resultado de la multiplicación escalar:\n");
    PrintVect(ResultVector, 0, 10);
    PrintVect(ResultVector, 90, 10);

    printf("Elementos 0 al 9 de la fila 0 de MatDD:\n");
    PrintRow(MatDD, 0, 0, 10);
    printf("Elementos 90 a 99 de la fila 100 de MatDD:\n");
    PrintRow(MatDD, 100, 90, 10);

    return 0;
}


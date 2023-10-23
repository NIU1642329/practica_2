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

// Funció per mostrar un vector a partir d'una posició donada
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

int main() {
    float V1[N]; // Declaració del vector V1
    InitData(); // Inicialitzem les dades, com s'ha proporcionat en la pregunta

    // Exemple d'ús de la funció PrintVect
    PrintVect(V1, 0, 10); // Mostra 20 elements del vector V1, començant des de la posició 10
    PrintVect(V1, 256, 10);
    return 0;
}


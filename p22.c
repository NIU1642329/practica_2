#include <stdio.h>
#include <stdlib.h>
#define N 512 // Definim la constant N igual a 512

float Mat[N][N]; // Declaración de la matriz Mat
float MatDD[N][N]; // Declaración de la matriz MatDD
float V1[N], V2[N], V3[N];

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
    PrintVect(V1, 10, 20); // Mostra 20 elements del vector V1, començant des de la posició 10

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512 // Definim la constant N igual a 512

float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];

void InitData(){
	int i,j;
	srand(4422543);
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ ){
			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			if ( (abs(i - j) <= 3) && (i != j))
				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			else if ( i == j )
				MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			else MatDD[i][j] = 0.0;
		}
	for( i = 0; i < N; i++ ){
		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}
void PrintVect(float vect[N], int from, int numel) {
    /*if (from < 0 || from >= N || numel <= 0 || from + numel > N) {
        printf("Error: Índex fora dels límits del vector.\n");
        return;
    }*/

    printf("Vector elements from position %d to %d:\n", from, from + numel - 1);
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);
    }
    printf("\n");
}

void PrintRow(float Mat[N][N], int row, int from, int numel) {
    /*if (row < 0 || row >= N || from < 0 || from >= N || numel <= 0 || from + numel > N) {
        printf("Paràmetres incorrectes\n");
        return;
    }*/
    for (int i = from; i < from + numel; i++) {
        printf("%f ", Mat[row][i]);
    }
    printf("\n");
}

void MultEscalar(float vect[N], float vectres[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vectres[i] = alfa * vect[i];
    }
}

float Scalar(float vect1[N], float vect2[N]) {
    float prod_esc = 0.0;

    for (int i = 0; i < N; i++) {
        prod_esc += vect1[i] * vect2[i];
    }

    return prod_esc;
}

float Magnitude(float vect[N]) {
    float sum = 0.0;

    for (int i = 0; i < N; i++) {
        sum += vect[i] * vect[i];
    }

    return sqrt(sum);
}

int Ortogonal( float vect1[N], float vect2[N] ) {
	int ortogonal = 0;
	
	float prod_esc = Scalar(vect1, vect2);
	
	if (prod_esc == 0.0) {
		ortogonal = 1;
	}
	return ortogonal;
}
float NormFrobenius( float M[N][N] ) {
	float sum = 0.0;
	
	for (int i = 0; i < N; i++) {
        	for (int j = 0; j < N; j++) {
            		sum += M[i][j] * M[i][j];
        	}
    	}

    return sqrt(sum);
}
int main() {
    InitData(); // Inicialitzem les dades, com s'ha proporcionat en la pregunta

    PrintVect(V1, 0, 10); // Mostra 10 elements del vector V1, començant des de la posició 0
    PrintVect(V1, 256, 10);
 
    printf("Des de 0 a 9 de la fila 0\n");
    PrintRow(Mat,0,0,10);
    printf("Des de 0 a 9 de la fila 100\n");
    PrintRow(Mat,100,0,10);   
	
    float ResultVector[N];
    float Scalart = 2.0;
    MultEscalar(V1, ResultVector, Scalart);
    printf("Resultado de la multiplicación escalar:\n");
    PrintVect(ResultVector, 0, 10);
    PrintVect(ResultVector, 90, 10);
   
    float V1Scaled[N];
    float alpha = 2.0;
    MultEscalar(V1, V1Scaled, alpha);
    printf("Vector V1Scaled (resultado de la multiplicación escalar):\n");
    PrintVect(V1Scaled, 0, 10);
    float dotProduct = Scalar(V1, V1Scaled);
    printf("Producto escalar entre V1 y V1Scaled: %f\n", dotProduct);

    return 0;
}


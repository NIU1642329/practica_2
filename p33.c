#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512 // Definim la constant N igual a 512
float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];
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

//1
void PrintVect(float vect[N], int from, int numel) {
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);
    }
    printf("\n");
}

//2
void PrintRow(float Mat[N][N], int row, int from, int numel) {
    for (int i = from; i < from + numel; i++) {
        printf("%f ", Mat[row][i]);
    }
    printf("\n");
}

//3
void MultEscalar(float vect[N], float vectres[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vectres[i] = alfa * vect[i];
    }
}

//4
float Scalar(float vect1[N], float vect2[N]) {
    float prod_esc = 0.0;

    for (int i = 0; i < N; i++) {
        prod_esc += vect1[i] * vect2[i];
    }
    return prod_esc;
}

//5
float Magnitude(float vect[N]) {
        return sqrt(Scalar(vect,vect));
}

//6
int Ortogonal( float vect1[N], float vect2[N] ) {
        int ortogonal = 0;
        float prod_esc = Scalar(vect1, vect2);
        if (prod_esc == 0.0) {
                ortogonal = 1;
        }
        return ortogonal;
}

//7
void Projection(float vect1[N], float vect2[N], float vectres[N]) {
        float prod_esc = Scalar(vect1, vect2);
        float magnitud = Magnitude(vect2);
        float terme = prod_esc / magnitud;
        MultEscalar(vect2, vectres, terme);
}

//8
float Infininorm(float M[N][N]) {
    float maxsum = 0.0;
    for (int i = 0; i < N; i++) {
        float sum = 0.0;
        for (int j = 0; j < N; j++) {
            sum += fabs(M[i][j]);
        }
        if (sum > maxsum) {
            maxsum = sum;
        }
    }
    return maxsum;
}

//9
float Onenorm(float M[N][N]) {
    float maxsum = 0.0;
    for (int j = 0; j < N; j++) {
        float sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += fabs(M[i][j]);
        }
        if (sum > maxsum) {
            maxsum = sum;
        }
    }
    return maxsum;
}

//10
float NormFrobenius( float M[N][N] ) {
        float sum = 0.0;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        sum += M[i][j] * M[i][j];
                }
        }
    return sqrt(sum);
}

//11
int DiagonalDom(float M[N][N]) {
    for (int i = 0; i < N; i++) {
        float diagonal = fabs(M[i][i]);
        float sum = 0.0;

        for (int j = 0; j < N; j++) {
            if (j != i) {
                sum += fabs(M[i][j]);
            }
        }

        if (diagonal < sum ) {
            return 0;
        }
    }

    return 1;
}

//12

int Jacobi(float M[N][N], float vect[N], float vectres[N], unsigned iter) {
        int diagonaldominant = DiagonalDom(M);

        if (diagonaldominant == 0) {
        return 0;
        }

        for (int k = 0; k < iter; k++) {
                for (int i = 0; i < N; i++) {
                        float sum = 0.0;
		
	                for (int j = 0; j < N; j++) {
        	                if (i != j) {
                	                sum += M[i][j] * vect[j];
                       		 }
                	}
		vectres[i] = (vect[i] - sum) / M[i][i];
	}
        // Actualiza el vector vect
        for (int i = 0; i < N; i++) {
            vect[i] = vectres[i];
        }
	}
    return 1;
}


// funció principal
int main() {
        //A
        InitData();
        printf("V1 del 0 al 9 i del 256 al 265:\n");
        PrintVect(V1, 0, 10);
        PrintVect(V1, 256, 10);
        printf("\nV2 del 0 al 9 i del 256 al 265: \n");
        PrintVect(V2, 0, 10);
        PrintVect(V2, 256, 10);
        printf("\nV3 del 0 al 9 i del 256 al 265: \n");
        PrintVect(V3, 0, 10);
        PrintVect(V3, 256, 10);

        //B
        printf("\n\n\nMat fila 0 i fila 100 del 0 al 9:\n");
        PrintRow(Mat,0,0,10);
        PrintRow(Mat,100,0,10);

        //C
        printf("\n\n\nMatDD fila 0 del 0 al 9 i fila 100 del 95 al 104\n");
        PrintRow(MatDD,0,0,10);
        PrintRow(MatDD,100,95,10);

        //D Mat
        //a infininorma?
        printf("\n\n\nInfininorma de Mat = %f\n", Infininorm(Mat));
        //b norma ú?
        printf("Norma ú de Mat = %f\n", Onenorm(Mat));
        //c norma de Forbenius?
        printf("Norma de Forbenius de Mat = %f\n", NormFrobenius(Mat));
        //d diagonal dominant?
        if (DiagonalDom(Mat) == 0) {
                printf("La matriu de Mat no és diagonal dominant\n");
        } else {
                printf("La matriu de Mat és diagonal dominant\n");
        }
        //D MatDD
        //a infininorma?
        printf("\n\n\nInfininorma de MatDD = %f\n", Infininorm(MatDD));
        //b norma ú?
        printf("Norma ú de MatDD = %f\n", Onenorm(MatDD));
        //c norma de Forbenius?
        printf("Norma de Forbenius de MatDD = %f\n", NormFrobenius(MatDD));
        //d diagonal dominant?
        if (DiagonalDom(MatDD) == 0) {
                printf("La matriu de MatDD no és diagonal dominant\n");
        } else {
                printf("La matriu de MatDD és diagonal dominant\n");
        }

        //E
        printf("\n\nEscalar <V1,V2> = %f \nEscalar <V1,V3> = %f \nEscalar <V2,V3> = %f", Scalar(V1,V2),Scalar(V1,V3),Scalar(V2,V3));
        //F
        printf("\n\n\nMagnitud V1 = %f \nMagnitud V2 = %f \nMagnitud V3 = %f\n\n\n",Magnitude(V1),Magnitude(V2),Magnitude(V3));
        //G
        if (Ortogonal(V1, V2) == 1) {
                printf("V1 i V2 són ortogonals\n");
        } else {
                printf("V1 i V2 no són ortogonals\n");
        }
        if (Ortogonal(V1, V3) == 1) {
                printf("V1 i V3 són ortogonals\n");
        } else {
                printf("V1 i V3 no són ortogonals\n");
        }
        if (Ortogonal(V2, V3) == 1) {
                printf("V2 i V3 són ortogonals\n");
        } else {
                printf("V2 i V3 no són ortogonals\n");
        }
	//H
        printf("\n\nEls elements del 0 al 9 del resultat de multiplicar V3x2.0 són:\n");
        MultEscalar(V3,V4,0.2);
        PrintVect(V4, 0, 10);
        printf("\nEls elements del 256 al 265 del resultat de multiplicar V3x2.0 són:\n");
        PrintVect(V4, 256, 10);
        
	//I
        printf("\n\n\nEls elements del 0 al 9 del resultat de la projecció de V2 sobre V3 són:\n");
        Projection(V2,V3,V4);
        PrintVect(V4,0,10);
        printf("\nEls elements del 0 al 9 del resultat de la projecció de V1 sobre V2 són:\n");
        Projection(V1,V2,V4);
        PrintVect(V4,0,10);

	//J
	//matriu MatDD 1 iteració
        int jacobi_1 = Jacobi(MatDD,V3,V4,1);
        if (jacobi_1 == 0){
                printf("\n\n\nLa matriu MatDD no és diagonal dominant, no es pot aplicar Jacobi\n");
        } else {
                printf("\n\n\nEls elements de 0 a 9 de la solució (1 iter) del sistma d'equacions MatDD*X = V3 són:\n");
                PrintVect(V4,0,10);
        }

	//matriu MatDD 1000 iteracions
        int jacobi_1000 = Jacobi(MatDD,V3,V4,1000);
        if (jacobi_1000 == 0){
                printf("\nLa matriu Mat no és diagonal dominant, no es pot aplicar Jacobi\n");
        } else {
                printf("\nEls elements de 0 a 9 de la solució (1000 iters) del sistma d'equacions Mat*X = V3 són:\n");
                PrintVect(V4,0,10);
        }
	
	//matriu Mat 1 iteració
        int jacobi_d_1 = Jacobi(Mat,V3,V4,1);
        if (jacobi_d_1 == 0){
                printf("\n\n\nLa matriu Mat no és diagonal dominant, no es pot aplicar Jacobi\n");
        } else {
                printf("\n\n\nEls elements de 0 a 9 de la solució (1 iter) del sistma d'equacions són:\n");
                PrintVect(V4,0,10);
        }
	//matriu Mat 1000 iteracions
        int jacobi_d_1000 = Jacobi(Mat,V3,V4,1000);
        if (jacobi_d_1000 == 0){
                printf("\nLa matriu Mat no és diagonal dominant, no es pot aplicar Jacobi\n");
        } else {
                printf("\nEls elements de 0 a 9 de la solució (1000 iters) del sistma d'equacions són:\n");
                PrintVect(V4,0,10);
        }

}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Variables globales
int pop[10][10]; //Almacena la poblacion generada de manera aleatoria.
int npop[10][10];
int tpop[10][10];
int x[10]; //Valores generados para x.
int fx[10]; //Valores obtenidos al evaluar la funcion en x.
int m_max = 1;
int ico = 0;
int ico1 = 0;
int it = 0;

void iteraciones(int [10][10], int, int);
void tour_sel(int, int);
void reproduccion(int, int);
void mutacion(int, int);

int main(){

	int k, m, nit, n;
	int p[10], a[10];

	srand(time(NULL));

	printf("%s\n", "Numero de la poblacion en cada iteracion:");
	scanf("%d", &n);
	printf("%s\n", "Numero de iteraciones:");
	scanf("%d", &nit);

	m = 5;

	int i, j;
	for(i=0; i<n; i++){
		for(j=m-1; j>=0; j--){
			pop[i][j] = rand()%31+1;
		}
	}

}

void iteraciones(int pp[10][10], int o, int p){
	//Pagina 299
}


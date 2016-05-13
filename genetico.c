#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Variables globales
int pop[10][10]; //Almacena la poblacion generada de manera aleatoria.
int npop[10][10]; //Almacena la poblacion generada a partir de la cruza de dos individuos.
int tpop[10][10]; //Almacena los individuos que han mutado.
int x[10]; //Valores generados para x.
int fx[10]; //Valores obtenidos al evaluar la funcion en x.
int m_max = 1;
int ico = 0;
int ico1 = 0;

void iteraciones(int [10][10], int, int);
void competir(int, int);
void reproduccion(int, int);
void mutacion(int, int);

int generaAleatorio(int num){

	return rand()%num;
}

int main(){

	int k, m, nit, n;

	srand(time(NULL));

	printf("%s\n", "Numero de la poblacion en cada iteracion:");
	scanf("%d", &n);
	printf("%s\n", "Numero de iteraciones:");
	scanf("%d", &nit);

	m = 5;

	int i, j;
	for(i=0; i<n; i++){
		for(j=m-1; j>=0; j--){
			pop[i][j] = generaAleatorio(2);
		}
	}


	printf("\nIteracion: %d \n", 0);
	iteraciones(pop, n, m);	

	for(k=1; k<nit; k++){
		printf("\nIteracion: %d \n", k);
		competir(n, m);
		iteraciones(pop, n, m);	
	}

	printf("\nDespues de la iteracion: %d el valor maximo is: %d \n", ico1, (int)sqrt(m_max));

	return 0;

}

void iteraciones(int pp[10][10], int population, int p){
	
	int max = 1;
	int i, j;

	for(i=0; i<population; i++){
		x[i] = 0;
		for(j=0; j<p; j++){
			x[i] = x[i] + (pp[i][j]*pow(2, p-1-j));
		}

		fx[i] = x[i]*x[i];
		if(max <= fx[i]){
			max = fx[i];
		}
	}

	printf("\n\n# \t Poblacion \t X \t F(X)\n\n");

	for(i=0; i<population; i++){
		printf("%d\t", ico);
		ico++;
		for(j=0; j<p; j++){
			printf("%d", pp[i][j]);
		}
		printf("\t\t %d \t %d \n", x[i], fx[i]);
	}
	printf("\nMaximo: %d \n", max);

	if(m_max < max){
		m_max = max;
		ico1++;
	}
}

void competir(int np, int mb){
	int co=0, cc;
	int i,j;
	int k,l;

	printf("%s\n", "Entrando a elegir al mejor");

	do{
		k = generaAleatorio(np);
		printf("Valor de k: %d\n", k);
		do{
			cc=0;
			l = generaAleatorio(np);
			if(l == 1){
				cc++;
			}
		}while(cc != 0);

		if(fx[k] > fx[l]){
			for(j=0; j<mb; j++){
				npop[co][j] = pop[k][j];
			}
		}else{
			if(fx[k] < fx[l]){
				for(j=0; j<mb; j++){
					npop[co][j] = pop[l][j];
				}
			}
		}
		co++;
	}while(co < np);

	reproduccion(np, mb);
	printf("%s\n", "Saliendo de elegir al mejor");
}

void reproduccion(int np1, int mb1){
	int i, j, k, l;
	int co, temp;

	i=0;

	printf("%s\n", "Entrando al metodo de reproduccion");

	do{
		k = rand() % 2;
		do{
			co = 0;
			l = generaAleatorio(mb1);
			if(((k == 0) && (l == 0)) || ((k == 1) && (l == mb1)))
				co++;
		}while(co != 0);

		if((k == 0) && (l != 0)){
			for(j=0; j<l; j++){
				temp = npop[i][j];
				npop[i][j] = npop[i+1][j];
				npop[i+1][j] = temp;
			}
		}else{
			if((k == 1) && (l != mb1)){
				for(j=l; j<mb1; j++){
					temp = npop[i][j];
					npop[i][j] = npop[i+1][j];
					npop[i+1][j] = temp;
				}
			}
		}
		i = i+2;
	}while(i < np1);

	for(i=0; i<np1; i++){
		for(j=0; j<mb1; j++){
			tpop[i][j] = npop[i][j];
		}
	}

	mutacion(np1, mb1);
}

void mutacion(int np2, int mb2){
	int i,j,r,k,z;
	int temp;

	i=0;

	do{
		for(k=0; k<np2; k++){
			r=0;
			if(i != k){
				for(j=0; j<mb2; j++){
					if(tpop[i][j] == tpop[k][j]){
						r++;
					}
				}
				if(r != (mb2 - 1)){

					z = generaAleatorio(mb2);

					if(tpop[i][z] == 0){
						tpop[i][z] = 1;
					}else{
						tpop[i][z] = 0;
					}

					if(npop[k][generaAleatorio(mb2)] == 0){
						npop[k][generaAleatorio(mb2)] = 1;
					}else{
						npop[k][generaAleatorio(mb2)] = 0;
					}
					mutacion(k, mb2);
				}
			}
		}
		i++;
	}while(i < np2);

	for(i=0; i<np2; i++){
		for(j=0; j<mb2; j++){
			pop[i][j] == tpop[i][j];
		}
	}
}



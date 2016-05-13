#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Programa en C que maximiza la funcion f(x) = x^2 haciendo uso de un algoritmo genetico. El rango de valores de x comprende entre
0 y 31. La representacion de cada individuo se genera a partir de cadenas de 5 bits de largo.*/

//Variables globales
int pop[10][10]; //Almacena la poblacion generada de manera aleatoria.
int npop[10][10]; //Almacena la poblacion generada a partir de la cruza de dos individuos.
int tpop[10][10]; //Almacena los individuos que han mutado.
int x[10]; //Valores generados para x.
int fx[10]; //Valores obtenidos al evaluar la funcion en x.
int m_max = 1;
int ico = 0; //Numero de iteracion
int ico1 = 0; //Numero de iteracion desde la cual se determino el valor maximo para la funcion.

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

	//Obtenemos el numero de individuos a generar y el numero de iteraciones por parte del usuario.
	/*
	 *El numero de individuos se refiere a la cantidad de elementos a ser evaluados en cada iteracion.
	 *
	 *El numero de iteraciones se refiere al numero de veces que sera aplicado el algorito genetico para llegar a una solucion
	 satisfactoria.
	 */
	printf("%s\n", "Numero de individuos para cada iteracion:");
	scanf("%d", &n);
	printf("%s\n", "Numero de iteraciones a realizar:");
	scanf("%d", &nit);

	m = 5;

	int i, j;

	//Se genera la poblacion inicial a partir de cadenas de 5 bits generadas de forma aleatoria.
	printf("%s\n", "Poblacion inicial: ");
	for(i=0; i<n; i++){
		for(j=m-1; j>=0; j--){
			pop[i][j] = generaAleatorio(2);
			printf("%d", pop[i][j]);
		}
		printf("\n");
	}

	//Se genera la primera iteracion con los primeros individuos generados.
	printf("\nIteracion: %d \n", 0);
	iteraciones(pop, n, m);	

	for(k=1; k<nit; k++){
		printf("\nIteracion: %d \n", k);
		competir(n, m);
		iteraciones(pop, n, m);	
	}

	//Muestra el resultado del valor maximo obtenido despues de haber ejecutado todas las iteraciones.
	printf("\nDespues de la iteracion: %d el valor maximo es: %d \n", ico1, (int)sqrt(m_max));

	return 0;

}

/*
 *El metodo iteraciones() recibe como parametros a la poblacion de individuos, al numero de individuos por iteracion y el numero de 
 *iteraciones a realizar. Ademas realiza la evaluacion en la funcion objetivo, en este caso f(x) = x^2. De esta manera, cada valor de x
 *generado sera evaluado en la funcion objetivo para asi determinar el valor maximo.
 */
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

/*
 * El metodo compertir() recibe como parametros el numero de individuos y el numero de iteraciones a realizar. Este metodo hace uso de
 * la "seleccion por torneo", es decir, pone a competir a los individuos de una poblacion generada para determinar a los mejores candidatos
 * que seran seleccionados para la reproduccion.
 *
 * Para seleccionar a los mejores candidatos se hace uso de la evaluacion del individuo "x" en la funcion objetivo. Se generan dos numeros
 * de forma aleatoria k y l, los cuales representan los indices dentro del arreglo fx (este contiene los resultados de evaluar x 
 * en la funcion objetivo). De esta manera se selecciona a los individuos de manera aleatoria.     
*/
void competir(int np, int mb){
	int co=0, cc;
	int i,j;
	int k,l;

	do{
		k = generaAleatorio(np);
		do{
			cc=0;
			l = generaAleatorio(np);
			if(l == 1){
				cc++;
			}
		}while(cc != 0);

		//Se comparan los valores obtenidos de forma aleatoria en fx para determinar a los mejores candidatos.
		//Los mejores candidatos para la reproduccion se almacenan dentro de la matriz npop. 
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
}

/*
 * El metodo reproduccion recibe como parametros el numero de individuos y el numero de iteraciones a realizar. 
 * Este metodo hace uso del operador "cross-over" o recombinacion el cual toma a dos individuos que se reproduciran para generar a un
 * nuevo individuo. Para esto:
 	--> Se selecciona a dos individuos de manera aleatoria, estos seran candidatos para la reproduccion.
 	--> Se obtiene un punto de corte de forma aleatoria, es decir, una posicion a lo largo de la cadena de bits.
 	--> Se realiza un intercambio de bits entre ambas cadenas de bits, para esto se reemplazan los mismos en el punto de corte.
*/

void reproduccion(int np1, int mb1){
	int i, j, k, l;
	int co, temp;

	i=0;

	do{
		k = rand() % 2;
		do{
			co = 0;
			l = generaAleatorio(mb1);
			if(((k == 0) && (l == 0)) || ((k == 1) && (l == mb1)))
				co++;
		}while(co != 0);

		//Se realiza el swap entre las dos cadenas de bits. La matriz npop contiene a los mejores mejores acandidatos para la reproduccion.
		//Se utiliza una variable temporal para almacenar el bit a ser intercambiado entre ambas cadenas de bits.
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

	//Se realiza una copia a la matriz tpop la cual almacenara los resultados de las cruzas entre individuos. 

	for(i=0; i<np1; i++){
		for(j=0; j<mb1; j++){
			tpop[i][j] = npop[i][j];
		}
	}

	mutacion(np1, mb1);
}

/*
 * El metodo mutacion() recibe como parametros el numero de individuos y el numero de iteraciones a realizar.
 *
 * El operador de mutacion consiste en invertir uno de los valores de la cadena de bits que representa a un individuo, es decir, se 
 * selecciona una posicion dentro de la cadena de bits del individuo y se checa el contenido de esa posicion. Si el valor es 0 se 
 * intercambia por un 1 y vice versa. 
*/
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

					//Se obtiene un valor de indice de manera aleatoria, de esta manera se obtiene una posicion dentro de la matriz
					//en la que se realizara la mutacion dentro del individio. 
					z = generaAleatorio(mb2);

					//Realizamos al mutacion, es decir el intercambio de bits para los individuos generados a partir de la reproduccion.
					if(tpop[i][z] == 0){
						tpop[i][z] = 1;
					}else{
						tpop[i][z] = 0;
					}

					//Realizamos la mutacion para los individuos seleccionados candidatos para la reproduccion. 
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

	//Tomamos a los individuos modificados a traves de la mutacion y los tratamos como nuestra nueva poblacion. De esta manera se repite
	//el proceso seguido por el algoritmo hasta terminar el numero de iteraciones especificadas por el usuario.
	for(i=0; i<np2; i++){
		for(j=0; j<mb2; j++){
			pop[i][j] = tpop[i][j];
			printf("%d", pop[i][j]);
		}
		printf(", ");
	}
}



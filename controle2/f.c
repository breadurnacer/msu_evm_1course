#include <stdlib.h>
#include <stdio.h>

//функция обработки матрицы
//int perform(double *a, int n, int m);

//int perform(double *a, int n, int m){}

int main(int ac, char *av[]){
	int n, m;
	double *a; //массив под матрицу
	char *str = malloc(LEN*sizeof(char));
	int sc=0;
	
	fputs("> ", stdout);
	fgets(str, LEN, stdin);
	sc = sscanf(str, "matrix s=[%d,%d]", &n, &m);
	if(sc<2){
		fputs("Error\n", stdout);
	}
	a=malloc(n*m*sizeof(double));
	printf("%d %d", n, m);
	
	
	free(a);
	return 0;
}

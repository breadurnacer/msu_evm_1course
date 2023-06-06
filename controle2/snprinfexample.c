#include <stdlib.h>
#include <stdio.h>

//функция обработки матрицы
//int perform(double *a, int n, int m);

//int perform(double *a, int n, int m){}

int main(void){
	int r=0;
	char *str = malloc(10*sizeof(char));
	
	printf("look: %d\n",r);
	
	r = snprintf(str, 21, "%f shundos loh", 1.5);
	
	printf("%s\n", str);
	printf("look: %d\n",r);
	
	
	
	return 0;
}

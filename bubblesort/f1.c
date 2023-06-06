#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//сортировка пузырьком (задача 2)
//первый файл
//
void bubblesort(int *a, int n); //сортировка
//
void generate_rand(int *a, int n); //сгенерировать рандомный 
void generate_increasing(int *a, int n); //сгенерировать возрастающий
void generate_decreasing(int *a, int n); //сгенерировать убывающий
//
void print(int *a, int n);
int read_from_file(FILE *fi, int *a, int n);
int check(int *a, int *t, int n);
//

int skip_chars(void) {
	int r, c;
	
	for(r = 0;;) {
		c = fgetc(stdin);
		
		if(c == '\n' || c == EOF)
			break;
		
		if(c != ' ' && c != '\t')
			r = -1;
	}
	return r;
}

int main(void){
	int *a1, *t1, *a2, *t2;
	int n;
	char t, ch;
	//int i;
	int c; //вспомогательный
	clock_t s1, e1, s2, e2;
	double time_n, time_2n;
	int check_n, check_2n;
	FILE *fi_n, *fi_2n;

	//ввод n - длины массива
	for(c = 0; !feof(stdin); c =1) {
		if(c)
			printf("Please, try again ...\n");
		
		printf("Input n: ");
		if(scanf("%d", &n) != 1) {
			skip_chars();
			continue;
		}
		if(skip_chars() == -1)
			continue;
		break;
	}
	
	//ввод t - тип создаваемого массива
	for(c = 0; !feof(stdin); c =1) {
		if(c)
			printf("Please, try again ...\n");
		
		printf("Input t (r/i/d/f): ");
		int sf;
		sf = scanf("%c", &t);
		if(sf != 1 || (t!='r' && t!='i' && t!='d' && t!='f')){
			skip_chars();
			continue;
		}
		if(skip_chars() == -1)
			continue;
		break;
	}
	
	//ввод c (ch в переменных) - проверять ли сортировку
	for(c = 0; !feof(stdin); c =1) {
		if(c)
			printf("Please, try again ...\n");
		
		printf("Input c (y/n): ");
		int sf;
		sf = scanf("%c", &ch);
		if(sf != 1 || (ch!='y' && ch!='n')) {
			skip_chars();
			continue;
		}
		if(skip_chars() == -1)
			continue;
		break;
	}
	
	a1 = malloc(6 * n * sizeof(int));
	if(!a1){
		fprintf(stderr, "Memory allocation error\n");
		return -1;
	}
	t1 = a1 + n;
	a2 = t1 + n;
	t2 = a2 + 2*n;
	
	switch(t){
		case 'r':
		generate_rand(a1, n);
		generate_rand(a2, 2*n);
		break;
		
		case 'i':
		generate_increasing(a1, n);
		generate_increasing(a2, 2*n);
		break;
		
		case 'd':
		generate_decreasing(a1, n);
		generate_decreasing(a2, 2*n);
		break;
		
		case 'f':
		fi_n = fopen("input1.txt", "r");
		fi_2n = fopen("input2.txt", "r");
		if(read_from_file(fi_n, a1, n) == -1)
			return -1;
		if(read_from_file(fi_2n, a2, 2*n) == -1)
			return -1;
		break;
		
		default:
		fprintf(stderr, "Wrong t\n");
		return -1;
	}
	/* print(a1,n);
	print(a2,2*n); */
	
	s1 = clock();
	bubblesort(a1, n);
	e1 = clock();
	time_n = (double)(e1-s1)/CLOCKS_PER_SEC;
	
	s2 = clock();
	bubblesort(a2, 2*n);
	e2 = clock();
	time_2n = (double)(e2-s2)/CLOCKS_PER_SEC;
	
	printf("t1= %.2lf \nt2= %.2lf \nt2/t1= %.2lf\n", time_n, time_2n, time_2n/time_n);
	
	/* print(a1,n);
	print(a2,2*n); */
	
	switch(ch){
		case 'y':
		check_n = check(a1, t1, n);
		check_2n = check(a2, t2, 2*n);
		switch(check_n){
			case 0:
			printf("Sort array N is correct\n");
			break;
			
			case -1:
			printf("Sort array N is INCORRECT\n");
			break;
		}
		switch(check_2n){
			case 0:
			printf("Sort array 2N is correct\n");
			break;
			
			case -1:
			printf("Sort array 2N is INCORRECT\n");
			break;
		}
		break;
		
		case 'n':
		break;
		
		default:
		fprintf(stderr, "Wrong c\n");
		return -1;
	}
	
	free(a1);
	return 0;
}
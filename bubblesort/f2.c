#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//сортировка пузырьком (задача 2)
//второй файл
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

void print(int *a, int n){
	int i;
	printf("n: %d a:", n);
	for(i = 0; i < n; i ++)
		printf(" %d", a[i]);
	printf("\n");
} 

void generate_rand(int *a, int n){
	int i;
	srand(time(NULL));
	for(i = 0; i<n; i++){
		a[i] = rand();
		a[i+n] = a[i];
	}
}

void generate_increasing(int *a, int n){
	int i;
	for(i = 0; i<n; i++){
		a[i] = i;
		a[i+n] = a[i];
	}
}

void generate_decreasing(int *a, int n){
	int i;
	for(i = 0; i<n; i++){
		a[i] = n-i;
		a[i+n] = a[i];
	}
}

void bubblesort(int *a, int n){
	int flag;
	double t;
	for (int i = n - 1; i >= 0; i--){
		flag = 1;
		for (int j = 0; j < i; j++){
			if (a[j] > a[j + 1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 0;
			}
		}
		if(flag)
			break;
	}
}

int check(int *a, int *t, int n){
	int i;
	int last, count;
	
	last = a[0];
	count = 0;
	for(i = 0; i < n - 1; i++){
		if(a[i] > a[i+1]){
			return -1;
		}
		
		if(a[i]==last){
			count++;
		}
		else{
			/* printf("LAST = %d\n", last);
			printf("COUNT = %d\n", count); */
			//проходимся по копии - массив до сортировки
			for(int j = 0; j < n; j++){
				if(t[j]==last)
					count--;
			}
			if(count!=0)
				return -1;
			
			last = a[i];
			count++;
		}
	}
	return 0;
}

int read_from_file(FILE *fi, int *a, int n){
	int end, i;
	for(i = 0; i < n; i++){
        if(fscanf(fi, "%d", a+i) != 1){
            fprintf(stderr, "Can't read element\n");
            fclose(fi);
            free(a);
            return -1;
        }
		a[i+n] = a[i];
    }
    
    if(fscanf(fi, "%d", &end) != EOF){
        fprintf(stderr, "Wrong input data\n");
        fclose(fi);
        free(a);
        return -1;
    }
	return 0;
}

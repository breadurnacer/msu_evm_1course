#include <stdlib.h>
#include <stdio.h>

//контрольная работа №1

void sort(double *a, int n, int m); //функция сортировки
double v(double *a, int l); //весовая функция
int read_from_file(FILE *fi, int *a, int n); //чтение матрицы из файла
int toInt(const char *str, int *r);

int toInt(const char *str, int *r){
    char *e;
    int res;

    errno = 0;
    res = strtol(str, &e, 10);
    if(!errno && *e == '\0')
        if(INT_MIN <= res && res <= INT_MAX )
            *r = 1;
		
    return res;
}

int read_from_file(FILE *fi, double *a, int n, int m){
	int i;
	double end;
	for(i = 0; i < n*m; i++){
        if(fscanf(fi, "%lf", a+i) != 1){
            fprintf(stderr, "Can't read element\n");
            fclose(fi);
            free(a);
            return -1;
        }
		a[i+n] = a[i];
    }
    
    if(fscanf(fi, "%lf", &end) != EOF){
        fprintf(stderr, "Wrong input data\n");
        fclose(fi);
        free(a);
        return -1;
    }
	return 0;
}

double v(double *a, int l, int /*m или n*/){
	
}

void sort(double *a, int n, int m){
	int flag;
	double t;
	
	for (int i = /*n или m*/ - 1; i >= 0; i--){
		flag = 1;
		for (int j = 0; j < i; j++){
			if (v(a,j) > v(a,j+1)){
				/*t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;*/
				//меняем строки или столбцы местами
				
				flag = 0;
			}
		}
		if(flag)
			break;
	}
}

void main(int ac, char *av[]){
	double *a; //массив матрицы
	int n, m; //размер матрицы
	FILE *fi;
	
	if(ac != 4)
		return -1;
	
	a = malloc(n * m * sizeof(double));
	if(!a1){
		fprintf(stderr, "Memory allocation error\n");
		return -1;
	}
	
	read_from_file(fi, a, n, m);









    free(a);
	return 0;
}

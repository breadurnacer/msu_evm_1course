#include <stdio.h>
#include <stdlib.h>

#define LEN 1024

/*функция принимает на вход строку, 
на выход даёт 1 - печатать строку,
0 - не печатать*/ 
int readNum(char *s);

int readNum(char *s){
	char *str;
	double x; 
	int scan;
	
	str = s;
	for(;;){
		scan = sscanf(str, "%lf", &x);
		switch(scan){
			case 1:{
			    //printf("%f\n", x);
				
				if(x > 100.0){
					return 1;
				} else{
					str = str + 1;
				}
			    break;
			}
			case -1:
			    return 0;
				
			case 0:
			    str = str + 1;
		}
	}
}

int main(int ac, char *av[]){
	FILE *fi, *fo;
	char *res_str = malloc(sizeof(char)*LEN);
	char *nstr = malloc(sizeof(char)*LEN); //очередная строка
	int r;
	
	if(ac!=3)
		return -1;
	
	fi = fopen(av[1], "r");
	fo = fopen(av[2], "w");
	
	for(;;){
		res_str = fgets(nstr, LEN, fi);
		//если дошли до конца строки
		if(!res_str){
			//printf("\nend of fi\n");
			break;
		}
		
		//иначе - отправляем строку в функцию
		//printf("%s", nstr);
		r = readNum(nstr);
		if(r){
			fprintf(fo, "%s", nstr);
		}
	}
	
	free(res_str);
	free(nstr);
	fclose(fi);
	fclose(fo);
	return 0;
}

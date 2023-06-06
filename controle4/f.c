#include <stdlib.h>
#include <stdio.h>

//контрольная №4
//на примере задачи 1
//https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

//символ который нужно напечатать
int change(int c);


int change(int c){
	if(c >= 65 && c <= 90){
		return (c+32);
	}
	
	if(c >= 97 && c <= 122){
		return (c-32);
	}
	
	return 42;
}

int main(int ac, char *av[]){
	FILE *fi, *fo;
	int ci, co;
	
	if(ac!=3){
		fprintf(stderr, "Usage: %s i.txt o.txt\n", av[0]);
		return -1;
	}
	
	fi = fopen(av[1], "r");
	if(!fi){
		fprintf(stderr, "Can't open %s\n", av[1]);
		return -1;
	}
	
	fo = fopen(av[2], "w");
	if(!fo){
		fclose(fi);
		fprintf(stderr, "Can't open %s\n", av[2]);
		return -1;
	}
	
	for(;;){
		ci = fgetc(fi);
		if(ci == EOF){
			break;
		}
		
		co = change(ci);
		if(fputc(co, fo) == EOF){
			fclose(fi);
			fclose(fo);
			fprintf(stderr, "Error write\n");
			return -1;
		}
	}
	
	if(!feof(fi)){
		fclose(fi);
		fclose(fo);
		fprintf(stderr, "Error read\n");
		return -1;
	}
	
	return 0;
}

#include <stdio.h>

int ramdom();
///int tamArray();
void remover(int num);
int lista[8];
int tam;
void llenar();

int main (){
	int lista2, i;
	llenar();
	for(i=0;i<9;i++){
		lista2=ramdom();
		printf("%d)  %d tam %d\n",i, lista2, tam);
		remover(lista2);
	}
	return 0;
}

int ramdom(){
	int x=10, s=1, i, y;
	y=tam;
	while(s!=0){
		x= rand()%11;

		for(i=0;i<y;i++){
			if(x==lista[i]){
				s--;
			}
		}
	}
	return x;
}

void remover(int num){
	int x, y, i,b=0;
	x=num;
	y=tam;

	for(i=0;i<y-1;i++){
		if(b==0){
			if(x==lista[i]){
				b++;
				lista[i]=lista[i+1];
			}
		}else{
			lista[i]=lista[i+1];
		}
	}
	tam--;
}

void llenar(){
    int i;
    for(i=0;i<9;i++){
        lista[i]=i+1;
        printf("%d",lista[i]);
    }
    tam=9;
}
/*
int tamArray(){
	int x, y, z;
	y= sizeof(int);
	z= sizeof(lista);
	x=z/y;
	return x;
}*/

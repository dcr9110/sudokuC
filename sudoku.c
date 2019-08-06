#include <stdio.h>

// Check Examples
int indiceS(int num);
int ramdom();
int comprobarFila(int fila, int columna,int nuevo);
//Compiler version gcc  6.3.0
int sud[9][9];
int lista[9];
int tam;

void remover(int num);
void llenar();

int main()
{
	int  x,y,col,fila, s, nuevo,q;

	printf("Sudoku\n");
	for(fila=0; fila<9;fila++){
		for(col=0;col<9;col++){
			s=0;
            llenar();
			while(s==0){
				nuevo=ramdom();
				//printf("%d",nuevo);
				s++;
				//revisa que en la fila no se repita el numero
				s=comprobarFila(fila,col,nuevo);
				if(s!=0){
                       //revisa que en la columna no exista el numero

                    s=comprobarColumna(fila,col,nuevo);
                    if(s!=0){
                            //revisa que en el sub cuadro no exista el numero
                        q=fila-indiceS(fila);

                        switch(q){
                            case 0:

                                break;
                            case 1:
                                s=comprobarFilaAnt(fila,col,nuevo);
                                break;
                            case 2:
                                s=comprobarFilaAnt(fila-1,col,nuevo);
                                if(s!=0){
                                    s=comprobarFilaAnt(fila,col,nuevo);
                                }
                                break;
                            default:
                                break;
                        }

				}
                }
                if(tam==0 && s==0){
                    s=1;
                    col=-1;
                    printf("\n");
                }else{
                    if(s==0){
                    remover(nuevo);
                    }else{
                        printf("f%d ", fila);
//                        printf("c%d)", col);
                        printf("%d \t", nuevo);
                        sud[fila][col]=nuevo;
                    }
                }

			}



		//system("PAUSE");
		}
		printf("\n");
	}
		for(fila=0; fila<9;fila++){
		for(col=0;col<9;col++){
            printf("%d\t",sud[fila][col]);
		}
		printf("\n");
		}
	return 0;
}

int ramdom(){
	int x=10, s=1;
	while(s!=0){
		x= rand()%11;
		if(x<=9 && x>=1){
			s--;
		}
	}
	return x;
}

int indiceS(int num){
	int x;
	if(num<=2){
				x=0;
			}else{
				if(num<=5){
					x=3;
				}else{
					x=6;
				}
			}
	return x;
}

int comprobarFilaAnt(int fila, int columna,int nuevo){
    int x=1,i,j,k;
    j=fila-1;
    i=indiceS(columna);
    k=i+3;
    for(i;i<k;i++){
            //printf("%d = %d |",sud[j][i],nuevo);
        if(sud[j][i]==nuevo){
            x=0;
        }
    }
    //printf("salio");
    return x;
}

void remover(int num){
	int x, y, i,b=0;
	x=num;
	y=tam;

	for(i=0;i<y;i++){
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
    }
    tam=9;
}

int comprobarColumna(int fila,int col,int nuevo){
    int i, x;

	for(i=0;i<fila;i++){
		if(nuevo==sud[i][col]){
			x=0;
			}
	}
	return x;

}


int comprobarFila(int fila,int col,int nuevo){
    int i, x;
	for(i=0;i<col;i++){
		if(nuevo==sud[fila][i]){
			x=0;
			}
	}
	return x;

}

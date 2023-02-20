#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define MAX 3
#define TXT 30
int val_number(char menu[]);
int val_number2(char menu[]);
int val_letra(char vletra[]);

void Encrypt(char menu [], int matrizC[][3]);
void Decrypt(char menu[], int matrizC[][3], float matrizInversa[][3]);

int main(){

	char mensaje[100], menu[5], vletra[100];
	int num,swmenu, matrizC[3][3]={{1,-2,2},{-1,1,3},{1,-1,-4}}; 
	float adjunta[3][3], matrizInversa[3][3]={{-1,-10,-8},{-1,-6,-5},{0,-1,-1}};
	int det1=0,det2=0,det3=0,det4=0,det5=0,det6=0,det=0;

do{	
	do{
	system("cls");
	
		printf("\n\t\t===QUE QUIERES HACER? ===");
		printf("\n\t\t*************************\n");
		printf("\t\t*1. ENCRIPTAR MENSAJE\t*\n");
		printf("\t\t*2. DESENCRIPTAR MENSAJE*\n");
		printf("\t\t*3. SALIR\t\t*\n");
		printf("\t\t*************************\n\t\t\t   ");
		printf("\n\t\t=== SELECCIONA UNA OPCION ===\n\t\t\t");
			fflush(stdin);
			scanf("%s",menu);
		num = val_number(menu);			
	}
	while(num==0);
	swmenu=atoi(menu);
	switch (swmenu){
		case 1:
			system("cls");
			Encrypt(vletra,matrizC);
			break;
		case 2:
			system("cls");
			Decrypt(menu, matrizC, matrizInversa);
			break;
		case 3:	
			printf("\t\t===NOS VEMOS! ===\n");
			exit(EXIT_SUCCESS);
			break;
		case 18:
		matrizInversa[3][3]==0;
			printf("Ingrese la matriz clave\n");
	fflush(stdin);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			do{
			printf("Matriz Clave [%d][%d] : ",i+1,j+1);
			scanf("%s",menu);
			num=val_number2(menu);
			}
			while(num==0);
			matrizC[i][j]=atoi(menu);
		}
	}
	
	// Calculo del determinante de la matriz clave
	det1 = matrizC[0][0]*matrizC[1][1]*matrizC[2][2];
	det2 = matrizC[0][1]*matrizC[1][2]*matrizC[2][0];
	det3 = matrizC[1][0]*matrizC[2][1]*matrizC[0][2];
	
	det4 = matrizC[2][0]*matrizC[1][1]*matrizC[0][2];
	det5 = matrizC[2][1]*matrizC[1][2]*matrizC[0][0];
	det6 = matrizC[1][0]*matrizC[0][1]*matrizC[2][2];
	
	det = det1+det2+det3-det4-det5-det6;
	printf("%d",det);
	
	// Calculo de la adjunta de la matriz clave
	adjunta[0][0] = (1)*(matrizC[1][1]*matrizC[2][2] - matrizC[1][2]*matrizC[2][1]);
	adjunta[1][0] = (-1)*(matrizC[1][0]*matrizC[2][2] - matrizC[1][2]*matrizC[2][0]);
	adjunta[2][0] = (1)*(matrizC[1][0]*matrizC[2][1] - matrizC[1][1]*matrizC[2][0]);
	adjunta[0][1] = (-1)*(matrizC[0][1]*matrizC[2][2] - matrizC[0][2]*matrizC[2][1]);
	adjunta[1][1] = (1)*(matrizC[0][0]*matrizC[2][2] - matrizC[0][2]*matrizC[2][0]);
	adjunta[2][1] = (-1)*(matrizC[0][0]*matrizC[2][1] - matrizC[0][1]*matrizC[2][0]);
	adjunta[0][2] = (1)*(matrizC[0][1]*matrizC[1][2] - matrizC[0][2]*matrizC[1][1]);
	adjunta[1][2] = (-1)*(matrizC[0][0]*matrizC[1][2] - matrizC[1][0]*matrizC[0][2]);
	adjunta[2][2] = (1)*(matrizC[0][0]*matrizC[1][1] - matrizC[0][1]*matrizC[1][0]);
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("\t(%.1f)",adjunta[j][i]);
		}
		printf("\n\n");
	}
	system("pause");
	
	//rellenar matriz inversa
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			matrizInversa[i][j]=(adjunta[j][i]/det);
		}
	}
	
	printf("MATRIZ INVERSA\n\n");
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("\t(%.1f)",matrizInversa[i][j]);
		}
		printf("\n\n");
	}
	system("pause");
			break;
		case 777:
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					printf("\t(%d)", matrizC[i][j]);
				}
				printf("\n\n");
			}
			system("pause");
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					printf("\t(%.1f)", matrizInversa[i][j]);
				}
				printf("\n\n");
			}
			system("pause");
			break;
		default:
			printf("\t\tERROR: OPCION NO VALIDA\n\n");
			system("pause");
			system("cls");
			break;
		}
	
	}
	while(1==1);
}

int val_number(char menu[]){
	int i;
	for (i=0; i<strlen(menu); ++i){
		if(!(isdigit(menu[i]))){
				printf("\t\tERROR: OPCION NO VALIDA\n\n");
		system("pause");
		system("cls");
			return 0;
		}
	}
	return 1;
}
int val_number2(char menu[]){
	int i;
	for (i = 0; i < strlen(menu); ++i){
		if(!(isdigit(menu[i]))){
			if(menu[0] == '-' && isdigit(menu[i+1])){
				
			}else{
					printf("\t\tERROR: NUMERO NO VALIDO\n\n");
				getch();system("cls");
			return 0;
			}
		}
	}
	return 1;
}
int val_letra(char vletra[]){
	int i=0;
	for(i=0; i<strlen(vletra); i++){
		if(!(isalpha(vletra[i]))){
			if(isdigit(vletra[i])){
				printf("\t\tERROR: OPCION NO VALIDA\n\n");
				getch();
				return 0;
			}
			if(vletra[i]==32){
				
			}
			else{
				printf("\t\tERROR: OPCION NO VALIDA\n\n");	
				getch();
				return 0;
			}	
		}
	}
	return 1;
}

void Encrypt(char menu [], int matrizC[][3]){
	int large, num, sum=0,i=0, j=0, x=0, k=0, l=0, a, tam;
	int matriz[100][3];
	int matrizR[100][100];
	char vletra[100], codigos[100]={" abcdefghijklmnopqrstuvwxyz"};
	int div=0, add;
	
do{
	printf("\t\t=== MENSAJE A ENCRIPTAR ===\n\n\t\t");
		fflush(stdin);
		gets(vletra);
	num=(val_letra(vletra));
	}
	while(num==10);
	large=strlen(vletra);
	div=large%3;
	
	for(i=0; i<100; i++){
		vletra[i]=tolower(vletra[i]);
	}
	
	if(div==2){
		for(i=0; i<1; i++){
			add=codigos[0];
			large++;
			vletra[large - 1]=add;
		}
	}
	if(div==1){
		for(i=0; i<2; i++){
			add=codigos[0];
			large++;
			vletra[large - 1]=add;
		}
	}
	x=large/3;
	printf("%d %d", x, div);
	
	for(i=0; i<=x; i++){
		for(j=0; j<=2; j++){
			for(k=a; k<=strlen(vletra); k++){
				for(l=0; l<=26; l++){
					if(vletra[k]==codigos[l]){
						matriz[i][j]=l;
						a++;
						break;
					}
				}
				break;
			}
		}
	}
	for (i=0 ; i<x; i++){ 
		for (k=0 ; k<3; k++){
			sum = 0 ;
        for (j=0 ; j<3; j++){                                 
         	   sum += matriz[i][j] * matrizC[j][k];
          	  matrizR[i][k] = sum;
        }
    }
}
	printf("\n\t\t=== SU MENSAJE ENCRIPTADO ES :\n\n\t\t");
	for(i=0; i<x; i++){
		for(j=0; j<3; j++){
			printf("[%d]",matrizR[i][j]);
		}
	}
	getch();
}
void Decrypt(char menu[], int matrizC[][3], float matrizInversa[][3]){
	int div=0, num=0,sum=0,i=0,a=0, j=0, x=0, k=0, large=0;
	int matriz[100][3];
	int matrizD[100][100];
	char vletra[100], codigos[100]={" abcdefghijklmnopqrstuvwxyz"};
do{
	do{
	
	printf("TENER EN CUENTA: si el codigo que ingrese no esta dentro de los parametros de encriptacion\n");
	printf(" del programa, este no dara una desencriptacion propia a su requerimiento\n\n");
	printf("\t===De que tamano sera el codigo a desencriptar===\n ");
	printf("(en cantidad de caracteres MAX 99 y que sea divisible entre 3)\n\t\t");
	fflush(stdin);
	scanf("%s",menu);
	num=val_number(menu);
	}
	while (num==0);
	large=atoi(menu);
	div=large%3;
	
	if(div != 0){
		printf("\t\tCUIDADO: Recuerde que debe ingresar un codigo divisible entre 3, gracias\n");
		getch();
		system("cls");
	}
}
while(div!=0);
	x=large/3;
	system("cls");
	for(int i=0; i<x; i++){
		for(int j=0; j<3; j++){
			do{
			printf("Codigo a desencriptar[%d][%d] : ",i+1,j+1);
			scanf("%s",menu);
			num=val_number2(menu);
			}
			while(num==0);
			matriz[i][j]=atoi(menu);
		}
	}
	
	for (i=0 ; i<x; i++){ 
		for (k=0 ; k<3; k++){
			sum = 0 ;
       		for (j=0 ; j<3; j++){                                 
         	   sum += matriz[i][j] * matrizInversa[j][k];
          	  matrizD[i][k] = sum;
       		}
   		}
	}

	char mensaje[100];
		i = 0;	j = 0;	a = 0;
		
	for(i = 0; i < x; i++){
		for(j = 0; j <= 2; j++){
			mensaje[a] = codigos[matrizD[i][j]];
			a++;	
		}
	}
	
	system("cls");
	printf("\n\t\t=== SU CODIGO ENCRIPTADO ES :\n\n\t\t");
	for(i=0; i<x; i++){
		for(j=0; j<3; j++){
			printf("[%d]",matriz[i][j]);
		}
	}
	getch();
	for(i = 0; i<x; i++){
	 mensaje[i] = tolower(mensaje[i]);
				mensaje[0] = toupper(mensaje[0]);
			}
	printf("\n\n\t\t=== SU CODIGO DESENCRIPTADO ES :\n\n\t\t");
	printf("%s", mensaje);
	getch();
	
	memset(mensaje,'\0', 100);

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void gerarChaves(short *Pn, short *Lp, double *e, double *d, double *num);
void decodificar(double d, double num);

int main(void) {
  	short PrimeList[40] = {179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409};
	//  e d public phi
	srand(time(NULL));
	short tresNumeros[3];
	double E;
	double D;
	double Num;
	for(int i = 0; i < 3; i++)
	{
		tresNumeros[i] = rand() % 40;
	}
	gerarChaves(PrimeList, tresNumeros, &E, &D, &Num);

	printf("Seu e: %ld, seu d: %ld, sua chave publica: %ld\n", E, D, Num);

	decodificar(D, Num);

  	return 0;
}
void gerarChaves(short *Pn, short *Lp, double *e, double *d, double *num)
{
	double phi;
	double D;
	*num = (*(Pn + *(Lp+0)))*(*(Pn + *(Lp+1)));//*(*(Pn + *(Lp+2)));
	phi = (*(Pn + *(Lp+0)) - 1)*(*(Pn + *(Lp+1)) - 1);//*(*(Pn + *(Lp+2)) - 1);
	printf("\nPHI:%d\n", phi);
	for(int i = 3; 1; i += 2)
	{
		if( i % (long)*(num) != 0)
		{
			D = (double)((2*phi) + 1)/(i);
			printf("\nD:%lf\n", D);
		  	if(D - (long)D == 0)
			{
				*(e) = i;
				break;
			}
		}
	}
	*(d) = (double)D;
}
void decodificar(double d, double num)
{
	double Entrada;
	scanf("%ld", &Entrada);
	double Saida;
	Saida = (long)pow(Entrada, d) % (long)num;
	printf("O valor decodificado eh %ld\n", Saida);
}
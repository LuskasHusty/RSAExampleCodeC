#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void gerarChaves(short *Pn, short *Lp, int *e, int *d, int *num);
void decodificar(int d, int num);

int main(void) 
{
  	short PrimeList[40] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173};
	//  e d public phi
	srand(time(NULL));
	short tresNumeros[3];
	int E;
	int D;
	int Num;
	for(int i = 0; i < 3; i++)
	{
		tresNumeros[i] = rand() % 40;
	}
	gerarChaves(PrimeList, tresNumeros, &E, &D, &Num);

	printf("Seu e: %d, seu d: %d, sua chave publica: %d\n", E, D, Num);

	while(1)
	{
		decodificar(D, Num);
	}
  	return 0;
}
void gerarChaves(short *Pn, short *Lp, int *e, int *d, int *num)
{
	int phi;
	double D;
	*num = (*(Pn + *(Lp+0)))*(*(Pn + *(Lp+1)));//*(*(Pn + *(Lp+2)));
	phi = (*(Pn + *(Lp+0)) - 1)*(*(Pn + *(Lp+1)) - 1);//*(*(Pn + *(Lp+2)) - 1);
	printf("\nPHI:%d\n", phi);
	for(int i = 3; i < phi; i += 2)
	{
		if( i % *(num) != 0)
		{
			D = (double)((2*phi) + 1)/(i);
			printf("\nD:%lf\n", D);
		  	if(D - (int)D == 0)
			{
				*(e) = i;
				break;
			}
		}
	}
	*(d) = (int)D;
}

long int cdn( long int c, long int d, long int n )      // work out c^d mod n
{
   unsigned long long int value = 1;
   while( d > 0 )
   {
      value *= c;
      value %= n;
      d--;
   }
   return value;
}

void decodificar(int d, int num)
{
	long int Entrada = 0;
	scanf("%lu", &Entrada);
	long int Saida = cdn(Entrada, d, num);
	printf("O valor decodificado eh %lu\n", Saida);
}
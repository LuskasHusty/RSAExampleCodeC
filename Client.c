#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int main(void) 
{
    double E = (double)11;
    double Pk = (double)2537;
    double Ns = (double)69;
    /*
	printf("Entre o E: ");
    scanf("%f", &E);
    printf("Entre a Chave Publica: ");
	scanf("%f", &Pk);
    printf("Entre seu numero secreto: ");
    scanf("%f", &Ns);
    */
    double NumeroCod;
    NumeroCod = pow(Ns, E);
    NumeroCod = fmod(NumeroCod, Pk);
    printf("Seu numero codificado eh: %lf", NumeroCod);
  	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>



long int cdn( long int c, long int d, long int n )      // work out c^d mod n
{
   long int value = 1;
   while( d > 0 )
   {
      value *= c;
      value %= n;
      d--;
   }
   return value;
}

int main(void) 
{
    long int E = 11;
    long int Pk = 2537;
    long int Ns = 69;

	printf("Entre o E: ");
    scanf("%lu", &E);
    printf("Entre a Chave Publica: ");
	scanf("%lu", &Pk);
    printf("Entre seu numero secreto: ");
    scanf("%lu", &Ns);
    long int NumeroCod;
    NumeroCod = cdn(Ns, E, Pk);
    printf("Seu numero codificado eh: %lu", NumeroCod);
  	return 0;
}
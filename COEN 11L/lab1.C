
#include <stdio.h>

#include <stdlib.h>

int division(int, int);

int main()

{

  int quotient1;
  
  int ctr=0;
 
  int i;
  
  int a=0;
  
  for(i=0;i<10;i++)

   { 

    int divisor= rand()% 12+1;

    printf("The denominator is %d \n", divisor);

    int quotient= rand()% 13;

    int dividend= divisor*quotient;

    printf("The dividend is %d \n", dividend);

    printf("Input the quotient: ");

    scanf("%d", &quotient1);

    a=division(quotient,quotient1);

    ctr+=a;

   }

  printf("\n Your score is %d \n", ctr);

}


int division(int quotient, int quotient1)

{

  if(quotient == quotient1)

    {

      printf("correct\n");

      return 1;

    }

  else 

    {

    printf("Wromg! The correct answer is %d \n", quotient);

    return 0;

  }
}



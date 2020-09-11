#include <stdio.h>

#include <string.h>

char name[100][40];

int size[30];

int ctr = 0;

void insert ();

void removes ();

void list ();

int
main ()

{
  
  for (;;)
 
   {

      int choice = 0;

      printf ("Choose an option: \n0.To Quit \n1.To Add a Booking \n2.To Remove a Name \n3.To List: \n");

      scanf ("%d", &choice);

      switch (choice)//choosing option in menu

	{

	case 0:

        return 0;

        case 1:

        insert ();

	  break;

	case 2:
	 
        removes ();

	  break;

        case 3:
	
        list ();

	}

    }


} 

void insert ()

{

  printf ("Enter name:");//asking name for booking

  scanf ("%s", name[ctr]);

  printf ("Enter number of people:");//asking size of booking

  scanf ("\n %d", &size[ctr]);

  ctr++;


}

void removes ()

{
  
  int opening=0;

  int ctr2=0;

  printf ("Enter size of booking: \n");

  scanf("%d", &opening);

  for(int i=0;i<ctr;i++)

  {

   if(ctr2==0)//counter to only enter loop once

      {
   
       if(opening>=size[i])
 
        {
 
         ctr2++;

         for(int j=i;j<ctr;j++)
   
         {
 
             int a=j+1;

             strcpy(name[j],name[a]);

             size[j]=size[a];

          }
          
         printf("table is yours: %s\n",name[i]);

          ctr--;

      }
    
  }
    
 }

}

void list ()

{
   
 for (int i = 0; i < ctr; i++)

   {

    printf ("%d. Name is: %s\n",i+1, name[i]);

    printf ("%d. Number of people: %d\n",i+1, size[i]);

   }

}
 
























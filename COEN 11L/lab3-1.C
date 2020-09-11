#include <stdio.h>

#include <string.h>

#define SIZE 10

int ctr = 0;

void insert ();

void removes ();

void list ();

void search_size();

int check_duplicate(char n[]);

typedef struct entry

{

  char name[20];

  int size;

}ENTRY;

ENTRY entries[SIZE];


int main ()

{


  for (;;)

    {

      int choice = 0;

      printf ("Choose an option: \n0.To Quit \n1.To Add a Booking \n2.To Remove a Name \n3.To List: \n4.Show smaller tables \n");

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

         break;

         case 4:

         search_size();

	}

    }


}

void insert ()

{

  char n[20];

  printf ("Enter name:");//asking name for booking

  scanf ("%s",n);

  int a=check_duplicate(n);

  if(a!=1)

  {

   strcpy(entries[ctr].name,n);

   printf ("Enter number of people:");//asking size of booking

   scanf ("\n %d",&entries[ctr].size);

   ctr++;

  }

  else

  {

   printf("This name already exists\n");

  }

}


int check_duplicate(char n[])

{

 ENTRY *p=entries;

 for(int i=0;i<ctr;i++)

 {

  if(strcmp(p->name,n)==0)

  {

    return 1;

  }

  else

  {

   p++;

  }

 }

return 0;

}

void removes ()

{
  int opening=0;

  int ctr2=0;

  printf ("Enter size of booking: \n");

  scanf("%d", &opening);

  int i;

  ENTRY *p=entries;

  for(i=0;i<ctr;i++)

  {

   if(ctr2==0)

   {

    if(opening>=p->size)

    {

     for(int j =i;j<ctr;j:++)

     {

     ctr2++;

     strcpy(p->name,(p+1)->name);

     p->size=(p+1)->size;

     p++;

     }

    ctr -=1;

    }

   }

   p++;

  }

}

void list ()

{

   ENTRY *p=entries;


   for (int i = 0; i < ctr; i++)

   {

    printf ("%d. Name is: %s",i+1, p->name);

    printf ("\t %d. Number of people: %d\n",i+1, p->size);

    p++;

   }

}

void search_size()

{

 int opening=0;

 printf("Enter size of booking: \n");

 scanf("%d", &opening);

 ENTRY *p=entries;

 for(int i=0;i<(ctr);i++)

 {

  if(p->size<=opening)

  {

   printf("%d. Name is: %s",i+1,p->name);

   printf("\t %d. Number of people: %d\n",i+1, p->size);
 
  }

  p++;

 }


}








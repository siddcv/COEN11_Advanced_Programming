
#include <stdio.h>

#include <string.h>

#define SIZE 10

int ctr = 0;

void insert ();

void removes ();

void list ();

void search_size();

int check_duplicate(char n[]);

union special

{

    char name1[20];

    int years;

    float avg_age;

};

struct entry

{

  char name[20];

  int size;

  int special_occasion;

  union special extra_info;

};


struct entry ENTRY[SIZE];

struct entry *p;

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

  p=ENTRY;

  char n[20];

  printf ("Enter name:");//asking name for booking

  scanf ("%s",n);

  int a=check_duplicate(n);

  if(a!=1)

  {

   strcpy(ENTRY[ctr].name,n);

   printf ("Enter number of people:");//asking size of booking

   scanf ("\n %d",&ENTRY[ctr].size);

   printf("Enter special occasion- 1 for birtday, 2 for anniversary, 3 for no occasion: ");

   scanf("\n %d", &ENTRY[ctr].special_occasion);

   switch(ENTRY[ctr].special_occasion)

   {

       case 1:

       printf("Enter name of persons birthday:");

       scanf(" \n %s",ENTRY[ctr].extra_info.name1);

       break;

       case 2:

       printf("Enter number of years:");

       scanf("\n %d", &ENTRY[ctr].extra_info.years);

       break;

       case 3:

       printf("Enter average age: ");

       scanf("\n %f", &ENTRY[ctr].extra_info.avg_age);

   }
   ctr++;

  }

  else

  {

   printf("This name already exists\n");

  }

}

int check_duplicate(char n[])

{

 p=ENTRY;

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

}

void removes ()

{
 
  int opening=0;

  int ctr2=0;

  printf ("Enter size of booking: \n");

  scanf("%d", &opening);

  int i;

  p=ENTRY;

  for(i=0;i<ctr;i++)

  {

   if(ctr2==0)

   {

    if(opening>=p->size)

    {

     for(int j =i;j<ctr;j++)

     {

     ctr2++;

     strcpy(p->name,(p+1)->name);

     p->size=(p+1)->size;

     p->special_occasion= (p+1)->special_occasion;

     p->extra_info=(p+1)->extra_info;

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
   
  p=ENTRY;

  for (int i = 0; i < ctr; i++)

   {

    printf ("%d. Name is: %s",i+1, p->name);

    printf ("\t %d. Number of people: %d\n",i+1, p->size);

    switch(p->special_occasion)

   {

       case 1:

       printf("The birthday person is :%s\n", p->extra_info.name1);

       break;

       case 2:

       printf("The number of years: %d\n", p->extra_info.years);

       break;

       case 3:

       printf("Enter average age: %f\n", p->extra_info.avg_age);

   }

    p++;

   }

}

void search_size()

{

 int opening=0;

 printf("Enter size of booking: \n");

 scanf("%d", &opening);

 p=ENTRY;

 for(int i=0;i<(ctr);i++)

 {

    if(p->size<=opening)

  {

   printf("%d. Name is: %s",i+1,p->name);

   printf("\t %d. Number of people: %d\n",i+1, p->size);

  }

     switch(p->special_occasion)

   {

       case 1:

       printf("The birthday person is :%s\n", p->extra_info.name1);

       break;

       case 2:

       printf("The number of years: %d\n", p->extra_info.years);

       break;

       case 3:

       printf("Enter average age: %f\n", p->extra_info.avg_age);

   }


  p++;

 }

}


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define SIZE 10

#define Node struct node

int ctr = 0;

void insert ();

void removes ();

void list ();

void search_size();

int check_duplicate(char n[]);

void free_p();

struct node

{

  char name[20];

  int size;

  Node *next;

};

struct list

{
  
  Node *head;

  Node *tail;

};

struct list List[4];

//Node *head=NULL;
//initializing head node

//Node *tail=NULL;
//initializing tail node

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

	 free_p();

         return 0;

         break;

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

  Node *temp=(Node*)malloc(sizeof(Node));//allocating memory for node
 
  temp->next=NULL;

  char n[20];

  printf ("Enter name:");//asking name for booking

  scanf ("%s",n);

  int a=check_duplicate(n);

  int i;

  if(a!=1)

  {

   printf("Enter number of people: \n");

   scanf("%d", &temp->size);

   if(temp->size<=2)

   i=0;

   else if(temp->size==3||temp->size==4)

   i=1;

   else if(temp->size==5||temp->size==6)

   i=2;

   else if(temp->size>6)

   i=3;

   if(List[i].head==NULL)

     List[i].head=temp;

   else

     List[i].tail->next=temp;

   List[i].tail=temp;//adding new node to the back

   strcpy(temp->name,n);

   ctr++;

  }

  else

  {

   printf("This name already exists\n");

  }

}


int check_duplicate(char n[])

{

 for(int i=0;i<4;i++)

{

 Node *p=List[i].head;

 while(p!=NULL)

 {

  if(strcmp(p->name,n)==0)

  {

    return 1;

  }

  else

   p=p->next;//traverses list

  }

 }

return 0;

}

void removes ()

{

  int opening=0;

  printf ("Enter size of booking: \n");

  scanf("%d", &opening);

  int i;

  if(opening<=2)

  i=0;

  else if(opening==3||opening==4)

  i=1;

  else if(opening==5||opening==6)

  i=2;

  else if(opening>6)

  i=3;

  for(int j=0;j<=i;j++)

  {

  Node *p=List[j].head;

  Node *prev=List[j].head;

  while(p!=NULL)//traverses whole list

  {

    if(opening>=p->size)

    {

     if(p==List[j].head)

     {

      List[j].head=List[j].head->next;

      if(p==List[j].tail)//checks if there is only node

       List[j].tail=List[j].tail->next;

     }

     else

     {

      while(prev->next!=p)

      prev=prev->next;

      prev->next=p->next;

      if(p==List[j].tail)

      List[j].tail=prev;

     }

     free(p);

     return;

    }

  p=p->next;

  }

}

}

void list ()

{

   int j=0;

   for(int i=0;i<4;i++)

  {

   j=1;

   Node *p=List[i].head;

  while(p!=NULL)

  {

    printf("\n%d%s: party of %d\n",j,p->name,p->size);

    p=p->next;

    j++;

  }

  printf("\n");

}

}

void search_size()

{

 int i=0;

 int opening=0;

 printf("Enter size of booking: \n");

 scanf("%d", &opening);

 if(opening<=2)

 i=0;

else if(opening==3||opening==4)

i=1;

else if(opening==5||opening==6)

i=2;

else if(opening>6)

i=3;

for(;i>=0;i--)

{

 Node *p=List[i].head;

 while(p!=NULL)

 {

  if(p->size<=opening)

  {

   printf("%d. Name is: %s",i+1,p->name);

   printf("\t %d. Number of people: %d\n",i+1, p->size);

  }

  p=p->next;

 }

}

}

void free_p()

{

  for(int i=0;i<4;i++)

  {

   Node *p=List[i].head;

   while(p!=NULL)

   {

    free(p);

    p=p->next;

}
}

}










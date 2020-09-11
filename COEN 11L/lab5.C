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

struct node

{

  char name[20];

  int size;

  Node *next;

};

Node *head=NULL;//initializing head node

Node *tail=NULL;//initializing tail node

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

  Node *temp=(Node*)malloc(sizeof(Node));//allocating memory for node
 
  temp->next=NULL;

  char n[20];

  printf ("Enter name:");//asking name for booking

  scanf ("%s",n);

  int a=check_duplicate(n);

  if(a!=1)

  {

   if(head==NULL)

     head=temp;

   else

     tail->next=temp;

   tail=temp;//adding new node to the back

   strcpy(temp->name,n);

   printf ("Enter number of people:\n");//asking size of booking

   scanf ("%d", &temp->size);

   ctr++;

  }

  else

  {

   printf("This name already exists\n");

  }

}


int check_duplicate(char n[])

{

 Node *p=head;
 while(p!=NULL)

 {

  if(strcmp(p->name,n)==0)

  {

    return 1;

  }

  else

  {

   p=p->next;//traverses list

  }

 }

return 0;

}

void removes ()

{

  Node *p=head;

  Node *prev=head;

  int opening=0;

  printf ("Enter size of booking: \n");

  scanf("%d", &opening);

  int i;

  while(p!=NULL)//traverses whole list

  {

    if(opening>=p->size)

    {

     if(p==head)

     {

      head=head->next;

      if(p==tail)//checks if there is only node

       tail=tail->next;

     }

     else

     {

      while(prev->next!=p)

      prev=prev->next;

      prev->next=p->next;

      if(p==tail)

      tail=prev;

     }

     free(p);

     return;

    }

  p=p->next;
 
 }

}

void list ()

{

   if(head==NULL)

   {

    printf("\nNo Reservations\n");

    return;

   }

  Node *p=head;

  while(p!=NULL)

  {

    printf("\n%s: party of %d\n",p->name,p->size);

    p=p->next;

  }

}

void search_size()

{
 int i=0;

 int opening=0,flag=0;

 printf("Enter size of booking: \n");

 scanf("%d", &opening);

 Node *p=head;

 while(p!=NULL&&flag==0)

 {

  if(p->size<=opening)

  {

   printf("%d. Name is: %s",i+1,p->name);

   printf("\t %d. Number of people: %d\n",i+1, p->size);

  }

  i++;

  p=p->next;

 }

}
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define SIZE 10

#define Node struct node

int ctr = 0;

void insert (char name[20], int size);

void removes ();

void list ();

void search_size();

int check_duplicate(char n[]);

void free_p();

void read(char *filename);

void write(char *filename);

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

int main (int argc, char *argv[])

{

  if(argc!=2)

  {

   printf("File not found");

   return 1;

  }

  for(int i=0;i<4;i++)

  {

  List[i].head=NULL;

  List[i].tail=NULL;

  }

  read(argv[1]);

  char name[20];

  int size;

  for (;;)

    {

      int choice = 0;

      printf ("Choose an option: \n0.To Quit \n1.To Add a Booking \n2.To Remove a Name \n3.To List: \n4.Show smaller tables \n");

      scanf ("%d", &choice);

      switch (choice)//choosing option in menu

        {

         case 0:

	 write(argv[1]);

         return 0;

         break;

         case 1:

         printf("Enter name of reservation: \n");

         scanf("%s",name);

         printf("Enter group size: \n");

         scanf("%d",&size);

	 insert (name,size);

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

void insert (char name[20],int size)

{

  Node *temp=(Node*)malloc(sizeof(Node));//allocating memory for node
 
  temp->next=NULL;

  int a=check_duplicate(name);

  int i;

  if(a!=1)

  {

   temp->size=size;

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

   strcpy(temp->name,name);

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


void write(char *filename)

{

 FILE *fp;

 Node *p;

 int i;

 if((fp=fopen("read.txt","w"))==NULL)

 {

  printf("Error saving data!");

  return;

 }

 fprintf(fp,"NAME\tGroup Size\n------------------\n");

 for(i=0;i<4;i++)

 {

  p=List[i].head;

  while(p!=NULL)

  {

   fprintf(fp,"%s\t\t%d\n",p->name,(p->size));

   p=p->next;

  }

 }

 fclose(fp);

}

void read(char *filename)

{

 FILE *fp;

 char name[20];

 int group;

 int size;

 if((fp=fopen("read.txt","r"))==NULL)

 return;

 fseek(fp,35,SEEK_SET);

 while((fscanf(fp,"%s%d",name,&size)==2))

 insert(name,size);

}









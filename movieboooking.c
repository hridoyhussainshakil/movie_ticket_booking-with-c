#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct movie
{
    int id;
    char name[30];
    char date[30];
    int cost;
    int seat;
    char showtime1[10];
    char showtime2[10];
    struct movie *next;
}*start=NULL;


void create()
{
    int i,n;
    struct movie *newnode,*current;
    printf("How many data  u want to insert:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        newnode=(struct movie*)malloc(sizeof(struct movie));
        printf("Enter the id:\n");
        scanf("%d",&newnode->id);
        getchar();
         printf("Enter the movie name:\n");
        scanf("%[^\n]",&newnode->name);
        getchar();
         printf("Enter the release date:\n");
        scanf("%s",&newnode->date);
        getchar();
         printf("Enter the ticket price:\n");
       scanf("%d",&newnode->cost);
        getchar();
        printf("Enter the show first time :\n");
       scanf("%s",&newnode->showtime1);
        getchar();
        printf("Enter the Second show time:\n");
       scanf("%s",&newnode->showtime2);
        getchar();
        printf("Enter the Total sit: \n");
        scanf("%d",&newnode->seat);
        getchar();
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
    }
}

void count()
{
    struct movie *current;
    int count=0;
    current=start;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    printf("\nThere is %d number of Movies in the  list.\n",count);
}

int search(int s_key)
{
    int pos=0;
    struct movie *current;
    current=start;
    while(current!=NULL)
    {
        pos++;
        if(s_key==current->id)
        {
            return pos;

        }
        current=current->next;

    }
    return -1;
}

void find()
{
    struct movie *current;
    current=start;
    int i,s_key;
    int pos;
    printf("Enter the id for searching a particular movie");
    scanf("%d",&s_key);
    pos=search(s_key);

    if(pos==-1)
    {
        printf("\n%d is no data in the  list.\n",s_key);
    }
    for(i=0; i<pos; i++)
    {
       printf("\n\n Code \t Name \t Date \t\t cost \t1st show\t2nd Show \n\n");
        printf("%d\t",current->id);
        printf("%s\t",current->name);
        printf("%s\t",current->date);
        printf("%d\t",current->cost);
        printf("%s\t",current->showtime1);
        printf("\t%s\n",current->showtime2);
        current=current->next;
    }

    printf("***********************************************");
}

void ma_insert()
{
    struct movie *newnode,*current,*temp;
    int key,pos,i;
    newnode=(struct movie*)malloc(sizeof(struct movie));
    printf("Enter the movie code :");
    scanf("%d",&newnode->id);
    getchar();
    printf("Enter the movie name  :");
    scanf("%[^\n]",&newnode->name);
    getchar();
    printf("Enter the movie release date :");
    scanf("%s",&newnode->date);
    getchar();
    printf("Enter the Ticket  Price for movie:");
    scanf("%d",&newnode->cost);
    getchar();
     printf("Enter the show first time :\n");
       scanf("%s",&newnode->showtime1);
        getchar();
        printf("Enter the Second show time:\n");
       scanf("%s",&newnode->showtime2);
        getchar();
    newnode->next=NULL;
    if(start==NULL)
    {
        printf("!!Error for there is no data");
    }
    printf("\nEnter the value after which the new movie has been insert:");
    scanf("%d",&key);
    pos=search(key);
    current=start;
    for(i=1; i<=pos-1; i++)
    {
        current=current->next;
    }
    printf("\n The current id is:%d\n",current->id);
    temp=current->next;
    current->next=newnode;
    newnode->next=temp;

}

void l_delete()
{
    int d_key;
    printf("\nEnter the movie code  you want to delete:");
    scanf("%d",&d_key);
    struct movie *current,*temp1,*temp2,*temp;
    int pos,i;
    pos=search(d_key);
    current=start;
    for(i=1; i<=pos-1; i++)
    {
        current=current->next;
    }
    printf("\n The current id is:%d\n",current->id);
    if(current==start)
    {
        start=current->next;
    }
    else if(current->next==NULL)
    {
        temp=start;
        for(i=1; i<=pos-2; i++)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    else
    {
        temp=start;
        for(i=1; i<=pos-2; i++)
        {
            temp=temp->next;
        }
        temp1=temp;
        temp=temp->next;
        temp=temp->next;
        temp2=temp;
        temp1->next=temp2;
    }
    printf("\n%d is successfully deleted.\n",d_key);

}
void display()
{
    struct movie *current;
    printf("\n\n Code \t Name \t Date \t\t cost \t1st show\t2nd Show \n\n");
    current=start;
    while(current!=NULL)
    {
        printf("%d\t",current->id);
        printf("%s\t",current->name);
        printf("%s\t",current->date);
        printf("%d\t",current->cost);
        printf("%s\t",current->showtime1);
        printf("\t%s\n",current->showtime2);
        current=current->next;
    }
    printf("\n********************************************\n");

}

void book_ticket()
{
    int total_cost;
    int t_seat;
    char phone[25];
    char uname[30];
    int total_seat;
    char showtime[14];
    int i,s_key;
    struct movie *current;
    current=start;
    int pos;
    display();
    printf("Enter the movie code for booking \n");
    scanf("%d",&s_key);
    system("cls");
    pos=search(s_key);
    int cpt;
    if(pos==-1)
    {
        printf("\n%d is not in the movie list.\n",s_key);
    }
    for(i=0; i<pos; i++)
    {
        printf("\n\n Code \t Name \t Date \t\t cost \t1st show\t2nd Show \n\n");
        printf("%d\t",current->id);
        printf("%s\t",current->name);
        printf("%s\t",current->date);
        printf("%d\t",current->cost);
         cpt=current->cost;
         current->seat = t_seat;
        printf("%s\t",current->showtime1);
        printf("\t%s\n",current->showtime2);
        current=current->next;

    }

    printf("\n\n***********************************************\n\n");
    //printf("%d",cpt);



    printf("Please Enter your name \n");
    scanf("%s",uname);
    getchar();

    printf("Please Enter your phone no \n");
    scanf("%s",phone);
    getchar();

    printf("Please Enter when your show time \n");
    scanf("%s",showtime);
     getchar();

    printf("Please Enter how many tickets you want \n");
    scanf("%d",&total_seat);
    getchar();

    if(total_seat<=
       t_seat){

    total_cost = cpt * total_seat;

    printf("***********ENJOY YOUR MOVIE***********");
    printf("\n\nBOOKING INFORMATION\n\n");
    printf("Movie name \n",current->name);
    printf("Buyer Name %s\n",uname);
    printf("Buyer Phone No %s\n",phone);
    printf("Show time %s\n",showtime);
    printf("Total seat %d\n",total_seat);
    printf("Total cost %d\n",total_cost);
    }
    else
    {
        printf("\n\n******Sorry No seat Available !******\n\n ");

    }


}


int main()
{

    printf("\n  ++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++ \n ");
    char name[20];
    char password[10];
    printf("Enter username: ");
    scanf("%s",name);
    getchar();
    printf("Enter password: ");
    scanf("%s",password);
    getchar();
    if (strcmp(name, "admin") == 0 && strcmp(password, "pass") == 0){
    printf("\n\n //// LOGIN SUCCESSFULL //// \n\n");
    int ch;

    do
    {
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf("\t Moive Ticket booking ");
        printf("\n");
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        printf("\nEnter >1< To Insert Movie Information");
        printf("\nEnter >2< To Insert Movie at the middle");
        printf("\nEnter >3< To View All Movie");
        printf("\nEnter >4< To Find Movie ");
        printf("\nEnter >5< To Delete ");
        printf("\nEnter >6< To Book a movie");
        printf("\nEnter >0< To Exit ");

        printf("\nEnter your Choice ::");
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1 :
            create();
            break;
        case 2:
            ma_insert();

            break;

        case 3:
            display();
            count();

            break;

        case 4:
            find();
            break;

        case 5:
             l_delete();
             display();
             count();
            break;

        case 6:
            book_ticket();

            break;


        case 0:
            exit(0);
            break;

        default:
            printf("Wrong choice !");
            break;
        }
    }
    while(ch!=0);
    }
        else printf("***SORRY WRONG PASSWORD***\n");

    return 0;
}

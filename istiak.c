#include<stdio.h>
#include<string.h>
# define null 0
int size=0;
void insert();
void del();
void search();
void modify();
void display();

struct symbtab
{
    char label[10];
    int addr;
    struct symbtab *next;
};
struct symbtab *first,*last;

int main()
{
    int op;
    int y;
    char la[10];
    do
    {
        printf("\nSYMBOL TABLE IMPLEMENTATION\n");
        printf("1. INSERT\n");
        printf("2. DISPLAY\n");
        printf("3. DELETE\n");
        printf("4. SEARCH\n");
        printf("5. MODIFY\n");
        printf("6. END\n");
        printf("Enter your option : ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            del();
            break;
        case 4:
            search();
            break;
        case 5:
            modify();
            break;
        case 6:
            break;
        }
    }
    while(op<6);
}
void insert()
{
    char l[10];
    printf("Enter the label : ");
    scanf("%s",l);
    struct symbtab *p = first;
    while (p != NULL)
    {
        if (strcmp(p->label, l) == 0)
        {
            printf("The label already exists. Duplicate can't be inserted.\n");
            return;
        }
        p = p->next;
    }
    p=(struct symbtab*)malloc(sizeof(struct symbtab));
    strcpy(p->label,l);
    printf("Enter the address : ");
    scanf("%d",&p->addr);

    p->next=null;
    if(size==0)
    {
        first=p;
        last=p;
    }
    else
    {
        last->next=p;
        last=p;
    }
    size++;

}

void search()
{
    printf("Enter your label which you want to search :");
    char l[10];
    scanf("%s",l);
    struct symbtab *p;
    p = first ;
    for(int i = 0; i < size ; i++)
    {
        if(strcmp(p->label,l) == 0)
        {
            printf("Label is found.\n");
            printf("Label is : %s ",p->label);
            printf("Label address is : %d\n\n",p->addr);
            return;
        }
        p = p->next;
    }
    printf("label is not found!\n");
}
void del()
{
    char l[10];
    printf("Enter the label to delete: ");
    scanf("%s",l);
    struct symbtab *p, *previous;
    p = first;
    previous = NULL;
    for(int i = 0 ; i < size; i++)
    {
        if(strcmp(p->label, l) == 0)
        {
            if(previous == NULL)
            {
                first = p->next;
            }
            else
            {
                previous->next = p->next;
            }
            free(p);
            printf("Label %s deleted successfully.\n", l);
            size--;
            return;
        }
        previous = p;
        p = p->next;
    }
    printf("Label %s not found.\n", l);
}
void modify()
{
    struct symbtab *p;
    p = first;

    printf("Write The Old Identify: ");
    char old[10];
    scanf("%s",old);
    for(int i = 0; i < size ; i++)
    {
        if(strcmp(p->label,old) == 0)
        {
            printf("Insert The New label : ");
            char New[10];
            scanf("%s",New);
            strcpy(p->label,New);
            printf("Insert The New Address : ");
            int add;
            scanf("%d",&add);
            p->addr = add;
            return;
        }
        p = p->next;
    }

    printf("You cannot modify because already exits\n");

}
void display()
{
    int i;
    struct symbtab *p;
    p=first;
    printf("LABEL\tADDRESS\n");
    for(i=0; i<size; i++)
    {
        printf("%s\t%d\n",p->label,p->addr);
        p=p->next;
    }

}




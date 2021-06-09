/*By Md. Sakib Shahriar
     ID: 17201122*/

#include <stdio.h>
#include<string.h>

struct product
{
    char name[100];
    int id;
    int price;
    char discription[100];
};

struct product p[100];
int index=0;

int menu()
{

    printf("\nPress 1 to Show All product\n");
    printf("press 2 to Add Product\n");
    printf("Press 3 to Delete Product\n");
    printf("Press 4 to update the info of an existing product\n");
    printf("Press -1 to Exit\n");
}

void addproduct()
{
    printf("Please Enter The Product name: \n");
    fflush(stdin);
    gets(p[index].name);
    printf("Please Enter The product id: \n");
    fflush(stdin);
    scanf("%d",&p[index].id);
    printf("Please Enter The product Price:\n");
    fflush(stdin);
    scanf("%d",&p[index].price);
    printf("Please Enter Description: \n");
    fflush(stdin);
    gets(p[index].discription);

    index++;

}

void deleteproduct()
{
    int i,n;
    int a,count=0;

    printf("Please Enter The Product ID Which You Want To Delete: \n");
    scanf("%d",&a);

    for(i=0; i<index; i++)
    {
        if(p[i].id==a)
        {
            for(i=0; i<index; i++)
            {
                p[i]=p[i+1];
                count=1;
            }
            index--;
        }
    }

    if(count==1)
    {
        printf("\nProduct found & deleted successfully!\n\n");
    }
}

void display()
{
    int i=0;

    if(index==0)
    {
        printf("No Data\n");
    }
    else
    {
        for(i=0; i<index; i++)
        {
            printf("\nProduct Name: %s\n",p[i].name);
            printf("ID: %d\n",p[i].id);
            printf("product Price: %d\n",p[i].price);
            printf("Description: %s\n\n",p[i].discription);
        }
    }
}

void update()
{
    int i,x,n,N;
    char c[100];

    printf("\nEnter the id of the product: ");
    scanf("%d",&x);

    for(i=0; i<index; i++)
    {
        if(p[i].id==x)
        {
            printf("\nProduct found!\n");

            printf("Press 1 for update price\n");
            printf("Press 2 for update description\n");
            printf("Enter your choice: ");

            scanf("%d",&n);
            if(n==1)
            {
                printf("\nEnter new price: ");
                scanf("%d",&N);
                p[i].price=N;
                printf("\nPrice updated successfully!\n");
            }
            if(n==2)
            {
                printf("Enter new description: ");
                fflush(stdin);
                gets(c);
                strcpy(p[i].discription,c);
                printf("\nDescription updated successfully!\n");
            }
        }

        else
            printf("\nProduct not found!\n");

    }
}

int main()
{
    printf("Welcome!!!!!!!\n");
    int n;
    while(1)
    {
        menu();

        printf("Please Enter your choice: ");
        scanf("%d",&n);

        if(n==1)
        {
            display();
        }
        if(n==2)
        {
            addproduct();
        }
        if(n==3)
        {
            deleteproduct();
        }
        if(n==4)
        {
            update();
        }
        if(n==-1)
        {
            printf("\nThank You!\n");
            break;
        }
    }
    return 0;
}

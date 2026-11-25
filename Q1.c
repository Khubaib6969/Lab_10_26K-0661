#include <stdio.h>


int main()
{
    FILE *ptr;

    ptr = fopen("items.txt","w");

    if (ptr == NULL)
    {
        printf("File could not be created");
        return 1;
    }
    else
    {
        fprintf(ptr,"%-4d %-20s %9.2f %5d\n",1,"Rice",250.00,40);
        fprintf(ptr,"%-4d %-20s %9.2f %5d\n",2,"Sugar",160.00,25);
        fprintf(ptr,"%-4d %-20s %9.2f %5d\n",3,"Milk",220.00,30);
        fprintf(ptr,"%-4d %-20s %9.2f %5d\n",4,"CookingOil",560.00,12);
        fprintf(ptr,"%-4d %-20s %9.2f %5d\n",5,"Tea",450.00,18);
    }

    fclose(ptr);

    ptr = fopen("items.txt","rb+");

    if (ptr == NULL)
    {
        printf("File not found!");
        return 1;
    }
    else
    {
        int item_num,quantity,stock;
        char Name[30];
        float price, total=0;

        printf("Enter item num: ");
        scanf("%d",&item_num);
        

        while(item_num != 0)
        {
            printf("Enter quantity: ");
            scanf(" %d",&quantity);
            fseek(ptr, (item_num-1)*42, SEEK_SET);
            fscanf(ptr,"%d %20s %f %d",&item_num,Name,&price,&stock);
            if(stock >= quantity)
            {
                printf("\nBill: %f",quantity *price);
                fseek(ptr, (item_num-1)*42, SEEK_SET);
                fprintf(ptr,"%-4d %-20s %9.2f %5d",item_num,Name,price,stock-quantity);
                total += quantity*price;
            }
            else
            {
                printf("Not enough stock!");
            }
            printf("\nEnter item num: ");
            scanf("%d",&item_num);
            printf("Enter quantity: ");
            scanf(" %d",&quantity);
            
        }
        fclose(ptr);
    } 
}
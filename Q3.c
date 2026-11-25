#include<stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("temperature.txt","w");
    if(ptr == NULL)
    {
        printf("File could not be created!");
        return 1;
    }
    else
    {
        fprintf(ptr,"%-10s %5.1f\n","Karachi",32.5);
        fprintf(ptr,"%-10s %5.1f\n","Lahore",30.1);
        fprintf(ptr,"%-10s %5.1f\n","Islamabad",24.3);
        fprintf(ptr,"%-10s %5.1f\n","Quetta",18.7);
        fprintf(ptr,"%-10s %5.1f\n","Peshawer",28.9);
        fclose(ptr);
    }
    FILE *ptr2;
    ptr2 = fopen("temperature.txt","rb+");
    if (ptr2 == NULL)
    {
        printf("\nFile not found !");
        return 1;
    }
    else
    {
        int cityNum,numHighest;
        float temperature,temp,highest=0.0;
        char Name[20];
        printf("\nEnter City Number: ");
        scanf("%d",&cityNum);
        fseek(ptr2, (cityNum-1)*18,SEEK_SET);
        fscanf(ptr2,"%s %f",Name,&temperature);
        printf("\n%-10s %0.1f",Name,temperature);
        printf("\nEnter city num: ");
        scanf("%d",&cityNum);
        printf("Enter correct temp: ");
        scanf("%f",&temperature);
        fseek(ptr2, (cityNum-1)*18,SEEK_SET);
        fscanf(ptr2, "%s %f",Name,&temp);
        fseek(ptr2, (cityNum-1)*18,SEEK_SET);
        fprintf(ptr2, "%-10s %5.1f",Name,temperature);
        printf("%s updated to %0.1f",Name,temperature);
        char cities[5][20];
        float temperature2[5];
        for(int i = 1;i<=5;i++)
        {
            fseek(ptr2, (i-1)*18,SEEK_SET);
            fscanf(ptr2,"%s %f",cities[i-1],&temperature2[i-1]);
            if(temperature2[i-1]>highest)
            {
                highest = temperature2[i-1];
                numHighest = i;
            }
        }
        fseek(ptr2, (numHighest-1)*18,SEEK_SET);
        fscanf(ptr2, "%s %f",Name,&temperature);
        printf("\nHottest City: %s (%0.1f)",Name,temperature);
    }
    fclose(ptr2);


}
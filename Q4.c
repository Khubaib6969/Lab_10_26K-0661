#include<stdio.h>


void CheckIn(int room, FILE *ptr);
void CheckOut(int room, FILE *ptr);


int main()
{
    FILE *ptr;
    ptr = fopen("Hotel.txt","w");
    if(ptr == NULL)
    {
        printf("File cannot be created!");
        return 1;
    }
    else
    {
        for(int i =0; i<10;i++)
        {
            fprintf(ptr, "%3d %c %-20s %2d %8.2f\n",101+i,'F',"-",0,8000.0);
        }
    }
    fclose(ptr);

    ptr = fopen("Hotel.txt","rb+");
    if(ptr == NULL)
    {
        printf("File not found!");
        return 1;
    }
    else
    {
        int Input=1;
        while(Input == 1)
        {
            
            int roomNum;
            printf("Room: ");
            scanf("%d",&roomNum);
            CheckIn(roomNum, ptr);
            printf("Enter 1 to Check-In again: ");
            scanf("%d",&Input);
        }
        Input = 1;
        while(Input == 1)
        {
            
            int roomNum;
            printf("Room: ");
            scanf("%d",&roomNum);
            CheckOut(roomNum,ptr);
            printf("Enter 1 to Check-Out again: ");
            scanf("%d",&Input);
        }
    }
}

void CheckIn(int room, FILE *ptr)
{
    char guest[20], status;
    int nights, roomNum = room;

    printf("Enter guest name: ");
    scanf("%s",guest);
    printf("Nights: ");
    scanf("%d",&nights);
    fseek(ptr,  (roomNum - 101) * 40, SEEK_SET);
    fscanf(ptr, "%d %c",&roomNum,&status);
    if(status == 'F')
    {
        fseek(ptr,  (roomNum - 101) * 40, SEEK_SET);
        fprintf(ptr, "%3d %c %-20s %2d %8.2f",roomNum,'B',guest,nights,8000.0);
        printf("\nRoom 103 Booked\n");
    }
    else
    {
        printf("\nRoom already booked!\n");
    }
}


void CheckOut(int room, FILE *ptr)
{
    char guest[20], status;
    float price, total;
    int nights, roomNum = room;
    fseek(ptr,  (roomNum - 101) * 40, SEEK_SET);
    fscanf(ptr, "%d %c %20s %d %f",&roomNum,&status,guest,&nights,&price);
    total = price * nights;
    printf("\nTotal: %0.2f\n",total);
}
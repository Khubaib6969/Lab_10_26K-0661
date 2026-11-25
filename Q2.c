#include<stdio.h>


int main()
{
    FILE *ptr;

    ptr = fopen("attendance.txt","w");

    if (ptr == NULL)
    {
        printf("File could not be created");
        return 1;
    }
    else
    {
        fprintf(ptr,"%-3d %-15s %3d\n",1,"Ayesha",18);
        fprintf(ptr,"%-3d %-15s %3d\n",2,"Bilal",14);
        fprintf(ptr,"%-3d %-15s %3d\n",3,"Hamza",20);
        fprintf(ptr,"%-3d %-15s %3d\n",4,"Sana",12);
        fprintf(ptr,"%-3d %-15s %3d\n",5,"Zainab",16);
    }

    fclose(ptr);


    ptr = fopen("attendance.txt","rb+");

    if (ptr == NULL)
    {
        printf("File not found !");
        return 1;
    }
    else
    {
        int rollNum,lectures, Leave;
        char Name[20];
        float percentage;
        printf("Please enter roll number: ");
        scanf("%d",&rollNum);

        fseek(ptr ,(rollNum-1)*25, SEEK_SET);
        fscanf(ptr ,"%d %15s %d",&rollNum,Name,&lectures);
        percentage = (lectures/20.0) * 100;
        printf("\n%s: %d / 20 (%0.1f%%)",Name,lectures,percentage);
        if(percentage<75)
        {
            printf(" Short Attendance\n");
        }
        else
        {
            printf("\n");
        }
        printf("Roll number for leave: ");
        scanf("%d",&rollNum);
        printf("Lectures: ");
        scanf("%d",&Leave);
        
        fseek(ptr ,(rollNum-1)*25, SEEK_SET);
        fscanf(ptr ,"%d %15s %d",&rollNum,Name,&lectures);
        fseek(ptr ,(rollNum-1)*25, SEEK_SET);
        fprintf(ptr,"%-3d %-15s %3d\n",rollNum,Name,lectures+Leave);
        printf("%s: now %d / 20 (%0.1f%%)\n",Name,lectures+Leave,((lectures+Leave)/20.0)*100);
        fseek(ptr, -25, SEEK_END);
        fscanf(ptr ,"%d %15s %d",&rollNum,Name,&lectures);
        printf("Last Record: %d %s %d",rollNum,Name,lectures);
        fclose(ptr);
    }
}
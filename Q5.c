#include <stdio.h>

int main() {
    
    FILE *ptr = fopen("expenses.txt", "wb");
    if (ptr == NULL)
    {
        return 1;
    }
    else
    { 
    fprintf(ptr, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(ptr, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(ptr, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(ptr, "%-12s %9.2f\n", "Mobile", 300.00);
    fclose(ptr);
    }
    
    char category[13];
    float amount;
    printf("Category: ");
    scanf("%12s", category);
    printf("Amount: ");
    scanf("%f", &amount);

    ptr = fopen("expenses.txt", "ab");
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        fprintf(ptr, "%-12s %9.2f\n", category, amount);
        fclose(ptr);
    }
    
    ptr = fopen("expenses.txt", "rb+");
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        char c1[13], c2[13];
        float a1, a2;
        fseek(ptr, -2 * 23, SEEK_END);
        fscanf(ptr, "%12s %f", c1, &a1);
        fscanf(ptr, "%12s %f", c2, &a2);
        printf("Latest two: %s %.2f, %s %.2f\n", c1, a1, c2, a2);
    }
    
    int entryNo;
    float correctAmt;
    printf("Entry to fix: ");
    scanf("%d", &entryNo);
    printf("Correct amount: ");
    scanf("%f", &correctAmt);

    long offset = (long)(entryNo - 1) * 23;
    fseek(ptr, offset, SEEK_SET);
    fscanf(ptr, "%12s %f", category, &amount);

    fseek(ptr, offset, SEEK_SET);
    fprintf(ptr, "%-12s %9.2f\n", category, correctAmt);
    fflush(ptr);

    
    rewind(ptr);
    float total = 0.0f;
    while (fscanf(ptr, "%12s %f", category, &amount) == 2) {
        printf("%s %.2f\n", category, amount);
        total += amount;
    }
    printf("Total: %.2f\n", total);

    fclose(ptr);
    return 0;
}
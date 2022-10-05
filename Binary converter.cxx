#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
void binary(unsigned long long num)
{
    int i = 0, array[1000];
    for (; num != 1 && num != 0; i++)
    {
        array[i] = num % 2;
        num /= 2;
    }
    array[i] = (num == 0) ? array[i] = 0 : array[i] = 1;
    for (; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
}
void bg(char array[10], int c1, int c2){
    textcolor(c1);
    printf("%s",array);
    textcolor(c2);
}
int main()
{
    textbackground(7);
    clrscr();
    textcolor(13);
    char string[10];
    printf("This program can convert positive numbers to binary form and vice-vorsa\n");
    printf("Type ");
    bg("series",12,13);
    printf(" for printing a series of binary numbers\n");
    printf("Type ");
    bg("binary",12,13);
    printf(" for converting decimal to binary\n");
    printf("Type ");
    bg("decimal",12,13);
    printf(" for converting binary to decimal\n");
loop:
    bg("Enter type:",0,1);
    gets(string);
    if (strcmp(string, "series") == 0 || strcmp(string, "Series") == 0)
    {
        unsigned long long ini, fin;
        bg("Enter initial range:",0,1);
        scanf("%llu", &ini);
        bg("Enter final range:",0,1);
        scanf("%llu", &fin);
        bg("Numbers\tBinary forms\n",2,9);
        if (ini > fin)
        {
            for (; ini >= fin; ini--)
            {
                printf("  %llu\t", ini);
                binary(ini);
                printf("\n");
            }
        }
        else
        {
            for (; ini <= fin; ini++)
            {
                printf("  %llu\t", ini);
                binary(ini);
                printf("\n");
            }
        }
        textcolor(0);
    }
    else if (strcmp(string, "binary") == 0 || strcmp(string, "Binary") == 0)
    {
        for (;;)
        {
            unsigned long long num;
            bg("Enter number:",0,1);
            scanf("%llu", &num);
            textcolor(0);
            printf("Binary form of %llu:", num);
            textcolor(9);
            binary(num);
            printf("\n");
        }
        textcolor(0);
    }
    else if (strcmp(string, "decimal") == 0 || strcmp(string, "Decimal") == 0)
    {
        for (;;)
        {
            int check = 0;
            char array[500];
            bg("Enter any binary form:",0,1);
            gets(array);
            for (int i = 0; i < strlen(array); i++)
            {
                if (array[i] == '0' || array[i] == '1')
                    check += 1;
            }
            if (strlen(array) == check)
            {
                int val = 0, power, num;
                for (int i = 1; i <= check; i++)
                {
                    power = pow(2, check - i);
                    num = (array[i - 1] == '1') ? 1 : 0;
                    val += power * num;
                }
                textcolor(0);
                printf("Decimal form of %s: ",array);
                textcolor(9);
                printf("%d\n",val);
                textcolor(0);
            }
            else{
                textcolor(2);
                printf("%s is not a binary form\n", array);
                textcolor(0);
            }
        }
    }
    else
    {
        bg("Please type  series, binary or decimal only\n",2,0);
        goto loop;
    }
}
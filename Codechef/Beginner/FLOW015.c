#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    else
        return false;
}

void printDayOfWeek(int num_odd_days)
{
    switch(num_odd_days)
    {
        case 0: printf("monday\n"); break;
        case 1: printf("tuesday\n"); break;
        case 2: printf("wednesday\n"); break;
        case 3: printf("thursday\n"); break;
        case 4: printf("friday\n"); break;
        case 5: printf("saturday\n"); break;
        case 6: printf("sunday\n"); break;
        // default: printf("monday\n"); 
    }
}

int main()
{
    int t, year, i;
    scanf("%d", &t);
    while(t--)
    {   
        scanf("%d", &year);
        int shift = 2001 - year;
        int num_odd_days = 0;

        if (shift < 0)
        {
            for (i = 2001; i < year; i++)
            {
                if (isLeapYear(i))
                    num_odd_days += 2;
                else
                    num_odd_days++;
            }
        }
        else
        {
            for (i = 2000; i >= year; i--)
            {
                if (isLeapYear(i))
                    num_odd_days -= 2;
                else
                    num_odd_days--;
            }
            
            int temp = ((-1 * num_odd_days) / 7) + 1;
            num_odd_days += (temp * 7);
        }

        num_odd_days %= 7;
        printDayOfWeek(num_odd_days);
    }
    return 0;
}
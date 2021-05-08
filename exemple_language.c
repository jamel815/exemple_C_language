#include <stdio.h>
#include <stdlib.h>

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int day;
    int month;
    int year;
};

int isLeap(int year)
{
    if (year % 400 == 0) return 1;
    if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}

int correctDate(struct Date d)
{
    if (isLeap(d.year))
    {
        if (d.day < 1 || d.day >(daysInMonth[d.month] + 1) || d.month > 12 || d.month < 1 || d.year < 1900)
            return 0;
    }
    else
    {
        if (d.day < 1 || d.day > daysInMonth[d.month] || d.month > 12 || d.month < 1 || d.year < 1900)
            return 0;
    }
    return 1;
}

long numOfDays(struct Date d)
{
    long result = 0;
    
    for (int i = 1; i < d.year; i++)
    {
        if (isLeap(i))
            result += 366;
        else
            result += 365;
    }

    for (int i = 1; i < d.month; i++)
    {
        result += daysInMonth[i];

        if (isLeap(d.year) && i == 2) result++;
    }

    result += d.day;
    return result;
}

int main()
{
    struct Date date;
    struct Date dateDefault = { 1, 1, 1900 };
    char weekdays[7][4] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    if ( scanf_s("%d%d%d", &date.day, &date.month, &date.year ) != 3) {
        puts("Bad input");
        return -1;
    }

    if (correctDate(date) == 0)
    {
        printf("Illegal date!");
        return 0;
    }

    int indexWeekday = (numOfDays(date) - numOfDays(dateDefault)) % 7;

    printf("%s", weekdays[indexWeekday]);
}

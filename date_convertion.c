#include <stdio.h>
#include <stdlib.h>

void Menu();
int DayOfYear(int year, int month, int day);
void MonthDay(int year, int yearDay, int *month, int *day);

static int dayTab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    int year, month, day, yearDay;
    char c;

    Menu();
    c = getchar();

    switch (c) {
        case '1':
            printf("Please enter year, month, day: ");
            scanf("%d %d %d", &year, &month, &day);
            yearDay = DayOfYear(year, month, day);
            printf("yearDay = %d\n", yearDay);
            break;
        case '2':
            printf("Please enter year, yearDay: ");
            scanf("%d %d", &year, &yearDay);
            MonthDay(year, yearDay, &month, &day);
            printf("month = %d, day = %d\n", month, day);
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("Input error!\n");
        break;
    }

    return 0;
}

//功能菜单
void Menu() {
    printf("1. year/month/day -> yearDay\n");
    printf("2. year/yearDay -> month/day\n");
    printf("3. exit\n");
    printf("Please enter your choice: ");
}

//由年月日得出是该年的第几天
int DayOfYear(int year, int month, int day) {
    //int yearDay = 0;//没必要定义这个变量
    int i = 0;
    int leap;

    /*
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        for (i = 0; i < month; i++) {
            yearDay += dayTab[1][i];
        }
    } else {
        yearDay += dayTab[0][i];
    }*/

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 0; i < month; i++) {
        day += dayTab[leap][i];
    }

    //yearDay += day;

    //return yearDay;
    printf("The day is %d\n", day);
    return day;
}

//由一年中的第几天得出几月几日
void MonthDay(int year, int yearDay, int *month, int *day) {
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; yearDay > dayTab[leap][i]; i++) {
        yearDay -= dayTab[leap][i];
    }

    *month = i;
    *day = yearDay;
}

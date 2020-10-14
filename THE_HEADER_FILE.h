#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct date{
    int day, month, year;
};

struct person{
    char name[32];
    struct date tookoffice;
};

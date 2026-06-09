//task4.h
#ifndef TASK4_H
#define TASK4_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//structure
struct User{

    char Name[10];
    char Surname[10];
    int card;
    float balance;

};

//functions
void deposit();
void withdraw();
void balance();
void quit();

#endif

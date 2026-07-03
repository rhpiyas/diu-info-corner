#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100

void login();
void adminMode();
void userMode();
void adminFunc();
void clearScreen();

struct User
{
    char phone[20];
    char email[50];
    char pin[5];
};

struct User admins[5] =
    {
        {"01632725621", "piyas242-35-182@diu.edu.bd", "4466"},
        {"01601793978", "monira242-35-637@diu.edu.bd", "2107"},
        {"01315-500511", "ahmed242-35-580@diu.edu.bd", "7135"},
        {"01303072338", "zihad242-35-435@diu.edu.bd", "4411"},
        {"01853828261", "atikur242-35-632@diu.edu.bd", "2481"}
    };

int isAdmin(char *phone, char *pin)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(phone, admins[i].phone) == 0 &&
            strcmp(pin, admins[i].pin) == 0)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    
    

    return 0;
}
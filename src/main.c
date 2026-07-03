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

void registerUser()
{
    printf("DIU Info Corner > Registration >\n");

    FILE *fp = fopen("users.txt", "a");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    struct User u;
    printf("\n          User Registration\n");
    printf("-------------------------------------\n\n");
    printf("Enter phone number: ");
    scanf("%s", u.phone);
    printf("Enter email: ");
    scanf("%s", u.email);
    printf("Enter 4-digit PIN: ");
    scanf("%s", u.pin);

    fprintf(fp, "%s %s %s\n", u.phone, u.email, u.pin);
    fclose(fp);

    printf("\n---------------------------------------------------\n");
    printf("|    Registration successful! Now Login Please!   |\n");
    printf("---------------------------------------------------\n\n");
    login();
}

int main()
{
    
    

    return 0;
}
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

void login()
{
    printf("DIU Info Corner > Login >\n");
    char phone[20], pin[5];

    printf("\n      Login to DIU Info Corner\n");
    printf("-------------------------------------\n\n");

    printf("Enter phone number: ");
    scanf("%s", phone);
    printf("Enter 4-digit PIN: ");
    scanf("%s", pin);

    if (isAdmin(phone, pin))
    {
        printf("\n------------------------------------\n");
        printf("|    Login successful as Admin!    |\n");
        printf("------------------------------------\n\n");
        clearScreen();
        adminMode();
    }
    else
    {
        FILE *fp = fopen("users.txt", "r");
        if (!fp)
        {
            printf("User Data file is empty!\n\n");
            return;
        }

        struct User u;
        int found = 0;

        while (fscanf(fp, "%s %s %s", u.phone, u.email, u.pin) != EOF)
        {
            if (strcmp(phone, u.phone) == 0 &&
                strcmp(pin, u.pin) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(fp);

        if (found)
        {
            printf("\n---------------------------------------------\n");
            printf("| User login successful! Welcome %s  |\n", phone);
            printf("---------------------------------------------\n\n");
            clearScreen();
            userMode();
        }
        else
        {
            printf("\n-----------------------------------\n");
            printf("|     Incorrect Phone or PIN!     |\n");
            printf("-----------------------------------\n\n");
            clearScreen();
        }
    }
}

void aboutApp()
{
    printf("DIU Info Corner > About this App \n\n");

    printf("App Name      :  DIU Info Corner\n");
    printf("App Version   :  1.0.0(beta)\n\n");
    printf("Developed by  :  Rakib Hasan Piyas  242-35-182\n");
    printf("                 Department of Software Engineering\n");
    printf("                 Batch : SWE 43\n");
    printf("                 Daffodil International University\n\n");

    printf("Disclaimer    :  This app is not an official DIU application.\n");
    printf("                 Data is collected from public sources such as the DIU website,\n");
    printf("                 and the admission office.\n");
    printf("                 For the latest and most accurate updates,\n");
    printf("                 Please contact the DIU Admission Office directly.\n\n");

    clearScreen();
}

void clearScreen()
{
    printf("Press any key to Clear and Continue...\n");
    getch();
    system("cls");
}

void countReg()
{
    printf("\n          Registered User\n");
    printf("-------------------------------------\n\n");

    FILE *fp = fopen("users.txt", "r");
    if (!fp)
    {
        return;
    }

    int count = 0;
    char phone[20], email[50], pin[5];

    while (fscanf(fp, "%s %s %s", phone, email, pin) == 3)
    {
        count++;
    }
    fclose(fp);

    printf("Total Registered Users: %d\n\n", count);
    clearScreen();
}

void userData()
{
    printf("\n          Registration Data\n");
    printf("-------------------------------------\n\n");

    FILE *fp = fopen("users.txt", "r");
    if (!fp)
    {
        printf("\nNo registered users found!\n\n");
        return;
    }

    char phone[20], email[50], pin[5];
    int count = 0;

    while (fscanf(fp, "%s %s %s", phone, email, pin) == 3)
    {
        count++;
        printf("%d. Phone: %s | Email: %s | PIN: %s\n", count, phone, email, pin);
    }
    printf("\n\n");

    if (count == 0)
    {
        printf("\nNo users found!\n\n");
    }

    fclose(fp);
    clearScreen();
}

void updateData()
{
    printf("\n          Update User Data\n");
    printf("-------------------------------------\n\n");

    printf("\a             !!!Sorry!!!\n");
    printf("This Features is corrently Unavailable!\n\n");
    clearScreen();
}

void deleteData()
{
    printf("\n          Delete User Data\n");
    printf("-------------------------------------\n\n");

    printf("\a             !!!Sorry!!!\n");
    printf("This Features is corrently Unavailable!\n\n");
    clearScreen();
}

void updateApp()
{
    printf("\n          Update App Data\n");
    printf("-------------------------------------\n\n");

    printf("1. Update Departemnt Information\n");
    printf("2. Update Seat Information\n");
    printf("3. Update Hall Information\n");
    printf("4. Update Admission Test Date\n\n");

    printf("\a             !!!Sorry!!!\n");
    printf("This Features is corrently Unavailable!\n\n");
    clearScreen();
}

void hallInfo()
{
    int hall;
    while (1)
    {
        printf("DIU Info Corner > Login > User Panel > Hall Info >\n\n");

        printf("\n   Residential Halls at Daffodil International University (DIU)\n");
        printf("-------------------------------------------------------------------\n\n");

        printf("1. Male Hall\n");
        printf("2. Female Hall\n");
        printf("3. <<<Back\n\n");

        printf("Enter Your Choice : ");
        scanf("%d", &hall);
        switch (hall)
        {
        case 1:
        {
            system("cls");

            printf("DIU Info Corner > Login > User Panel > Hall Info > Male\n\n");

            printf("\n           Male Hall\n");
            printf("----------------------------------\n\n");

            printf("1. Yunus Khan Scholar Garden - 1\n");
            printf("        Capacity: 1,600 students\n");
            printf("        Number of Buildings: 2\n");

            printf("2. Yunus Khan Scholar Garden - 2\n");
            printf("        Capacity: 2,000 students\n");
            printf("        Number of Buildings: 2\n");

            printf("3. Yunus Khan Scholar Garden - 3\n");
            printf("        Capacity: 500 students\n");
            printf("        Number of Buildings: 1\n");

            printf("\nHall Fee : BDT. 3,500 per month(Have to pay Semester wise)\n");
            printf("Registration Fee : BDT. 3,000\n\n");
            clearScreen();
            break;
        }
        case 2:
        {
            system("cls");

            printf("DIU Info Corner > Login > User Panel > Hall Info > Female\n\n");

            printf("\n          Female Hall\n");
            printf("----------------------------------\n\n");

            printf("1. Rowshan Ara Scholar Garden - 1\n");
            printf("        Capacity: 1,000 students\n");
            printf("        Number of Buildings: 2\n");

            printf("2. Rowshan Ara Scholar Garden - 2\n");
            printf("        Capacity: 1,200 students\n");
            printf("        Number of Buildings: 1\n");

            printf("\nHall Fee : BDT. 3,500 per month(Have to pay semester wise)\n");
            printf("Registration Fee : BDT. 3,000\n\n");
            clearScreen();
            break;
        }
        case 3:
        {
            system("cls");
            return;
        }
        default:
        {
            printf("\n\aInvalid choice!\n\n");
            clearScreen();
        }
        }
    }
}

void directAdmission()
{
    printf("DIU Info Corner > Login > User Panel > Direct Admission\n\n");

    float ssc, hsc;
    printf("\n    DIU Direct Admission Eligibility Checker\n");
    printf("----------------------------------------------------\n\n");
    printf("Enter SSC GPA: ");
    scanf("%f", &ssc);
    printf("Enter HSC GPA: ");
    scanf("%f", &hsc);

    if (ssc >= 4.5f && hsc >= 4.5f)
    {
        printf("\nCongratulations!!!  You are Eligle for DIRECT ADMISSION.\n");
        printf("Note: University may still verify subject requirements and make final decision.\n\n");
        clearScreen();
    }
    else
    {
        printf("\nResult: You do NOT meet the 4.5+ GPA criteria in both SSC and HSC!.\n");
        printf("       => You are likely required to sit the DIU admission test.\n");
        printf("For more Information, Please select Admission Test Info from User Panel!\n\n");
        clearScreen();
    }
}

int main()
{
    
    

    return 0;
}
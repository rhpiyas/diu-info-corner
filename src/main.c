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

void admissionTest()
{
    printf("DIU Info Corner > Login > User Panel > Admission Test Info\n\n");

    printf("\n      Admission Test Information\n");
    printf("-------------------------------------\n\n");

    printf("Note: Admission test dates are subject to change.\n");
    printf("For the most accurate and updated schedule,\n");
    printf("Please contact the Admission Office directly.\n\n");
    printf("Admission Office Phone Numbers:\n");
    printf("1. +8801713493050   counselor@daffodilvarsity.edu.bd\n");
    printf("2. +8801713493051   counselor3@daffodilvarsity.edu.bd\n");
    printf("3. +8801847140017   counselor1@daffodilvarsity.edu.bd\n\n");

    printf("Admission Helpline: +8809617901212\n");
    printf("Email: admission@daffodilvarsity.edu.bd\n\n");

    clearScreen();
}

void help()
{
    printf("DIU Info Corner > Login > User Panel > Help and Support\n\n");

    printf("\n          Help and Support\n");
    printf("-------------------------------------\n\n");

    printf("For any kind of help,\n");
    printf("     Please contact with the Admin Team.\n\n");
    printf("Admin Contact List:\n");
    printf("1. Rakib Hasan Piyas - 01632725621\n");

    printf("We are always ready to help you!\n\n");
    clearScreen();
}

void deptinfo()
{
    int choice;

    while (1)
    {
        printf("DIU Info Corner > Login > User Panel > Dept Info\n\n");

        printf("\n        Department Information\n");
        printf("-------------------------------------\n\n");

        printf("Available Information for Department of :\n");
        printf("1. CSE       2. SWE      3. CIS\n");
        printf("4. EEE       5. Civil    6. BBA\n");
        printf("7. Pharmacy  8. NFE      9. LAW\n");
        printf("10. B.Arch.  11. TE      12. MCT\n");
        printf("13. English  14. JMC     15. ESDM\n");
        printf("16. <<<Back\n");
        printf("\nMore Department will be added soon!\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > CSE\n\n");
            printf("\n  B. Sc. in Computer Science and Engineering.(CSE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 154.5\n");
            printf("Admission Fees    : 51,867 BDT\n");
            printf("Semester Cost     : 75,000 BDT\n");
            printf("Total Cost        : 9,31,800 BDT\n\n");

            clearScreen();
            break;

        case 2:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > SWE\n\n");
            printf("\n         B. Sc. in Software Engineering.(SWE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 145\n");
            printf("Admission Fees    : 51,867 BDT\n");
            printf("Semester Cost     : 70,000 BDT\n");
            printf("Total Cost        : 8,71,200 BDT\n\n");

            clearScreen();
            break;
        case 3:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > CIS\n\n");
            printf("\n   B. Sc. in Computing and Information System.(CIS)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 142\n");
            printf("Admission Fees    : 50,667 BDT\n");
            printf("Semester Cost     : 58,000 BDT\n");
            printf("Total Cost        : 7,12,500 BDT\n\n");

            clearScreen();
            break;
        case 4:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > EEE\n\n");
            printf("\nB. Sc. in Electrical and Electronic Engineering.(EEE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 8\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 144\n");
            printf("Admission Fees    : 58,400 BDT\n");
            printf("Semester Cost     : 92,000 BDT\n");
            printf("Total Cost        : 7,63,200 BDT\n\n");

            clearScreen();
            break;
        case 5:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > CIVIL\n\n");
            printf("\n          B. Sc. in Civil Engineering.(CE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 8\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 147\n");
            printf("Admission Fees    : 59,000 BDT\n");
            printf("Semester Cost     : 91,000 BDT\n");
            printf("Total Cost        : 7,53,075 BDT\n\n");

            clearScreen();
            break;
        case 6:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > BBA\n\n");
            printf("\n      Bachelor of Business Administration.(BBA)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 130\n");
            printf("Admission Fees    : 56,450 BDT\n");
            printf("Semester Cost     : 60,000 BDT\n");
            printf("Total Cost        : 7,43,200 BDT\n\n");

            clearScreen();
            break;
        case 7:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > PHARMACY\n\n");
            printf("\n           Bachelor of Pharmacy.(B. Pharm)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 8\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 160\n");
            printf("Admission Fees    : 66,000 BDT\n");
            printf("Semester Cost     : 1,22,500 BDT\n");
            printf("Total Cost        : 10,08,200 BDT\n\n");

            clearScreen();
            break;
        case 8:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > NFE\n\n");
            printf("\n   Bachelor of Nutrition and Food Engineering.(NFE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 151\n");
            printf("Admission Fees    : 49,200 BDT\n");
            printf("Semester Cost     : 50,000 BDT\n");
            printf("Total Cost        : 6,20,450 BDT\n\n");

            clearScreen();
            break;
        case 9:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > LAW\n\n");
            printf("\n                    LL.B. (Hons.)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 144\n");
            printf("Admission Fees    : 1,30,000 BDT\n");
            printf("Semester Cost     : 1,04,000 BDT\n");
            printf("Total Cost        : 8,54,200 BDT\n\n");

            clearScreen();
            break;

        case 10:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > B. Arch.\n\n");
            printf("\n         Bachelor of Architecture (B. Arch.)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 5 Years\n");
            printf("Total Semesters   : 10\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 194\n");
            printf("Admission Fees    : 55,100 BDT\n");
            printf("Semester Cost     : 85,000 BDT\n");
            printf("Total Cost        : 8,72,700 BDT\n\n");

            clearScreen();
            break;

        case 11:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > TE\n\n");
            printf("\n          B.Sc. in Textile Engineering (TE)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 8\n");
            printf("Semester Type     : Bi-semester\n");
            printf("Credit Hours      : 154\n");
            printf("Admission Fees    : 59,200 BDT\n");
            printf("Semester Cost     : 85,000 BDT\n");
            printf("Total Cost        : 7,04,200 BDT\n\n");

            clearScreen();
            break;

        case 12:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > MCT\n\n");
            printf("\n   B.Sc. in Multimedia & Creative Technology (MCT)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 147\n");
            printf("Admission Fees    : 50,467 BDT\n");
            printf("Semester Cost     : 55,000 BDT\n");
            printf("Total Cost        : 6,83,850 BDT\n\n");

            clearScreen();
            break;

        case 13:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > English\n\n");
            printf("\n               B.A. (Hons) in English\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 130\n");
            printf("Admission Fees    : 52,000 BDT\n");
            printf("Semester Cost     : 50,000 BDT\n");
            printf("Total Cost        : 6,20,000 BDT\n\n");

            clearScreen();
            break;

        case 14:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > JMC\n\n");
            printf("\n   BSS in Journalism, Media and Communication (JMC)\n");
            printf("-----------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 142\n");
            printf("Admission Fees    : 52,067 BDT\n");
            printf("Semester Cost     : 45,000 BDT\n");
            printf("Total Cost        : 5,53,600 BDT\n\n");

            clearScreen();
            break;

        case 15:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Dept Info > ESDM\n\n");
            printf("\n  B.Sc. in Environmental Science and Disaster Management (ESDM)\n");
            printf("-----------------------------------------------------------------\n\n");

            printf("Program Duration  : 4 Years\n");
            printf("Total Semesters   : 12\n");
            printf("Semester Type     : Tri-semester\n");
            printf("Credit Hours      : 146\n");
            printf("Admission Fees    : 46,867 BDT\n");
            printf("Semester Cost     : 44,000 BDT\n");
            printf("Total Cost        : 5,51,200 BDT\n\n");

            clearScreen();
            break;

        case 16:
            system("cls");
            return;

        default:
            printf("\n\a<<<Invalid choice!>>>\n\n");
            clearScreen();
        }
    }
}

void seat()
{
    printf("DIU Info Corner > Login > User Panel > Total Seat\n\n");

    printf("\n       Total Seat per Departemnt\n");
    printf("-------------------------------------\n\n");

    printf("CSE      : Total Seat 800\n");
    printf("SWE      : Total Seat 600\n");
    printf("CIS      : Total Seat 100\n");
    printf("EEE      : Total Seat 400\n");
    printf("CIVIL    : Total Seat 400\n");
    printf("BBA      : Total Seat 300\n");
    printf("PHARMACY : Total Seat 100\n");
    printf("NFE      : Total Seat 400\n");
    printf("LAW      : Total Seat 100\n");
    printf("B. Arch  : Total Seat 70\n");
    printf("TE       : Total Seat 300\n");
    printf("MCT      : Total Seat 50\n");
    printf("English  : Total Seat 300\n");
    printf("JMC      : Total Seat 50\n");
    printf("ESDM     : Total Seat 100\n\n");

    printf("Each section consists of 50 students.\n");
    printf("Note: Seat numbers are approximate and may change.\n\n\n");
    clearScreen();
}

void waiver()
{
    int choice;
    while (1)
    {
        printf("DIU Info Corner > Login > User Panel > Waiver >\n\n");

        printf("\n           Waiver Category\n");
        printf("-------------------------------------\n\n");

        printf("1. Result-Based Waiver (SSC and HSC)\n");
        printf("2. CGPA-Based Waiver\n");
        printf("3. <<<Back\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Waiver > Result-Based\n\n");

            printf("\n         Result-Based Waiver\n");
            printf("-------------------------------------\n\n");

            printf("RESULT-BASED WAIVER (SSC AND HSC/UNDER GRADUATE)\n");
            printf("DIU offers the tuition fee waiver for the students on the basis of their results\n");
            printf("in SSC & HSC or equivalent exam including fourth subject in the following categories:\n\n");

            printf("Qualification                                 Waiver     Min CGPA\n");
            printf("---------------------------------------      --------   ----------\n");
            printf("Golden GPA-5 both in SSC and in HSC           75%%       3.50\n");
            printf("Golden GPA-5 in HSC                           50%%       3.25\n");
            printf("GPA-5 both in SSC and in HSC                  35%%       3.25\n");
            printf("GPA-5 in HSC                                  25%%       3.00\n");
            printf("4.90-4.99 in HSC                              20%%       3.00\n");
            printf("4.75-4.89 in HSC                              10%%       3.00\n");
            printf("Below 4.75 in HSC                              0%%       0.00\n\n");

            clearScreen();
            break;
        case 2:
            system("cls");
            printf("DIU Info Corner > Login > User Panel > Waiver > CGPA-Based\n\n");

            printf("\n          CGPA-Based Waiver\n");
            printf("-------------------------------------\n\n");

            printf("CGPA-BASED WAIVER (DIU)\n");
            printf("Tuition fee waiver for current students based on CGPA:\n\n");

            printf("CGPA Range                         Waiver\n");
            printf("-----------------                 --------\n");
            printf("4.00                               50%%\n");
            printf("3.90 - 3.99                        30%%\n");
            printf("3.85 - 3.89                        20%%\n");
            printf("3.80 - 3.84                        10%%\n");
            printf("Below 3.80                          0%%\n\n");

            clearScreen();
            break;
        case 3:
            system("cls");
            return;
        default:
            printf("\n\aInvalid choice!\n\n");
            clearScreen();
        }
    }
}

void adminMode()
{
    int mood;
    while (1)
    {
        printf("DIU Info Corner > Login > Admin Mood >\n\n");

        printf("\n            Welcome Admin!\n");
        printf("-------------------------------------\n\n");

        printf("You can use DIU Info Corner as a Normal User.\n");
        printf("You have the Access of Admin Mood!\n\n");

        printf("1. User Panel\n");
        printf("2. Admin Panel\n");
        printf("3. Logout\n\n");

        printf("Enter Mood: ");
        scanf("%d", &mood);

        switch (mood)
        {
        case 1:
            system("cls");
            userMode();
            break;
        case 2:
            system("cls");
            adminFunc();
            break;
        case 3:
            printf("Are you sure to Log Out???\n");
            clearScreen();
            return;
        default:
            printf("\n\a<<<Invalid choice!>>>\n\n");
            clearScreen();
        }
    }
}

void adminFunc()
{
    int choice;
    while (1)
    {
        printf("DIU Info Corner > Login > Admin Mood > Admin Panel > \n\n");

        printf("\n       Welcome to Admin Panel!\n");
        printf("-------------------------------------\n\n");

        printf("1. View Total Registered Users\n");
        printf("2. View All User Registration Data\n");
        printf("3. Update User Data\n");
        printf("4. Delete User Data\n");
        printf("5. Update App Data (Dept. info, hall info etc.)\n");
        printf("6. Exit Admin Panel\n\n");

        printf("Enter Menu: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("DIU Info Corner > Login > Admin Mood > Admin Panel > Total Users\n\n");
            countReg();
            break;
        case 2:
            system("cls");
            printf("DIU Info Corner > Login > Admin Mood > Admin Panel > User Data\n\n");
            userData();
            break;
        case 3:
            system("cls");
            printf("DIU Info Corner > Login > Admin Mood > Admin Panel > Update Data\n\n");
            updateData();
            break;
        case 4:
            system("cls");
            printf("DIU Info Corner > Login > Admin Mood > Admin Panel > Delete Data\n\n");
            deleteData();
            break;
        case 5:
            system("cls");
            printf("DIU Info Corner > Login > Admin Mood > Admin Panel > Update App\n\n");
            updateApp();
            break;
        case 6:
            system("cls");
            return;
        default:
            printf("\n\a<<<Invalid choice!>>>\n\n");
            clearScreen();
        }
    }
}

void userMode()
{
    int choice;
    while (1)
    {
        printf("DIU Info Corner > Login > User Panel > \n\n");
        printf("\n       Welcome to User Panel!\n");
        printf("-------------------------------------\n\n");

        printf("1. View Departemnt Info\n");
        printf("2. View Totol Seat per Departemnt\n");
        printf("3. View Waiver\n");
        printf("4. Check Direct Admission Eligibility\n");
        printf("5. View Admission Test Info\n");
        printf("6. View Hall Info\n");
        printf("7. Help and Support\n");
        printf("8. Logout User Panel\n\n");

        printf("Enter Menu: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            deptinfo();
            break;
        case 2:
            system("cls");
            seat();
            break;
        case 3:
            system("cls");
            waiver();
            break;
        case 4:
            system("cls");
            directAdmission();
            break;
        case 5:
            system("cls");
            admissionTest();
            break;
        case 6:
            system("cls");
            hallInfo();
            break;
        case 7:
            system("cls");
            help();
            break;
        case 8:
            system("cls");
            return;
        default:
            printf("\n\a<<<Invalid choice!>>>\n\n");
            clearScreen();
        }
    }
}



int main()
{
    
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[10], rollno[10], dob[10], father[10], mother[10];
    int class, maths, social, hindi, physics, chemistry, bio, science, english;
    struct student *next;
};

struct student *temp1;

struct student *topid8;
struct student *topid9;
struct student *topid10;

struct student *top8;
struct student *top9;
struct student *top10;

struct student *create(char name[], char rollno[], int class)
{
    struct student *newnode = (struct student *)calloc(1,sizeof(struct student));
    strcpy(newnode->name, name);
    strcpy(newnode->rollno, rollno);
    newnode->class = class;
    if (class == 8)
    {
        if (top8 == NULL)
        {
            top8 = newnode;
            topid8 = newnode;
            newnode->next = NULL;
            return top8;
        }
        else
        {
            top8->next = newnode;
            top8 = newnode;
            top8->next = NULL;
            return top8;
        }
    }
    else if (class == 9)
    {
        if (top9 == NULL)
        {
            top9 = newnode;
            topid9 = newnode;
            newnode->next = NULL;
            return top9;
        }
        else
        {
            top9->next = newnode;
            top9 = newnode;
            top9->next = NULL;
            return top9;
        }
    }
    else if (class == 10)
    {

        if (top10 == NULL)
        {
            top10 = newnode;
            topid10 = newnode;
            newnode->next = NULL;
            return top10;
        }
        else
        {
            top10->next = newnode;
            top10 = newnode;
            top10->next = NULL;
            return top10;
        }
    }
}

void display(int class)
{
    struct student *temp1 = topid8;

    int i = 1;
    if (class == 8)
    {
        printf("\nStudent Details of class 8th\n");
        printf("==============================\n");

        printf("Slno\tName\tRollNo\tMaths\tSocial\tHindi\tScience\tEnglish\tTotalMarks\n");
        printf("----\t----\t------\t-----\t------\t-----\t-------\t-------\t----------\n");

        while (temp1 != NULL)
        {
            printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", i, temp1->name, temp1->rollno, temp1->maths, temp1->social, temp1->hindi, temp1->science, temp1->english, (temp1->hindi + temp1->english + temp1->maths + temp1->social + temp1->science));
            temp1 = temp1->next;
            i++;
        }
    }
    else if (class == 9 || class == 10)
    {
        if (class == 9)
        {
            printf("\nStudent Details of class 9th\n");
            temp1 = topid9; // Assign the correct pointer based on class
        }
        else
        {
            printf("\nStudent Details of class 10th\n");
            temp1 = topid10; // Assign the correct pointer based on class
        }
        printf("===================================================================================\n");
        printf("Slno\tName\tRollNo\tEnglish\tMaths\tSocial\tHindi\tPhysics\tChemistry   Biology   TotalMarks\n");
        printf("----\t----\t------\t-------\t-----\t------\t-----\t-------\t---------   -------   -----------\n");

        while (temp1 != NULL)
        {
            printf("  %d\t%s\t  %s\t  %d\t  %d\t  %d\t  %d\t  %d\t    %d\t       %d\t   %d\n",
                   i, temp1->name, temp1->rollno, temp1->english,
                   temp1->maths, temp1->social,
                   temp1->hindi, temp1->physics,
                   temp1->chemistry, temp1->bio,
                   (temp1->maths + temp1->social + temp1->hindi + temp1->english + temp1->physics + temp1->chemistry + temp1->bio));

            temp1 = temp1->next;
            i++;
        }
    }
}

void subject(struct student *newnode, int class)
{
    int hindi, english, mathematics, social, science, physics, chemistry;
    printf("enter marks in Hindi ");
    scanf("%d", &hindi);
    newnode->hindi = hindi;
    printf("enter marks in English ");
    scanf("%d", &english);
    newnode->english = english;
    printf("enter marks in Mathematics ");
    scanf("%d", &mathematics);
    newnode->maths = mathematics;
    printf("enter marks in Social Science ");
    scanf("%d", &social);
    newnode->social = social;
    if (class == 8)
    {
        printf("enter marks in Science ");
        scanf("%d", &science);
        newnode->science = science;
    }
    else if (class == 9 || class == 10)
    {
        printf("enter marks in physics ");
        scanf("%d", &physics);
        newnode->physics = physics;
        printf("enter marks in chemistry ");
        scanf("%d", &chemistry);
        newnode->chemistry = chemistry;
        printf("enter marks in Social Science ");
        scanf("%d", &social);
    }
}

void delete(int class, char rollno[])
{
    struct student *temp1;
    struct student *temp2 = NULL;
    if (class == 8)
    {
        temp1 = topid8;
    }
    else if (class == 9)
    {
        temp1 = topid9;
    }
    else if (class == 10)
    {
        temp1 = topid10;
    }
    else
    {
        printf("Invalid class\n");
        return;
    }

    while (temp1 != NULL && strcmp(temp1->rollno, rollno) != 0)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL)
    {
        printf("Student with roll number %s not found\n", rollno);
        return;
    }

    if (temp1->next == NULL && temp2 == NULL)
    {
        if (class == 8)
        {
            topid8 = NULL;
            top8 = NULL;
        }
        else if (class == 9)
        {
            top9 = NULL;
            topid9 = NULL;
        }
        else if (class == 10)
        {
            top10 = NULL;
            topid10 = NULL;
        }
    }

    if (temp2 == NULL)
    {
        if (class == 8)
        {
            topid8 = temp1->next;
        }
        else if (class == 9)
        {
            topid9 = temp1->next;
        }
        else if (class == 10)
        {
            topid10 = temp1->next;
        }
    }
    else
    {
        temp2->next = temp1->next;
    }

    printf("Deleted student with roll number %s\n", rollno);
    free(temp1);
}

void updatedetail(struct student *newnode, int op, char data[])
{
    if (op == 3)
    {
        strcpy(newnode->name, data);
    }
    else if (op == 4)
    {
        strcpy(newnode->rollno, data);
    }
    else
    {
        strcpy(newnode->name, data);
        strcpy(newnode->rollno, data);
    }
}

void update(struct student *newnode, int op, int subject, int class)
{
    if (op == 5)
    {
        newnode->maths = subject;
    }
    else if (op == 6)
    {
        newnode->social = subject;
    }
    else if (op == 7)
    {
        newnode->hindi = subject;
    }
    else if (op == 8)
    {
        newnode->english = subject;
    }
    if (class == 8 && op == 9)
    {
        newnode->science = subject;
    }
    else if (class == 9 || class == 10 && op == 0)
    {

        newnode->physics = subject;
    }
    else if (op == 10)
    {
        newnode->chemistry = subject;
    }
    else if (op == 11)
    {
        newnode->bio = subject;
    }
}
void updateall(struct student *newnode, int class)
{
    printf("enter name ");
    scanf("%s", newnode->name);
    printf("enter rollno ");
    scanf("%s", newnode->rollno);
    subject(newnode, class);
}
struct student *find(int class, char rollno[])
{
    if (class == 8)
    {
        temp1 = topid8;
    }
    else if (class == 9)
    {
        temp1 = topid9;
    }
    else if (class == 10)
    {
        temp1 = topid10;
    }
    while (temp1 != NULL)
    {
        if (strcmp(temp1->rollno, rollno) == 0)
        {
            return temp1;
        }
        temp1 = temp1->next;
    }
    return NULL;
}
void writedata()
{
    FILE *testfile;
    int i;
    if (topid8 != NULL)
    {
        testfile = fopen("output8.txt", "w");
        fprintf(testfile, "Slno\tName\tRollNo\tMaths\tSocial\tHindi\tScience\tEnglish\tTotalMarks\n");
        temp1 = topid8;
        i = 1;
        while (temp1->name != NULL)
        {
            fprintf(testfile, "  %d\t %s\t  %s\t  %d\t      %d\t     %d\t      %d\t      %d\t       %d\n", i, temp1->name, temp1->rollno, temp1->maths, temp1->social, temp1->hindi, temp1->science, temp1->english, (temp1->hindi + temp1->english + temp1->maths + temp1->social + temp1->science));
            temp1 = temp1->next;
            i++;
        }
        fclose(testfile);
    }

    if (topid9 != NULL)
    {
        testfile = fopen("output9.txt", "w");
        fprintf(testfile, "Slno\tName\tRollNo\tEnglish\tMaths\tSocial\tHindi\tPhysics\tChemistry\tBiology\tTotalMarks\n");
        temp1 = topid9;
        i = 1;
        while (temp1->name != NULL)
        {
            fprintf(testfile, "  %d\t    %s\t  %s\t   %d\t  %d\t      %d\t      %d\t       %d\t   %d\t       %d\t    %d\n", i, temp1->name, temp1->rollno, temp1->english, temp1->maths, temp1->social, temp1->hindi, temp1->physics, temp1->chemistry, temp1->bio, (temp1->maths + temp1->social + temp1->hindi + temp1->english + temp1->physics + temp1->chemistry + temp1->bio));
            temp1 = temp1->next;
            i++;
        }
        fclose(testfile);
    }

    if (topid10 != NULL)
    {
        testfile = fopen("output10.txt", "w");
        fprintf(testfile, "Slno\tName\tRollNo\tEnglish\tMaths\tSocial\tHindi\tPhysics\tChemistry\tBiology\tTotalMarks\n");
        temp1 = topid10;
        i = 1;
        while (temp1->name != NULL)
        {
            fprintf(testfile, "  %d\t    %s\t  %s\t   %d\t  %d\t      %d\t      %d\t       %d\t   %d\t       %d\t    %d\n", i, temp1->name, temp1->rollno, temp1->english, temp1->maths, temp1->social, temp1->hindi, temp1->physics, temp1->chemistry, temp1->bio, (temp1->maths + temp1->social + temp1->hindi + temp1->english + temp1->physics + temp1->chemistry + temp1->bio));
            temp1 = temp1->next;
            i++;
        }
        fclose(testfile);
    }
    printf("exit..");
    exit(0);
}
void readsub8(int maths, int social, int hindi, int science, int english, struct student *newnode)
{
    newnode->english = english;
    newnode->social = social;
    newnode->science = science;
    newnode->maths = maths;
    newnode->hindi = hindi;
}
void readsub9and10(int english, int maths, int social, int hindi, int physics, int chemistry, int bio, struct student *newnode)
{
    newnode->english = english;
    newnode->social = social;
    newnode->physics = physics;
    newnode->chemistry = chemistry;
    newnode->bio = bio;
    newnode->maths = maths;
    newnode->hindi = hindi;
}
void read()
{
    FILE *check = fopen("output8.txt", "r");
    if (check)
    {
        char line[100], name[20], rollno[20];
        int maths, social, total, hindi, science, english;
        fgets(line, sizeof(line), check);
        while (fgets(line, sizeof(line), check))
        {
            if (sscanf(line, "%*d %49s %19s %d %d %d %d %d %d", name, rollno, &maths, &social, &hindi, &science, &english, &total) == 8)
            {
                struct student *address = create(name, rollno, 8);
                readsub8(maths, social, hindi, science, english, address);
            }
        }
    }
    check = fopen("output9.txt", "r");
    if (check)
    {
        char line[100], name[20], rollno[20];
        int maths, social, total, hindi, english, physics, chemistry, bio;
        fgets(line, sizeof(line), check);
        while (fgets(line, sizeof(line), check))
        {
            if (sscanf(line, "%*d %49s %19s %d %d %d %d %d %d %d %d", name, rollno, &english, &maths, &social, &hindi, &physics, &chemistry, &bio, &total) == 10)
            {
                struct student *address = create(name, rollno, 9);
                readsub9and10(english, maths, social, hindi, physics, chemistry, bio, address);
            }
        }
    }
    check = fopen("output10.txt", "r");
    if (check)
    {
        char line[100], name[20], rollno[20];
        int maths, social, total, hindi, english, physics, chemistry, bio;
        fgets(line, sizeof(line), check);
        while (fgets(line, sizeof(line), check))
        {
            if (sscanf(line, "%*d %49s %19s %d %d %d %d %d %d %d %d", name, rollno, &english, &maths, &social, &hindi, &physics, &chemistry, &bio, &total) == 10)
            {
                struct student *address = create(name, rollno, 10);
                readsub9and10(english, maths, social, hindi, physics, chemistry, bio, address);
            }
        }
    }
}
void certificate(int class, char rollno[])
{
    int total;
    struct student *node = find(class, rollno);
    printf("\n------------------------------------------------------------------------------------\n");
    printf("|                  KARNATAKA BOARD HIGH SCHOOL CERTIFICATE EXAMINATION                     |\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|Your name: %s\tclass: %dth\tRoll Number: %s\n", node->name, node->class, node->rollno);
    printf("|Father name: %s\n");
    printf("|Mother name: %s\n");
    printf("|Date of birth: %s\n");
    printf("|School name: %s\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tSUBJECTS      \tMAX MARKS\tMIN MARKS\tTHEORY MARKS\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tHINDI         \t  100      \t   33       \t    %d\n", node->hindi);
    printf("|\tENGLISH       \t  100      \t   33       \t    %d\n", node->english);
    printf("|\tMATHEMATICS   \t  100      \t   33       \t    %d\n", node->maths);
    printf("|\tSOCIAL SCIENCE\t  100      \t   33       \t    %d\n", node->social);
    if(class==8){
    printf("|\tSCIENCE       \t  100      \t   33       \t    %d\n", node->science);
     total = (node->hindi + node->english + node->maths + node->social+node->science);
    }else if(class==9 || class==10){
     total = (node->hindi + node->english + node->maths + node->social+node->physics+node->bio+node->chemistry);
    printf("|\tPHYSICS       \t  100      \t   33       \t    %d\n", node->science);
    printf("|\tCHEMISTRY       \t  100      \t   33       \t    %d\n", node->science);
    printf("|\tBIOLOGY       \t  100      \t   33       \t    %d\n", node->science);
    }
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\t              \t  600    |    GRAND TOTAL\t    %d\n", total);
    printf("|------------------------------------------------------------------------------------\n");
    if ((total / 6) >= 81 && (total / 6) <= 100)
    {
        printf("|RESULT : PASS IN FIRST DIVISION\n");
        printf("|GRADE  : A+\n");
    }
    if ((total / 6) >= 60 && (total / 6) <= 80)
    {
        printf("|RESULT : PASS IN FIRST DIVISION\n");
        printf("|GRADE  : A\n");
    }
    else if ((total / 6) >= 41 && (total / 6) <= 59)
    {
        printf("|RESULT : PASS IN SECOND DIVISION\n");
        printf("|GRADE  : B\n");
    }
    else if ((total / 6) >= 31 && (total / 6) <= 40)
    {
        printf("|RESULT : PASS IN THIRD DIVISION\n");
        printf("|GRADE  : C\n");
    }
    else if ((total / 6) >= 1 && (total / 6) <= 30)
    {
        printf("|RESULT : Fail\n");
        printf("|GRADE  : D\n");
    }
    printf("|------------------------------------------------------------------------------------\n\n");
}
void main()
{
    read();
    struct student *address;
    while (1)
    {
        printf("\nOperations\n1.create\n2.delete\n3.display\n4.update\n5.Student Cirtificate\n6.exit\n");
        int op, class, maths, social, english, science, hindi;
        char name[10], rollno[10], yn;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("enter name\n");
            scanf("%s", name);
            printf("enter rollno\n");
            scanf("%s", rollno);
            printf("enter class\n");
            scanf("%d", &class);
            address = create(name, rollno, class);
            printf("enter the marks now ? (y,n)");
            scanf("%c", &yn);
            scanf("%c", &yn);
            if (yn == 'y' || yn == 'Y')
            {
                subject(address, class);
            }
            break;
        case 2:
            printf("enter strudent rollno and class");
            scanf("%s%d", rollno, &class);
            delete (class, rollno);
            break;
        case 3:
            printf("enter class\n");
            scanf("%d", &class);
            display(class);
            break;
        case 4:
            printf("enter the class and rollno");
            scanf("%d%s", &class, rollno);
            address = find(class, rollno);
            if (class == 8 || class == 9 || class == 10)
            {

                printf("what would u like to update\n1.update all details\n2.update all subject marks\n3.update Name\n4.update RollNo\n5.update marks in Maths\n6.update marks in Social\n7.update marks in Hindi\n8.update marks in English");
                if (class == 8)
                {
                    printf("\n9.update marks in Science\n");
                }
                else if (class == 9 || class == 10)
                {
                    printf("\n9.update marks in Physics\n10.update marks in Chemistry\n11.update marks in Biology\n");
                }
                scanf("%d", &op);
                switch (op)
                {
                case 1:
                    updateall(address, class);
                    break;
                case 2:
                    subject(address, class);
                    break;
                case 3:
                    printf("enter name\n");
                    scanf("%s", name);
                    updatedetail(address, op, name);
                    break;
                case 4:
                    printf("enter rollno\n");
                    scanf("%s", rollno);
                    updatedetail(address, op, rollno);
                    break;
                case 5:
                    printf("enter marks in Maths ");
                    scanf("%d", &maths);
                    update(address, op, maths, class);
                    break;
                case 6:
                    printf("enter marks in Social ");
                    scanf("%d", &social);
                    update(address, op, social, class);
                    break;
                case 7:
                    printf("enter marks in Hindi ");
                    scanf("%d", &hindi);
                    update(address, op, hindi, class);
                    break;
                case 8:
                    printf("enter marks in English ");
                    scanf("%d", &english);
                    update(address, op, english, class);
                    break;
                case 9:
                    if (class == 8)
                    {
                        printf("enter marks in Science ");
                        scanf("%d", &science);
                        update(address, op, science, class);
                    }
                    else if (class == 9 || class == 10)
                    {
                        printf("enter marks in Physics ");
                        scanf("%d", &science);
                        update(address, op, science, class);
                    }
                    break;
                case 10:
                    printf("enter marks in Chemistry ");
                    scanf("%d", &english);
                    update(address, op, english, class);
                    break;
                case 11:
                    printf("enter marks in Biology ");
                    scanf("%d", &english);
                    update(address, op, english, class);
                    break;
                default:
                }
            }
            else
            {
                printf("invalid class or rollno");
            }
            break;
            break;
        case 5:
            printf("enter class and rollno : ");
            scanf("%d%s", &class, rollno);
            certificate(class, rollno);
            break;
        case 6:
            writedata();
        default:
            break;
        }
    }
}

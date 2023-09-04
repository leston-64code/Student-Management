#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[10],rollno[10],father[10],mother[10];
    int class, maths, social, hindi, physics, chemistry, bio, science, english;
    struct student *next;
};


struct student *root8;
struct student *root9;
struct student *root10;

struct student *top8;
struct student *top9;
struct student *top10;


void addNewStudent(){
    char name[20],rollno[10];
    int class;

    struct student *newnode = (struct student *)calloc(1, sizeof(struct student));
    
    // Input
    printf("Enter student's name :- ");
    scanf("%s",name);
    printf("Enter student's class :- ");
    scanf("%d",&class);
    printf("Enter student's rollno :- ");
    scanf("%s",rollno);

    // Initialization
    strcpy(newnode->name,name);
    strcpy(newnode->rollno,rollno);
    newnode->class = class;

    if (class == 8)
    {
        if (top8 == NULL){
            top8 = newnode;
            root8 = newnode;
            newnode->next = NULL;
        }
        else{
            top8->next = newnode;
            top8 = newnode;
            top8->next = NULL;
        }
    }else if (class == 9){

        if (top9 == NULL){
            top9 = newnode;
            root9 = newnode;
            newnode->next = NULL;
        }else{
            top9->next = newnode;
            top9 = newnode;
            top9->next = NULL;
        }
    }
    else if (class == 10)
    {
        if (top10 == NULL){
            top10 = newnode;
            root10 = newnode;
            newnode->next = NULL;
        }else
        {
            top10->next = newnode;
            top10 = newnode;
            top10->next = NULL;
        }
    }
}

void getAllStudents(){
    struct student *temp;
    int class;
    printf("Enter the class :- ");
    scanf("%d",&class);
    if(class==8){
        temp=root8;
    }else if(class==9){
        temp=root9;
    }else if(class==10){
        temp=root10;
    }else{
        printf("Class does not exist....\n");
        return;
    }

    while(temp!=NULL){
        if(class==8){
            printf("%s %s %s %d\n",temp->name,temp->rollno,temp->father,temp->maths);
        }else if(class==9 || class==10){
            printf("%s %s %s %d\n",temp->name,temp->rollno,temp->father,temp->maths);
        }
        temp=temp->next;
    }

}

void updatePersonalDetails(struct student *temp){
    char name[20],roll[10],father[20],mother[20];
    printf("Enter updated values if not enter -1");
    printf("Enter students name , roll no , father's name , mother's name\n");
    scanf("%s %s %s %s", name, roll, father, mother);
    if (strcmp(name, "-1"))
    {
        strcpy(temp->name, name);
    }
    if (strcmp(roll, "-1"))
    {
        strcpy(temp->rollno, roll);
    }
    if (strcmp(father, "-1"))
    {
        strcpy(temp->father, father);
    }
    if (strcmp(mother, "-1"))
    {
        strcpy(temp->mother, mother);
    }
}

void updateStudentsMarks(struct student *temp,int class){
    int maths, social, hindi, physics, chemistry, biology, science, english;
    printf("Enter updated values if not enter -1");
    if(class==8){
        printf("Enter students marks for maths, english , social , hindi, science \n");
        scanf("%d %d %d %d %d", &maths, &english, &social, &hindi, &science);
    }else{
        printf("Enter students marks for maths, english , social , hindi, physics, chemistry, biology\n");
        scanf("%d %d %d %d %d", &maths, &english, &social, &hindi, &physics , &chemistry, &biology);
    }
    if (maths != -1)
    {
        temp->maths = maths;
    }
    if (english != -1)
    {
        temp->english = english;
    }
    if (social != -1)
    {
        temp->social = social;
    }
    if (hindi != -1)
    {
        temp->hindi = hindi;
    }
    if(class==8){
        if (science != -1)
        {
            temp->science = science;
        }
    }else{
        if (physics != -1)
        {
            temp->physics = physics;
        }if (chemistry != -1)
        {
            temp->chemistry = chemistry;
        }if (biology != -1)
        {
            temp->bio = biology;
        }
    }
}

void commonUpdate(struct student *temp,char rollno[],int class){
    int choice;
     while(temp!=NULL){
            if(!strcmp(temp->rollno,rollno)){
                printf("\n%s\n",temp->name);
                printf("What you want to update ?");
                printf("1.Student's personal details\n2.Student's marks\n3.None");
                scanf("%d",&choice);
                switch (choice){
                    case 1:
                        updatePersonalDetails(temp);
                        break;
                    case 2:
                        updateStudentsMarks(temp,class);
                        break;
                    case 3:
                        printf("Updates done........\n");
                        return;
                    default:
                        printf("Invalid choice\n");
                        return;
                }
                return;
            }else{
                temp=temp->next;
            }
        }

        printf("Student not found \n");
}

void updateAStudent(){
    int class,choice;
    char rollno[10];
    struct student *temp;

    printf("Enter the class and roll no :- ");
    scanf("%d %s",&class,rollno);
    if(class==8){
        temp=root8;
    }else if(class==9){
        temp=root9;
    }else{
        temp=root10;
    }
    commonUpdate(temp,rollno,class);
}

struct student *checkClass(int class){
    
    if(class==8){
        return root8;
    }else if(class==9){
        return root9;
    }else if(class==10){
        return root10;
    }
    printf("Class does not exit\n");
}

// struct student *checkRollno(struct student *temp,int rollno){
//     while(temp!=NULL){
//         if(!strcmp(temp->rollno,rollno)){

//         }
//     }
// }

void deleteAStudent(){
    struct student *prev;
    int class;
    char rollno[10];
    printf("Enter the class and roll no :- ");
    scanf("%d %s",&class,rollno);
    struct student *temp=checkClass(class);
    while(temp!=NULL){
        prev=temp;
        if(!strcmp(temp->rollno,rollno)){
            prev->next=temp->next;
            free(temp);
            return;
        }
        temp=temp->next;
    }
    printf("Student not found........");
}

void main()
{
    int role,ch;
    char pass[5] = "admin";
    char password[10];
    while (1)
    {
        printf("\nLogin........\n");
        printf("1.Admin\n2.Student\n3.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &role);
        switch (role)
        {
        case 1:
            printf("Enter the password: ");
            scanf("%s", password);
            if (strcmp(pass, password))
            {
                while (1)
                {
                    printf("Admin opertaions.......\n");
                    printf(" 1.Add a student\n 2.Update a student\n 3.Delete a student\n 4.Get all students\n 5.Student Cirtificate\n 6.Exit\n");
                    printf("Enter the choice:- ");
                    scanf("%d",&ch);
                    switch (ch){
                        case 1:
                            addNewStudent();
                            break;
                        case 2:
                            updateAStudent();
                            break;
                        case 3:
                            deleteAStudent();
                            break;
                        case 4:
                            getAllStudents();
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        default:
                            printf("Invalid choice\n");
                            break;
                    }
                }
            }
            else
            {
                printf("Invalid password.......");
            }
            break;

        case 2:
            break;

        case 3:
            exit(0);
        default:
            printf("Please enter valid choice");
            break;
        }
    }
}
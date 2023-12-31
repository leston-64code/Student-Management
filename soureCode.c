#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct student {
    char name[20];
    int class;
    int rollno;
    float avgscore;
    char gender;
    struct subjects *applied_subjects;
    struct student *next;
};

struct subjects {
    int maths;
    int science;
    int social_studies;
    int english;
    int ethics;
};


int isEmpty(struct student *root) {
    if (root == NULL) {
        printf("No students available.\n");
        return 1;
    }
    return 0; 
}

void tableDisplay(struct student *root){
    struct student *presentNode=root;
    if(isEmpty(root)){
        return;
    }
    char nameString[20],upper;
    int count=0;
    printf("SL NO\t\tNAME\t\tCLASS\t\tROLL NO\t\tSCORE(%)\tGENDER\n");
    while(presentNode!=NULL){
        ++count;
        strcpy(nameString,presentNode->name);
        if(strlen(nameString)>=13){
            nameString[13]='\0';
        };
        nameString[0]=toupper(nameString[0]);
        upper=toupper(presentNode->gender);
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%.2f%\t\t%c\n",count,nameString,presentNode->class,presentNode->rollno,presentNode->avgscore,upper);
        presentNode=presentNode->next;
    }
}

void addStudent(struct student **root) {
    int class, rollno;
    char name[20],gender;
    struct student *newstudent = (struct student*)malloc(sizeof(struct student));
    if (*root != NULL) {
        struct student *presentNode = *root;
        while (presentNode->next != NULL) {
            presentNode = presentNode->next;
        }
        presentNode->next = newstudent;
    } else {
        *root = newstudent;
    }
    printf("Enter the student's name, class, rollno, gender(m/f): ");
    scanf("%s %d %d %c", name, &class, &rollno, &gender);
    for (int i = 0; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    strcpy(newstudent->name,name);
    newstudent->class = class;
    newstudent->rollno = rollno;
    newstudent->gender = gender;
    newstudent->avgscore = 0.0;
    newstudent->next = NULL;

    char choice;
    printf("Do you want to enter the student's marks now? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        newstudent->applied_subjects = (struct subjects*)malloc(sizeof(struct subjects));
        printf("Enter marks for Maths, Science, Social Studies, English, and Ethics:\n");
        scanf("%d %d %d %d %d",&newstudent->applied_subjects->maths,&newstudent->applied_subjects->science,&newstudent->applied_subjects->social_studies,&newstudent->applied_subjects->english,&newstudent->applied_subjects->ethics);
    } else {
        newstudent->applied_subjects = NULL;
    }
}

void updateStudent(struct student *root) {
    if (isEmpty(root)) {
        return;
    }

    int maths,science,social_studies,english,ethics;

    int class,rollno;
    printf("Enter the class and roll no of student you want to delete\n");
    printf("Class :- ");
    scanf("%d",&class);
    printf("Rollno :- ");
    scanf("%d",&rollno);

    struct student *currentNode = root;
    while (currentNode != NULL) {
        if (currentNode->rollno == rollno) {
            printf("Enter the updated class and rollno: ");
            scanf("%d %d", &currentNode->class, &currentNode->rollno);

            char response;
            printf("Do you want to update subject marks for this student?(y/n): ");
            scanf(" %c", &response);

            if (response == 'y' || response == 'Y') {
                if (currentNode->applied_subjects == NULL) {
                    currentNode->applied_subjects = (struct subjects*)malloc(sizeof(struct subjects));
                }

                printf("Enter updated marks for Maths, Science, Social Studies, English, and Ethics:\n");
                printf("Enter -1 for subjects you don't want to update.\n");
                scanf("%d %d %d %d %d",&maths,&science,&social_studies,&english,&ethics);

                if(maths!=-1){
                    currentNode->applied_subjects->maths=maths;
                }

                if(science!=-1){
                    currentNode->applied_subjects->science=science;
                }

                if(social_studies!=-1){
                    currentNode->applied_subjects->social_studies=social_studies;
                }

                if(english!=-1){
                    currentNode->applied_subjects->english=english;
                }

                if(ethics!=-1){
                    currentNode->applied_subjects->ethics=ethics;
                }

                printf("Subject marks updated successfully..............\n");
            }

            printf("Student details updated successfully..............\n");
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Student with roll number %d and class %d not found.\n",rollno,class);
}

void getAllStudents(struct student *root) {
    if(isEmpty(root)){
        return;
    }
    tableDisplay(root);
}

void getStudentsOfAParitcularClass(struct student *root) {
    if(isEmpty(root)){
        return;
    }
    int selectedClass=0;
    printf("Enter the class you want to fetch\n");
    scanf("%d",&selectedClass);
    printf("Students of class %d:\n", selectedClass);
    
    struct student *presentNode = root;
    printf("SL NO\t\tNAME\t\tCLASS\t\tROLL NO\t\tSCORE(%)\tGENDER\n");
    int count=0; 
    char nameString[20],upper;
    while (presentNode != NULL) {
        if (presentNode->class == selectedClass) {
            ++count;
            strcpy(nameString,presentNode->name);
            if(strlen(nameString)>=13){
                nameString[13]='\0';
            };
            nameString[0]=toupper(nameString[0]);
            upper=toupper(presentNode->gender);
            printf("%d\t\t%s\t\t%d\t\t%d\t\t%.2f%\t\t%c\n",count,nameString,presentNode->class,presentNode->rollno,upper
            );
       }
        presentNode = presentNode->next;
}
}

void calculateAverageScore(struct student *root){
    if(isEmpty(root)){
        return;
    }
    struct student *presentNode = root;
    while(presentNode!=NULL){
        int totalMarks=presentNode->applied_subjects->english +  presentNode->applied_subjects->ethics + presentNode->applied_subjects->maths + presentNode->applied_subjects->science + presentNode->applied_subjects->social_studies;
        float percentage=(totalMarks*100)/500;
        presentNode->avgscore=percentage;
        presentNode=presentNode->next;
    }
    printf("******* Average score of students updated.................\n");
    tableDisplay(root);
}

void deleteAParticularStudent(struct student *root) {
    if (isEmpty(root)) {
        return;
    }

    int class,rollno;
    printf("Enter the class and roll no of student you want to delete\n");
    printf("Class :- ");
    scanf("%d",&class);
    printf("Rollno :- ");
    scanf("%d",&rollno);
    
    struct student *presentNode = root;
    struct student *previousNode = NULL;

    while (presentNode!=NULL && (presentNode->class != class || presentNode->rollno != rollno) ) {
        previousNode=presentNode;
        presentNode=presentNode->next;
    }
    if (presentNode==NULL) {
        printf("No student Found.\n", class, rollno);
        return;
    }
    if (previousNode==NULL) {
        root=presentNode->next;
    } else {
        previousNode->next=presentNode->next;
    }
    free(presentNode->applied_subjects);
    free(presentNode);
    printf("Student with class %d and roll number %d deleted successfully.\n",class,rollno);
}

void getAParticularStudent(struct student *root) {
    if (isEmpty(root)) {
        return;
    }

    int class,rollno;
    printf("Enter the class and roll no of student you want to delete\n");
    printf("Class :- ");
    scanf("%d",&class);
    printf("Rollno :- ");
    scanf("%d",&rollno);

    struct student *presentNode = root;
    printf("NAME\t\tCLASS\t\tROLL NO\t\tSCORE(%)\tGENDER\n");
    char nameString[20],upper;

    while (presentNode != NULL) {
        if (presentNode->class==class&&presentNode->rollno==rollno) {
            strcpy(nameString,presentNode->name);
            if(strlen(nameString)>=13){
                nameString[13]='\0';
            };
            nameString[0]=toupper(nameString[0]);
            upper=toupper(presentNode->gender);
            printf("%s\t\t%d\t\t%d\t\t%.2f%\t\t%c\n",nameString,presentNode->class,presentNode->rollno,upper
            );
        }
        presentNode = presentNode->next;
    }

    printf("Student with class %d and roll number %d not found.\n",class,rollno);
    return; 
}


int main() {
    int ch;
    struct student *root = NULL;
    while (1) {
        printf("Enter your choice\n");
        printf("1. Add student\n2. Update student details\n3. Get all students\n4. Get students of a class\n5.Calculate Average Score\n6.Delete a particular student\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                addStudent(&root);
                break;
            case 2:
                updateStudent(root);
                break;
            case 3:
                getAllStudents(root);
                break;
            case 4:
                getStudentsOfAParitcularClass(root);
                break;
            case 5:
                calculateAverageScore(root);
                break;
            case 6:
                deleteAParticularStudent(root);
                break;
            case 7:
                getAParticularStudent(root);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}

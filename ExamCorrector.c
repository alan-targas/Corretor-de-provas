#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_EXAMS 100

typedef struct {
    int id;
    char name[50];
    int num_questions;         
    char answer_key[MAX_QUESTIONS + 1];
} Exam;

Exam saved_exams[MAX_EXAMS];
int total_exams = 0;
int counter_id =1;


void correct_exam()
{
    printf("\nIt worked!");
}

void add_answer_key()
{
    int flag = 1;
    char ak_name[100];
    int ak_id;
    int num_questions_chosen;
    if(total_exams>=MAX_EXAMS)
    {
        flag = 0;
        printf("\n!!! Answer keys maximum quantity reached. Erase unused ones for space before adding a new one. !!!");
    }
    if(flag!=0)
    {
        printf("\nPlease, select a name for this answer key: ");
        getchar();
        fgets(ak_name, sizeof(ak_name), stdin);
        ak_name[strcspn(ak_name, "\n")] = '\0';

        do
        {
            printf("\nChoose number of questions (max %d): ",MAX_QUESTIONS);
            scanf("%d",&num_questions_chosen);

            if(num_questions_chosen<1||num_questions_chosen>MAX_QUESTIONS)
            {
                printf("\nPlease, choose a valid number.");
            }
        } while (num_questions_chosen<1||num_questions_chosen>MAX_QUESTIONS);

        ak_id=counter_id;

        printf("\nEnter the correct answers (a, b, c, d, etc.):\n");
        for (int i = 0; i < num_questions_chosen; i++)
        {
            printf("\nQuestion %d: ", i + 1);
            scanf(" %c", &saved_exams[total_exams].answer_key[i]);
        }

        saved_exams[total_exams].answer_key[num_questions_chosen] = '\0';
        

        strcpy(saved_exams[total_exams].name, ak_name);
        saved_exams[total_exams].id = ak_id;
        saved_exams[total_exams].num_questions = num_questions_chosen;

        counter_id++;
        total_exams++;

        printf("\nAnswer key successfully saved!\n");
    }

}

void list_answer_key()
{
    int option;
    if(total_exams==0)
    {
        printf("\nNo answer keys added.");
        return;
    }
    for(int i=0; i<=total_exams-1;i++)
    {
        printf("\n%d. %s",i+1,saved_exams[i].name);
    }
    do
    {
        printf("\nChoose an exam to check: ");
        scanf("%d",&option);
        if(option<1||option>total_exams)
        {
            printf("\nInvalid option.");
        }

    } while (option<1||option>total_exams);

    printf("\nExam ID: %d",saved_exams[option-1].id);
    printf("\nName: %s",saved_exams[option-1].name);
    printf("\nNumber of question: %d",saved_exams[option-1].num_questions);
    printf("\nAnswer Key: ");
    for (int i = 0; i < saved_exams[option-1].num_questions; i++)
        {
            printf("%d-%c    ",i+1, saved_exams[option-1].answer_key[i]);
        }
    printf("\n");
    



    
}

void alter_answer_key()
{
    int option;
    if(total_exams==0)
    {
        printf("\nNo answer keys added.");
        return;
    }
    for(int i=0; i<=total_exams-1;i++)
    {
        printf("\n%d. %s",i+1,saved_exams[i].name);
    }
    do
    {
        printf("\nChoose an exam to alter answer key: ");
        scanf("%d",&option);
        if(option<1||option>total_exams)
        {
            printf("\nInvalid option.");
        }

    } while (option<1||option>total_exams);

    printf("\nEnter the correct answers (a, b, c, d, etc.):\n");
        for (int i = 0; i < saved_exams[option-1].num_questions; i++)
        {
            printf("\nQuestion %d: ", i + 1);
            scanf(" %c", &saved_exams[option-1].answer_key[i]);
        }

    printf("\nAnswer key successfully altered!\n");
}

void erase_answer_key()
{
    printf("\nIt worked!");
}

int main()
{
    int option;

    do
    {
        printf("\n----------MENU----------\n");
        printf("\n 1. Correct Exam");
        printf("\n 2. Add Answer Key");
        printf("\n 3. List Answer Key");
        printf("\n 4. Alter Answer Key");
        printf("\n 5. Delete Answer Key");
        printf("\n 0. Exit");

        do
        {
            printf("\n Choose an option: ");
            scanf("%d",&option);

            if(option>5||option<0)
            {
                printf("\nPlease, select a valid option.");
            }
        } while (option>5||option<0);
    
        switch(option)
        {
            case 1:
                correct_exam();
                break;

            case 2:
                add_answer_key();
                break;

            case 3:
                list_answer_key();
                break;

            case 4:
                alter_answer_key();
                break;

            case 5:
                erase_answer_key();
                break;
            
            case 0:
                printf("\nExiting...");
                break;
            
            default:
                break;
        }
        

    } while (option!=0);

    return 0;
    
}
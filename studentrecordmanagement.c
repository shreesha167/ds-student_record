#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;

};
struct Student * insert(struct Student *head, int rollnumber, char name[100], char phone[100], float percentage)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;

    if(head==NULL)
    {
        /* if head is NULL, set student as the new head */
        head = student;
    }
    else{
        /* if list is not empty
         insert student in beginning of head */
        student->next = head;
        head = student;
    }

    return head;

}
void search(struct Student *head, int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
             printf("Roll Number: %d || Name: %s || Phone: %s || Percentage: %0.4f \n", temp->rollnumber,temp->name,temp->phone,temp->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(struct Student *head, int rollnumber)
{

    struct Student * temp = head;
    while(temp!=NULL){

        if(temp->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);

}
struct Student * Delete(struct Student *head, int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL){

        if(temp1->rollnumber==rollnumber){


            if(temp1==temp2){
                /* this condition will run if
                the record that we need to delete is the first node
                of the linked list */
                head = head->next;
                free(temp1);
            }
            else{
                /* temp1 is the node we need to delete
                 temp2 is the node previous to temp1 */
                temp2->next = temp1->next;
                free(temp1);
            }

            return head;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }

    return head;

}
void display(struct Student *head)
{
    struct Student * temp = head;
    while(temp!=NULL){

        printf("Roll Number: %d || Name: %s || Phone: %s || Percentage: %0.4f \n", temp->rollnumber,temp->name,temp->phone,temp->percentage);
        temp = temp->next;

    }
}
struct Student * sort(struct Student *head){

    struct Student *temp = NULL;
    struct Student *ptr;
    struct Student *lptr;
    while(head!=NULL){

        ptr = head;
        lptr = head;
        while(ptr!=NULL){
            if(ptr->rollnumber > lptr->rollnumber){
                lptr = ptr;
            }
            ptr = ptr->next;
        }
        temp = insert(temp, lptr->rollnumber, lptr->name, lptr->phone, lptr->percentage);
        head = Delete(head, lptr->rollnumber);
    }
    return temp;

}
int main()
{
    struct Student *head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("\n---------MENU--------");
    printf("\n1.Insert student details\n2.Search for student details\n3.Delete student details\n4.Update student details\n5.Display all student details\n6.Sort records based on roll number\n");
    do
    {  
        printf("\nEnter Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                head = insert(head,rollnumber, name, phone, percentage);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(head,rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                head = Delete(head, rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(head, rollnumber);
                break;
            case 5:
                display(head);
                break;
            case 6:
                head = sort(head);
                break;
        }

    } while (choice != 0);
}
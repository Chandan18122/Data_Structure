#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//structure for student 
typedef struct student{
    char name[50];
    char sname[50];
    char city[50];
    int age;
    char standard[50];
}student;
//structure foe make node for student data 
typedef struct node{
    student* data;
    struct node* next;
}node;
//function  for add the student data 
student* student_data(char name[50],char sname[50],char city[50], int age, char standard[50]){
    student* new = malloc(sizeof(student));
    strcpy(new->name, name);
    strcpy(new->sname, sname);
    strcpy(new->city, city);
    new->age = age;
    strcpy(new->standard, standard);
    return new;
}
//function for create node
node* create_node(student* studentData){
    node* new = malloc(sizeof(node));
    new->data = studentData;
    new->next = NULL;
    return new;
}
//function for create the student record and make link list
node* student_record(node* head,char name[20],char sname[20],char city[20],int age,char standard[20]){
    student* studentData = student_data(name,sname,city,age,standard);
    if(head == NULL){
        node* new = create_node(studentData);
        return new;
    }
    while(head->next != NULL){
        head = head->next;
    }
    node* new = create_node(studentData);
    head->next = new;
}
//function for display the list
void display_student_data(node* ptr){
    if(ptr == NULL){
        printf("there is no any data.\n");
        return;
    }
    while(ptr !=NULL){
        printf("\nName : %s\n",ptr->data->name);
        printf("SurName : %s\n",ptr->data->sname);
        printf("City : %s\n",ptr->data->city);
        printf("Age : %d\n",ptr->data->age);
        printf("Standard : %s\n",ptr->data->standard);
        ptr = ptr->next;
    }
}
//function for delete the record in the list
node* delete_record(node* head,char dname[20]){
    node* prev = NULL;
    node* temp = head;
    if(head == NULL){
        printf("Student record is empty.\n");
        return head;
    }
    while(temp !=NULL){
        if(strcmp(temp->data->name, dname) == 0) break;
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Given name is not in the record.\n");
        return head;
    }
    //for first node
    if(temp == head){
        head = temp->next;
    }
    //for any node
    else{
        prev->next = temp->next;
    }
    free(temp);
    printf("record deleted.\n");
    return head;
}
//function for save the data in the file
int save_file(node* ptr){
    FILE *fptr;
    if(ptr == NULL){
        printf("there is no any data to save in the file.\n");
        return 0;
    }
    fptr = fopen("student_data.txt", "w");
    //fprintf(fptr,"Name\tSurName\tCity\tAge\tStandard\n");
    while(ptr != NULL){
        fprintf(fptr,"%s\t%s\t%s\t%d\t%s\n",
        ptr->data->name, ptr->data->sname, ptr->data->city, ptr->data->age, ptr->data->standard);
        ptr = ptr->next;
    }
    fclose(fptr);
    return 1;
}
//function for lode the data from file
node* load_file(node* head){
    FILE* fptr;
    fptr = fopen("student_data.txt", "r");
    if(fptr == NULL){
        //printf("\nFile is empty.\n");
        exit(1);
    }
    char name[100];
    char sname[100];
    char city[100];
    char age[100];
    char standard[100];
    //read data from file 
    while(fscanf(fptr,"%s %s %s %s %s\n",name,sname,city,age,standard) != EOF){
        head = student_record(head,name,sname,city,atoi(age),standard);
    }
    fclose(fptr);
    return head;
}
//function for search and display data of one student 
void search_display(node* head,char search_name[40]){
    node* ptr = head;
    if(head == NULL){
        printf("Student record is empty.\n");
        return;
    }
    while(ptr != NULL){
        if(strcmp(ptr->data->name, search_name) == 0) break;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Given name is not in the record.\n");
        return;
    }
    printf("\nName : %s\n",ptr->data->name);
    printf("SurName : %s\n",ptr->data->sname);
    printf("City : %s\n",ptr->data->city);
    printf("Age : %d\n",ptr->data->age);
    printf("Standard : %s\n",ptr->data->standard);
}
int main(){
    node* head = NULL;
    int cho;
    printf("Choise :\n0 for exit\n1 for add data\n2 for display all\n3 for delete by name\n");
    printf("4 for save into file\n5 for search data and display by name\n");
    //load data from file
    head = load_file(head);
    while(1){
	cho = 0;
        printf("\nEnter the choise : ");
        scanf("%d",&cho);
        switch(cho){
            case 0:
	    exit(1);
            break;
            case 1:
            char name[50];
	    char sname[50];
	    char city[50];
	    int age;
	    char standard[50];
            printf("Enter the First Name : ");
            scanf("%s",name);
            printf("Enter the SurName/last name : ");
            scanf("%s",sname);
            printf("Enter the city : ");
            scanf("%s",city);
            printf("Enter the Age : ");
            scanf("%d",&age);
            printf("Enter the Standard : ");
            scanf("%s",standard);
            head = student_record(head,name,sname,city,age,standard);
            //update data into file after the add new recored
            save_file(head);
            break;
            case 2:
            display_student_data(head);
            break;
            case 3:
            char dname[40];
            printf("Enter the name you want to delete record : ");
            scanf("%s",dname);
            head = delete_record(head,dname);
            //update data into file sfter the delete record
            save_file(head);
            break;
            case 4:
            if(save_file(head)){
                printf("Data is save into the file.\n");   
            }
            break;
            case 5:
            char search_name[40];
            printf("Enter the name you want to search record : ");
            scanf("%s",search_name);
            search_display(head,search_name);
            break;
        }
        if(cho == 0) break;
    }
    return 0;
}


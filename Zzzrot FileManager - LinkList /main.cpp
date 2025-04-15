#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	int p;
	char name[1001];
	Data *next;
	Data *prev;
}Data;

Data *head=NULL;
Data *tail=NULL;
//Function for input Data
Data* create(int p, char *name){
	Data *data =(Data*)malloc(sizeof(Data));
	data->p = p;
	strcpy(data->name, name);
	data->next = NULL;
	data->prev = NULL;
	return data;
}
//Function for Push Head Data
void push_head(Data *data){
	if(!head){
		head = tail = data;
	}
	else{
		data->next = head;
		head->prev = data;
		head = data;
	}
}
//Function for Push Tail Data
void push_tail(Data *data){
	if(!head){
		head = tail = data;
	}
	else{
		tail->next = data;
		data->prev = tail;
		tail = data;
	}
}
//Function for Push priority/Queue
void push_pq(Data *data){
	if(!head){
		push_head(data);
	}
	else if(data->p >= head->p){
		push_head(data);
	}
	else if(data->p < tail->p){
		push_tail(data);
	}
	else{
		Data *temp = head;
		while(temp->p > data->p){
			temp = temp->next;
		}
		Data *left = temp->prev;
		Data *right = temp->next;
		left->next = data;
		data->prev = left;
		data->next = right;
		right->prev = data;
	}
}
//Function for printf/output
void view(){
	if(!head){
		printf("LL is Empty\n");
	}
	Data *temp = head;
	while(temp){
		printf("%s          %dkb \n", temp->name, temp->p);
		temp = temp->next;
	}
}
//Funtion for delete head data
void pop_head(){
	if(!head){
		printf("Error!\n");
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}
//Funtion for delete tail data
void pop_tail(){
	if(!head){
		printf("Error!\n");
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
}
//function to delete the data you want
void pop_s(char *name){
	if(!head){
		printf("Error!\n");
	}
	if(strcmp(head->name, name) == 0){
		pop_head();
		printf("Filehead '%s' deleted successfully.\n", name);
	}
	else if(strcmp(tail->name, name) == 0){
		pop_tail();
		printf("Filetail '%s' deleted successfully.\n", name);
	}
	else{
		Data *temp = head;
		while(temp){
			if(strcmp(temp->name, name) == 0){
				Data *left = temp->prev;
				Data *right = temp->next;
				free(temp);
				left->next = right;
				right->prev = left;
				printf("File '%s' deleted successfully.\n", name);
				return;
			}
			temp = temp->next;
		}
		printf("Error ( Data not found )!\n");
	}
}

//funtion for delet all data
void pop_all(){
	while(head){
		pop_head();
	}
}
int main(){
	int size;
	char name[101];
	char filename[101];
	int choice;
	while (1) {
		system("cls");
        printf("\nZzrot File Manager\n");
        printf("1. Insert File\n");
        printf("2. Delete File\n");
        printf("3. Show Files\n");
        printf("4. Remove All Files and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        	case 1 : 
        		system("cls");
        		printf("Enter filename (must end '.doc') : ");
        		scanf("%s", name);
        		if(strstr(name, ".doc") == NULL){
				while(strstr(name, ".doc") == NULL){
					printf("Error (Format must be '.doc') : ");
					scanf("%s", name);
				}
			}
			printf("Enter filesize (1-9999): ");
                	scanf("%d", &size);
                	if(size < 1 || size > 9999){
				while(size < 1 || size > 9999){
	                		printf("Error (Size must be > 1 and < 9999) : ");
	                		scanf("%d", &size);
				}
			}
			push_pq(create(size, name));
			printf("File inserted successfully.\n");
			system("pause");
                	break;
                	
            case 2 :
           		system("cls");
            		printf("Enter filename to delete : ");
            		scanf("%s", filename);
            		pop_s(filename);
            		system("pause");
            		break;
            		
            case 3 :
            		system("cls");
            		view();
            		system("pause");
            		break;
            	
            case 4:
	                pop_all();
	                printf("...\n");
	                return 0;

            default:
	                printf("Invalid choice. Please try again.\n");
	                system("pause");
	            	
		}
    }
	return 0;
}

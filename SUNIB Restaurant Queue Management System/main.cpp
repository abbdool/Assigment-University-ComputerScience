#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data{
	char name[101];
	char clas[101];
	Data *next;
	Data *prev;	
}Data;

int get(char *clas){
	if(strcmp(clas, "VVIP") == 0)
	{
		return 1;
	}
	else if(strcmp(clas, "VIP") == 0)
	{
		return 2;
	}
	if(strcmp(clas, "member") == 0)
	{
		return 3;
	}
	if(strcmp(clas, "guest") == 0)
	{
		return 4;
	}
	return 5;
}
Data *head = NULL;
Data *tail = NULL;
Data *create(char *name, char *clas){
	Data *data = (Data*)malloc(sizeof(Data));
	strcpy(data->name, name);
	strcpy(data->clas, clas);
	data->next = NULL;
	data->prev = NULL;
	return data;
}

void pushh(Data *data){
	if(!head){
		head = tail = data;
	}
	else{
		data->next = head;
		head->prev = data;
		head = data;
	}
}

void pusht(Data *data){
	if(!head){
		head = tail = data;
	}
	else{
		data->prev = tail;
		tail->next = data;
		tail = data;
	}
}

void pushpq(Data *data){
	if(!head){
		pushh(data);
	}
	else if(get(data->clas) < get(head->clas)){
		pushh(data);
	}
	else if(get(data->clas) >= get(head->clas)){
		pusht(data);
	}
	else{
		Data *temp = head;
		while(get(temp->clas) <= get(data->clas)){
			temp = temp->next;
		}
		Data *l = temp->prev;
		Data *r = temp;
		data->prev = l;
		l->next = data;
		data->next = r;
		r->prev = data;
	}
}
void show(){
	printf("Waiting Line:\n");
	if(!head){
		printf("No data\n\n");
	}
	else{
		Data *temp = head;
		int i = 1;
		while(temp){
			printf("%d. %s\n", i, temp->name);
			temp = temp->next;
			i++;
		}
	}
}
void poph(){
	if(!head){
		printf("No data\n");
	}
	else if(head == tail){
		free(head);
		head = NULL;
	}
	else{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}

void popall(){
	while(head){
		poph();
	}
}
void serv(){
	if(strcmp(head->clas, "VVIP") == 0){
		printf("Attention! %s is being served at VVIP table.\n", head->name);
	}
	else if(strcmp(head->clas, "VIP") == 0){
		printf("Attention! %s is being served at the VIP table.\n", head->name);
	}
	else if(strcmp(head->clas, "member") == 0){
		printf("Attention! %s is being served at regular table.\n", head->name);
	}
	else if(strcmp(head->clas, "guest") == 0){
		printf("Attention! Guest %s is being served at regular table.\n", head->name);
	}
}
void servall()
{
	
	while(head){
		if(strcmp(head->clas, "VVIP") == 0){
			printf("Attention! %s is being served at VVIP table.\n", head->name);
			
		}
		else if(strcmp(head->clas, "VIP") == 0){
			printf("Attention! %s is being served at the VIP table.\n", head->name);
			
		}
		else if(strcmp(head->clas, "member") == 0){
			printf("Attention! %s is being served at regular table.\n", head->name);
			
		}
		else if(strcmp(head->clas, "guest") == 0){
			printf("Attention! Guest %s is being served at regular table.\n", head->name);
			
		}
		head = head->next;
	}
}
int main(){
	char name[101];
	char type[101];
	int choice;
	while(1){
		show();
		printf("\n\n");
		printf("1. Add Customer to Queue\n");
		printf("2. Serve One\n");
		printf("3. Serve All\n");
		printf("4. Dismiss Queue\n");
		printf("0. Exit\n");
		printf("Input Menu Number: ");
		scanf("%d", &choice);
		puts("");
		switch(choice){
			case 1 : 
				
				scanf("%s %s", type, name);
				pushpq(create(name, type));
				printf("Attention! %s is being served at VVIP table.\n", name);
				system("cls");
				break;
			case 2 :
				serv();
				poph();
				system("pause");
				system("cls");
				break;
			case 3 :
				servall();
				popall();
				system("pause");
				system("cls");
				break;
			case 4:
				popall();
				printf("End of the day!\n");
				system("pause");
				system("cls");
				break;
			case 0 :
				return 0;
			default :
			printf("Input Numbet Invalid\n");
			system("pause");
			system("cls");
			}
		
	}
	return 0;
}

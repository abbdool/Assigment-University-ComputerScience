#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	char name[101];
	int v;
	Data *next;
	Data *prev;
}Data;

Data *head = NULL;
Data *tail = NULL;

Data* create(char *name, int v){
	Data *data =(Data*)malloc(sizeof(Data));
	strcpy(data->name , name);
	data->v = v;
	data->next = NULL;
	data->prev = NULL;
	return data;
}

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

void push_tail(Data *data){
	if(!head){
		head = tail =data;
	}
	else{
		tail->next = data;
		data->prev = tail;
		tail = data;
	}
}

void push_pq(Data *data){
	if(!head){
		push_head(data);
	}
	else if(strcmp(data->name,head->name) < 0){
		push_head(data);
	}
	else if(strcmp(data->name, tail->name) >= 0){
		push_tail(data);
	}
	else{
		Data *temp = head;
		while(temp){
			if(strcmp(temp->name, data->name) < 0){
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
}

void view(){
	if(!head){
		printf("No data\n");
	}
	else{
		Data *temp = head;
		while(temp){
			printf("%s || %d\n\n", temp->name, temp->v);
			temp= temp->next;
		}
	}
}

void poph(){
	if(!head){
		printf("Empty\n");
	}	
	else if(head = tail){
		free(head);
		head = tail = NULL;
	}
	else{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}

void popt(){
	if(!head){
		printf("LL empty!\n");
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

void pops(char *name){
	if(!head){
		printf("LL Empty\n");
		return;
	}
	else if(strcmp(head->name, name) == 0)
	{
		poph();
	}
	else if(strcmp(tail->name, name) == 0){
		popt();
	}
	else{
		Data *temp = head;
		while(strcmp(temp->name, name) == 0){
			Data *l = temp->prev;
			Data *r = temp->next;
			free(temp);
			l->next = r;
			r->prev = l;
			return;
			
		}
		temp = temp->next;
	}
}

void popal(){
	while(head){
		poph();
	}
}
int main()
{
	int choice;
	char name[101];
	int v;
	while(1){
		system("cls");
		printf("-----Basic Double LL-----\n\n");
		printf("1. Insert Data\n");
		printf("2. Show Data\n");
		printf("3. Delete Data\n");
		printf("4. Exit\n");
		printf("Insert Menu : ");
		scanf("%d", &choice);
		switch(choice){
			case 1 : 
					system("cls");
					printf("Insert data (Name Number) : ");
					scanf("%s %d", name, &v);
					push_pq(create(name, v));
					printf("Insert Data Succesfully\n");
					system("pause");
					break;
			case 2 :
					system("cls");
					printf("Name || Number\n\n");
					view();
					system("pause");
					break;
			case 3 :
					system("cls");
					view();
					printf("Insert name of data :");
					scanf("%s", name);
					pops(name);
					system("pause");
					break;
			case 4 :
					system("cls");
					popal();
					printf("Exit ....\n");
					return 0;
			default : 
					system("cls");
					printf("Invalid Command!!\n");
					system("pause");
					break;
		}
	}
	return 0;
}

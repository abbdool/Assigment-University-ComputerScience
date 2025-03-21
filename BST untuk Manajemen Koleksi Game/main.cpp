#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	char name[101];
	int n;
	Data *l;
	Data *r;
}Data;
Data *root = NULL;

Data* create(char *name, int n){
	Data *data =(Data*)malloc(sizeof(Data));
	strcpy(data->name, name);
	data->n = n;
	data->l = NULL;
	data->r = NULL;
	return data;
}

Data *push(Data *curr, char *name, int n){
	if(!curr){
		return create(name, n);
	}
	else if(strcmp(curr->name, name) == 0){
		curr->n = n;
	}
	else if(strcmp(name, curr->name) > 0){
		curr->l = push(curr->l, name, n);
	}
	else if(strcmp(name, curr->name) < 0){
		curr->r = push(curr->r, name, n);
	}
	return curr;
}

void pre(Data *curr){
	if(curr){
		printf("PreOrder : %s %d\n", curr->name, curr->n);
		pre(curr->l);
		pre(curr->r);	
	}
}
void in(Data *curr){
	if(curr){
		in(curr->l);
		printf("InOrder : %s %d\n", curr->name, curr->n);
		in(curr->r);	
	}
}
void post(Data *curr){
	if(curr){
		post(curr->l);
		post(curr->r);	
		printf("PostOrder : %s %d\n", curr->name, curr->n);
	}
}
Data *get1(Data *curr){
	curr = curr->l;
	while(curr->r){
		curr = curr->r;
	}
	return curr;
}
Data *pop(Data *curr, char *name){
	if(!curr){
		printf("No data!\n");
	}
	else if(strcmp(name, curr->name) > 0){
		curr->l = pop(curr->l, name);
	}
	else if(strcmp(name, curr->name) < 0){
		curr->r =pop(curr->r, name);
	}
	else if(strcmp(curr->name, name) == 0){
		if(!curr->l && !curr->r){
			free(curr);
			curr=NULL;
		}
		else if(curr->l && !curr->r){
			Data *temp = curr;
			curr = curr->l;
			free(temp);
		}else if(!curr->l && curr->r){
			Data *temp = curr;
			curr = curr->r;
			free(temp);
		}
		else{
			Data *get = get1(curr);
			strcpy(curr->name, get->name);
			curr->l = pop(curr->l, get->name);
		}
	}
}

int main(){
	int choice;
	char name[101];
	int n;
	while(1){
		system("cls");
		printf("1. Insert Data\n");
		printf("2. Delete Data\n");
		printf("3. Show Data\n");
		printf("4. exit\n");
		printf("Enter Menu : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					system("cls");
					printf("Insert (Name game) : ");
					scanf(" %[^\n]", name);
					printf("\nInsert (Rating Game) : ");
					scanf("%d", &n);
					while( n < 1 || n > 10){
						printf("Insert rate (1 - 10):");
						scanf("%d", &n);
					}
					root = push(root , name, n);
					printf("Succes inserting name\n");
					system("pause");
					break;
			case 2: {
					system("cls");
					pre(root);
					in(root);
					post(root);
					printf("Delete data by name : ");
					scanf("%s", name);
					pop(root, name);
					Data *temp = pop(root, name);
					if(!temp){
						printf("No data brow\n");
					}
					printf("deleted succesfully\n");
					system("pause");
					break;
				}
			case 3:
				system("cls");
				pre(root);
				in(root);
				post(root);
				system("pause");
				break;
			case 4:
				printf("Exiting......\n");
				return 0;
					
		}
	}
	return 0;
}

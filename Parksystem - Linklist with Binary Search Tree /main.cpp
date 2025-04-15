#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Data{
	int out;
	int jam;
	char type[101];
	char name[1001];
	char rnd[20];
	char status[101];
	Data *L;
	Data *R;
}Data;

Data *Root = NULL;
int total;

Data* create(char *name, char *type,char *status, int jam, char *rnd, int out){
	Data *data = (Data*)malloc(sizeof(Data));
	strcpy(data->name, name);
	strcpy(data->type, type);
	strcpy(data->rnd, rnd);
	strcpy(data->status, status);
	data->jam = jam;
	data->out = out;
	data->L = NULL;
	data->R = NULL;
	return data;
}
Data *push(Data *curr, char *name, char *type,char *status, int jam, char *rnd, int out){
	if(!curr){
		return create(name,type,status,jam, rnd, out);
	}
	else if(strcmp(name, curr->name) == 0){
		printf("Duplicate Data!!! Eror\n");
	}
	else if(strcmp(name, curr->name) < 0){
		curr->L = push(curr->L, name, type,status, jam, rnd, out);
	}
	else if(strcmp(name, curr->name) > 0){
		curr->R = push(curr->R, name, type,status, jam, rnd, out);
	}
	return curr;
}

void pre(Data *curr){
	if(curr){
		printf("%-12s %-20s %-10s %-9d %s\n", curr->rnd, curr->name,curr->type, curr->jam, curr->status);
		pre(curr->L);
		pre(curr->R);
	}
}

void in(Data *curr){
	if(curr){
		in(curr->L);
		printf("%-12s %-20s %-10s %-9d %s\n", curr->rnd, curr->name,curr->type, curr->jam, curr->status);
		in(curr->R);
	}
}

void post(Data *curr){
	if(curr){
		post(curr->L);
		post(curr->R);
		printf("%-12s %-20s %-10s %-9d %s\n", curr->rnd, curr->name,curr->type, curr->jam, curr->status);
	}
}

Data *Getpredecessor(Data *curr){
	curr = curr->L;
	while(curr->R){
		curr = curr->R;
	}
	return curr;
}

Data *pop(Data *curr, char *rnd){
	if(!curr){
		printf("Data is empty!!\n");
	}
	else if(strcmp(rnd, curr->rnd) < 0){
		curr->L = pop(curr->L, rnd);
	}
	else if(strcmp(rnd, curr->rnd) > 0){
		curr->R = pop(curr->R, rnd);
	}
	else if(strcmp(rnd, curr->rnd)==0){
//		printf("%s is found\n");
		if(!curr->L && !curr->R){
			free(curr);
			curr = NULL;
		}
		else if(curr->L && !curr->R){
			Data *temp = curr;
			curr = curr->L;
			free(temp);
		}
		else if(!curr->L && curr->R){
			Data *temp = curr;
			curr = curr->R;
			free(temp);
		}
		else{
			Data *predecessor = Getpredecessor(curr);
			strcpy(curr->rnd, predecessor->rnd);
			curr->L = pop(curr->L, predecessor->rnd);
		}
	}
	return curr;
}

int mintwo(char *str){
	for(int i = 0; str[i]!='\0';i++){
		if(str[i] == ' '){
			return 1;
		}
	}
	return 0;
}
void generateVehicleCode(char *result) {
    int angka1 = rand() % 10;
    int angka2 = rand() % 10;
    int angka3 = rand() % 10;
    int angka4 = rand() % 10;

    char huruf1 = 'A' + (rand() % 26);
    char huruf2 = 'A' + (rand() % 26);
    char huruf3 = 'A' + (rand() % 26);
    sprintf(result, "B %d%d%d%d %c%c%c", angka1, angka2, angka3, angka4, huruf1, huruf2, huruf3);
}
void view(Data *curr){
	printf("PRE-ORDER\n");
	printf("============================================================\n\n");
	printf("CODE        OWNER                TYPE       IN TIME   STATUS\n");
	printf("------------------------------------------------------------\n");
	pre(curr);
	printf("\n\n");
	
	
	printf("IN-ORDER\n");
	printf("============================================================\n\n");
	printf("CODE        OWNER                TYPE       IN TIME   STATUS\n");
	printf("------------------------------------------------------------\n");
	in(curr);
	printf("\n\n");
	
	
	printf("POST-ORDER\n");
	printf("============================================================\n\n");
	printf("CODE        OWNER                TYPE       IN TIME   STATUS\n");
	printf("------------------------------------------------------------\n");
	post(curr);
	printf("\n\n");
}
void list(Data *curr){
	if(!curr){
		printf("No data!!\n");
		return;
	}
	in(curr);
}
int payment(Data *curr){
	int jml = 0;
	if(strcmp(curr->type, "Sedan") == 0){
		jml+=(curr->out - curr->jam)*3000;
	}
	else if(strcmp(curr->type, "Truck") == 0){
		jml+=(curr->out - curr->jam)*4000; 
	}
	else if(strcmp(curr->type, "Motorcycle") == 0){
		jml+=(curr->out - curr->jam)*2000;
	}
	return jml; 
}
void popall(Data *curr){
	if(curr){
		popall(curr->L);
		popall(curr->R);
		free(curr);
	}
}
int main(){
	int out;
	char rnd[20];
	int choice;
	char name[1001];
	char type[101];
	int jam;
	srand(time(NULL));
	while(1){
	system("cls");
	printf("VEHICLE - PARK ARENA\n\n");
	printf("============================================================\n\n");
	printf("MENU\n");
	printf("1. Add data\n");
	printf("2. View data\n");
	printf("3. Park out\n");
	printf("4. Exit\n");
	printf("Menu : ");
	scanf("%d", &choice);
	switch(choice){
		case 1 :
				system("cls");
				generateVehicleCode(rnd);
				printf("Input owner's name[5-20 characters, at least two words]: ");
				scanf(" %[^\n]", name);
				while(!mintwo(name)){
					printf("Input owner's name[5-20 characters, at least two words]: ");
					scanf(" %[^\n]", name);	
				}
				printf("Input in time[6-9]: ");
				scanf("%d", &jam);
				while(jam < 6 || jam > 9){
					printf("Input in time[6-9]: ");
					scanf("%d", &jam);
				}
				printf("Input vehicle's type[Sedan||Truck||Motorcycle]: ");
				scanf("%s", type);
				while(strcmp(type, "Sedan") != 0 && strcmp(type, "Truck") != 0 && strcmp(type, "Motorcycle") != 0){
					printf("Input vehicle's type[Sedan||Truck||Motorcycle]: ");
					scanf("%s", type);
				}
				Root = push(Root,name,type,"IN",jam, rnd, 0);
				printf("Vehicle's code : %s\n", rnd);
				printf("Owner's name   : %s\n", name);
				printf("Vehicle's type : %s\n", type);
				printf(" In time       : %d\n", jam);
				printf(" Status        : IN\n\n\n");
				system("pause");
				break;
				
		case 2 :
				system("cls");
				view(Root);
				system("pause");
				break;
				
		case 3 : {
				system("cls");
				printf("VEHICLE LIST\n");
				printf("============================================================\n");
				printf("CODE        OWNER                TYPE       IN TIME   STATUS\n");
				printf("------------------------------------------------------------\n");
				list(Root);
				printf("\n\n");
				printf("Input vehicle's code: ");
				scanf(" %[^\n]", rnd);
				Data *temp = Root;
				while(temp && strcmp(temp->rnd, rnd) !=0){
					if(strcmp(rnd,temp->rnd) < 0){
						temp = temp->L;
						}else{
							temp = temp->R;
						}
					}
				if(!temp){
					printf("Data not Found!");
					break;
				}
				printf("Input out time[10-18]: ");
				scanf("%d", &out);
				while(out < 10 || out > 18){
				printf("Input out time[10-18]: ");
				scanf("%d", &out);	
				}
				strcpy(temp->status, "OUT");
				temp->out = out;
				total = payment(temp);
				printf("Vehicle's code : %s\n", rnd);
				printf("Owner's name   : %s\n", name);
				printf("Vehicle's type : %s\n", type);
				printf(" In time       : %d\n", jam);
				printf(" Out time      : %d\n", out);
				printf(" Status        : OUT\n");
				printf("Payment        : %d\n", total);
				system("pause");
				break;
				}
		case 4 :
				system("cls");
				printf("Exit....\n");
				popall(Root);
				Root = NULL;
				return 0;
				
		default:
			system("cls");
			printf("Invalid Command! Please try again\n");
			system("pause");
			break;
				}
	}
				
	return 0;
}

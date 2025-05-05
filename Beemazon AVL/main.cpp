#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data{
	long long int number;
	char name[101];
	int h;
	Data *l;
	Data *r;
}Data;

Data* Root = NULL;

int getm(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

int geth(Data *data){
	if(!data) return 0;
	return data->h;
}

int calch(Data *data){
	return getm(geth(data->l), geth(data->r)) + 1;
}

int calcbf(Data *data){
	if(!data) return 0;
	return geth(data->l) - geth(data->r);
}

Data *getp(Data* data){
	Data *curr = data->r;
	while(curr->l){
		curr = curr->l;
	}
	return curr;
}

Data* create (long long int number, char* name){
	Data *data = (Data*)malloc(sizeof(Data));
	strcpy(data->name, name);
	data->number = number;
	data->h = 1;
	data->l = NULL;
	data->r = NULL;
	return data;
}


Data *Lrotate(Data *data){
	Data *pivot = data->r;
	Data *cut = pivot->l;
	pivot->l = data;
	data->r = cut;
	data->h = calch(data);
	pivot->h = calch(pivot);
	return pivot;
}
Data *Rrotate(Data *data){
	Data *pivot = data->l;
	Data *cut = pivot->r;
	pivot->r = data;
	data->l = cut;
	data->h = calch(data);
	pivot->h = calch(pivot);
	return pivot;
}

Data* Insert(Data *curr, long long int number, char* name){
	if(!curr){
		curr = create(number, name);
	}
	else if(curr->number == number){
		return curr;
	}
	else if(number < curr->number){
		curr->l = Insert(curr->l, number, name);
	}
	else if(number > curr->number){
		curr->r = Insert(curr->r, number, name);
	}
	curr->h = calch(curr);
	int balance = calcbf(curr);
	
	if(balance > 1 && number < curr->l->number){
		curr = Rrotate(curr);
	}
	if(balance > 1 && number > curr->l->number){
		curr->l = Lrotate(curr->l);
		curr = Rrotate(curr);
	}
	if(balance < -1 && number > curr->r->number){
		curr = Lrotate(curr);
	}
	if(balance < -1 && number < curr->r->number){
		curr->r = Rrotate(curr->r);
		curr = Lrotate(curr);
	}
	return curr;
}
void in(Data *data){
	if(data){
		in(data->l);
		printf("%lld %s\n", data->number, data->name);
		in(data->r);
	}
}


Data* finds(Data *data, long long int key) {
	Data* predecessor = NULL;
	while (data) {
		if (key > data->number) {
			predecessor = data;
			data = data->r;
		} else {
			data = data->l;
		}
	}
	return predecessor;
}
Data* del(Data *data, long long int key){
	if(!data){
		printf("No data Instead!\n");
		return data;
	}
	if(key < data->number){
		data->l = del(data->l, key);
	}
	else if(key > data->number){
		data->r = del(data->r, key);
	}
	else if(key == data->number){
		if(!data->l && !data->r){
			free(data);
			data = NULL;
		}
		else if(data->l && !data->r){
			Data *temp = data;
			data = data->l;
			free(temp);
		}
		else if(!data->l && data->r){
			Data *temp = data;
			data = data->r;
			free(temp);
		}
		else if(data->l && data->r){
			Data *pre = getp(data);
			data->number = pre->number;
			data->h = pre->h;
			strcpy(data->name, pre->name);
			data->r = del(data->r, pre->number);
		}
	}
	if(data) data->h = calch(data);
	
	int balance = calcbf(data);
	
	if( balance > 1 && calcbf(data->l) >= 0 ){
		return Rrotate(data);
	}
	
	if(balance > 1 && calcbf(data->l) < 0 ){
		data->l = Lrotate(data->l);
		return Rrotate(data);
	}
	
	if(balance < -1 && calcbf(data->r) <=0 ){
		return Lrotate(data);
	}
	
	if( balance < -1 && calcbf(data->r) > 0 ){
		data->r = Rrotate(data->r);
		return Lrotate(data);
	}
	
	return data;
}
void popal(Data *data){
	if(data){
		popal(data->l);
		popal(data->r);
		free(data);
		data = NULL;
	}
}

int main(){
	int choice;
	long long int number;
	char name[101];
	while(1){
		system("cls");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Find Similiar\n");
		printf("4. Show Data\n");
		printf("5. Exit\n");
		printf("Enter Command : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					system("cls");
					printf("Insert Price : ");
					scanf("%lld", &number);
					printf("Insert ProductName : ");
					scanf("%s", name);
					Root = Insert(Root, number, name);
					system("pause");
					break;
			case 2:
				system("cls");
				long long int key;
				in(Root);
				printf("\n\n");
				printf("Insert Price To delete : ");
				scanf("%lld", &key);
				Root = del(Root, key);
				system("pause");
				break;
			case 3:{
				system("cls");
				long long int key;
				printf("Insert price to find similliar : ");
				scanf("%lld", &key);	
				Data* pred = finds(Root, key);
				if(pred){
					printf("%lld %s\n", pred->number, pred->name);
				} else {
					printf("No similliar found.\n");
				}
				system("pause");
				break;
			}
			case 4:
				system("cls");
				in(Root);
				system("pause");
				break;
			case 5:
				popal(Root);
				return 0;
		}
	}
	return 0;
}

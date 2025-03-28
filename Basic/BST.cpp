#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data{
	int angka;
	Data *L;
	Data *R;
}Data;
Data *Root = NULL;

Data *create(int angka){
	Data *data =(Data*)malloc(sizeof(Data));
	data->angka =angka;
	data->L = NULL;
	data->R = NULL;
	return data;
}
Data *push(Data *curr, int angka){
	if(!curr){
		return create(angka);
	}
	else if(angka < curr->angka){
		curr->L = push(curr->L, angka);
	}
	else if(angka > curr->angka){
		curr->R = push(curr->R, angka);
	}
	else if(curr->angka == angka){
		printf("%d is Duplicate Data\n\n", curr->angka);
	}
	return curr;
}

void pre(Data *curr){
	
	if(curr){
		printf("%d ",curr->angka);
		pre(curr->L);
		pre(curr->R);
	}
}
void in(Data *curr){

	if(curr){
		in(curr->L);
		printf("%d ",curr->angka);
		in(curr->R);
	}
}
void post(Data *curr){

	if(curr){
		post(curr->L);
		post(curr->R);
		printf("%d ",curr->angka);
	}
}
Data *get(Data *curr){
	curr = curr->L;
	while(curr->R){
		curr = curr->R;
	}
	return curr;
}
Data *pop(Data *curr, int angka){
	if(!curr){
		printf("No data\n");
	}
	else if(angka < curr->angka){
		curr->L = pop(curr->L, angka);
	}
	else if(angka > curr->angka){
		curr->R = pop(curr->R, angka);
	}
	else{
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
			Data *predecessor = get(curr);
			curr->angka = predecessor->angka;
			curr->L = pop(curr->L, predecessor->angka);
		}
	}
}

int main(){
	Root = push(Root, 6);
	Root = push(Root, 9);
	Root = push(Root, 4);
	Root = push(Root, 5);
	Root = push(Root, 6);
	printf("Preorder : ");
	pre(Root);
	printf("\n\n");
	printf("Inorder : ");
	in(Root);
	printf("\n\n");
	printf("Postorder : ");
	post(Root);
}					

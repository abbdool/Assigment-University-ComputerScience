#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	int umur;
	char name[101];
}Data;

Data *arr[101];
int size = 0;

int parent(int index){
	return (index-1)/2;
}
int Lc(int index){
	return index * 2 + 1;
}
int Rc(int index){
	return index * 2 + 2;
}
void swap(int a, int b){
	Data *temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Upheap(int index){
	if(index <= 0)return;
	int parent_index = parent(index);
	if(arr[index]->umur < arr[parent_index]->umur){
		swap(parent_index, index);
	}
	else{
		return;
	}
	Upheap(parent_index);
}

void Insert(char *name, int umur){
	Data *n = (Data*)malloc(sizeof(Data));
	n->umur = umur;
	strcpy(n->name, name);
	
	arr[size] = n;
	size++;
	Upheap(size-1);
}
void Downheap(int index){
	if(index >= size)return;
	int small = index;
	int left = Lc(index);
	int right = Rc(index);
	if(left < size && arr[left]->umur < arr[small]->umur){
		small = left;
	}
	if(right < size && arr[right]->umur < arr[small]->umur){
		small = right;
	}
	if(small == index)return;
	swap(small, index);
	Downheap(small);
}
Data *del(){
	if(size == 0)return NULL;
	Data *deleted = arr[0];
	swap(0, size - 1);
	size--;
	Downheap(0);
	return deleted;
}

int main(){
	Insert("a", 11);
	Insert("b", 221);
	Insert("c", 3321);
	Insert("e", 1223);
	while(size > 0){
		Data *d = del();
		printf("%s %d\n", d->name, d->umur);
		free(d);
	}
}

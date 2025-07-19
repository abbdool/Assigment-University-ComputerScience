#include <stdio.h>

int arr[101];
int size = 0;

int parentS(int n){
	return (n - 1) / 2;
}

int Lc(int n){
	return n * 2 + 1;
}

int Rc(int n){
	return n * 2 + 2;
}

void swap(int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void upheap(int index){
	if(index <= 0)return;
	int parent_index = parentS(index);
	if(arr[index] < arr[parent_index]){
		swap(index, parent_index);
		upheap(parent_index);
	}
	return;
}
void insert(int angka){
	arr[size] = angka;
	size++;
	upheap(size-1);
}
void downheap(int index){
	if(index >= size) return;
	int Smallest = index;
	int kiri = Lc(index);
	int kanan = Rc(index);
	if(kiri < size && arr[kiri] < arr[Smallest]){
		Smallest = kiri;
	}
	if(kanan < size && arr[kanan] < arr[Smallest]){
		Smallest = kanan;
	}
	if(Smallest == index){
		return;
	}
	swap(index , Smallest);
	downheap(Smallest);
}

int del(){
	int deleted = arr[0];
	swap(0, size-1);
	size--;
	downheap(0);
	return deleted;
}

int main(){
	while(1){
		int input;
		scanf("%d", &input);
		if(input == 0){
			break;
		}
		else{
			int found = 0;
			for(int i = 0; i < size; i++){
				if(input == arr[i]){
					found = 1;
					break;
				}
			}
	
			if(found){
				if(input == arr[0]){
					del();
				}else{
					printf("Eror\n");
				}

			} else {
				insert(input);
			}
			for(int i= 0;i < size; i ++){
				printf("%d\n", arr[i]);
			}
		}
	}
}

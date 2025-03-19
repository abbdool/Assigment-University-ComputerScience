#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data {
    char title[101];
    char genre[101];
    int durasi;
    Data *next;
    Data *prev;
} Data;

Data *headm = NULL;
Data *tailm = NULL;
Data *headw = NULL;
Data *tailw = NULL;

Data* create(char *title, char *genre, int durasi) {
    Data *data = (Data*)malloc(sizeof(Data));
    strcpy(data->title, title);
    strcpy(data->genre, genre);
    data->durasi = durasi;
    data->next = NULL;
    data->prev = NULL;
    return data;
}

void pushh(Data *data) {
    if (!headm) {
        headm = tailm = data;
    } else {
        data->next = headm;
        headm->prev = data;
        headm = data;
    }
}

void pusht(Data *data) {
    if (!headm) {
        headm = tailm = data;
    } else {
        data->prev = tailm;
        tailm->next = data;
        tailm = data;
    }
}

void pushpq(Data *data) {
    if (!headm) {
        pushh(data);
    } else if (strcmp(data->title, headm->title) < 0) {
        pushh(data);
    } else if (strcmp(data->title, tailm->title) >= 0) {
        pusht(data);
    } else {
        Data *temp = headm;
        while (strcmp(temp->title, data->title) < 0) {
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

void pushh1(Data *data) {
    if (!headw) {
        headw = tailw = data;
    } else {
        data->next = headw;
        headw->prev = data;
        headw = data;
    }
}

void pusht1(Data *data) {
    if (!headw) {
        headw = tailw = data;
    } else {
        data->prev = tailw;
        tailw->next = data;
        tailw = data;
    }
}

void pushpq1(Data *data) {
    if (!headw) {
        pushh1(data);
    } else if (strcmp(data->title, headw->title) < 0) {
        pushh1(data);
    } else if (strcmp(data->title, tailw->title) >= 0) {
        pusht1(data);
    } else {
        Data *temp = headw;
        while (strcmp(temp->title, data->title) < 0) {
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

void merge(){
    if (!headw) {
        printf("No watch later Data!\n");
    } else {
        Data *temp = headw;
        while (temp){
        	Data *curr = temp->next;
            pushpq(temp);
            temp = curr;
        }
        headw = tailw = NULL;
    }
}

void play() {
    if (!headm) {
        printf("No data\n");
    } else if(headm == tailm){
    	printf("Now Playing: %s %s %d\n", headm->title, headm->genre, headm->durasi);
    	free(headm);
    	headm = NULL;
	}
	else{
		printf("Now Playing: %s %s %d\n", headm->title, headm->genre, headm->durasi);
		headm = headm->next;
		free(headm->prev);
		headm->prev = NULL;
	}
}

void show() {
    if (!headm && !headw) {
        printf("No data in storage!\n");
    } else {
        if (headm) {
            printf("Main List:\n");
            Data *temp = headm;
            while (temp) {
                printf("%s %s %d\n", temp->title, temp->genre, temp->durasi);
                temp = temp->next;
            }
        }
        if (headw) {
            printf("Watch Later List:\n");
            Data *temp = headw;
            while (temp) {
                printf("%s %s %d\n", temp->title, temp->genre, temp->durasi);
                temp = temp->next;
            }
        }
    }
}

void poph() {
    if (!headm) {
        printf("No data\n");
    } else if (headm == tailm) {
        free(headm);
        headm = tailm = NULL;
    } else {
        headm = headm->next;
        free(headm->prev);
        headm->prev = NULL;
    }
}

void popall() {
    while (headm) {
        poph();
    }
    while (headw) {
        Data *temp = headw;
        headw = headw->next;
        free(temp);
    }
}

int main() {
    int durasi;
    char title[101];
    char genre[101];
    int choice;
    while (1) {
    	system("cls");
        printf("1. Insert Main\n");
        printf("2. Insert Watch Later\n");
        printf("3. Play\n");
        printf("4. Merge\n");
        printf("5. Show Data\n");
        printf("6. Exit\n");
        printf("Enter menu: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                printf("Enter title, genre, and duration: ");
                scanf("%s %s %d", title, genre, &durasi);
                pushpq(create(title, genre, durasi));
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Enter title, genre, and duration: ");
                scanf("%s %s %d", title, genre, &durasi);
                pushpq1(create(title, genre, durasi));
                system("pause");
                break;
            case 3:
                system("cls");
                play();
                system("pause");
                break;
            case 4:
                system("cls");
                merge();
                system("pause");
                break;
            case 5:
                system("cls");
                show();
                system("pause");
                break;
            case 6:
                popall();
                system("pause");
                return 0;
            default:
                printf("Invalid choice!\n");
                system("pause");
                break;
        }
    }
    return 0;
}

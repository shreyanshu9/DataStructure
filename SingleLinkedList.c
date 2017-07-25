#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* link;
}*start=NULL, *curr, *temp, *ptr, *temp1;

void create(int value) {
	temp = (struct node*) malloc(sizeof(struct node));
	temp -> data = value;
	temp -> link = NULL;
	if(start == NULL) {
		start = temp;
		curr = temp;
	} else {
		curr -> link = temp;
		curr = temp;
	}
}
void display() {
	temp = start;
	while(temp != NULL) {
		printf("\n%d",temp -> data);
		temp = temp -> link;
	}
}

void ibeginning(int value) {
	ptr = (struct node*) malloc(sizeof(struct node));
	ptr -> data = value;
	ptr -> link = start;
	start = ptr;
}

void iEnd(int value) {
	temp = start;
	while(temp -> link != NULL) {
		temp = temp -> link;
	}
	ptr = (struct node*) malloc(sizeof(struct node));
	ptr -> link = NULL;
	ptr -> data = value;
	temp -> link = ptr;
}

void iAny(int position, int value) {
	int current = 1;
	temp = start;
	if(position == 1) {
		ibeginning(value);
	} else {
		while(current != position && temp != NULL) {
			current++;
			ptr = temp;
			temp = temp -> link;
		}
		if(temp == NULL) {
			iEnd(value);
		} else {
			temp1 = (struct node*) malloc(sizeof(struct node));
			temp1 -> data = value;
			temp1 -> link = temp;
			ptr -> link = temp1;
		}
	}
}

void insert() {
	int position,value,choice;
	system("cls");
	printf("\n=== Insert Menu ===");
	printf("\n1.Insert at the beginning");
	printf("\n2.Insert at any Position");
	printf("\n3.Insert at the End");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice) {
		case 1 : printf("\nEnter Data : ");
				 scanf("%d",&value);
				 ibeginning(value);
				 break;

	    case 2 : printf("\nEnter Position : ");
			 scanf("%d",&position);
			 printf("\nEnter Data : ");
			 scanf("%d",&value);
			 iAny(position, value);
			 break;

	    case 3 : printf("\nEnter Data : ");
			 scanf("%d",&value);
			 iEnd(value);
			 break;
	}
}

void rbeginning() {
	temp = start;
	start = start -> link;
	free(temp);
}

void rEnd() {
	temp = start;
	while(temp -> link != NULL) {
		ptr = temp;
		temp = temp -> link;
	}
	ptr -> link = NULL;
	free(temp);
}

void rAny(int position) {
	int current = 1;
	temp = start;
	if(position == 1) {
		rbeginning();
	} else {
		while(current != position && temp -> link != NULL) {
			current++;
			ptr = temp;
			temp = temp -> link;
		}
		ptr -> link = temp -> link;
		free(temp);
	}
}

void removeElement() {
	int position,choice;
	system("cls");
	printf("\n=== Remove Menu ===");
	printf("\n1.Remove at the beginning");
	printf("\n2.Remove at any Position");
	printf("\n3.Remove at the End");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice) {
		case 1 : rbeginning();
				 break;

	    case 2 : printf("\nEnter Position : ");
			 scanf("%d",&position);
			 rAny(position);
			 break;

	    case 3 : rEnd();
			 break;
	}
}

int entryDisplay() {
	int choice;
	system("cls");
	printf("\n===Main Menu===");
	printf("\n1.Create Linked List");
	printf("\n2.Display");
	printf("\n3.Insert an Element");
	printf("\n4.Remove an Element");
	printf("\n5.Exit");
	printf("\nEnter your Choice : ");
	scanf("%d",&choice);
	return choice;
}

void displayAction(int choice) {
	int n, i, data;
	switch(choice) {
		case 1 : printf("\nEnter number of elements : ");
				 scanf("%d",&n);
				 for(i=0;i<n;i++){
					printf("\nEnter data : ");
					scanf("%d",&data);
					create(data);
				}
				printf("\n\nPress ENTER to continue ...");
				getch();
				break;

		case 2 :display();
			printf("\n\nPress ENTER to continue ...");
				getch();
				break;

		case 3 : insert();
				printf("\n\nPress ENTER to continue ...");
				getch();
				 break;

		case 4 : removeElement();
				printf("\n\nPress ENTER to continue ...");
				getch();
				 break;

		case 5 : exit(0);
				 break;

		default : printf("\nEnter a valid choice");
	}
}
int main() {
	int i,n,choice;
	system("cls");
	do {
		choice = entryDisplay();
		displayAction(choice);
	}
	while(choice != 5);
	getch();
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
} *start = NULL, *ptr, *end = NULL, *temp;

void create(int value) {
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = value;
    temp -> right = NULL;
    if(start == NULL) {
        temp -> left = NULL;
        start = temp;
        end = temp;
    } else {
        temp -> left = end;
        end -> right = temp;
        end = temp;
    }
}

void forwardDisplay() {
    temp = start;
    while (temp != NULL) {
        printf("\n%d",temp -> data);
        temp = temp -> right;
    }
}

void backDisplay() {
    temp = end;
    while (temp != NULL) {
        printf("\n%d",temp -> data);
        temp = temp -> left;
    }
}

void display() {
    int choice;
    system("cls");
    printf("\n=== Display Menu ===");
    printf("\n1.Forward");
    printf("\n2.Backward");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice) {
        case 1 : forwardDisplay();
                 break;
        case 2 : backDisplay();
                 break;
    }
}

void iBeginning(int value) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr ->left = NULL;
    ptr -> right = start;
    start -> left = ptr;
    start = ptr;
}

void iEnd(int value) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> right = NULL;
    ptr -> left = end;
    end -> right = ptr;
    end = ptr;
}

void iAny(int position, int value) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = value;
    temp = start;
    int current = 1;
    if (position == 1) {
        iBeginning(value);
    } else {
        while(current != position && temp != NULL) {
            current++;
            temp = temp -> right;
        }
        if (temp == NULL) {
            iEnd(value);
        } else {
            ptr -> right = temp;
            ptr -> left = temp -> left;
            temp -> left -> right = ptr;
            temp -> left = ptr;

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
				 iBeginning(value);
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

void rBeginning() {
    temp = start;
    start = start -> right;
    start -> left = NULL;
    free(temp);
}

void rEnd() {
    temp = end;
    end = end -> left;
    end -> right = NULL;
    free(temp);
}

void rAny(int position) {
    temp = start;
    int current = 1;
    if (position == 1) {
        rBeginning();
    } else {
        while (current != position && temp != NULL) {
            current ++;
            temp = temp -> right;
        }
        if (temp == NULL) {
            rEnd();
        } else {
            temp -> left -> right = temp -> right;
            temp -> right -> left = temp -> left;
            free(temp);
        }
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
		case 1 : rBeginning();
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
	int choice;
	system("cls");
	do {
		choice = entryDisplay();
		displayAction(choice);
	}
	while(choice != 5);
	getch();
	return 0;
}

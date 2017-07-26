#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL, *ptr;

void push() {
    int value;
    printf("\nEnter Data : ");
    scanf("%d",&value);
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> link = top;
    top = ptr;
    printf("\nAdded : %d", top -> data);
}

void pop() {
    if (top == NULL) {
        printf("\nEmpty List");
    } else {
        ptr = top;
        top = top -> link;
        printf("\nRemoved : %d", ptr -> data);
        free(ptr);
    }
}

void display(struct node* pointer) {
    if (pointer != NULL) {
        display(pointer -> link);
        printf("\n%d", pointer -> data);
    } else {
        return;
    }
}

int linkedMenu() {
    int choice, n;
    system("cls");
    printf("\n==Linked List Stack Menu==");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display");
    printf("\n4.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice) {
        case 1: push();
                break;

        case 2: pop();
                break;

        case 3: display(top);
                break;

        case 4: exit(0);
    }
}

int main() {
    int choice;
    do {
        choice = linkedMenu();
        printf("\n\nPress ENTER to continue ...");
        getch();
    } while (choice != 4);
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node* link;
} *top = NULL, *ptr, *start = NULL, *curr;

void reverse() {
    curr = start;
    while (curr != NULL) {
        push(curr -> data);
        curr = curr -> link;
    }
    curr = start;
    while (curr != NULL) {
        curr -> data = pop();
        curr = curr -> link;
    }
}

void create(char a) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = a;
    ptr -> link = NULL;
    if (start == NULL) {
        start = ptr;
        curr = ptr;
    } else {
        curr -> link = ptr;
        curr = ptr;
    }
}

void push(char a) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = a;
    ptr -> link = top;
    top = ptr;
}

int pop() {
    char a;
    if (top == NULL) {
        return 0;
    } else {
        ptr = top;
        top = top -> link;
        a = ptr -> data;
        free(ptr);
        return a;
    }
}

void display(struct node* current) {
    if (current != NULL) {
        printf("%c", current -> data);
        display(current -> link);
    }
}

int main() {
    system("cls");
    char a;
    printf("\nPress # to stop\n");
    printf("\nEnter String : ");
    scanf("%c",&a);
    while (a != '#') {
        create(a);
        scanf("%c",&a);
    }
    display(start);
    printf("\n");
    reverse();
    display(start);
    printf("\n");
    return 0;
}

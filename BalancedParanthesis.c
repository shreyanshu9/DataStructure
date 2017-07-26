#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node* link;
} *top = NULL, *ptr;

void push(char a) {
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = a;
    ptr -> link = top;
    top = ptr;
}

void pop() {
    if(top != NULL) {
        ptr = top;
        top = top -> link;
        free(ptr);
    }
}

int main() {
    char a;
    printf("\n\nPress # to stop");
    printf("\nEnter String : ");
    scanf("%c",&a);
    while(a != '#') {
        if (a == '{') {
            push(a);
        } else if( a == '}') {
            if (top == NULL) {
                printf("\nNot Balanced");
                return 0;
            } else {
                pop();
            }
        }
        scanf("%c",&a);
    }
    if(top == NULL) {
        printf("\nBalanced");
    } else {
        printf("\nNot Balanced");
    }
}

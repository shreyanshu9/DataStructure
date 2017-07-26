#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int top = -1, n = 0;

void push(int a[]) {
    int data;
    top++;
    if (top == n) {
        printf("\nOverFlow");
    } else {
        printf("\nEnter Data : ");
        scanf("%d",&data);
        a[top] = data;
        printf("\nAdded : %d",a[top]);
    }
}

void pop() {
    top--;
    if (top < 0) {
        printf("\nEmpty");
        top = -1;
    } else {
        printf("\nRemoved : %d",a[top+1]);
    }
}

void display(int a[]) {
    int i;
    for (i = 0;  i <= top; i++) {
        printf("\n%d",a[i]);
    }
}

int arrayMenu(int a[]) {
    int choice, n;
    system("cls");
    printf("\n==Array Stack Menu==");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display");
    printf("\n4.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice) {
        case 1: push(a);
                break;

        case 2: pop();
                break;

        case 3: display(a);
                break;

        case 4: exit(0);
    }
}

int main() {
    int choice;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int a[n];
    do {
        choice = arrayMenu(a);
        printf("\n\nPress ENTER to continue ...");
        getch();
    } while (choice != 4);
}

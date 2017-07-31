#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
} *root = NULL, *ptr, *temp;

void clearList(struct node* pointer) {
    if (pointer != NULL) {
        clearList(pointer -> left);
        clearList(pointer -> right);
        free(pointer);
    }
}

struct node* insert(struct node* pointer, int value) {
    if (pointer == NULL) {
        ptr = (struct node*) malloc (sizeof(struct node));
        ptr -> data = value;
        ptr -> right = NULL;
        ptr -> left = NULL;
        pointer = ptr;
    } else {
        if (value > pointer -> data) {
            pointer-> right = insert(pointer -> right, value);
        } else {
            pointer-> left = insert(pointer -> left, value);
        }
    }
    return pointer;
}

void create() {
    clearList(root);
    int n, value;
    printf("\nNumber of Elements : ");
    scanf("%d",&n);
    while (n > 0) {
        ptr = (struct node*) malloc(sizeof(struct node));
        printf("\nEnter Data : ");
        scanf("%d",&value);
        root = insert(root, value);
        n--;
    }
}

void display(struct node* pointer) {
    if (pointer != NULL) {
        display(pointer -> left);
        printf("%d ", pointer -> data);
        display(pointer -> right);
    }
}

int search(struct node* pointer, int n) {
    int check = 0;
    if (n == pointer -> data) {
        check = 1;
        printf("\nFound\nHere ");
    } else if (n > pointer -> data) {
        if (pointer -> right == NULL) {
            check = 0;
        } else {
            check = search(pointer -> right, n);
            if (check == 1) {
                printf("<- Right ");
            }
        }
    } else if (n < pointer -> data) {
        if (pointer -> left == NULL) {
            check = 0;
        } else {
            check = search(pointer -> left, n);
            if (check == 1) {
                printf("<- Left ");
            }
        }
    }
    return check;
}

int entryDisplay() {
    system("cls");
    int choice;
    printf("\n=== BST Menu ===");
    printf("\n1. Create");
    printf("\n2. Insert");
    printf("\n3. Display");
    printf("\n4. Search");
    printf("\n5. Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    return choice;
}

void displayAction(int choice) {
    int n,check;
    switch (choice) {
        case 1: create();
                break;

        case 2: printf("\nEnter Data : ");
                scanf("%d",&n);
                insert(root, n);
                break;

        case 3: display(root);
                break;

        case 4: printf("\nEnter Search Element : ");
                scanf("%d",&n);
                check = search(root, n);
                if (check == 0) {
                    printf("\nNot Found");
                } else {
                    printf("<- Root");
                }
                break;

        case 5: return;

    }
}

int main() {
    int choice;
    do {
        choice = entryDisplay();
        displayAction(choice);
        printf("\n\nPress ENTER to continue...");
        getch();
    } while (choice != 5);
}

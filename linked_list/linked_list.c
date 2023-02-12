#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBegin(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("Linked List is already empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked List is already empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void display() {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Begin\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteAtBegin();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice");
        }

    }
    return 0;
}
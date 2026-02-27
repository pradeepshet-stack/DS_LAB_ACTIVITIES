#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;   // Global head

// Function declarations
void createList();
void deleteFromBegin();
void deleteFromEnd();
void deleteFromPosition();
void display();

int main() {
    int choice;

    do {
        printf("\n--- DELETION MENU ---\n");
        printf("1. Create List\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Position\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createList(); break;
            case 2: deleteFromBegin(); break;
            case 3: deleteFromEnd(); break;
            case 4: deleteFromPosition(); break;
            case 5: display(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}

// Create List
void createList() {
    struct Node *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = NULL;

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Delete from Beginning
void deleteFromBegin() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

// Delete from End
void deleteFromEnd() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

// Delete from Specific Position
void deleteFromPosition() {
    struct Node *temp, *prev;
    int pos, i;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position!\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted.\n");
    }
}

// Display
void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
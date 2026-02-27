#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node *head = NULL, *newNode = NULL, *temp = NULL;
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        // If first node
        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display linked list
    printf("\nLinked List Elements:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free memory
    temp = head;
    while(temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
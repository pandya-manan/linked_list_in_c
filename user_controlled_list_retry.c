#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
struct Node* insertNodeAtFirst(struct Node* head, int data) {
    struct Node* toAdd = (struct Node*)malloc(sizeof(struct Node));
    toAdd->data = data;
    toAdd->next = head;
    return toAdd;
}

// Function to insert a node at a specific index
struct Node* insertNodeAtIndex(struct Node* head, int index, int element) {
    if (index == 0) { // Special case: insert at the beginning
        return insertNodeAtFirst(head, element);
    }

    struct Node* p = head;
    struct Node* toAdd = (struct Node*)malloc(sizeof(struct Node));
    toAdd->data = element;

    int i = 0;
    while (p != NULL && i < index - 1) {
        p = p->next;
        i++;
    }

    if (p == NULL) { // Index is out of bounds
        printf("Index out of bounds. Unable to insert.\n");
        free(toAdd); // Free the allocated memory
        return head;
    }

    toAdd->next = p->next;
    p->next = toAdd;
    return head;
}

// Function to insert a node at the end of the list
struct Node* insertNodeAtEnd(struct Node* head, int data) {
    if (head == NULL) {
        return insertNodeAtFirst(head, data);
    }

    struct Node* toAdd = (struct Node*)malloc(sizeof(struct Node));
    toAdd->data = data;
    toAdd->next = NULL;

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = toAdd;
    return head;
}

// Function to delete a node from the beginning of the list
struct Node* deleteFromTheBeginning(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }

    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
}

// Function to compute the length of the linked list
int computeLengthOfTheLinkedList(struct Node* head) {
    int i = 0;
    struct Node* p = head;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

// Function to delete a node at a given index
struct Node* deleteAtGivenIndex(struct Node* head, int index) {
    int lengthOfLinkedList = computeLengthOfTheLinkedList(head);
    if (index >= lengthOfLinkedList || index < 0) {
        printf("Deletion is not possible. Index out of bounds.\n");
        return head;
    }

    if (index == 0) {
        return deleteFromTheBeginning(head);
    }

    int i = 0;
    struct Node* ptr = head;
    struct Node* qtr = head->next;

    while (i < index - 1) {
        ptr = ptr->next;
        qtr = qtr->next;
        i++;
    }
    
    ptr->next = qtr->next;
    free(qtr);
    return head;
}

// Function to delete a node from the end of the list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty. Cannot delete from the last end.\n");
        return head;
    }
    if (head->next == NULL) { // Only one element
        free(head);
        return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Function to traverse and print the linked list
void traverseLinkedList(struct Node* ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int element;
    int choice = 0;
    int subChoice = 0;
    int index = 0;

    while (1) {
        printf("Menu to operate on singly linked lists\n");
        printf("1. Add new element\n");
        printf("2. Delete an element\n");
        printf("3. Traverse a linked list\n");
        printf("4. Length of the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Menu for addition operations\n");
                printf("1. Add element at the first node\n");
                printf("2. Add element at given index position\n");
                printf("3. Add element at the end\n");
                printf("4. Exit Program\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1:
                        printf("Enter an element which needs to be inserted into the linked list: ");
                        scanf("%d", &element);
                        head = insertNodeAtFirst(head, element);
                        break;
                    case 2:
                        printf("Enter the index position where the element needs to be added: ");
                        scanf("%d", &index);
                        printf("Enter the element which needs to be added at the above index position: ");
                        scanf("%d", &element);
                        head = insertNodeAtIndex(head, index, element);
                        break;
                    case 3:
                        printf("Enter the element which needs to be added at the end of the linked list: ");
                        scanf("%d", &element);
                        head = insertNodeAtEnd(head, element);
                        break;
                    case 4:
                        printf("Sad to see you go! Have a nice day! Good Bye!\n");
                        exit(1);
                        break;
                    default:
                        printf("Please enter the correct choice!\n");
                        break;
                }
                break;

            case 2:
                printf("Menu for deletion operations\n");
                printf("1. Delete at the beginning\n");
                printf("2. Delete at given index\n");
                printf("3. Delete from the end\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1:
                        head = deleteFromTheBeginning(head);
                        break;
                    case 2:
                        printf("Enter the index from where the value needs to be removed: ");
                        scanf("%d", &index);
                        head = deleteAtGivenIndex(head, index);
                        break;
                    case 3:
                        head = deleteAtEnd(head);
                        break;
                    case 4:
                        printf("Sad to see you go! Have a nice day! Good Bye!\n");
                        exit(1);
                        break;
                    default:
                        printf("Please enter the correct choice!\n");
                        break;
                }
                break;

            case 3:
                traverseLinkedList(head);
                break;

            case 4:
                printf("The length of the linked list is: %d\n", computeLengthOfTheLinkedList(head));
                break;

            case 5:
                printf("Sad to see you go! Have a nice day! Good Bye!\n");
                exit(1);
                break;

            default:
                printf("Please enter the correct choice!\n");
                break;
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void traverseLinkedList(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node* insertNodeAtFirst(struct Node* ptr,int data)
{
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=data;
    toAdd->next=ptr;
    ptr=toAdd;
    return ptr;
}

struct Node* insertNodeAtIndex(struct Node* head,int data,int index)
{
    struct Node* p=head;
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=data;
    int i=0;
    while(!(i==(index-1)))
    {
        p=p->next;
        i++;
    }
    toAdd->next=p->next;
    p->next=toAdd;
    return head;

}

struct Node* insertNodeAtEnd(struct Node* head, int data)
{
    struct Node* toAdd=(struct Node*)malloc(sizeof(struct Node));
    toAdd->data=data;

    struct Node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=toAdd;
    toAdd->next=NULL;
    return head;
}

struct Node* deleteFirstNode(struct Node* head)
{
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head,int index)
{
    struct Node* ptr=head;
    struct Node* qtr=head->next;
    int i=0;
    while(!(i==(index-1)))
    {
        ptr=ptr->next;
        qtr=qtr->next;
        i++;
    }
    ptr->next=qtr->next;
    free(qtr);
    return head;
}

struct Node* deleteNodeAtEnd(struct Node* head)
{
    struct Node* ptr=head;
    struct Node* qtr=head->next;
    while(qtr->next!=NULL)
    {
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    return head;
}

struct Node* deleteNodeGivenValue(struct Node* head, int value)
{
    struct Node* ptr=head;
    struct Node* qtr=head->next;
    while(qtr->next!=NULL && qtr->data!=value)
    {
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=qtr->next;
    free(qtr);
    return head;
}

int main()
{
    //Creating four nodes
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));
    //Linking the nodes
    head->data=17;
    head->next=second;

    second->data=19;
    second->next=third;

    third->data=21;
    third->next=fourth;

    fourth->data=23;
    fourth->next=NULL;

    //Traverse Linked List
    traverseLinkedList(head);

    //Insert a new node at the beginning
    head=insertNodeAtFirst(head,15);

    traverseLinkedList(head);

    head=insertNodeAtIndex(head,27,1);

    traverseLinkedList(head);

    head=insertNodeAtEnd(head,87);

    traverseLinkedList(head);

    head=deleteFirstNode(head);

    traverseLinkedList(head);

    head=deleteAtIndex(head,2);

    traverseLinkedList(head);

    head=deleteNodeAtEnd(head);

    traverseLinkedList(head);

    head=deleteNodeGivenValue(head,21);

    traverseLinkedList(head);
    return 0;
}
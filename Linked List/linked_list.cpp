#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void createNode(struct Node *ptr){
    struct Node *temp;
    temp = ptr;
    int ch;

    while(1){
        cout<<"Enter the data element of the link list: ";
        cin>>temp->data;
        temp->next = NULL;
        cout<<endl;

        cout<<"Do you want to enter another data into the linked list (0/1)? : ";
        cin>>ch;
        cout<<endl;
        if(ch == 0){
            break;
        }

        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next;
    }
}

void displayList(struct Node *ptr){
    struct Node *temp;
    temp = ptr;

    while(temp != NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

struct Node* reverseList(struct Node *ptr){
    struct Node *prev , *temp, *cur;
    cur = ptr;
    prev = NULL;

    while(cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

struct Node* insertAtLast(struct Node *head){
    struct Node *p = head;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter data: ";
    cin>>temp->data;
    cout<<endl;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;

    return head;
}

struct Node* insertAtFirst(struct Node *head){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter data: ";
    cin>>temp->data;
    cout<<endl;

    temp->next = head;
    head = temp;

    return head;
}

void deleteLastNode(struct Node *head){
    struct Node *p;
    struct Node *d;

    p = head;
    d = head;
    p = p->next;

    while(p->next != NULL){
        p = p->next;
        d = d->next;
    }

    d->next = NULL;
    free(p);
}

struct Node* deleteNode(struct Node *head, int index){
    struct Node *p, *q;
    p = head;
    int i = 0;

    for(int i=1;i<index;i++){
        p = p->next;
    }

    q = p->next;
    p->next = q->next;
    q->next = NULL;
    free(q);

    return head;
}

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p;
    createNode(head);
    //p = reverseList(head);
    displayList(head);
    //head = insertAtFirst(head);
    //deleteLastNode(head);
    deleteNode(head,2);
    displayList(head);

    return 0;
}
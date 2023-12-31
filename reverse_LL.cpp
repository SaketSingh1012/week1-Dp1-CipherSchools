// Reversing Linked List reccursively.

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data=data;
            next=NULL;
        }
};

node* recursivereverse(node * head)
{
    if(head->next==NULL or head==NULL){                     // Checking if the Linked list is empty or contain only one element, then it will return the head;
        return head;
    }

    node * shead = recursivereverse(head->next);        // Using recursion to set new head as last and 
    head->next -> next = head;
    head->next = NULL;
    return shead;
}

void insertathead(node * &head, int data)
{
    if(head==NULL){
        head=new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

void printll(node *head){
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    system("cls");
    node *head = NULL;

    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,0);

    cout<<"Linked List: \n";
    printll(head);

    head = recursivereverse(head);              // Passing the head to the function so it can use it to set new head. Which then will be saved in the head.

    cout<<"\nAfter reverse: \n";
    printll(head);
}
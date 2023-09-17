#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "memory is free for node with data " << value << endl;
    }
};

void print(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtBeginning(Node* &head,int data)
{
if(head == NULL)
{
    Node* temp = new Node(data);
    head = temp;
}else{
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

// return head;
}


void insertAtEnd(Node* head,int data)
{
    Node* temp = new Node(data);
    Node* curr = head;

    if(curr == NULL)
    {
        head = temp;
        //then no head node exist yet ,so set curr as head
    }else{
        while(curr -> next !=NULL){
            curr =curr -> next;
        }

        curr -> next = temp;

    }

    
}

void deleteFirst(Node* &head){
    Node* temp = head;

    if(head == NULL)
        return ;

    head = head -> next;
    temp ->next = NULL;
    delete temp;
    return;

}

void deleteLast(Node* head)
{
    Node* temp = NULL;
    Node* curr = head;

    if(head == NULL)
        return;

    while(curr -> next){
        temp = curr ;
        curr = curr -> next;
    }

    temp -> next = NULL;
    delete curr;
    
}

int main()
{
Node* head = new Node(1);
cout << head<<endl;
// head=
insertAtBeginning(head,2);
print(head);
cout<<head<<endl;
insertAtEnd(head,0);
insertAtEnd(head,0);
insertAtEnd(head,0);
print(head);
cout << head<<endl;
deleteFirst(head);
print(head);
cout << head << endl;
deleteLast(head);
print(head);
cout << head << endl;
return 0;
}
#include<iostream>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~DLLNode()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            delete prev;
            prev=NULL;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

void insert(DLLNode* &head,int data, int position)
{
    int count=1;
    DLLNode* curr = head;
    // cout<<"value of curr "<<curr<<" value of head "<<head<<endl;
    DLLNode* newNode = new DLLNode(data);

    if(position ==1)
    {
        newNode ->next = head;
        head = newNode;

        return ;
    }



    while(count < position-1 && curr->next != NULL){
        curr=curr->next;
        count++;
    }


    if(count < position -1){
        cout<<"Desire position does not exist\n";
    }

    newNode->next=curr->next;
    newNode->prev = curr;

    if(curr->next)
        curr->next->prev= newNode;

    curr ->next = newNode;

    return;
}

void print(DLLNode *head)
{
    DLLNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtHead(DLLNode *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        DLLNode *temp = new DLLNode(d);
        head = temp;
        
    }
    else
    {
        DLLNode *temp = new DLLNode(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void deleteFirstNode(DLLNode* &head){
    if(head==NULL)
    {
        cout<<"Head is Empty";
        return;
    }

    DLLNode* temp= head;
    head= head->next;
    head->prev = NULL;
    temp->next=NULL;
    delete temp;
    return;

    // DLLNode *temp = head;
    // temp->next->prev = NULL;
    // head = temp->next;
    // temp->next = NULL;
    // // memory free start
    // delete temp;
}

void deleteLastNode(DLLNode* head)
{

    DLLNode* curr = head;
    if(head==NULL)
    {
        cout<<"DLL is empty"<<endl;
        return;
    }

    while(curr->next!=NULL)
        curr = curr -> next;

    DLLNode* temp = curr->prev;
    temp -> next = curr -> next;
    delete curr;
    return;
}

void deleteNode(DLLNode* &head,int position)
{
    int count = 1;
    DLLNode *temp = head;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
   
    
    if(position == 1)
    {
        head = head -> next;

        if(head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }

    while(count<position && temp->next != NULL)
    {
        temp = temp -> next;
        count++;
    }

    if(count < position){
        cout<<"desired position doesn't exist \n";
        return;
    }

    DLLNode* temp2 = temp -> prev;
    temp2 -> next = temp -> next;
    if(temp->next)
    {
        temp -> next -> prev = temp2;
    }

    delete temp;

    return;
}

int main()
{
    DLLNode *newOne = new DLLNode(1);
    // DLLNode* tail = NULL; 
    insertAtHead(newOne, 10);
    insertAtHead(newOne, 15);
    insertAtHead(newOne, 20);
    insertAtHead( newOne, 25);
    print(newOne);
    insert(newOne, 30, 1);
    print(newOne);
    insert(newOne, 5, 5);
    print(newOne);
    insert(newOne, 5, 7);
    print(newOne);
    deleteFirstNode(newOne);
    print(newOne);
    deleteLastNode(newOne);
    print(newOne);
    deleteNode(newOne,2);
    print(newOne);
    return 0;
}
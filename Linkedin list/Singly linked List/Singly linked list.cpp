#include<iostream>
using namespace std;

class LinkedList{
    public:
    int data;
    LinkedList *next;

    LinkedList(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~LinkedList()
    {
        int value=this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
 
        cout<<"memory is free for node with data"<< value<<endl;
    }
};


void print(LinkedList* &head)
{
    LinkedList* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

void insertAtHead(LinkedList *&head, int d)
{

    if(head==NULL)
    {
        LinkedList* temp = new LinkedList(d);
        head = temp;
    }else{
        // new node create
        LinkedList* temp = new LinkedList(d);
        temp->next = head;
        head = temp;
    }
}



void insertAtTail(LinkedList* &tail,int d)
{
    
        // new node create
        LinkedList* temp = new LinkedList(d);
        tail->next = temp;
}


void insertAtPosition(LinkedList* &tail,LinkedList* &head, int position, int d)
{
    //insert at start
    if(position==1)
    {
        insertAtHead(head,d);
        return ;
    }

    //inserting at last position
    LinkedList* temp = head;
    int cnt = 1;

    while(cnt<position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d

    LinkedList* nodeToInsert = new LinkedList(d);
    nodeToInsert -> next = temp->next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, LinkedList* &head)
{
    //deleting first or start node 
    if(position == 1)
    {
        LinkedList* temp = head;
        head = head->next;
        temp->next=NULL;
        //memory free start
        delete temp;
    } 
    else{
        //deleting any middle node or last node 
    LinkedList* curr = head;
    LinkedList*prev = NULL;

    int cnt = 1;
    while(cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
        prev -> next = curr->next; 
        curr->next=NULL;
        delete curr;
    }
}

int main() 
{
    LinkedList* node1 = new LinkedList(10);
    // cout<<node1->data<<endl;
    // cout<< node1->next << endl;

    LinkedList* head = node1;
    LinkedList* tail = node1;

    print(head);
    insertAtHead(head,12);
    print(head);

    insertAtTail(tail,200);
    print(head);

    insertAtPosition(tail,head,2,222);
    print(head);
    
    insertAtPosition(tail, head, 4, 222);
    print(head);

    deleteNode(1,head);
    print(head);
    
    return 0;
}


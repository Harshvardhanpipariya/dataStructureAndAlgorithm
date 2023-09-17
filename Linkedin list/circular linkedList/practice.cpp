#include <iostream>
using namespace std;

class circularNode
{
public:
    int data;
    circularNode *next;

    // constructor
    circularNode(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~circularNode()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(circularNode *&head, int data)
{
    circularNode* current = head;
    circularNode* newNode = new circularNode(data);
    

    if(current == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        return ;
    }

    while(current -> next != head)
    {
        current = current -> next;
        
    }

    current->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(circularNode* &head,int data)
{
//    cout<<"tail function start"<<endl;
    circularNode *N = new circularNode(data);
    circularNode *curr = head;
    if(head==NULL)
    {

        head = N;
        N->next = N;
        return;
    }


   

    while(curr->next != head){
        // cout << "middle of tail function" << endl;
        curr = curr -> next;
    }

    // curr -> next = N;
    // N -> next = head;

    N -> next = curr-> next;
    curr->next = N;
    
}





int length(circularNode* head)
{
    circularNode *curr = head;
    // cout<<tail->data<<" ";

    // while(tail->next != curr){
    //     cout<<tail->data<<" ";
    //     tail = tail->next;

    // }
    // cout<<" ";
    int count = 0;
    do{
        head = head->next;
       count++;
    } while (head != curr);

    return count;
}



void display(circularNode* head)
{
    cout<<"in print function"<<endl;
    circularNode* temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;
}

int main()
{
circularNode* head = NULL;
cout<<"Start of the Program"<<endl;

insertAtTail(head,12);
display(head);

insertAtTail(head,13);
display(head);
insertAtTail(head, 14);
display(head);
insertAtTail(head,15);
display(head);

insertAtHead(head,50);
display(head);

int ans = length(head);
cout<<"ans "<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int totalCapacity;
    int *arr;
    int top;
public:
    Stack(int val);
    void push(int val);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    
};

Stack::Stack(int val)
{
    totalCapacity = val;
    arr = new int[totalCapacity];
    top = -1; 
}

void Stack::push(int val)
{
    if(top>totalCapacity-1)
    {
        cout<<"overflow"<<endl;
        return;
    }
    top++;
    arr[top] = val;
}

int Stack::pop()
{
    if (top<=-1)
    {
        cout << "Underflow" << endl;
        return 0;
    }
    int returnValue = arr[top];
    top--;

    return returnValue;
}

int Stack ::peek()
{
    if (top <= -1)
    {
        cout << "Underflow" << endl;
        return 0;
    }

    return arr[top];
}


int Stack :: size()
{
    return top+1;
}


bool Stack :: isEmpty()
{
    return (top == (-1) );
}



    int main()
{

    Stack s(19);
    s.push(21);
    s.push(22);
   cout<< s.size()<<endl;
   cout<< s.isEmpty()<<endl;
   cout<< s.peek()<<endl;
   s.pop();
   s.pop();
   cout << s.isEmpty() << endl;

   return 0;
}
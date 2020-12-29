#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class Stack{
private:
    node *top;


public:
    // Constructor
    Stack(){
        top = NULL;
    }

    void push(int val){
        node *newNode = new node;
        newNode -> data = val;
        if(isEmpty()){
            newNode -> next = NULL;
        } else {
            newNode -> next = top;
        }
        top = newNode;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        node *temp = top;
        top = top -> next;
        delete temp;
    }

    void printAll(){
        while(!isEmpty()){
            cout << top -> data << " ";
            pop();
        }
    }

    bool isEmpty(){
        if(top == NULL)
            return 1;

        return 0;
    }

    // Destructor
    ~Stack(){
        node *temp = top;
        while(temp -> next != NULL){
            temp = temp -> next;
            delete top;
            top = temp;
        }
    }
};

int main()
{
    Stack q1;
    q1.push(1);
    q1.push(109);
    q1.push(23);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.printAll();
    q1.~Stack();
}

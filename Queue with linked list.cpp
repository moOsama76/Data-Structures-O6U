#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class Queue{
private:
    node *Front;
    node *Rear;

public:
    // Constructor
    Queue(){
        Front = NULL;
        Rear = NULL;
    }

    void enqueue(int n){
        node *newNode = new node;
        newNode -> data = n;
        newNode -> next = NULL;
        if(isEmpty()){
            Front = newNode;
            Rear = newNode;
        } else {
            Rear -> next = newNode;
            Rear = newNode;
        }
    }

    void dequeue(){
        if(isEmpty())
            return;
        node *temp = Front;
        Front = Front -> next;
        delete temp;
    }

    void print(){
        node *temp = Front;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    bool isEmpty(){
        if(Front == NULL && Rear == NULL)
            return 1;

        return 0;
    }

    // Destructor
    ~Queue(){
        node *temp = Front;
        while(temp -> next != NULL){
            temp = temp -> next;
            delete Front;
            Front = temp;
        }
    }
};

int main()
{
    /*Queue q1;
    q1.enqueue(1);
    q1.enqueue(109);
    q1.enqueue(23);
    q1.dequeue();
    q1.dequeue();
    q1.print();
    q1.~Queue();*/
}

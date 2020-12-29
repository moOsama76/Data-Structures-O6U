#include <iostream>
using namespace std;

const int MAX = 100;

class Stack{
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack(){
        top = -1;
    }

    void push(int val){
        if(isFull()){
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        top--;
    }

    void printAll(){
        while(!isEmpty()){
            cout << arr[top] << " ";
            pop();
        }
    }

    bool isEmpty(){
        if(top == -1)
            return 1;

        return 0;
    }

    bool isFull(){
        if(top == MAX-1)
            return 1;

        return 0;
    }

    // Destructor
    ~Stack(){
        delete arr;
    }
};

int main()
{
    Stack q1;
    q1.push(1);
    q1.push(109);
    q1.push(23);

    q1.printAll();
    q1.~Stack();
}

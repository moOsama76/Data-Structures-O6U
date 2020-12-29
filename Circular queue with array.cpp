#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue{
    private:
    int arr[MAX];
    int Front = -1;
    int Rear = -1;

    
    public:
    void enqueue (int val){
        if (isEmpty()){
            Front = 0;
            Rear = 0;
        } else {
            Rear = (Rear + 1) % MAX;
        }
        arr[Rear] = val;
    }

    void dequeue(){
        if (isEmpty()){
            return;
        }

        if (Front == Rear){
            Front = Rear = -1;
        } else {
            Front = (Front + 1) % MAX;
        }
    }
    
    void printAll(){
        if(isEmpty()){
            return;
        }

        for (int i = Front; i <= Rear; i++){
            cout << arr[i] << " ";
        }
    }

    bool isEmpty(){
        if (Front == -1 && Rear == -1){
            return 1;
        }

        return 0;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.dequeue();
    q1.printAll();
    return 0;
}

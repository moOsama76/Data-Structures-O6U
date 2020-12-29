#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class linkedList{
private:
    node *head;
public:
    //Constructor
    linkedList(){
        head = NULL;
    }

    void insertFirst(int val){
        node *newNode = new node;
        newNode -> data = val;
        if(isEmpty()){
            newNode -> next = NULL;
        } else {
            newNode -> next = head;
        }
        head = newNode;
    }

    void insertLast(int val){
        node *newNode = new node;
        newNode -> data = val;
        newNode -> next = NULL;
        if(isEmpty()){
            head = newNode;
        } else {
            node *temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }

    }
    void deleteFirst(){
        if(isEmpty()){
            return;
        }

        node *temp = head;
        head = head -> next;
        delete temp;
    }

    void deleteLast(){
        if(isEmpty()){
            return;
        }

        if(head -> next == NULL){
            deleteFirst();
        } else {
            node *temp = head;
            while(temp -> next -> next != NULL){
                temp = temp -> next;
            }

            delete temp -> next;
            temp -> next = NULL;
        }
    }

    int maxElement(){
        node *temp = head;
        int mx = -1;
        while(temp != NULL){
            mx = max(mx, temp -> data);
            temp = temp -> next;
        }
        return mx;
    }

    int minElement(){
        node *temp = head;
        int mn = 1000000000;
        while(temp != NULL){
            mn = min(mn, temp -> data);
            temp = temp -> next;
        }
        return mn;
    }

    void revers(){
        if(isEmpty() || head -> next == NULL){
            return;
        }

        node *pre = NULL;
        node *curr = head;
        node *next = NULL;

        while(curr -> next != NULL){
            next = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = next;
        }

        head = curr;
        head -> next = pre;
    }

    void print(){
        node *temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    bool isEmpty(){
        if(head == NULL){
            return 1;
        }

        return 0;
    }
    // Destructor
    ~linkedList(){
        node *temp = head;
        while(temp != NULL){
            temp = temp -> next;
            delete head;
            head = temp;
        }
    }
};
int main()
{
    linkedList l1;
    l1.insertLast(5);
    l1.insertLast(32);
    l1.insertFirst(25);
    l1.revers();
    l1.print();
}

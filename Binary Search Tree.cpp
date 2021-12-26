#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *right;
    node *left;
};

class BST{
private:
    node *root;
public:
    BST(){
        root = NULL;
    }
    node *getRoot(){
        return root;
    }

    node *createNode(int val){
        node *newNode = new node;
        newNode -> data = val;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    void insertNode(int val){
        node *newNode = createNode(val);

        if(root == NULL){
            root = newNode;
            return;
        }

        node *tempRoot = NULL;
        node *temp = root;
        while(temp != NULL){
            tempRoot = temp;
            if(val < temp -> data){
                temp = temp -> left;
            } else {
                temp = temp -> right;
            }
        }

        if(val < tempRoot -> data){
            tempRoot -> left = newNode;
        } else {
            tempRoot -> right = newNode;
        }
    }

    void inorder(node *currRoot){
        if(currRoot == NULL)
            return;
        inorder(currRoot -> left);
        cout << currRoot -> data << " ";
        inorder(currRoot -> right);

    }
    void preorder(node *currRoot){
        if(currRoot == NULL)
            return;
        cout << currRoot -> data << " ";
        preorder(currRoot -> left);
        preorder(currRoot -> right);

    }
    void postorder(node *currRoot){
        if(currRoot == NULL)
            return;
        postorder(currRoot -> left);
        postorder(currRoot -> right);
        cout << currRoot -> data << " ";

    }
};
int main() {
    BST bst1;
    bst1.insertNode(10);
    bst1.insertNode(5);
    bst1.insertNode(20);
    bst1.insertNode(8);
    bst1.insertNode(30);
    bst1.postorder(bst1.getRoot());
}

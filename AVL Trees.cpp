#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *right;
    node *left;
    int height;
};

class AVL{
private:
    node *root;
public:
    AVL(){
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
        newNode -> height = 1;
        return newNode;
    }

    int calcHeight(node *currRoot){
        if(currRoot == NULL)
            return 0;
        return currRoot -> height = max(calcHeight(currRoot -> left), calcHeight(currRoot -> right)) + 1;

    }
    int BalanceFactor(node *currRoot){
        int left = 0, right = 0;
        if(currRoot->left != NULL)
            left = currRoot->left->height;
        if(currRoot->right != NULL)
            right = currRoot->right->height;
        return left-right;
    }
    node *ll(node *currRoot){
        node *temp;
        temp = currRoot -> left;
        currRoot -> left = temp -> right;
        temp -> right = currRoot;
        return temp;
    }
    node * rr(node *currRoot){
        node *temp;
        temp = currRoot -> right;
        currRoot -> right = temp -> left;
        temp -> left = currRoot;
        return temp;
    }
    node * lr(node *currRoot){
        node *temp;
        temp = currRoot -> left;
        currRoot -> left = rr(temp);
        return ll(currRoot);
    }
    node * rl(node *currRoot){
        node *temp;
        temp = currRoot -> right;
        currRoot -> right = ll(temp);
        return rr(currRoot);
    }
    bool backtrackUnbalanced(node *&currRoot, int val){
        if(currRoot -> data == val)
            return true;
        bool tryRight = false, tryLeft = false;
        if(val <= currRoot -> data)
            tryLeft = backtrackUnbalanced(currRoot -> left, val);
        else
            tryRight = backtrackUnbalanced(currRoot -> right, val);
        if(tryLeft || tryRight){
            if(BalanceFactor(currRoot) < -1){
                if(BalanceFactor(currRoot -> right) < 0){
                    currRoot = rr(currRoot);
                } else {
                    currRoot = rl(currRoot);
                }
            } else if(BalanceFactor(currRoot) > 1) {
                if(BalanceFactor(currRoot -> left) > 0){
                    currRoot = ll(currRoot);
                } else {
                    currRoot = lr(currRoot);
                }
            }
        }
        return tryRight|| tryLeft;
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
        calcHeight(root);
        backtrackUnbalanced(root, val);
    }

    void inorder(node *currRoot){
        if(currRoot == NULL)
            return;
        inorder(currRoot -> left);
        cout << currRoot -> data << " ";
        inorder(currRoot -> right);

    }
    void preorderWithChildren(node *currRoot){
        if(currRoot == NULL)
            return;
        cout << currRoot -> data << " ";
        if(currRoot -> left)
            cout << currRoot -> left -> data << " ";
        if(currRoot -> right)
            cout << currRoot -> right -> data << " ";
        cout << '\n';
        preorderWithChildren(currRoot -> left);
        preorderWithChildren(currRoot -> right);

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
    AVL avl1;
    for(int i = 10; i >= 1; i--){
        avl1.insertNode(i);
    }
    /*avl1.insertNode(10);
    avl1.insertNode(8);
    avl1.insertNode(12);
    avl1.insertNode(14);
    avl1.insertNode(13);
    //avl1.insertNode(13);*/
    avl1.preorderWithChildren(avl1.getRoot());
}

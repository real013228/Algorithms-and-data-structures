#include <iostream>
#include <string>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int ky){
        this->key = ky;
        left = right = nullptr;
    }
};


Node* treeMax(Node* tree) {
    if(tree->right == nullptr){
        return tree;
    }
    return treeMax(tree->right);
}

Node* treeMin(Node* tree) {
    if(tree->left == nullptr){
        return tree;
    }
    return treeMin(tree->left);
}

void insert(Node** tree, int key){
    if(*tree == nullptr){
        *tree = new Node(key);
    } else {
        if(key < (*tree)->key){
            if((*tree)->left != nullptr){
                insert(&(*tree)->left, key);
            } else {
                (*tree)->left = new Node(key);
            }
        }
        if(key > (*tree)->key){
            if((*tree)->right != nullptr){
                insert(&(*tree)->right, key);
            } else {
                (*tree)->right = new Node(key);
            }
        }
    }
}

Node* treeSuccessor(Node* tree, int key){
    Node* current = tree;
    Node* successor = nullptr;
    while(current != nullptr){
        if(current->key > key){
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

Node* treePrevious(Node* tree, int key){
    Node* current = tree;
    Node* successor = nullptr;
    while(current != nullptr){
        if(current->key < key){
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return successor;
}

Node* remove(Node** tree, int key){
    if(tree == nullptr){
        return *tree;
    }
    if(key < (*tree)->key){
        (*tree)->left = remove(&(*tree)->left, key);
    }
    else if(key > (*tree)->key){
        (*tree)->right = remove(&(*tree)->right, key);
    }
    else if((*tree)->left != nullptr  && (*tree)->right != nullptr){
        (*tree)->key = treeMin((*tree)->right)->key;
        (*tree)->right = remove(&(*tree)->right, (*tree)->key);
    } else{
        if((*tree)->left != nullptr){
            *tree = (*tree)->left;
        }
        else if((*tree)->right != nullptr){
            *tree = (*tree)->right;
        } else{
            *tree = nullptr;
        }
    }
    return *tree;
}
bool check(Node* tree, int key) {
    if(tree == nullptr){
        return false;
    }
    if (tree->key == key) {
        return true;
    }
    if (key < tree->key) {
        if (tree->left != nullptr) {
            return check(tree->left, key);
        } else {
            return false;
        }
    } else {
        if (tree->right != nullptr) {
            return check(tree->right, key);
        } else {
            return false;
        }
    }
}

int main() {
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    string str;
    Node *tree = nullptr;
    while (cin >> str) {
        int num;
        cin >> num;
        if (str == "insert") {
            insert(&tree, num);
        }
        if (str == "exists") {
            if (check(tree, num)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        if (str == "delete") {
            if (check(tree, num))
                remove(&tree, num);
        }
        if (str == "next") {
            if (tree && treeMax(tree)->key > num) {
                cout << treeSuccessor(tree, num)->key << endl;
            } else {
                cout << "none" << endl;
            }
        }
        if (str == "prev") {
            if (tree && treeMin(tree)->key < num) {
                cout << treePrevious(tree, num)->key << endl;
            } else {
                cout << "none" << endl;
            }
        }
    }
    return 0;
}

#include <iostream>
 
using namespace std;
 
typedef struct Node{
    int key; //Поле значения
    Node *left; // Указатели на левую и правую поддеревья
    Node *right;
}tree;
tree* firstNode(int key, tree* root){
    root = new tree;
    root->key = key;
    root->right = NULL;
    root->left = NULL;
    return root;
}
tree* add(int key){
    tree* node;
    node = new tree;
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    return node;
}
tree* TreeSearch(tree* node, int value){
    while((node->left != NULL || node->right != NULL) && value != node->key){
        if(value < node->key){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return node;
}
 
void create(int key, tree* root){
    if(key < root->key){
        if(root->left != NULL){
            create(key, root->left);
        }
        else{
            root->left = add(key);
        }
    }
    else{
        if(root->right != NULL){
            create(key, root->right);
        }
        else{
            root->right = add(key);
        }
    }
}
 
int height(tree* root){
    if(root)
        return 1 + max(height(root->left), height(root->right));
}
 
int main()
{
    freopen("height.in","r",stdin);
    freopen("height.out","w",stdout);
    tree *root = NULL;
    int n;
    cin >> n;
    int arr[2000001];
    int leftpointer[2000001];
    int rightpointer[2000001];
    for(int i = 0; i < n; i++){
        cin >> arr[i] >> leftpointer[i] >> rightpointer[i];
    }
    root = firstNode(arr[0], root);
    for(int i = 0; i < n; i++){
        if(leftpointer[i]!= 0){
            create(arr[leftpointer[i] - 1], root);
        }
        if(rightpointer[i] != 0){
            create(arr[rightpointer[i] - 1], root);
        }
    }
    if(n == 0){
        cout << '0';
        return 0;
    }
    cout << height(root);
    return 0;
}
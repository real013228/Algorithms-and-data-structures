#include <iostream>

using namespace std;

struct Node{
    int key; //Поле значения
    int left = 0; // Указатели на левую и правую поддеревья
    int right = 0;
};
//tree* firstNode(int key, tree* root){
//    root = new tree;
//    root->key = key;
//    root->right = NULL;
//    root->left = NULL;
//    return root;
//}
//tree* add(int key){
//    tree* node;
//    node = new tree;
//    node->key = key;
//    node->right = NULL;
//    node->left = NULL;
//    return node;
//}
//tree* TreeSearch(tree* node, int value){
//    while((node->left != NULL || node->right != NULL) && value != node->key){
//        if(value < node->key){
//            node = node->left;
//        }
//        else{
//            node = node->right;
//        }
//    }
//    return node;
//}
//
//void create(int key, tree* root){
//    if(key < root->key){
//        if(root->left != NULL){
//            create(key, root->left);
//        }
//        else{
//            root->left = add(key);
//        }
//    }
//    else{
//        if(root->right != NULL){
//            create(key, root->right);
//        }
//        else{
//            root->right = add(key);
//        }
//    }
//}
Node tree[200005]; // global initialization tree
int height(int index){
    if(index != 0)
        return 1 + max(height(tree[index].left), height(tree[index].right)); //recurrent formule of searching max height of tree
}



int main()
{
    freopen("height.in","r",stdin);
    freopen("height.out","w",stdout);
    int n;
    cin >> n;
    int arr[200002];
    int leftpointer[200002];
    int rightpointer[200002];
    for(int i = 1; i <= n; i++){
        cin >> arr[i] >> leftpointer[i] >> rightpointer[i]; //input
        tree[i].key = arr[i];
        tree[i].left = leftpointer[i];
        tree[i].right = rightpointer[i];
    }
    if(n == 0){
        cout << '0';
        return 0;
    }
    cout << height(1);
    return 0;
}

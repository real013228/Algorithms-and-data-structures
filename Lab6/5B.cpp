
#include <iostream>
 
using namespace std;
 
struct Node {
    int key{}; //Поле значения
    int left = 0; // Указатели на левую и правую поддеревья
    int right = 0;
};
///    root = new tree;
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
//}/tree* firstNode(int key, tree* root){
 
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
Node tree[200005];
int array[200005];
int g_cnt(1);
 
void global_arr(int key){
    array[::g_cnt] = key;
    ::g_cnt++;
    int cnt = ::g_cnt;
}
 
void inorder_tree_walk(int index, int n) {
    int cnt;
    if (index != 0) {
        inorder_tree_walk(tree[index].left, n);
        global_arr(tree[index].key);
        inorder_tree_walk(tree[index].right, n);
    }
}
 
 
 
int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    cin >> n;
    int arr[200002];
    int leftPointer[200002];
    int rightPointer[200002];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> leftPointer[i] >> rightPointer[i];
        tree[i].key = arr[i];
        tree[i].left = leftPointer[i];
        tree[i].right = rightPointer[i];
    }
//    if (n == 0) {
//        cout << '0';
//        return 0;
//    }
    inorder_tree_walk(1, n);
    int flag = 1;
    for(int i = 1; i < n; i++){
        if(array[i] >= array[i+1]){
            flag = 0;
        }
        if (flag == 0){
            cout << "NO";
            break;
        }
    }
    if(flag){
        cout << "YES";
    }
    return 0;
}
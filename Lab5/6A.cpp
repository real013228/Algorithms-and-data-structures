#include <iostream>
#include <string>
 
struct List{
    int key;
    int value;
    bool flag;
    List* next;
    List(int key, int value){
        this->key = key;
        this->value = value;
        this->flag = true;
        this->next = nullptr;
    }
};
void insert(List **node, int key1, int value1){
    if(*node == nullptr || !(*node)->flag){
        if(*node != nullptr){
            List* pointerToNext = (*node)->next;
            *node = new List(key1, value1);
            (*node)->next = pointerToNext;
        } else{
            *node = new List(key1, value1);
 
        }
    } else {
        insert(&(*node)->next, key1, value1);
    }
}
void remove(List **node, int value1){
    if(*node == nullptr){
        return;
    } else {
        if((*node)->value == value1){
            (*node)->flag = false;
            return;
        } else {
            remove(&(*node)->next, value1);
        }
    }
}
bool exist(List **node, int value1){
    if(*node == nullptr){
        return false;
    } else {
        if((*node)->value == value1 && (*node)->flag){
            return true;
        } else{
            exist(&(*node)->next, value1);
        }
    }
}
int hashIt(int value){
    return abs(value % 98317);
}
 
List *array[98317] = {};
int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    int num = 0;
    std::string request;
    std::string inserting = "insert";
    std::string removing = "delete";
    std::string existing = "exists";
    while(std::cin >> request){
        std::cin >> num;
        if(request == inserting){
            if(!exist(&array[hashIt(num)], num))
                insert(&array[hashIt(num)], hashIt(num), num);
        }
        if(request == removing){
            remove(&array[hashIt(num)], num);
        }
        if(request == existing){
            if(exist(&array[hashIt(num)], num)){
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        }
    }
}
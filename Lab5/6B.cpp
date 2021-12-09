#include <iostream>
#include <cstdlib>
#define SIZE 100001
template<typename T>
class List {
    struct Node {
        T key;
        T value;
        Node *prev;
        Node *next;
        bool flag;
 
        Node() {
            flag = true;
            prev = nullptr;
            next = nullptr;
        }
    };
 
    Node *tail;
    Node *head;
public:
    List() = default;
 
    ~List() {
        while (head) {
            tail = head->next;
            delete head;
            head = tail;
        }
    }
 
    void add(T key, T value) {
        Node *temp = new Node;
        temp->next = nullptr;
        temp->key = key;
        temp->value = value;
        temp->flag = true;
        if (head && head->flag) {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        } else {
            temp->prev = nullptr;
            head = tail = temp;
        }
    }
 
    void remove(T key) {
        Node *curNode = head;
        while (curNode) {
            if (curNode->key == key) {
                if (curNode == head) {
                    head = head->next;
                    if (head) {
                        head->prev = nullptr;
                    } else {
                        tail = nullptr;
                    }
                    break;
                } else if (curNode == tail) {
                    tail = tail->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                    break;
                } else {
                    curNode->prev->next = curNode->next;
                    curNode->next->prev = curNode->prev;
                    curNode = nullptr;
                    break;
                }
            } else {
                curNode = curNode->next;
            }
        }
    }
 
    bool exist(T key) {
        Node *curNode = head;
        if (curNode == nullptr) {
            return false;
        }
        while (curNode) {
            if (curNode->key == key && curNode->flag) {
                return true;
            } else {
                curNode = curNode->next;
            }
        }
    }
 
    void reWrite(T key, T value) {
        Node *curNode = head;
        while (curNode) {
            if (curNode->key == key && curNode->flag) {
                curNode->value = value;
                return;
            } else {
                curNode = curNode->next;
            }
        }
    }
 
    void get(T key) {
        Node *curNode = head;
        if (curNode == nullptr) {
            std::cout << "none\n";
            return;
        }
        while (curNode) {
            if (curNode->key == key && curNode->flag) {
                std::cout << curNode->value << '\n';
                return;
            } else {
                curNode = curNode->next;
            }
        }
        std::cout << "none\n";
    }
 
    void show() {
        Node *temp = head;
        while (temp) {
            std::cout << temp->key << ": " << temp->value << '\n';
            temp = temp->next;
        }
    }
};
unsigned long long hashIt(const std::string& key){
    int seed = 131;
    unsigned long long hash = 0;
    for(char i : key)
    {
        hash = (hash * seed) + i;
    }
    return hash % SIZE;
}
//unsigned long long hashIt(const std::string& key){
//    unsigned long long hash = key[0];
//    return hash % SIZE;
//}
 
int main() {
    List<std::string> array[SIZE] = {};
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    freopen("map.in","r",stdin);
    freopen("map.out","w",stdout);
    std::string request;
    std::string inserting = "put";
    std::string removing = "delete";
    std::string existing = "get";
    while (std::cin >> request) {
        if (request == inserting) {
            std::string key, value;
            std::cin >> key >> value;
            if (array[hashIt(key)].exist(key)) {
                array[hashIt(key)].reWrite(key, value);
            } else {
                array[hashIt(key)].add(key, value);
            }
        }
        if (request == removing) {
            std::string key;
            std::cin >> key;
            array[hashIt(key)].remove(key);
        }
        if (request == existing) {
            std::string key;
            std::cin >> key;
            array[hashIt(key)].get(key);
        }
    }
 
    return 0;
}
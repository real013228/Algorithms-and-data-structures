#define SIZE 100001

class Node {
public:
    std::string key;
    std::string value;
    Node *oldest;
    Node *newest;
    Node *prev;
    Node *next;
    bool flag{};
    Node() {
        prev = nullptr;
        next = nullptr;
        oldest = nullptr;
        newest = nullptr;
    }
};
class List {
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
    Node* add(std::string key, std::string value, Node* prev) {
        Node *temp = new Node;
        temp->next = nullptr;
        temp->key = std::move(key);
        temp->value = std::move(value);
        temp->flag = true;
        temp->oldest = prev;
        if (head && head->flag) {
            prev->newest = temp;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        } else {
            if(prev)
                prev->newest = temp;
            temp->prev = nullptr;
            head = tail = temp;
        }
        return temp;
    }

    Node *reWrite(const std::string &key, const std::string &value, Node *prev) {
        Node *curNode = head;
        while (curNode) {
            if (curNode->key == key) {
                if(curNode->oldest){
                    curNode->oldest->newest = curNode->newest;
                }
                if(curNode->newest) {
                    curNode->newest->oldest = curNode->oldest;
                }
                curNode->newest = nullptr;
                curNode->oldest = prev;
                curNode->value = value;
                prev->newest = curNode;
                return curNode;
            } else {
                curNode = curNode->next;
            }
        }
        return curNode;
    }
    void remove(const std::string &key, Node **prev) {
        Node *curNode = head;
        while (curNode) {
            if (curNode->key == key) {
                *prev = curNode->newest;
                if(curNode->oldest && curNode->newest) {
                    curNode->oldest->newest = curNode->newest;
                    curNode->newest->oldest = curNode->oldest;
                } else {
                    if(curNode->oldest){
                        curNode->oldest->newest = curNode->newest;
                        curNode->oldest = nullptr;
                    }
                    if(curNode->newest){
                        curNode->newest->oldest = curNode->oldest;
                        curNode->newest = nullptr;
                    }
                }
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
                    break;
                }
            } else {
                curNode = curNode->next;
            }
        }
    }
    void prev(const std::string& key){
        Node *curNode = head;
        if (curNode == nullptr) {
            std::cout << "none\n";
            return;
        }
        while(curNode){
            if(curNode->key == key) {
                if(curNode->oldest)
                    std::cout << curNode->oldest->value << '\n';
                else
                    std::cout << "none\n";
                return;
            } else {
                curNode = curNode->next;
            }
        }
        std::cout << "none\n";
    }
    void next(const std::string& key){
        Node *curNode = head;
        if (curNode == nullptr) {
            std::cout << "none\n";
            return;
        }
        while(curNode){
            if(curNode->key == key) {
                if(curNode->newest)
                    std::cout << curNode->newest->value << '\n';
                else
                    std::cout << "none\n";
                return;
            } else {
                curNode = curNode->next;
            }
        }
        std::cout << "none\n";
    }
    bool exist(const std::string& key) {
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
        return false;
    }

    void get(const std::string& key) {
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

#include <iostream>
#include <string>
#include <cstdint>
#include <stdio.h>
#define qqMax 100001
#define maxValue 100001
//#define notation 65536
#define twoInEight 256

using namespace std;


struct Queue {
    int qu[qqMax]{};
    int head;
    int tail;

    Queue() {
        head = 1;
        tail = 0;
    }
};

void put(struct Queue *queue, uint16_t key) {
    queue->tail++;
    queue->qu[queue->tail] = key;
}

bool isEmpty(struct Queue *queue) {
    if (queue->tail < queue->head) {
        return true;
    } else {
        return false;
    }
}

//int getx(struct Queue *queue) {
//    uint16_t key;
//    if(isEmpty(queue)) {
//        return 0;
//    }
//    key = queue->qu[queue->head];
//    queue->head++;
//    return key;
//}
int get(struct Queue *queue) {
    uint16_t key;
    if (isEmpty(queue)) {
        printf("Очередь пуста!\n");
        return 0;
    }
    key = queue->qu[queue->head];
    for (int i = queue->head; i < queue->tail; i++) {
        queue->qu[i] = queue->qu[i + 1];
    }
    queue->tail--;
    return key;
}
string requests[maxValue];
uint16_t registers[26];
int main() {
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    string request;
    Queue queue;
    int ind = 0;
    int size = 0;
    while (cin >> request) {
        requests[size++] = request;
    }
    request = "";
    while(ind < size && request != "Q"){
        request = requests[ind++];
        if(request == "+"){
            put(&queue, get(&queue) + get(&queue));
            continue;
        }
        else if(request == "-"){
            put(&queue, get(&queue) - get(&queue));
            continue;
        }
        else if(request == "*"){
            put(&queue, get(&queue) * get(&queue));
            continue;
        }
        else if(request == "/"){
            uint16_t key1 = get(&queue);
            uint16_t key2 = get(&queue);
            if(key2 == 0){
                put(&queue, key2);
            } else{
                put(&queue, key1 / key2);
            }
            continue;
        }
        else if(request == "%"){
            uint16_t key1 = get(&queue);
            uint16_t key2 = get(&queue);
            if(key2 == 0){
                put(&queue, key2);
            } else{
                put(&queue, key1 % key2);
            }
            continue;
        }
        else if(request[0] == '>'){
            char reg = request[1];
            registers[reg - 'a'] = get(&queue);
            continue;
        }
        else if(request[0] == '<'){
            char reg = request[1];
            put(&queue, registers[reg - 'a']);
            continue;
        }
        else if(request == "P"){
            cout << get(&queue) << '\n';
            continue;
        }
        else if(request[0] == 'P'){
            char reg = request[1];
            cout << registers[reg - 'a'] << '\n';
            continue;
        }
        else if(request[0] == ':'){
            continue;
        }
        else if(request[0] == 'J'){
            string jump = request;
            jump[0] = ':';
            for(int i = 0; i < maxValue; i++){
                if(requests[i] == jump){
                    ind = i;
                    break;
                }
            }
            continue;
        }
        else if(request[0] == 'Z'){
            char reg = request[1];
            if(registers[reg - 'a'] == 0){
                string jump(request.size() - 1, 'a');
                jump[0] = ':';
                for(int i = 0; i < request.size(); i++){
                    jump[i + 1] = request[i + 2];
                }
                for(int i = 0; i < maxValue; i++){
                    if(requests[i] == jump){
                        ind = i;
                        break;
                    }
                }
            }
            continue;
        }
        else if(request == "C"){
            cout << char(get(&queue));
            continue;
        }
        else if(request[0] == 'C'){
            char reg = request[1];
            cout << char(registers[reg - 'a']);
        }
        else if(request[0] == 'E'){
            char reg1 = request[1];
            char reg2 = request[2];
            if(registers[reg1 - 'a'] == registers[reg2 - 'a']){
                string jump(request.size() - 2, 'a');
                jump[0] = ':';
                for(int i = 0; i < request.size(); i++){
                    jump[i + 1] = request[i + 3];
                }
                for(int i = 0; i < maxValue; i++){
                    if(requests[i] == jump){
                        ind = i;
                        break;
                    }
                }
            }
            continue;
        }
        else if(request[0] == 'G'){
            char reg1 = request[1];
            char reg2 = request[2];
            if(registers[reg1 - 'a'] > registers[reg2 - 'a']){
                string jump(request.size() - 2, 'a');
                jump[0] = ':';
                for(int i = 0; i < request.size(); i++){
                    jump[i + 1] = request[i + 3];
                }
                for(int i = 0; i < maxValue; i++){
                    if(requests[i] == jump){
                        ind = i;
                        break;
                    }
                }
            }
            continue;
        }
        else if(request == "Q"){
            break;
        }
        else{
            if(ind < size){
                uint16_t key = stoi(request);
                put(&queue, key);
            }
            continue;
        }
    }
    return 0;
}
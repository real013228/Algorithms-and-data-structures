#include <iostream>
#include <string>
 
using namespace std;
 
char stack[10000001];
 
bool stack_check(char *stack, int ind, char sym)
{
    if(ind < 0)
        return false;
    else
    {
        if(stack[ind] == '(')
        {
            if(stack[ind + 1] != ')')
            {
                return false;
            }
        }
        if(stack[ind] == '[')
        {
            if(stack[ind + 1] != ']')
            {
                return false;
            }
        }
        return true;
    }
}
 
void stack_push(char *stack, int ind, char sym)
{
    stack[ind] = sym;
}
 
void stack_remove(char *stack, int ind)
{
 
}
int main() {
    freopen("brackets.in","r",stdin);
    freopen("brackets.out", "w",stdout);
    string str;
    while(cin >> str) {
        bool flag = true;
        int head = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                stack_push(stack, head, str[i]);
                head++;
            }
            if (str[i] == ')' || str[i] == ']') {
                stack_push(stack, head, str[i]);
                head--;
                if (!stack_check(stack, head, str[i])) {
                    flag = false;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if (flag && head == 0)
            cout << "YES" << endl;
        if (flag && head != 0)
            cout << "NO" << endl;
    }
    return 0;
}
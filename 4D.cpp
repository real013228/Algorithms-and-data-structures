#include <iostream>
#include <string>
 
using namespace std;
 
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
 
void stack_push(int *stack, int ind, int num)
{
    stack[ind] = num;
}
 
void stack_remove(char *stack, int ind)
{
 
}
int main() {
    freopen("postfix.in","r",stdin);
    freopen("postfix.out", "w",stdout);
    int stack[1000001];
    char symbol;
    char add = '+';
    char minus = '-';
    char mult = '*';
    int ind = 0;
    while(cin >> symbol)
    {
        if(symbol != add && symbol != minus && symbol != mult)
        {
            int num = int(symbol - '0');
            stack_push(stack, ind, num);
            ind++;
        }
        else
        {
            int ans = 0;
            if(symbol == add)
            {
                ans = stack[ind - 1] + stack[ind - 2];
                ind -= 2;
                stack_push(stack, ind, ans);
            }
            if(symbol == minus)
            {
                ans = stack[ind - 2] - stack[ind - 1];
                ind -= 2;
                stack_push(stack, ind, ans);
            }
            if(symbol == mult)
            {
                ans = stack[ind - 1] * stack[ind - 2];
                ind -= 2;
                stack_push(stack, ind, ans);
            }
            ind++;
        }
    }
    cout << stack[ind - 1] << '\n';
    return 0;
}
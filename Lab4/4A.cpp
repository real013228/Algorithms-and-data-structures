#include <iostream>
using namespace std;
 
int main() {
    freopen("stack.in","r",stdin);
    freopen("stack.out", "w",stdout);
    int ans[1000001];
    int stack[1000001];
    int t;
    char push = '+';
    char remove = '-';
    cin >> t;
    int ind = 0;
    int ind_for_ans = 0;
    for(int _ = 0; _ < t; _++)
    {
        char first;
        cin >> first;
        if(first == push)
        {
            int num;
            cin >> num;
            stack[ind++] = num;
        }
        if(first == remove)
        {
            ans[ind_for_ans++] = stack[ind - 1];
            ind--;
        }
    }
    for(int i = 0; i < ind_for_ans; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
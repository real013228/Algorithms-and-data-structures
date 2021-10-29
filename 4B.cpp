#include <iostream>
using namespace std;
 
void _swap(int *arr, int head)
{
    for(int i = head - 1; i > 0; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
}
int main() {
    freopen("queue.in","r",stdin);
    freopen("queue.out", "w",stdout);
    int ans[1000001];
    int queue[1000001];
    int t;
    char push = '+';
    char remove = '-';
    cin >> t;
    int head = 0;
    int ind_for_ans = 0;
    for(int _ = 0; _ < t; _++)
    {
        char first;
        cin >> first;
        if(first == push)
        {
            int num;
            cin >> num;
            queue[head++] = num;
            _swap(queue, head);
        }
        if(first == remove)
        {
            ans[ind_for_ans++] = queue[head - 1];
            head--;
        }
    }
    for(int i = 0; i < ind_for_ans; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
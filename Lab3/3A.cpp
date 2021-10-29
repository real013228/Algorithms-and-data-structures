#include <iostream>
using namespace std;
 
int main()
{
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out","w", stdout);
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    bool flag = true;
    while(i < n && flag)
    {
        if(2 * (i + 1) + 1 <= n && flag)
        {
            if(2 * (i + 1) <= n)
            {
                if(arr[i] <= arr[2 * (i + 1) - 1] && arr[i] <= arr[2 * (i + 1) - 1])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                if(arr[i] <= arr[2 * (i + 1) - 1])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            i++;
        }
        else
        {
            if(2 * (i + 1) <= n && flag)
            {
                if(arr[i] <= arr[2 * (i + 1) - 1])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            i++;
        }
    }
    if(flag == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
#include <iostream>
#include <string>
 
using namespace std;
 
void bin_search1(int *arr, int length, int num)
{
    int cnt = 0;
    int left = 0;
    int right = length - 1;
    int ans1 = -1, ans2 = -1;
    while(right > left + 1)
    {
        int mid = (left + right)/ 2;
        if(num > arr[mid])
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    if(right < length && arr[right] == num)
    {
        if(arr[left] == num)
        {
            cout << left + 1;
        }
        else
        {
            cout << right + 1;
        }
    }
    else
    {
        cout << -1;
    }
}
void bin_search2(int *arr, int length, int num)
{
    int cnt = 0;
    int left = 0;
    int right = length - 1;
    int ans1 = -1, ans2 = -1;
    while(right > left + 1)
    {
        int mid = (left + right)/ 2;
        if(num < arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    if(right < length && arr[left] == num)
    {
        if(arr[right] == num)
        {
            cout << right + 1;
        }
        else
        {
            cout << left + 1;
        }
    }
    else
    {
        cout << -1;
    }
}
int main() {
    freopen("binsearch.in","r",stdin);
    freopen("binsearch.out", "w",stdout);
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num;
    int m;
    cin >> m;
    for(int _ = 0; _ < m; _++)
    {
        cin >> num;
        bin_search1(arr, n, num);
        cout << ' ';
        bin_search2(arr, n, num);
        cout << '\n';
    }
    return 0;
}
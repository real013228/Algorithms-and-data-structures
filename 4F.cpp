#include <iostream>
#include <string>
 
using namespace std;
 
//bool monotone_check(long long *arr, int n)
//{
//    for(int i = 1; i < n - 1; i++)
//    {
//        if(arr[i] > arr[i + 1])
//            return false;
//    }
//    return true;
//}
 
long long armwrestling(long long hi, long long hi1, int n)
{
    for(int i = 1; i < n; i++)
    {
        long long hi2 = 2 * hi1 + 200000 - hi;
        long long tmp = hi1;
        hi1 = hi2;
        hi = tmp;
        if(i == n - 2)
        {
            return hi2;
        }
    }
}
 
bool check(long long hi, long long hi1, int n)
{
    for(int i = 1; i < n - 1; i++)
    {
        long long hi2 = 2 * hi1 + 200000 - hi;
        if(hi2 < 0 || hi1 < 0 || hi < 0)
        {
            return false;
        }
        else
        {
            long long tmp = hi1;
            hi1 = hi2;
            hi = tmp;
        }
    }
    return true;
}
 
int main() {
    freopen("garland.in","r",stdin);
    freopen("garland.out", "w",stdout);
    int n;
//    long long *arr = new long long[n];
    int flag = 0;
    long long ans = 0;
    long long ans2 = 0;
    float h1;
    cin >> n >> h1;
    long long h1INT = h1 * 100000;
    long long left = 0;
    int del = 100;
    long long right = h1INT;
//    if (check(1000000, 437500, 3))
//        cout << armwrestling(1000000, 437500, 3) << '\n';
    long long hi = h1INT;
    while(right - left > 1)
    {
        long long hi1 = (right + left) / 2;
        if(check(hi, hi1, n))
        {
            ans = armwrestling(hi, hi1, n);
            right = hi1;
            ans2 = hi1;
            //cout << "arm!!!!!\n";
        }
        else
        {
            left = hi1;
        }
    }
    int cnt = 0;
    ans2 = ans;
    while(ans2 > 0)
    {
        ans2 /= 10;
        cnt++;
    }
 
    cout.precision(cnt - 3);
    if(ans == 0)
    {
        cout << "0.00";
    }
    else
    {
        cout << float(ans) / 100000.0;
    }
    return 0;
}
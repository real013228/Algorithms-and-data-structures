#include <iostream>
#define ll long long int
using namespace std;
ll nmax = 3000001;
ll ans = 0;
void Merge(ll *arr, ll left, ll mid, ll right)
{
    ll
            n1 = mid - left + 1,
            n2 = right - mid,
            d[nmax];
    ll L[n1 + 1], R[n2 + 1];
 
    for(ll i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    L[n1] = 1000000001;
    for(ll i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1];
    }
    R[n2] = 1000000001;
    ll
            i = 0,
            k = 0,
            j = 0;
    while(i < n1 || j < n2)
    {
        if(L[i] <= R[j])
        {
            ans += j;
            arr[left + k] = L[i];
            i++;
        }
        else
        {
            arr[left + k] = R[j];
            j++;
        }
        k++;
    }
}
void MergeSort(ll *arr, ll left, ll right)
{
    if(right > left)
    {
        ll mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
 
int main()
{
    freopen("inversions.in","r",stdin);
    freopen("inversions.out","w", stdout);
    ll n;
    ll arr[3000001];
    cin >> n;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    //for(ll i = 0; i < n; i++)
    //{
    //    cout << arr[i] << ' ';
    //}
    cout << ans << '\n';
}
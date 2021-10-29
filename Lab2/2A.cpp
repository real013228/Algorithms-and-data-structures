#include <iostream>
using namespace std;
int nmax = 300001;
int ans = 0;
void Merge(int *arr, int left, int mid, int right)
{
    int
            n1 = mid - left + 1,
            n2 = right - mid,
            d[nmax];
    int L[n1 + 1], R[n2 + 1];
 
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    L[n1] = 1000000001;
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1];
    }
    R[n2] = 1000000001;
    int
            i = 0,
            k = 0,
            j = 0;
    while(i < n1 || j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[left + k] = L[i];
            i++;
        }
        else
        {
            ans += j;
            arr[left + k] = R[j];
            j++;
        }
        k++;
    }
}
void MergeSort(int *arr, int left, int right)
{
    if(right > left)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
 
int main()
{
    //freopen("sort.in","r",stdin);
    //freopen("sort.out","w", stdout);
    int n;
    int arr[400000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    //cout << '\n' << ans << '\n';
}
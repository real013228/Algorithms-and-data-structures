#include <iostream>
using namespace std;
void qSort(int *arr, int left, int right, int k)
{
    if(left >= right)
    {
        return;
    }
    int
            key = arr[(left + right) / 2],
            i = left,
            j = right;
    while(i <= j)
    {
        while(arr[i] < key)
        {
            i++;
        }
        while(arr[j] > key)
        {
            j--;
        }
        if(i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(j + 1 >= k)
        qSort(arr, left, j, k);
    else
        qSort(arr, i, right, k);
}
int main()
{
    freopen("kth.in","r", stdin);
    freopen("kth.out","w", stdout);
    int n, k, A, B, C, a1, a2;
    cin >> n >> k;
    cin >> A >> B >> C >> a1 >> a2;
    int *arr = new int[n];
    arr[0] = a1;
    arr[1] = a2;
    for(int i = 2; i < n; i++)
    {
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
    }
    //swap(arr[(n - 1) / 2], arr[n - 1]);
    qSort(arr, 0, n - 1, k);
    /*for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }*/
    cout << arr[k - 1];
    return 0;
}
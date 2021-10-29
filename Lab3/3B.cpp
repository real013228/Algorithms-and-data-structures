#include <iostream>
using namespace std;
void Heapify(int *arr, int element, int size)
{
    int left = element * 2;
    int largest;
    int right = element * 2 + 1;
    if(left <= size && arr[left] > arr[element])
    {
        largest = left;
    }
    else
    {
        largest = element;
    }
    if(right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != element)
    {
        swap(arr[element], arr[largest]);
        Heapify(arr, largest, size);
    }
}
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = n / 2; i >= 1; i--)
    {
        Heapify(arr, i, n);
    }
    for(int i = n; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        int size = i;
        Heapify(arr, 1, size - 1);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
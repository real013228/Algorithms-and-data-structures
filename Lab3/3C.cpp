#include <iostream>
#include <string>
using namespace std;
char digit(string str, int razryad)
{
    return str[str.size() - razryad];
}
void radix(string *arr, int n, int m, int k)
{
    int C[1000];
    string A[1000];
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            C[j] = 0;
        }
        for(int j = 0; j < n; j++)
        {
            char d = digit(arr[j], i);
            C[int(d - 'a')]++;
        }
        int cnt = 0;
        for(int j = 0; j < 26; j++)
        {
            int tmp = C[j];
            C[j] = cnt;
            cnt += tmp;
        }
        for(int j = 0; j < n; j++)
        {
            char d = digit(arr[j], i);
            A[C[int(d - 'a')]] = arr[j];
            C[int(d - 'a')]++;
        }
        for (int j = 0; j < n; ++j) {
            arr[j] = A[j];
        }
    }
}
int main() {
    freopen("radixsort.in","r",stdin);
    freopen("radixsort.out","w",stdout);
    int
        n,
        k,
        m;
    cin >> n >> m >> k;
    string *arr = new string[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    radix(arr, n, m, k);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}
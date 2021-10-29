#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Merge(vector<pair<string,string>>* arr, int left, int mid, int right)
{
    int
            n1 = mid - left + 1,
            n2 = right - mid;
    vector<pair<string,string>> R(n2);
    vector<pair<string,string>> L(n1);
    for(int i = 0; i < n1; i++)
    {
        L[i] = (*arr)[left + i]; // *(arr + left + i) == arr[left + i]
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = (*arr)[mid + i + 1];
    }
    int
            i = 0,
            k = 0,
            j = 0;
    while(i < n1 && j < n2)
    {
        if(L[i].first.compare(R[j].first) <= 0)
        {
            (*arr)[left + k] = L[i];
            i++;
        }
        else
        {
            (*arr)[left + k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        (*arr)[left + k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        (*arr)[left + k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(vector <pair<string,string>>* arr, int left, int right)
{
    if(right > left)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1,  right);
        Merge(arr, left, mid, right);
    }
}
 
int main()
{
    freopen("race.in","r",stdin);
    freopen("race.out","w", stdout);
    int n;
    vector<pair<string,string>> arr;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string country, name;
        cin >> country >> name;
        arr.push_back(make_pair(country, name));
    }
    MergeSort(&arr, 0, n - 1);
    int i = 0;
    string tmp = "please_give_me_100_balls(scores)";
    while(i < n)
    {
        if(arr[i].first != tmp)
        {
            cout <<"=== " << arr[i].first << " ===" << endl;
            tmp = arr[i].first;
        }
        cout << arr[i].second << '\n';
        i++;
    }
 
 
    return 0;
}
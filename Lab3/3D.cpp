#include <iostream>
#include <string>
using namespace std;
int arr[1000001];
int pushel[1000001];
class queue
{
public:
    int *arr;
    void push(int num, int Size)
    {
        for(int i = 0; i <= Size; i++)
        {
            swap(arr[Size - i], arr[Size - i - 1]);
        }
        arr[0] = num;
    }
    void extract(int *arr, int *cnt)
    {
        if(*cnt <= 0)
        {
            cout << "*" << endl;
            *cnt = 1;
        }
        else
        {
            int Size = *cnt;
            int min = 100000001;
            int iter;
            for (int i = 0; i < Size; i++)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                    iter = i;
                }
            }
            cout << min << endl;
            remove(arr, min, iter, *cnt);
        }
    }
    void remove(int *arr, int num, int iter, int cnt)
    {
        arr[iter] = 0;
        for(int i = iter; i < cnt - 1; i++)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    void decrease(int *arr, int num1, int num2, int *pushel)
    {
        int num = pushel[num1 - 1];
        for(int i = 0; i < 10000002; i++)
        {
            if(arr[i] == num)
            {
                arr[i] = num2;
                pushel[num1 - 1] = num2;
                break;
            }
        }
    }
};
/*int push(int *arr, int cnt)
{
    arr
}*/
int main()
{
    int x = 8;
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    queue
        Queue;
    int
        num1,
        num2,
        cnt = 1,
        flag = 0;
    string
        str1,
        push = "push",
        extractmin = "extract-min",
        decreasekey = "decrease-key";
    Queue.arr = arr;
    while(cin >> str1)
    {
        if(str1.compare(push) == 0)
        {
            cnt++;
            cin >> num1;
            Queue.push(num1, cnt);
            pushel[flag++] = num1;
        }
        if(str1.compare(extractmin) == 0)
        {
            cnt--;
            Queue.extract(arr, &cnt);
            pushel[flag++] = -1;
        }
        if(str1.compare(decreasekey) == 0)
        {
            cin >> num1 >> num2;
            Queue.decrease(arr, num1, num2, pushel);
            pushel[flag++] = -1;
        }
        x--;
    }
    /*for(int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }*/
    return 0;
}
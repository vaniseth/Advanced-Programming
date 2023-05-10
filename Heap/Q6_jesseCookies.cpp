#include <iostream>
using namespace std;
class HeapFunc
{
public:
    void insert(int a[], int v)
    {
        if (a[0] >= sizeof(a) / sizeof(a[0]))
        {
            cout << "Array Full" << endl;
            return;
        }
        else
        {
            a[a[0]] = v;
            a[0] = a[0] + 1;
            sort(a);
        }
    }
    void sort(int a[])
    {
        for (int i = 1; i < a[0] - 1; i++)
        {
            for (int j = i + 1; j < a[0]; j++)
            {
                if (a[j] < a[i])
                {
                    int r = a[j];
                    a[j] = a[i];
                    a[i] = r;
                }
            }
        }
    }
    void merge(int a[], int v)
    {
        int c = 0;
        while (a[1] < v)
        {
            if (a[2] == 0)
            {
                cout << "-1" << endl;
                return;
            }
            a[1] = a[1] + a[2];
            a[2] = a[a[0] - 1];
            a[a[0] - 1] = 0;
            a[0]--;
            sort(a);
            c++;
        }
        cout << c << endl;
    }
};
int main()
{
    int arr[8] = {1, 0, 0, 0, 0, 0, 0, 0};
    HeapFunc hf;
    int n;
    for (int i = 0; i < 7; i++)
    {
        cin >> n;
        if (n == 0)
            break;
        hf.insert(arr, n);
    }
    int q;
    cin >> q;
    hf.merge(arr, q);
    return 0;
}
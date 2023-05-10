#include <iostream>
using namespace std;
class Haunt
{
public:
    void insert(int a[], int v)
    {
        for (int i = 0; i < sizeof(a) / sizeof(*a); i = i + 2)
        {
            if (a[i] == v)
            {
                a[i + 1]++;
                return;
            }
        }
    }
    void fGhost(int a[])
    {
        int j = 1;
        for (int i = 3; i < sizeof(a) / sizeof(*a); i = i + 2)
        {
            if (a[i] > a[j])
            {
                j = i;
            }
        }
        cout << a[j - 1] << " " << a[j] << endl;
    }
};
int main()
{
    Haunt h;
    int n, m;
    cin >> n >> m;
    int a[m * 2];
    for (int i = m; i > 0; i--)
    {
        int j = m - i;
        a[j * 2] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        h.insert(a, t);
        h.fGhost(a);
    }
    return 0;
}
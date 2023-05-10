#include <iostream>
using namespace std;
class Arrange
{
public:
    void place(int i, int j, int e, int k, int *n, char *a)
    {
        int i1, j1, i2, j2;
        if (e > k || i > j)
            return;
        if (e == 2)
        {
            if (i == 0)
            {
                n[0] = 2;
                place(1, j, 4, k, n, a);
            }
            else
            {
                n[j] = 2;
                place(i, j - 1, 4, k, n, a);
            }
            return;
        }
        else if (e == 3)
        {
            if (i == 0)
            {
                n[0] = 3;
                place(1, j, 5, k, n, a);
            }
            else
            {
                n[j] = 3;
                place(i, j - 1, 5, k, n, a);
            }
            return;
        }
        int l = j - i + 1;
        if (l % 2 == 0)
            if (a[e - 1] == 'L')
            {
                n[l / 2 - 1] = e;
                i1 = l / 2;
                j1 = j;
                i2 = i;
                j2 = l / 2 - 2;
            }
            else
            {
                n[l / 2] = e;
                i1 = i;
                j1 = l / 2 - 1;
                i2 = l / 2;
                j2 = j;
            }
        else
        {
            n[i + l / 2] = e;
            i1 = i;
            j1 = i + (l / 2) - 1;
            i2 = i + (l / 2) + 1;
            j2 = j;
        }
        place(i1, j1, e * 2, k, n, a);
        place(i2, j2, e * 2 + 1, k, n, a);
    }
};
int main()
{
    Arrange arr;
    int n, k, q;
    cin >> n >> k;
    int seat[n] = {0};
    char a[k];
    cin >> a;
    arr.place(0, n - 1, 1, k, seat, a);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;
        if (seat[v - 1] == 0)
            cout << "-1" << endl;
        else
            cout << seat[v - 1] << endl;
    }
    return 0;
}
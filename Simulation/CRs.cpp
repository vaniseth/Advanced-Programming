// This Code is just for one floor...Similarly we can do for all the floors
#include <iostream>
using namespace std;
/// Floor plan of Academic Block
int AB[4][4] = {1, 1, 0, 1,
                1, 0, 1, 0,
                1, 1, 1, 0,
                0, 0, 1, 1};
// Floor Plan Of Crs.
int CRs[4][4] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0};
int findCRs(int i, int j, int n){
    // Boundary conditions or any obstacle
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (AB[i][j] == 1)
    {
        CRs[i][j] = 1;
        if (findCRs(i, j + 1, n) == 1)
            return 1;
        if (findCRs(i, j + 1, n) == 1)
            return 1;
        CRs[i][j] = 0;
    }
    return 0;
}
int main()
{
    findCRs(0, 0, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 4; i++)
        {
            if (CRs[i][j]) {
                    cout << i, j;
                }
        }
    }
}
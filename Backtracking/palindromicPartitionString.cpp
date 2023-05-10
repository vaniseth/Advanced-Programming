#include <iostream>
#include <vector>
using namespace std;

bool check_palindrome(string s, int index, int i)
{
    while (index <= i)
    {
        if (s[index++] != s[i--])
            return 0;
    }
    return 1;
}
void the_helper(vector<vector<string>> &result,

                vector<string> &dump, string s, int n,
                int index)

{
    if (index == n)
    {
        result.push_back(dump);
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (check_palindrome(s, index, i))
        {
            dump.push_back(s.substr(index, i - index + 1));
            the_helper(result, dump, s, n, i + 1);
            dump.pop_back();
        }
    }
}
int main()
{
    string s = "bcc";
    int n = s.size();
    vector<vector<string>> result;
    vector<string> dump;
    the_helper(result, dump, s, n, 0);
    int row_l = result.size();
    cout << "All Possible palindromic partitions of a "

            "string : "
         << endl;
    cout << "[";
    for (int i = 0; i < row_l; i++)
    {
        cout << "[";
        int m = result[i].size();
        for (int j = 0; j < m; j++)
        {

            if (j == m - 1)
            {
                cout << result[i][j];
                continue;
            }
            cout << result[i][j] << ",";
        }
        if (i == row_l - 1)
        {
            cout << "]";
            continue;
        }
        cout << "],";
    }
    cout << "]";
    return 0;
}
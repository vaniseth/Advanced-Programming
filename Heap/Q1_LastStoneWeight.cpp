#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        while (stones.size() > 1)
        {
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();
            if (a != b)
            {
                stones.push_back(a - b);
                sort(stones.begin(), stones.end());
            }
        }
        if (stones.size())
            return stones[0];
        return 0;
    }
};
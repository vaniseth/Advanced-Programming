#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    struct element
    {
        int number, frequency;
        bool operator<(const element arg) const
        {
            return frequency < arg.frequency;
        }
    };
    priority_queue<element> sol;
    vector<int> solution;
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 1;
        for (; i < nums.size(); i++)
        {
            int freq = 1;
            while (i < nums.size() && nums[i] == nums[i - 1])
            {
                i++;
                freq++;
            }
            element el;
            el.number = nums[i - 1];
            el.frequency = freq;
            sol.push(el);
        }
        if (i == nums.size())
        {
            element el;
            el.number = nums[nums.size() - 1];
            el.frequency = 1;
            sol.push(el);
        }
        while (k)
        {
            solution.push_back(sol.top().number);
            sol.pop();
            k--;
        }
        return solution;
    }
};
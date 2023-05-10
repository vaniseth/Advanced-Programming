#include <bits/stdc++.h>
#include <vector>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int s1, s2;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty())
        {
            maxHeap.push(num);
        }
        else if (num > maxHeap.top())
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }
        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1)
        {
            int ele;
            if (maxHeap.size() > minHeap.size())
            {
                ele = maxHeap.top();
                maxHeap.pop();
                minHeap.push(ele);
            }
            else
            {
                ele = minHeap.top();
                minHeap.pop();
                maxHeap.push(ele);
            }
        }
    }
    double findMedian()
    {
        s1 = maxHeap.size(), s2 = minHeap.size();
        if ((s1 + s2) % 2 == 0)
        {
            double ans = ((double)maxHeap.top() + (double)minHeap.top()) /

                         (double)2;

            return ans;
        }
        else
        {
            if (s1 > s2)

                return maxHeap.top();
            else
                return minHeap.top();
        }
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}
#include <iostream>
#include <list>
#include <vector>
using namespace std;

NodePtr deleteMin()
{
    NodePtr (curr = head);
    NodePtr (prevMin = nullptr);
    NodePtr (minPtr = nullptr);
    NodePtr (prevPtr = nullptr_;
    int min = 999999;
    while (curr != nullptr)
    {
        if (curr->data <= min)
        {
            min = curr->data;
            prevMin = prevPtr;
            minPtr = curr;
        }
        prevPtr = curr;
        curr = curr->sibling;
    }
    if (prevMin != nullptr && minPtr->sibling != nullptr)
    {
        prevMin->sibling = minPtr->sibling;
    }
    else if (prevMin != nullptr && minPtr->sibling == nullptr)
    {
        prevMin->sibling = nullptr;
    }
    else if (prevMin == nullptr and minPtr->sibling != nullptr)
    {
        head = minPtr->sibling;
    }
    else if (prevMin == nullptr and minPtr->sibling == nullptr)
    {
        head = nullptr;
    }
    NodePtr (childPtr = minPtr->child);
    while (childPtr != nullptr)
    {
        childPtr->p = nullptr;

        childPtr = childPtr->sibling;
    }
    stack<NodePtr> s;
    childPtr = minPtr->child;
    while (childPtr != nullptr)
    {
        s.push(childPtr);
        childPtr = childPtr->sibling;
    }
    curr = s.top();
    NodePtr temp = curr;
    s.pop();
    while (!s.empty())
    {
        curr->sibling = s.top();
        s.pop();
        curr = curr->sibling;
    }
    curr->sibling = nullptr;
    BinomialHeap h;
    h.setHead(temp);
    merge(h);
    return minPtr;
}
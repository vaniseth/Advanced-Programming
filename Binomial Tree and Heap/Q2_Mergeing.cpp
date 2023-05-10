#include <bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;

void merge(BinomialHeap h1)
{

    NodePtr curr1 = getHead();
    NodePtr curr2 = h1.getHead();
    NodePtr curr3 = nullptr;
    NodePtr temp = nullptr;

    if (curr1->degree <= curr2->degree)
    {

        curr3 = curr1;
        curr1 = curr1->sibling;
    }
    else
    {
        curr3 = curr2;
        curr2 = curr2->sibling;
    }
    temp = curr3;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->degree <= curr2->degree)
        {
            curr3->sibling = curr1;
            curr1 = curr1->sibling;
        }
        else
        {
            curr3->sibling = curr2;
            curr2 = curr2->sibling;
        }
        curr3 = curr3->sibling;
    }
    if (curr1 != nullptr)
    {
        while (curr1 != nullptr)
        {
            curr3->sibling = curr1;
            curr1 = curr1->sibling;
            curr3 = curr3->sibling;
        }
    }
    if (curr2 != nullptr)
    {

        while (curr2 != nullptr)
        {
            curr3->sibling = curr2;
            curr2 = curr2->sibling;
            curr3 = curr3->sibling;
        }
    }
    curr3 = temp;
    NodePtr prev = nullptr;
    NodePtr next = curr3->sibling;
    while (next != nullptr)
    {
        if ((curr3->degree != next->degree) || (next->sibling != nullptr && curr3->degree == next -

                                                                                                 > sibling->degree))
        {

            prev = curr3;
            curr3 = next;
        }
        else
        {
            if (curr3->data <= next->data)
            {
                curr3->sibling = next->sibling;
                BinomialHeap::linkBinomialTrees(curr3, next);
            }
            else
            {
                if (prev == nullptr)
                {
                    temp = next;
                }
                else
                {
                    prev->sibling = next;
                }
                BinomialHeap::linkBinomialTrees(next, curr3);
                curr3 = next;
            }
        }
        next = curr3->sibling;
    }
    setHead(temp);
}
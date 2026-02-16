#include <bits/stdc++.h>
using namespace std;
int b[100];
int sz = 0; // supose it when size ==0
void Insert(int number)
{
    if (sz == 0)
    {
        b[1] = number;
        sz = 1;
    }
    else
    {
        // insertion the x
        sz++;
        b[sz] = number;
    }
    // fixzing the tree
    int child = sz;
    int parent = child / 2;
    /// heapify up
    while (parent >= 1 && b[parent] > b[child])
    {
        swap(b[parent], b[child]);
        child = parent;
        parent = int(child / 2);
    }
}
// Delete minimum element (root)
void deleteMin()
{
    if (sz == 0)
    {
        cout << "Heap is empty\n";
        return;
    }

    if (sz == 1)
    {
        sz = 0;
        return;
    }

    // Move last element to root
    b[1] = b[sz];
    sz--;

    int parent = 1;

    // heapify down
    while (true)
    {
        int left = 2 * parent;
        int right = 2 * parent + 1;
        int smallest = parent;

        if (left <= sz && b[left] < b[smallest])
            smallest = left;

        if (right <= sz && b[right] < b[smallest])
            smallest = right;

        if (smallest == parent)
            break;

        swap(b[parent], b[smallest]);
        parent = smallest;
    }
}

// Get minimum element
int getMin()
{
    if (sz == 0)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    return b[1];
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            Insert(x);
        }
        else if (type == 2)
        {
            cout << getMin() << endl;
        }
        else if (type == 3)
        {
            deleteMin();
        }
    }
    return 0;
}
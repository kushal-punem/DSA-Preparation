#include <iostream>
using namespace std;

int heap[100];
int size = 0;

// Insert element into max heap
void insert(int x)
{
    size++;
    heap[size] = x;

    int child = size;
    int parent = child / 2;

    // Heapify UP (change sign only)
    while (parent >= 1 && heap[parent] < heap[child])
    {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }
}

// Get maximum element
int getMax()
{
    if (size == 0)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    return heap[1];
}

// Delete maximum element
void deleteMax()
{
    if (size == 0)
    {
        cout << "Heap is empty\n";
        return;
    }

    heap[1] = heap[size];
    size--;

    int parent = 1;

    // Heapify DOWN
    while (true)
    {
        // yah pe ham 1 based indexing use kar rahe hai es liye
        int left = 2 * parent;
        int right = 2 * parent + 1;
        int largest = parent;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest == parent)
            break;

        swap(heap[parent], heap[largest]);
        parent = largest;
    }
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
            insert(x);
        }
        else if (type == 2)
        {
            cout << getMax() << endl;
        }
        else if (type == 3)
        {
            deleteMax();
        }
    }

    return 0;
}

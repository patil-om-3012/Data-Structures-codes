//find kth smallest ele in minHeap

// given a min-heap. Find maximum element.

#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    void heapifyUp(int index)
    {
        int parent = (index - 1)/2;

        while(index > 0 && heap[parent] > heap[index])
        {
            swap(heap[index],heap[parent]);
            index = parent;
            parent = (index - 1)/2;
        }
    }

    void heapifyDown(int index,int heapSize)
    {
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        int largest = index;

        if(heap[leftChild] < heap[largest] && leftChild < heapSize)
        {
            largest = leftChild;
        } 

        if(heap[rightChild] < heap[largest] && rightChild < heapSize)
        {
            largest = rightChild;
        }

        if(largest!=index)
        {
            swap(heap[largest],heap[index]);
            heapifyDown(largest,heapSize);
        }
    }

    void push(int ele)
    {
        heap.push_back(ele);
        heapifyUp(heap.size() - 1);
    }

    void printHeap()
    {
        for(int ele:heap)
        {
            cout << ele << " " ;
        }
    }

    void extractMin()
    {
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        heapifyDown(0,heap.size());
    }
};

int main()
{
    MinHeap h;
    h.push(10);
    h.push(42);
    h.push(2);
    h.push(1);
    h.push(11);
    h.push(3);
    h.push(37);
    h.push(5);
    h.push(21);
    h.push(18);
    h.push(28);
    h.push(14);

    int k=3;

    h.printHeap();

    for(int i=0;i<k-1;i++)
    {
        h.extractMin();
    }

    h.printHeap();
}
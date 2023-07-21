//max heap : heapify opertaions

#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index, int heapSize) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heapSize && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heapSize && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest, heapSize);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }

    int extractMax() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty!");

        int maxElement = heap[0];
        int lastIndex = heap.size() - 1;
        std::swap(heap[0], heap[lastIndex]);
        heap.pop_back();
        heapifyDown(0, heap.size());

        return maxElement;
    }

    void printHeap() {
        for (int element : heap) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(7);
    heap.insert(14);
    heap.insert(5);
    heap.insert(20);

    heap.printHeap(); // Output: 20 10 14 5 7

    int maxElement = heap.extractMax();
    std::cout << "Extracted maximum element: " << maxElement << std::endl; // Output: Extracted maximum element: 20

    heap.printHeap(); // Output: 14 10 7 5

    return 0;
}

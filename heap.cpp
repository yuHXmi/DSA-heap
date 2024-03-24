#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1e5 + 5;

struct maxHeap {
    int arr[MAXSIZE], size;

    maxHeap() {
        size = 0;
    }

    int parent(int i) {
        return i / 2;
    }

    int left_child(int i) {
        return 2 * i;
    }

    int right_child(int i) {
        return 2 * i + 1;
    }

    void swim_up(int i) {
        while (i > 1 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void sink_down(int i) {
        int maxIndex = i;
        int l = left_child(i);
        if (l <= size && arr[l] > arr[maxIndex])
            maxIndex = l;
        int r = right_child(i);
        if (r <= size && arr[r] > arr[maxIndex]) 
            maxIndex = r;
        if (i != maxIndex) {
            swap(arr[i], arr[maxIndex]);
            sink_down(maxIndex);
        }
    }

    void insert(int value) {
        arr[++size] = value;
        swim_up(size);
    }

    int get_max() {
        return arr[1];
    }

    int remove_max() {
        int result = arr[1];
        arr[1] = arr[size--];
        sink_down(1);
        return result;
    }

    void remove(int i) {
        swap(arr[i], arr[size--]);
        sink_down(i);
    }
};

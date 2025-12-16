#include <iostream>

using namespace std;

class PriorityQueue {
private:
    long long *heap;
    int sz;

    void swap(long long &a, long long &b) {
        long long t = a;
        a = b;
        b = t;
    }

    void siftUp(int i) {
        while (i > 1 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    void siftDown(int i) {
        while (2 * i <= sz) {
            int j = 2 * i;
            if (j + 1 <= sz && heap[j + 1] < heap[j])
                j++;
            if (heap[i] <= heap[j]) return;
            swap(heap[i], heap[j]);
            i = j;
        }
    }

public:
    PriorityQueue(int capacity) {
        heap = new long long[capacity + 1];
        sz = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void push(long long v) {
        heap[++sz] = v;
        siftUp(sz);
    }

    void popMin() {
        if (sz == 0) return;
        heap[1] = heap[sz--];
        if (sz > 0)
            siftDown(1);
    }

    long long getMin() {
        return (sz == 0 ? -1 : heap[1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    PriorityQueue pq(q);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long v;
            cin >> v;
            pq.push(v);
        } else {
            pq.popMin();
        }

        cout << pq.getMin() << ' ';
    }

    return 0;
}

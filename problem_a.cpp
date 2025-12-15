#include <iostream>

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray() {
        capacity = 4;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int v) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = v;
    }

    int pop_back() {
        if (size == 0) return -1;
        return data[--size];
    }

    void insert(int p, int v) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i >= p; --i) {
            data[i] = data[i - 1];
        }
        data[p - 1] = v;
        size++;
    }

    int remove_at(int p) {
        if (p < 1 || p > size) return -1;
        int val = data[p - 1];
        for (int i = p - 1; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
        return val;
    }

    int find_min_pos(int v) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == v) return i + 1;
        }
        return -1;
    }

    int get(int p) {
        if (p < 1 || p > size) return -1;
        return data[p - 1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    if (!(std::cin >> q)) return 0;

    DynamicArray arr;
    bool firstOutput = true;

    while (q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int v;
            std::cin >> v;
            arr.push_back(v);
        }
        else if (type == 2) {
            int res = arr.pop_back();
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 3) {
            int p, v;
            std::cin >> p >> v;
            arr.insert(p, v);
        }
        else if (type == 4) {
            int p;
            std::cin >> p;
            int res = arr.remove_at(p);
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 5) {
            int v;
            std::cin >> v;
            int res = arr.find_min_pos(v);
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 6) {
            int p;
            std::cin >> p;
            int res = arr.get(p);
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
    }
    std::cout << "\n";

    return 0;
}
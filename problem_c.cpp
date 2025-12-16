#include <iostream>

using namespace std;

class Dictionary {
private:
    static const int MOD = 1000003;

    struct Node {
        long long key, value;
        Node* next;
        Node(long long k, long long v, Node* n)
            : key(k), value(v), next(n) {}
    };

    Node* table[MOD];

    int hashKey(long long k) {
        return k % MOD;
    }

public:
    Dictionary() {
        for (int i = 0; i < MOD; i++)
            table[i] = nullptr;
    }

    ~Dictionary() {
        for (int i = 0; i < MOD; i++) {
            Node* cur = table[i];
            while (cur) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
    }

    long long setValue(long long k, long long v) {
        int h = hashKey(k);
        Node* cur = table[h];

        while (cur) {
            if (cur->key == k) {
                long long old = cur->value;
                cur->value = v;
                return old;
            }
            cur = cur->next;
        }

        table[h] = new Node(k, v, table[h]);
        return -1;
    }

    long long removeValue(long long k) {
        int h = hashKey(k);
        Node* cur = table[h];
        Node* prev = nullptr;

        while (cur) {
            if (cur->key == k) {
                long long old = cur->value;
                if (prev) prev->next = cur->next;
                else table[h] = cur->next;
                delete cur;
                return old;
            }
            prev = cur;
            cur = cur->next;
        }

        return -1;
    }

    long long getValue(long long k) {
        int h = hashKey(k);
        Node* cur = table[h];

        while (cur) {
            if (cur->key == k)
                return cur->value;
            cur = cur->next;
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    Dictionary dict;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long k, v;
            cin >> k >> v;
            cout << dict.setValue(k, v) << ' ';
        }
        else if (type == 2) {
            long long k;
            cin >> k;
            cout << dict.removeValue(k) << ' ';
        }
        else {
            long long k;
            cin >> k;
            cout << dict.getValue(k) << ' ';
        }
    }

    return 0;
}

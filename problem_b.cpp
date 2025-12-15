#include <iostream>

struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(int v) {
        Node* newNode = new Node(v);
        if (size == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int pop_front() {
        if (size == 0) return -1;
        
        Node* temp = head;
        int val = temp->val;
        
        if (size == 1) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        size--;
        return val;
    }

    int pop_back() {
        if (size == 0) return -1;
        
        Node* temp = tail;
        int val = temp->val;
        
        if (size == 1) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        size--;
        return val;
    }

    void insert_before(int p, int v) {
        if (p <= 0 || p > size) return; 

        if (p == 1) {
            push_front(v);
            return;
        }

        Node* cur = head;
        for (int i = 1; i < p; ++i) {
            cur = cur->next;
        }
        
        Node* newNode = new Node(v);
        Node* pre = cur->prev;
        
        pre->next = newNode;
        newNode->prev = pre;
        
        newNode->next = cur;
        cur->prev = newNode;
        
        size++;
    }

    int remove_at(int p) {
        if (p <= 0 || p > size) return -1;

        if (p == 1) return pop_front();
        if (p == size) return pop_back();

        Node* cur = head;
        for (int i = 1; i < p; ++i) {
            cur = cur->next;
        }
        
        int val = cur->val;
        Node* pre = cur->prev;
        Node* nxt = cur->next;
        
        pre->next = nxt;
        nxt->prev = pre;
        
        delete cur;
        size--;
        return val;
    }

    int find_min_pos(int v) {
        Node* cur = head;
        int pos = 1;
        while (cur != nullptr) {
            if (cur->val == v) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    int get_at(int p) {
        if (p <= 0 || p > size) return -1;
        
        Node* cur = head;
        for (int i = 1; i < p; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    if (!(std::cin >> q)) return 0;

    LinkedList list;
    bool firstOutput = true;

    while (q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            char s;
            int v;
            std::cin >> s >> v;
            if (s == 'f') list.push_front(v);
            else list.push_back(v);
        }
        else if (type == 2) {
            char s;
            std::cin >> s;
            int res;
            if (s == 'f') res = list.pop_front();
            else res = list.pop_back();
            
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 3) {
            int p, v;
            std::cin >> p >> v;
            list.insert_before(p, v);
        }
        else if (type == 4) {
            int p;
            std::cin >> p;
            int res = list.remove_at(p);
            
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 5) {
            int v;
            std::cin >> v;
            int res = list.find_min_pos(v);
            
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
        else if (type == 6) {
            int p;
            std::cin >> p;
            int res = list.get_at(p);
            
            if (!firstOutput) std::cout << " ";
            std::cout << res;
            firstOutput = false;
        }
    }
    std::cout << "\n";

    return 0;
}
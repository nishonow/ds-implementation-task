# This is a repository for Implementation Tasks of Data Structures Course


## Problem A — Dynamic Array
### Description
- Implements a simple dynamic array (vector-like) with manual memory management in C++.
- Supports operations: push_back, pop_back, insert at position, remove at position, find first position of a value, and get value at a position.

## Problem B — Linked List

### Description
Linked list implemented in C++ with manual memory management. Supports insertion, deletion, and querying operations.

### Implementation Details
- Node: Stores `val`, `prev`, and `next` pointers.
- LinkedList: Tracks `head`, `tail`, and `size`. Manages memory with `new`/`delete`.

### Operations
- Insertion: `push_front(v)`, `push_back(v)`, `insert_before(p, v)`
- Deletion: `pop_front()`, `pop_back()`, `remove_at(p)`
- Querying: `find_min_pos(v)`, `get_at(p)`

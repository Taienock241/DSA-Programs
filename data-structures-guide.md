# Data Structures Guide

Data structures are ways to organize data so that common operations can be
performed efficiently. Choose a structure based on the operations your program
needs most often: accessing, searching, inserting, deleting, or ordering data.

## Quick comparison

| Structure | Best use | Access | Search | Insert/delete |
| --- | --- | ---: | ---: | ---: |
| Array | Fixed-size, contiguous data | `O(1)` | `O(n)` | `O(n)` in the middle |
| `vector` | Resizable array in C++ | `O(1)` | `O(n)` | `O(1)` at end (amortized) |
| Linked list | Frequent insertion/deletion with a node position | `O(n)` | `O(n)` | `O(1)` when the node is known |
| Stack | Last-in, first-out (LIFO) data | top only | `O(n)` | `O(1)` push/pop |
| Queue | First-in, first-out (FIFO) data | front only | `O(n)` | `O(1)` enqueue/dequeue |
| Hash table | Fast key/value lookup | not index-based | `O(1)` average | `O(1)` average |
| Binary search tree | Ordered data with tree operations | `O(log n)` average | `O(log n)` average | `O(log n)` average |
| Graph | Relationships between objects | depends on representation | depends on algorithm | depends on representation |

The stated bounds are typical cases. Hash tables and binary search trees can
become `O(n)` in their worst cases.

## Core structures

### Arrays and vectors

Arrays store elements next to each other in memory. This makes indexing fast,
but inserting near the beginning requires shifting later elements.

```cpp
#include <vector>

std::vector<int> numbers{10, 20, 30};
numbers.push_back(40);       // Add at the end
int first = numbers[0];      // Constant-time access
```

Use `std::vector` by default when you need a sequence that can grow.

### Structs and classes

A `struct` groups related values. It is useful for representing a record such
as a student, node, or edge.

```cpp
struct Student {
    std::string name;
    int age;
};
```

In C++, members of a `struct` are public by default. Use a `class` when the
data should be private and accessed through methods.

### Linked lists

A linked list stores each value in a node containing a link to another node.
It does not provide constant-time indexing, but inserting after a known node is
efficient.

```cpp
struct Node {
    int value;
    Node* next;
};
```

Always manage ownership carefully when using raw pointers. Prefer
`std::forward_list`, `std::list`, or smart pointers in larger programs.

### Stack

A stack follows **LIFO**: the last item added is the first item removed.
Typical operations are `push`, `pop`, and `top`.

```cpp
#include <stack>

std::stack<int> values;
values.push(10);
values.push(20);
values.pop();                // Removes 20
```

Stacks are useful for undo operations, recursion, bracket matching, and
depth-first search.

### Queue

A queue follows **FIFO**: the first item added is the first item removed.
Typical operations are `push`, `pop`, `front`, and `back`.

```cpp
#include <queue>

std::queue<int> waiting;
waiting.push(10);
waiting.push(20);
waiting.pop();               // Removes 10
```

Queues are useful for scheduling, buffering, and breadth-first search.

### Hash tables

Hash tables map a key to a value. In C++, use `std::unordered_map` for average
constant-time lookup when ordering is not required.

```cpp
#include <unordered_map>

std::unordered_map<std::string, int> ages;
ages["Jane"] = 14;
```

Use `std::map` instead when keys must remain sorted.

## Trees and graphs

- A **tree** is a hierarchy with one path between connected nodes.
- A **binary tree** has at most two children per node.
- A **binary search tree** keeps smaller values on the left and larger values
  on the right.
- A **heap** keeps the smallest or largest priority at the root and is useful
  for priority queues.
- A **graph** contains vertices and edges. It can be directed or undirected,
  weighted or unweighted.

Common graph representations:

- **Adjacency list:** memory-efficient for sparse graphs.
- **Adjacency matrix:** fast edge lookup, but uses `O(V^2)` memory.

## How to choose a structure

1. Need indexed access? Start with an array or `std::vector`.
2. Need frequent access to the newest item? Use a stack.
3. Need first-come, first-served processing? Use a queue.
4. Need key-based lookup? Use `std::unordered_map`.
5. Need sorted keys or range queries? Use `std::map`.
6. Need relationships or routes? Use a graph.
7. Need repeated minimum/maximum retrieval? Use a heap or priority queue.

## Complexity reminders

- `O(1)` does not grow with input size.
- `O(log n)` usually comes from repeatedly halving the search space.
- `O(n)` grows linearly with the number of elements.
- `O(n log n)` is common for efficient comparison sorting.
- `O(n^2)` often appears when every item is compared with every other item.

When analyzing an algorithm, count how the number of operations changes as the
input size `n` grows. Ignore constant factors and smaller terms, so
`3n + 10` is `O(n)`.

## Practice checklist

- Draw the data structure before writing code.
- Define what each node or element stores.
- Check empty and single-element cases.
- Check overflow, underflow, and out-of-range access.
- Decide who owns dynamically allocated memory.
- Test normal, boundary, and invalid inputs.
- State the time and space complexity of each operation.

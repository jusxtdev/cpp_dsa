# C++ STL Cheat Sheet

Focused on **DSA / Competitive Programming**.

---

# 1. Containers

## 1. `array`

### What is it?

A **fixed-size array** whose size is known at compile time.

```cpp
#include <array>

array<int, 5> a = {1, 2, 3, 4, 5};
```

### Syntax

```cpp
array<T, N> name;

array<int, 5> a;
array<string, 3> names = {"A", "B", "C"};
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| Access `a[i]` | O(1) |
| `front()` / `back()` | O(1) |
| `size()` | O(1) |
| `fill()` | O(N) |
| `begin()` / `end()` | O(1) |

### Methods

```cpp
a[i]
a.at(i)       // bounds-checked
a.front()
a.back()
a.size()
a.empty()
a.fill(value)

a.begin()
a.end()
a.rbegin()
a.rend()
```

### Gotchas

- Size **cannot change**.
- `a[i]` does **not** perform bounds checking.
- `a.at(i)` does bounds checking.
- Unlike raw arrays, it knows its own size.

### Why use it?

You want an array but want STL functionality such as `.size()`, `.fill()`, and iterators.

### When to use?

```text
Size known at compile time → array
Size changes dynamically → vector
```

---

## 2. `vector`

### What is it?

A **dynamic array**.

```cpp
vector<int> v = {1, 2, 3};
```

The most commonly used STL container for DSA.

### Syntax

```cpp
vector<int> v;
vector<int> v(5);          // {0,0,0,0,0}
vector<int> v(5, 10);      // {10,10,10,10,10}

v.push_back(10);
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| `v[i]` | O(1) |
| `push_back()` | **O(1) amortized** |
| `pop_back()` | O(1) |
| `insert()` middle | O(N) |
| `erase()` middle | O(N) |
| `front()` / `back()` | O(1) |
| `size()` | O(1) |
| `clear()` | O(N) |

### Methods

```cpp
v.push_back(x)
v.pop_back()

v.front()
v.back()

v.size()
v.empty()

v.clear()
v.resize(n)
v.reserve(n)

v.insert(pos, x)
v.erase(pos)

v.begin()
v.end()
v.rbegin()
v.rend()
```

### Gotchas

#### `push_back()` is amortized O(1)

The vector occasionally needs to allocate a bigger memory block and copy/move everything.

#### `reserve()` ≠ `resize()`

```cpp
v.reserve(100);  // capacity >= 100
                   // size is still 0

v.resize(100);   // size becomes 100
```

### Why use it?

Fast random access + dynamic size + contiguous memory.

### When to use?

**Default container for most DSA problems.**

```text
Need a dynamic array → vector
```

---

## 3. `deque`

### What is it?

**Double-ended queue.**

Efficient insertion/removal from both ends.

```cpp
deque<int> dq;
```

### Syntax

```cpp
deque<int> dq = {1, 2, 3};

dq.push_front(0);
dq.push_back(4);
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| `dq[i]` | O(1) |
| `push_front()` | O(1) |
| `push_back()` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| Insert middle | O(N) |
| Erase middle | O(N) |

### Methods

```cpp
dq.push_front(x)
dq.push_back(x)

dq.pop_front()
dq.pop_back()

dq.front()
dq.back()

dq[i]

dq.insert()
dq.erase()

dq.size()
dq.empty()
dq.clear()
```

### Gotchas

- Random access is O(1), but it is **not contiguous memory like vector**.
- Usually less cache-friendly than `vector`.

### Why use it?

When you need:

```text
Random access + efficient operations at BOTH ends
```

### When to use?

Sliding window / monotonic queue problems are common examples.

---

## 4. `list`

### What is it?

A **doubly linked list**.

```cpp
list<int> l;
```

Conceptually:

```text
[1] <-> [2] <-> [3] <-> [4]
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| Access by iterator | O(1) |
| `front()` / `back()` | O(1) |
| `push_front()` | O(1) |
| `push_back()` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| Insert with iterator | O(1) |
| Erase with iterator | O(1) |
| Find element | O(N) |
| Random access `l[i]` | ❌ |

### Methods

```cpp
l.push_front(x)
l.push_back(x)

l.pop_front()
l.pop_back()

l.front()
l.back()

l.insert(it, x)
l.erase(it)

l.remove(x)
l.remove_if(condition)

l.sort()
l.reverse()

l.size()
l.empty()
l.clear()
```

### Gotchas

**No random access.**

```cpp
l[3];  // ❌
```

You need an iterator:

```cpp
auto it = l.begin();
advance(it, 3);
```

### Why use it?

Very cheap insertion/deletion when you already have the iterator pointing to the location.

### When to use?

Rare in competitive programming.

Use it when:

```text
Frequent insertion/deletion in middle
+
You already have an iterator
```

---

## 5. `stack`

### What is it?

**LIFO** data structure.

```text
Last In → First Out

    3 ← top
    2
    1
```

### Syntax

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| `push()` | O(1) |
| `pop()` | O(1) |
| `top()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |

### Methods

```cpp
st.push(x)
st.pop()
st.top()

st.empty()
st.size()

st.emplace(x)
```

### Gotchas

`pop()` **doesn't return the element**.

Wrong:

```cpp
int x = st.pop();  // ❌
```

Correct:

```cpp
int x = st.top();
st.pop();
```

### Why use it?

When the problem naturally requires **LIFO** behavior.

### When to use?

- Parentheses matching
- Next greater element
- DFS
- Monotonic stack
- Undo-like behavior

---

## 6. `queue`

### What is it?

**FIFO** data structure.

```text
First In → First Out

front → 1 2 3 ← back
```

### Syntax

```cpp
queue<int> q;

q.push(10);
q.push(20);
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| `push()` | O(1) |
| `pop()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |

### Methods

```cpp
q.push(x)
q.pop()

q.front()
q.back()

q.empty()
q.size()

q.emplace(x)
```

### Gotchas

```cpp
q.pop();       // removes
q.front();     // gets
```

`pop()` doesn't return the element.

### Why use it?

FIFO processing.

### When to use?

Most commonly:

**BFS**

```cpp
queue<int> q;
q.push(start);

while (!q.empty()) {
    int node = q.front();
    q.pop();
}
```

---

## 7. `priority_queue`

### What is it?

A **heap-based priority queue**.

Default = **max heap**.

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top();  // 30
```

### Syntax

#### Max heap

```cpp
priority_queue<int> pq;
```

#### Min heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| `top()` | O(1) |
| `push()` | O(log N) |
| `pop()` | O(log N) |
| `empty()` | O(1) |
| `size()` | O(1) |

### Methods

```cpp
pq.push(x)
pq.pop()
pq.top()

pq.empty()
pq.size()

pq.emplace(x)
```

### Gotchas

Default is **max heap**:

```cpp
priority_queue<int> pq;
```

For minimum:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Why use it?

You repeatedly need the **largest/smallest element** efficiently.

### When to use?

- Dijkstra
- Top K problems
- Scheduling
- Kth largest/smallest
- Heap problems
- Merge K sorted arrays/lists

---

## 8. `set`

### What is it?

Stores **unique elements in sorted order**.

```cpp
set<int> s;

s.insert(10);
s.insert(5);
s.insert(10);
```

Result:

```text
5 10
```

### Time Complexity

Typically **O(log N)**.

| Operation | Complexity |
|---|---:|
| `insert()` | O(log N) |
| `erase()` | O(log N) |
| `find()` | O(log N) |
| `count()` | O(log N) |
| `lower_bound()` | O(log N) |
| `upper_bound()` | O(log N) |
| `begin()` | O(1) |
| `rbegin()` | O(1) |

### Methods

```cpp
s.insert(x)

s.erase(x)
s.erase(iterator)

s.find(x)
s.count(x)

s.lower_bound(x)
s.upper_bound(x)

s.begin()
s.end()

s.size()
s.empty()
s.clear()
```

### Gotchas

Duplicates automatically disappear.

```cpp
s.insert(5);
s.insert(5);

cout << s.size(); // 1
```

`set` is sorted:

```text
1 3 5 8 10
```

### Why use it?

You need:

```text
unique + sorted + O(log N) operations
```

### When to use?

Use `set` when you need ordered unique elements.

---

## 9. `map`

### What is it?

Stores **key-value pairs**, sorted by key.

```cpp
map<int, string> mp;

mp[1] = "Alice";
mp[2] = "Bob";
```

Internally it is typically a balanced BST.

### Time Complexity

| Operation | Complexity |
|---|---:|
| Access | O(log N) |
| Insert | O(log N) |
| Erase | O(log N) |
| Find | O(log N) |
| `lower_bound()` | O(log N) |
| `upper_bound()` | O(log N) |

### Methods

```cpp
mp[key]

mp.insert({key, value})
mp.emplace(key, value)

mp.find(key)
mp.count(key)

mp.erase(key)

mp.lower_bound(key)
mp.upper_bound(key)

mp.begin()
mp.end()

mp.size()
mp.empty()
mp.clear()
```

### Gotcha: `operator[]`

```cpp
mp[100]
```

If `100` doesn't exist, it **creates it** with a default value.

Prefer:

```cpp
auto it = mp.find(100);
```

when you only want to check whether it exists.

### Why use it?

You need:

```text
key → value
+
sorted keys
```

### When to use?

Examples:

```text
frequency counting
coordinate/value mapping
ordered key-value data
range queries using bounds
```

---

## 10. `unordered_map`

### What is it?

Hash table storing **key-value pairs**.

```cpp
unordered_map<string, int> mp;

mp["apple"] = 5;
```

### Time Complexity

Average:

| Operation | Average |
|---|---:|
| Insert | O(1) |
| Find | O(1) |
| Erase | O(1) |
| Access | O(1) |

Worst case:

```text
O(N)
```

### Methods

```cpp
mp[key]

mp.insert({key, value})
mp.emplace(key, value)

mp.find(key)
mp.count(key)

mp.erase(key)

mp.size()
mp.empty()
mp.clear()
```

### Gotchas

**Not sorted.**

```text
map:
1 2 3 4 5

unordered_map:
3 1 5 2 4   ← order is not guaranteed
```

Never depend on iteration order.

### Why use it?

Fast key → value lookup.

### When to use?

Usually when:

```text
You don't care about ordering
+
You want average O(1) lookup
```

Extremely common for frequency counting:

```cpp
unordered_map<int, int> freq;

for (int x : v)
    freq[x]++;
```

---

## 11. `unordered_set`

### What is it?

A hash table containing **unique elements**.

```cpp
unordered_set<int> s;

s.insert(10);
s.insert(20);
```

### Time Complexity

Average:

| Operation | Complexity |
|---|---:|
| Insert | O(1) |
| Find | O(1) |
| Erase | O(1) |
| Count | O(1) |

Worst case:

```text
O(N)
```

### Methods

```cpp
s.insert(x)

s.erase(x)

s.find(x)
s.count(x)

s.size()
s.empty()
s.clear()
```

### Gotchas

- Not sorted.
- Iteration order is not guaranteed.
- Worst-case operations can be O(N).

### Why use it?

You need:

```text
unique elements + fast lookup
```

### When to use?

Use instead of `set` when **ordering doesn't matter**.

---

# Container Decision Cheat Sheet

| Requirement | Use |
|---|---|
| Fixed-size array | `array` |
| Dynamic array | `vector` |
| Insert/remove both ends | `deque` |
| Linked list | `list` |
| LIFO | `stack` |
| FIFO | `queue` |
| Always get min/max | `priority_queue` |
| Unique + sorted | `set` |
| Key → value + sorted | `map` |
| Key → value + fast lookup | `unordered_map` |
| Unique + fast lookup | `unordered_set` |

### Most important for DSA

```text
vector
unordered_map
set
map
unordered_set
priority_queue
queue
stack
```

`array`, `deque`, and especially `list` are more situational.

---

# 2. Algorithms

Generally:

```cpp
#include <algorithm>
```

---

## 1. Binary Search

### What is it?

Searches a **sorted range** by repeatedly dividing the search space in half.

```cpp
vector<int> v = {1, 3, 5, 7, 9};

bool found = binary_search(v.begin(), v.end(), 5);
```

### Syntax

```cpp
binary_search(begin, end, value);
```

Returns:

```text
true / false
```

### Complexity

```text
O(log N)
```

### Example

```cpp
if (binary_search(v.begin(), v.end(), 5))
    cout << "Found";
```

### Gotchas

The range must be **sorted** according to the comparison being used.

```cpp
sort(v.begin(), v.end());
```

### Why use it?

You only care:

```text
Does this value exist?
```

### When to use?

Sorted data + existence check.

If you need the **position**, use `lower_bound()`.

---

## 2. `lower_bound()` / `upper_bound()`

These are extremely important for DSA.

Assume:

```cpp
vector<int> v = {1, 2, 2, 2, 4, 5};
```

### `lower_bound`

Returns iterator to the **first element >= x**.

```cpp
auto it = lower_bound(v.begin(), v.end(), 2);
```

Points to:

```text
1 2 2 2 4 5
  ↑
```

### Formula

```text
lower_bound(x)
= first element >= x
```

---

### `upper_bound`

Returns iterator to the **first element > x**.

```cpp
auto it = upper_bound(v.begin(), v.end(), 2);
```

Points to:

```text
1 2 2 2 4 5
        ↑
```

### Formula

```text
upper_bound(x)
= first element > x
```

### Complexity

```text
O(log N)
```

for random-access iterators such as `vector`.

### Getting index

```cpp
int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
```

### Count occurrences

For sorted vector:

```cpp
int count = upper_bound(v.begin(), v.end(), x)
          - lower_bound(v.begin(), v.end(), x);
```

### Gotcha

If no element satisfies the condition:

```cpp
lower_bound(...) == v.end()
```

Don't dereference it.

### Why use it?

For:

- Binary search variants
- Finding insertion position
- Counting duplicates
- Finding first/last occurrence
- Range queries

---

## 3. `min()` / `max()`

### Syntax

```cpp
min(a, b);
max(a, b);
```

Example:

```cpp
int x = min(10, 20); // 10
int y = max(10, 20); // 20
```

### Multiple values

```cpp
int x = min({4, 2, 8, 1});
int y = max({4, 2, 8, 1});
```

### Complexity

Two values:

```text
O(1)
```

For `k` values:

```text
O(k)
```

### Also useful

```cpp
min_element(v.begin(), v.end());
max_element(v.begin(), v.end());
```

These return **iterators**.

```cpp
auto it = max_element(v.begin(), v.end());

cout << *it;
```

Complexity:

```text
O(N)
```

### Gotcha

`min_element()` returns an iterator, not the value itself.

---

## 4. `rotate()` / `reverse()`

### `reverse`

Reverses a range.

```cpp
reverse(v.begin(), v.end());
```

Before:

```text
1 2 3 4 5
```

After:

```text
5 4 3 2 1
```

### Complexity

```text
O(N)
```

### Syntax

```cpp
reverse(first, last);
```

---

### `rotate`

Moves elements so that the specified middle becomes the beginning.

```cpp
rotate(v.begin(), v.begin() + 2, v.end());
```

Before:

```text
1 2 3 4 5
```

After:

```text
3 4 5 1 2
```

Conceptually:

```text
[begin ... middle) [middle ... end)
         ↓
[middle ... end) [begin ... middle)
```

### Complexity

```text
O(N)
```

### Gotcha

The second iterator is the **new beginning**.

```cpp
rotate(begin, new_begin, end);
```

---

## 5. `sort()` / `swap()`

### `sort`

Sorts a range.

```cpp
sort(v.begin(), v.end());
```

Ascending:

```text
1 2 3 4 5
```

### Complexity

```text
O(N log N)
```

### Descending

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Or:

```cpp
sort(v.rbegin(), v.rend());
```

### Custom comparator

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

For pairs:

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b) {
    return a.second < b.second;
});
```

### Gotchas

- `sort()` requires random-access iterators.
- Works with `vector`, `array`, etc.
- Doesn't work with `list`.

For `list`:

```cpp
l.sort();
```

---

### `swap`

### What is it?

Exchanges two values.

```cpp
int a = 10;
int b = 20;

swap(a, b);
```

Now:

```text
a = 20
b = 10
```

### Complexity

Usually:

```text
O(1)
```

for primitive types and efficient STL containers.

### Syntax

```cpp
swap(a, b);
```

---

# ⭐ Ultimate Quick Reference

## Containers

```text
array          fixed-size array
vector         dynamic array
deque          dynamic array + both-end operations
list           doubly linked list
stack          LIFO
queue          FIFO
priority_queue heap → min/max
set            sorted + unique
map            sorted key → value
unordered_map  hash key → value
unordered_set  hash + unique
```

## Algorithms

```text
binary_search()
    Does x exist?
    O(log N)
    Requires sorted range

lower_bound()
    first element >= x
    O(log N)

upper_bound()
    first element > x
    O(log N)

min() / max()
    minimum / maximum of values

min_element()
    iterator to minimum
    O(N)

max_element()
    iterator to maximum
    O(N)

reverse()
    reverse range
    O(N)

rotate()
    move middle to beginning
    O(N)

sort()
    sort range
    O(N log N)

swap()
    exchange two values
    ~O(1)
```

---

# ⭐ What to Memorize First for DSA

```cpp
vector<int> v;

sort(v.begin(), v.end());

auto it = lower_bound(v.begin(), v.end(), x);

unordered_map<int, int> freq;

priority_queue<int> pq;
```

Remember this distinction:

```text
vector        → ordered data, index access

set           → unique + sorted

unordered_set → unique + fast lookup

map           → key/value + sorted

unordered_map  → key/value + fast lookup

priority_queue → repeatedly get min/max
```

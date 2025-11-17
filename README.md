# **AVL Tree Implementations:**

This repository contains **Independent C++ AVL Tree projects**, each demonstrating a different use-case of self-balancing binary search trees:

1. **AVL Tree with k-th Smallest Element**
2. **AVL Tree Counting Keys in a Given Range**
3. **AVL Tree for Gamer Leaderboard Management (rank + accuracy)**

All implementations follow standard AVL rotation rules and maintain node `height`.
The first two also track subtree `size` for order statistics.

---

## **1. AVL Tree with k-th Smallest Element**

### **Purpose**

Efficiently find the **k-th smallest value** in a dynamic set of integers using AVL height-balancing + subtree size tracking.

### **Key Features**

* Standard AVL insertion
* Left/Right + LR/RL rotations
* Each node stores:

  * `height`
  * `size` (number of nodes in its subtree)
* `kthSmallest(root, k)` using `size(left_subtree)` logic

  * O(log n) time

### **How It Works**

The tree stays balanced through rotations.
Using subtree sizes, the algorithm compares:

```
k == size(left) + 1   → root is the k-th element
k <  size(left)       → go left
k >  size(left) + 1   → go right (adjust k)
```

### **Sample Output**

```
The 3rd smallest element is: 25
```

---

## **2. AVL Tree: Count Elements Within a Range [l, r]**

### **Purpose**

Count how many numbers fall within a user-defined range — efficiently.

### **Key Features**

* Same AVL balancing and insertion logic as above
* Recursive range counting:

  * If `l ≤ root->data ≤ r` → count node + both subtrees
  * If root < l → skip left subtree
  * If root > r → skip right subtree

### **Complexity**

Worst case still O(n), but AVL helps keep the tree balanced, making traversal predictable.

### **Usage**

User inputs range:

```
enter l: 5
enter r: 15
RESULT: 4
```

---

## **3. Gamer Leaderboard Using AVL Tree**

### **Purpose**

A leaderboard where:

* Players are indexed by **rank** (BST key)
* Each player stores **accuracy**
* Search, delete, rebalance, and min-accuracy removal works cleanly

### **Key Features**

* `Gamer` class with `(rank, accuracy)`
* AVL tree sorted by **rank**
* In-order traversal prints leaderboard ascending by rank
* Delete **node with minimum accuracy**, not minimum rank
* Full AVL rebalancing after both insertions and deletions
* `verifyAVL()` to sanity-check your tree structure

### **Leaderboard Example**

```
=== Leaderboard (sorted by rank) ===
Rank: #30, Accuracy: 70.2
Rank: #50, Accuracy: 85.5
Rank: #70, Accuracy: 92.1
```

After deleting the player with lowest accuracy:

```
=== Leaderboard (sorted by rank) ===
Rank: #50, Accuracy: 85.5
Rank: #70, Accuracy: 92.1

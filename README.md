# Disclaimer

This is a medium-level coding challenge, likely much harder than anything you will see on an EECS280 exam.

It is, however, good practice to think recursively in a problem you probably haven't seen before.

Don't feel bad if you struggle to solve it!

Good luck!

# Task

Your task is to implement the sumOfEvenGrandparents function below. This
function should take in a pointer to the root of a tree and determine the sum of
even-valued grandparents. (A grandparent of a node is the parent of its parent,
if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

# Starter Code

The problem header includes the definition of Node, which is a struct used to
represent nodes in our tree.

We include it below for your reference. Note that the nodes do NOT contain
parent pointers!

You cannot add additional members to the Node struct. Your solution must work
with the given header file.

```cpp
struct Node {
  Node(int value_in) : value{value_in}, left{nullptr}, right{nullptr} {}

  int value;
  Node* left;
  Node* right;
};
```

# Sample Input and Correct Output

Consider the following Binary Tree as your input:

```
              1
            /   \
           2     3
          /  \   / \
         4    5 6    6
        / \   /
       6   6 6
```

In the above example, your function should return: `6 + 6 + 6 = 18`

## Explanation:

```
              1
            /   \
          [2]     3
          /  \   / \
         4    5 6    6
        / \   /
       6   6 6
       ^   ^ ^
```

The nodes pointed to with a `^` are the ones included in the sum, because their grandparen, `[2]`, is even.

# Hints

1. Think recursively... you need to somehow get the grandparent value, yet you do not have parent pointers!
2. Often, it is helpful to write a recursive helper function with additional parameters

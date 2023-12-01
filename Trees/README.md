# Binary Tree

## Overview

A Binary Tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. It is a widely used data structure for various applications, such as representing hierarchical relationships, expression parsing, and binary search.

## Basic Structure

A node in a binary tree consists of three components:

- **Data:** The value or information stored in the node.
- **Left Child:** A pointer/reference to the left child node.
- **Right Child:** A pointer/reference to the right child node.

## Building a Binary Tree

Building a binary tree involves taking user input for each node and recursively creating its left and right subtrees. A typical user input may include a special value (e.g., -1) to denote a NULL node.

## PseudoCode to Create a Binary Tree
```plaintext
Procedure createBinaryTree:
    Input: None
    Output: Pointer to the root of the binary tree

    // Define the structure for a tree node
    Class Node:
        Data
        LeftChild
        RightChild

    // Function to create a new node
    Function createNode(data):
        newNode = new Node
        newNode.Data = data
        newNode.LeftChild = null
        newNode.RightChild = null
        return newNode

    // Recursive function to build the binary tree
    Function buildBinaryTree():
        Print("Enter the data for the node (-1 for NULL):")
        Read data

        // Base case: if data is -1, return null (indicating a NULL node)
        If data == -1:
            Return null

        // Create a new node with the entered data
        newNode = createNode(data)

        Print("Enter the data to insert in the left of ", data)
        // Recursively build the left subtree
        newNode.LeftChild = buildBinaryTree()

        Print("Enter the data to insert in the right of ", data)
        // Recursively build the right subtree
        newNode.RightChild = buildBinaryTree()

        Return newNode

    // Main function to initiate tree creation
    Function main():
        // Initialize an empty tree
        root = null
        // Call the recursive function to build the tree
        root = buildBinaryTree()

        // The root now points to the root of the created binary tree
```

## Algorithm to create a Binary Tree

```plaintext
Algorithm: BuildBinaryTree
Input: None
Output: Pointer to the root of the binary tree

Class Node:
    Data
    LeftChild
    RightChild

Function createNode(data):
    newNode = new Node
    newNode.Data = data
    newNode.LeftChild = null
    newNode.RightChild = null
    return newNode

Function buildBinaryTree():
    Print("Enter the data for the node (-1 for NULL):")
    Read data

    // Base case: if data is -1, return null (indicating a NULL node)
    If data == -1:
        Return null

    // Create a new node with the entered data
    newNode = createNode(data)

    Print("Enter the data to insert in the left of ", data)
    // Recursively build the left subtree
    newNode.LeftChild = buildBinaryTree()

    Print("Enter the data to insert in the right of ", data)
    // Recursively build the right subtree
    newNode.RightChild = buildBinaryTree()

    Return newNode

Function main():
    // Initialize an empty tree
    root = null
    // Call the recursive function to build the tree
    root = buildBinaryTree()

    // The root now points to the root of the created binary tree
```

## Types of Binary Trees

1. **Full Binary Tree:**
   - Every node has either 0 or 2 children.
   - All leaves are at the same level.

2. **Complete Binary Tree:**
   - All levels are completely filled except possibly the last level.
   - All nodes are as left as possible.

3. **Perfect Binary Tree:**
   - Every level is completely filled with nodes.
   - The number of nodes is \(2^{h+1} - 1\), where \(h\) is the height.

4. **Balanced Binary Tree:**
   - The height of the left and right subtrees of any node differs by at most one.

## Binary Tree Traversal

Traversal involves visiting all the nodes of a tree and performing an operation at each node. There are three common types of binary tree traversals:

1. **Inorder Traversal:**
   - Left subtree -> Root -> Right subtree.
   - Used to get the elements of a binary search tree in non-decreasing order.

2. **Preorder Traversal:**
   - Root -> Left subtree -> Right subtree.
   - Used to create a prefix expression (Polish notation) of an expression tree.

3. **Postorder Traversal:**
   - Left subtree -> Right subtree -> Root.
   - Used to create a postfix expression (Reverse Polish notation) of an expression tree.

## Level Order Traversal

Level order traversal involves visiting nodes level by level, from left to right. It is commonly implemented using a queue.

## Applications

1. **Expression Trees:**
   - Used to represent mathematical expressions for easy evaluation.

2. **Binary Search Trees (BST):**
   - Used for efficient searching, insertion, and deletion operations.

3. **Huffman Coding Trees:**
   - Used for data compression.

4. **File Systems:**
   - Directory structures in file systems are often represented as trees.

## Usage

Binary trees are fundamental data structures with various applications in computer science. Understanding their properties and traversal methods is crucial for algorithmic problem-solving.

## Complexity

- **Time Complexity:** The time complexity of common operations (insertion, deletion, search) depends on the height of the tree. For a balanced tree, it is \(O(\log n)\), but for an unbalanced tree, it can be \(O(n)\).
- **Space Complexity:** The space complexity depends on the number of nodes, resulting in \(O(n)\) space in the worst case.

## Advantages

- Simple and flexible data structure.
- Efficient for specific applications like binary search.

## Disadvantages

- The time complexity of operations can degrade in an unbalanced tree.

## Conclusion

Binary trees are versatile data structures with applications in various domains. Understanding their properties and traversal methods is essential for designing efficient algorithms and solving computational problems.

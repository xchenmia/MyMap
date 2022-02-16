/* mymap.h
 *
 * Project 5 Oct 28
 * Xiao Chen
 *
 * This project implementing a templated map class. It will have a
 * similar functionality to the C++ standard library map container.
 */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

template <typename keyType, typename valueType> class mymap {
private:
  struct NODE {
    keyType key;     // used to build BST
    valueType value; // stored data for the map
    NODE *left;      // links to left child
    NODE *right;     // links to right child
    int nL;          // number of nodes in left subtree
    int nR;          // number of nodes in right subtree
    bool isThreaded;
  };
  NODE *root; // pointer to root node of the BST
  int size;   // # of key/value pairs in the mymap

  //
  // iterator:
  // This iterator is used so that mymap will work with a foreach loop.
  //
  struct iterator {
  private:
    NODE *curr; // points to current in-order node for begin/end

  public:
    iterator(NODE *node) { curr = node; }

    keyType operator*() { return curr->key; }

    bool operator==(const iterator &rhs) {
      if (curr == nullptr && rhs.curr == nullptr) {
        return this == &rhs;
      }
      return curr == rhs.curr;
    }

    bool operator!=(const iterator &rhs) {
      if (curr == nullptr && rhs.curr == nullptr) {
        return this == &rhs;
      }
      return curr != rhs.curr;
    }

    bool isDefault() { return !curr; }

    //
    // operator++:
    //
    // This function should advance curr to the next in-order node.
    // O(logN)
    //
    iterator operator++() {
      if (curr->isThreaded) {
        curr = curr->right;
      }

      else {
        curr = curr->right;
        if (curr != nullptr) {
          while (curr->left != nullptr) {
            curr = curr->left;
          }
        }
      }

      return iterator(curr);
    }
  };

  //
  //_checkBalance
  //
  // Returns a string of mymap that verifies that the tree is properly
  // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
  // function should return a string in this format (in pre-order):
  // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  void _checkBalance(NODE *node, ostream &result) {
    if (node == nullptr) {
      return;
    }
    result << "key: " << node->key << ", nL: " << node->nL
           << ", nR: " << node->nR << endl;
    _checkBalance(node->left, result);
    if (node->isThreaded != true) {
      _checkBalance(node->right, result);
    }
  }

  //
  //_toVector
  //
  // This is helper function for toVector
  //
  void _toVector(NODE *node, vector<pair<keyType, valueType>> &Vreturn) {
    if (node == nullptr) {
      return;
    }
    _toVector(node->left, Vreturn);
    Vreturn.push_back(make_pair(node->key, node->value));
    if (node->isThreaded != true) {
      _toVector(node->right, Vreturn);
    }
  }

  //
  // subVector
  //
  // This is function for get violatedNode and it child Node in the vector
  //
  void subVector(NODE *node, vector<NODE *> &V) {
    if (node == nullptr) {
      return;
    }
    subVector(node->left, V);
    V.push_back(node);
    if (node->isThreaded) {
      node = nullptr;
    } else {
      subVector(node->right, V);
    }
  }

  //
  // inOrder
  //
  // This is helper function for print in order
  //
  void inOrder(NODE *node, ostream &out) {
    if (node == nullptr) {
      return;
    }
    NODE *curr = node;
    inOrder(node->left, out);
    out << "key: " << node->key << " value: " << node->value << endl;
    if (curr->isThreaded == true) {
      curr = nullptr;
    } else {
      inOrder(node->right, out);
    }
  }

  //
  // balanceNode
  //
  // This function is made rebalance the tree, it
  // check it node to find ViolatedNode.
  //

  void balanceNode(keyType key) {
    NODE *curr = nullptr;
    NODE *parents = nullptr;
    NODE *ViolatedNode = nullptr;
    curr = root;
    FindViolation(curr, ViolatedNode, parents, key);
    // check the violated
    if (ViolatedNode != nullptr) {
      //   // split violatedNode notes
      vector<NODE *> cutNode;
      NODE *newSubtree = nullptr;
      subVector(ViolatedNode, cutNode);
      if (cutNode.size() == 0) {
        newSubtree = nullptr;
      } else if (cutNode.size() == 1) {
        newSubtree = ViolatedNode;
      } else {
        newSubtree = Rebalance(cutNode, nullptr, 0, cutNode.size() - 1);
      }
      // if still in this loop & stack size == 0,then it is a not tree
      if (parents == nullptr) {
        root = newSubtree;
      } else {
        if (parents->key < newSubtree->key) {
          parents->right = newSubtree;
        } else {
          parents->left = newSubtree;
        }
      } // outer else

    } // if
  }

  //
  // _newN
  //
  // make new node and  initialize the Value
  //
  NODE *_newN(keyType key, valueType value) {
    NODE *n = new NODE();
    n->key = key;
    n->value = value;
    n->left = nullptr;
    n->right = nullptr;
    n->nL = 0;
    n->nR = 0;
    n->isThreaded = false;
    return n;
  }

  //
  // Rebalance
  //
  // There's a function is made for balance tree, it use the mid,low and high
  // to  link the new tree and update nL,nR
  //

  NODE *Rebalance(vector<NODE *> &cutNode, NODE *h, int low, int high) {
    if (low > high) {
      return nullptr;
    }
    int mid = (low + high) / 2;
    NODE *root = cutNode[mid];
    root->nL = 0;
    root->nR = 0;
    root->isThreaded = false;
    root->left = Rebalance(cutNode, root, low, mid - 1);
    if (root->left != nullptr) {
      root->nL = root->left->nR + root->left->nL + 1;
    }
    root->right = Rebalance(cutNode, h, mid + 1, high);
    if (root->right != nullptr) {
      root->nR = root->right->nR + root->right->nL + 1;
    } else {
      root->right = h;
      if (root->right != nullptr) {
        root->isThreaded = true;
      }
    }
    return root;
  }

  //
  // cutVector
  //
  // Make vector of type Node*
  //
  vector<NODE *> cutVector(vector<NODE *> n, int l, int r) {
    vector<NODE *> newVector;
    for (int i = l; i <= r; i++) {
      newVector.push_back(n[i]);
    }
    return newVector;
  }

  //
  // FindViolation
  //
  // This function is made for find violation.
  //
  void FindViolation(NODE *r, NODE *&ViolatedNode, NODE *&parents,
                     keyType key) {
    NODE *curr = r;
    parents = nullptr;
    while (curr != nullptr) {
      if (ifBalanced(curr->nL, curr->nR) == false) {
        ViolatedNode = curr;
        return;
      }
      if (key < curr->key) // Search left
      {
        parents = curr;
        curr = curr->left;
      } else {
        parents = curr;
        curr = (curr->isThreaded) ? nullptr : curr->right; // Search Right
      }
    } // end while
  }

  //
  // deleteNode
  //
  // This function is made for delete Nodes
  //
  void deleteNode(NODE *node) {
    if (node == nullptr) {
      return;
    }
    deleteNode(node->left);
    if (node->isThreaded != true) {
      deleteNode(node->right);
    }
    delete node;
//    node = nullptr;
    size--;
  }

  //
  // _copyTree
  //
  // This is make for copy tree
  //
  void _copyTree(NODE *&thisNode, NODE *otherNode) {
    if (otherNode == nullptr) {
      return;
    }
    NODE *n = new NODE();
    n->key = otherNode->key;
    n->value = otherNode->value;
    n->left = nullptr;
    n->right = nullptr;
    n->nL = otherNode->nL;
    n->nR = otherNode->nR;
    n->isThreaded = otherNode->isThreaded;
    thisNode = n;
    _copyTree(thisNode->left, otherNode->left);
    if (otherNode->isThreaded) {
      otherNode = nullptr;
    } else {
      _copyTree(thisNode->right, otherNode->right);
    }
    this->size++;
  }

public:
  //
  // default constructor:
  //
  // Creates an empty mymap.
  // Time complexity: O(1)
  //
  mymap() {
    root = nullptr;
    size = 0;
  }

  //
  // copy constructor:
  //
  // Constructs a new mymap which is a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap(const mymap &other) {
    this->size = 0;
    this->root=nullptr;
    _copyTree(this->root, other.root);
  }

  //
  // operator=:
  //
  // Clears "this" mymap and then makes a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap &operator=(const mymap &other) {
    if (this == &other) {
      return *(this);
    }
    this->clear();
    _copyTree(this->root, other.root);
    return *this; // TODO: Update this return.
  }

  // clear:
  //
  // Frees the memory associated with the mymap; can be used for testing.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  void clear() { 
    deleteNode(root);
    root=nullptr;
    size=0;
    
               }

  //
  // destructor:
  //
  // Frees the memory associated with the mymap.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  ~mymap() {
    //    if(size != 0){
    deleteNode(root);
    //         }
  }

  bool ifBalanced(int nL, int nR) {
    if (max(nL, nR) <= 2 * min(nL, nR) + 1) {
      return true;
    } else {
      return false;
    }
  }

  //
  // put:
  //
  // Inserts the key/value into the threaded, self-balancing BST based on
  // the key.
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-tree that needs to be re-balanced.
  // Space complexity: O(1)
  //
  void put(keyType key, valueType value) {
    NODE *prev = nullptr;
    NODE *curr = root;
    stack<NODE *> nodes;
    //
    // 1. Search for key, return if found
    //
    while (curr != nullptr) {
      if (key == curr->key) {
        curr->value = value;
        return;
      }
      nodes.push(curr);
      if (key < curr->key) // Search left
      {
        prev = curr;
        curr = curr->left;
      } else {
        prev = curr;
        curr = (curr->isThreaded) ? nullptr : curr->right; // Search Right
      }
    } // end while

    //
    // 2. If not found, insert where we
    //    fell out from the tree
    //
    NODE *n = _newN(key, value);
    if (root == nullptr) {
      root = n;
      size++;
      return;
    }
    if (key < prev->key) {
      prev->left = n;
      // may not need
      // nodes.push(prev->left);
      n->right = prev; // points parents;
      n->isThreaded = true;
    } else {
      n->right = prev->right;
      prev->right = n;
      //  nodes.push(prev->right);
      n->isThreaded = true;
      prev->isThreaded = false;
    }
    size++;
    while (nodes.size() != 0) {
      NODE *cur = nodes.top();
      if (cur->key > n->key) {
        cur->nL++;
      } else {
        cur->nR++;
      }
      nodes.pop();
    }
    balanceNode(key);
  }

  //
  // contains:
  // Returns true if the key is in mymap, return false if not.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  bool contains(keyType key) {
    NODE *curr = root;
    while (curr != nullptr) {
      //             cout<<"key: "<<key<<endl;
      //             cout<<"curr->key: "<<curr->key<<endl;
      if (key == curr->key) {
        return true;
      }
      if (key < curr->key) {
        
//         if(curr->left != nullptr){
        curr = curr->left;
//         }
      } else {
        curr = (curr->isThreaded) ? nullptr : curr->right;
      }
    }             // end while
    return false; // If we get here, not found
  }

  //
  // get:
  //
  // Returns the value for the given key; if the key is not found, the
  // default value, valueType(), is returned (but not added to mymap).
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  valueType get(keyType key) {
    NODE *curr = root;
    while (curr != nullptr) {
      if (key == curr->key)
        return curr->value;
      if (key < curr->key) {
        curr = curr->left;
      } else {
        curr = (curr->isThreaded) ? nullptr : curr->right; // Search Right
      }
    }                   // end while
    return valueType(); // If we get here, not found
  }

  //
  // operator[]:
  //
  // Returns the value for the given key; if the key is not found,
  // the default value, valueType(), is returned (and the resulting new
  // key/value pair is inserted into the map).
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-trees that need to be re-balanced.
  // Space complexity: O(1)
  //
  valueType operator[](keyType key) {
    if (!contains(key)) {
      put(key, valueType());
    }
    return get(key);
  }

  //
  // Size:
  //
  // Returns the # of key/value pairs in the mymap, 0 if empty.
  // O(1)
  //
  int Size() { return this->size; }

  //
  // begin:
  //
  // returns an iterator to the first in order NODE.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  iterator begin() {
    NODE *curr = root;
    while (curr->left != nullptr) {
      curr = curr->left;
    }
    return iterator(curr);
  }

  //
  // end:
  //
  // returns an iterator to the last in order NODE.
  // this function is given to you.
  //
  // Time Complexity: O(1)
  //
  iterator end() { return iterator(nullptr); }

  //
  // toString:
  //
  // Returns a string of the entire mymap, in order.
  // Format for 8/80, 15/150, 20/200:
  // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string toString() {
    stringstream ss;
    inOrder(root, ss);
    return ss.str();
  }

  //
  // toVector:
  //
  // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
  // {{8, 80}, {15, 150}, {20, 200}}
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  vector<pair<keyType, valueType>> toVector() {
    vector<pair<keyType, valueType>> Vreturn;
    _toVector(root, Vreturn);

    return Vreturn; // TODO: Update this return.
  }

  //
  // checkBalance:
  //
  // Returns a string of mymap that verifies that the tree is properly
  // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
  // function should return a string in this format (in pre-order):
  // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //'
  //

  string checkBalance() {
    stringstream result;
    _checkBalance(root, result);
    return result.str();
  }
};

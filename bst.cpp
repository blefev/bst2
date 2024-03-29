#include "bst.h"

using namespace std;

BST::BST() { root = NULL; }

void BST::insert(int val) {
  node *newNode = new node;
  newNode->val = val;

  if (!this->root) {
    this->root = newNode;
    return;
  }

  this->insert_helper(val, this->root, newNode);
}

void BST::insert_helper(int val, node *cur, node *newNode) {
  if (val < cur->val) {
    if (!cur->left) {
      newNode->parent = cur;
      newNode->from = LEFT;
      cur->left = newNode;
      return;
    }
    this->insert_helper(val, cur->left, newNode);
  } else if (val > cur->val) {
    if (!cur->right) {
      newNode->parent = cur;
      newNode->from = RIGHT;
      cur->right = newNode;
      return;
    }
    this->insert_helper(val, cur->right, newNode);
  }
  return;
}

void BST::inorder() {
  cout << "INORDER: ";
  this->inorder_helper(this->root);
  cout << "END\n";
}

void BST::inorder_helper(node *inputNode) {
  if (!inputNode) {
    return;
  }

  this->inorder_helper(inputNode->left);
  cout << inputNode->val << " -> ";
  this->inorder_helper(inputNode->right);
}

void BST::postorder() {
  cout << "POSTORDER: ";
  this->postorder_helper(this->root);
  cout << "END\n";
}

void BST::postorder_helper(node *inputNode) {
  if (!inputNode) {
    return;
  }

  this->postorder_helper(inputNode->right);
  cout << inputNode->val << " -> ";
  this->postorder_helper(inputNode->left);
}

void BST::preorder() {
  cout << "PREORDER: ";
  this->preorder_helper(this->root);
  cout << "END\n";
}

void BST::preorder_helper(node *inputNode) {
  if (!inputNode) {
    return;
  }

  cout << inputNode->val << " -> ";
  this->preorder_helper(inputNode->right);
  this->preorder_helper(inputNode->left);
}

node *BST::search(int val) { return this->search_helper(val, this->root); }

node *BST::search_helper(int val, node *cur) {
  if (!cur) {
    return NULL;
  } else if (val == cur->val) {
    return cur;
  } else if (val < cur->val) {
    return this->search_helper(val, cur->left);
    cout << "Search val < cur";
    if (!cur->left)
      return NULL;
  } else if (val > cur->val) {
    if (!cur->right)
      return NULL;
    cout << "Search val > cur";
    return this->search_helper(val, cur->right);
  }
  return NULL;
}

bool BST::remove(int val) {
  node *toRemove = this->search(val);

  if (!toRemove) {
    return false;
  }

  if (!toRemove->parent) {
    // To remove is root node
  }

  if (toRemove->left && toRemove->right) {
    node *rep = this->findMinHelper(toRemove->left);

    if (toRemove->from == LEFT) {
      toRemove->parent->left = rep;
    } else if (toRemove->from == RIGHT) {
      toRemove->parent->right = rep;
    } else
      return false;

    rep->parent = toRemove->parent;

    delete toRemove;
    return true;
  }

  if (!toRemove->left && !toRemove->right) {
    node *parent = toRemove->parent;

    if (toRemove->from == LEFT) {
      parent->left = NULL;
    } else if (toRemove->from == RIGHT) {
      parent->right = NULL;
    }
    delete toRemove;
    return true;
  }

  // Node has one child
  if (!toRemove->left ^ !toRemove->right) {

    node *child;

    if (toRemove->left) {
      child = toRemove->left;
    } else if (toRemove->right) {
      child = toRemove->right;
    }

    node *parent = toRemove->parent;

    child->parent = parent;

    // Now we set the parent pointer to the child
    if (toRemove->from == LEFT) {
      parent->left = child;
    } else if (toRemove->from == RIGHT) {
      parent->right = child;
    }
    delete toRemove;
    return true;
  }
  return false;
}

node *BST::findMin() { return findMinHelper(this->root); }

node *BST::findMax() { return findMaxHelper(this->root); }

node *BST::findMinHelper(node *cur) {
  if (!cur->left)
    return cur;

  return findMinHelper(cur->left);
}

node *BST::findMaxHelper(node *cur) {
  if (!cur->right)
    return cur;

  return findMaxHelper(cur->right);
}

int BST::findHeight() { this->findHeightHelper(this->root, 0); }

int BST::findHeightHelper(node *cur, int height) {
  if (!cur)
    return 0;

  int leftHeight = findHeightHelper(cur->left, height) + height + 1;
  int rightHeight = findHeightHelper(cur->right, height) + height + 1;

  return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

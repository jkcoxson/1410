// Jackson Coxson

#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"
#include <sstream>
#include <string>

template <typename T> class BST {
public:
  BST() : root(nullptr), node_count(0) {}

  void insert(const T &value) { root = insertRec(root, value); }

  bool contains(const T &value) const { return containsRec(root, value); }

  int count() const { return node_count; }

  std::string search(const T &value) const {
    std::ostringstream out;

    if (!root)
      return "Not found:";

    Node<T> *curr = root;
    out << "root(" << root->getData() << ")";

    while (curr) {
      if (value == curr->getData()) {
        return "Found: " + out.str();
      }

      if (value < curr->getData()) {
        if (curr->getLeft()) {
          out << "->left(" << curr->getLeft()->getData() << ")";
        } else {
          return "Not found: " + out.str();
        }
        curr = curr->getLeft();
      } else {
        if (curr->getRight()) {
          out << "->right(" << curr->getRight()->getData() << ")";
        } else {
          return "Not found: " + out.str();
        }
        curr = curr->getRight();
      }
    }

    // Should never reach here
    return "Not found: " + out.str();
  }

  void remove(const T &value) { root = removeRec(root, value); }

private:
  Node<T> *root;
  int node_count;

  Node<T> *insertRec(Node<T> *node, const T &value) {
    if (!node) {
      node_count++;
      return new Node<T>(value);
    }
    if (value < node->getData())
      node->setLeft(insertRec(node->getLeft(), value));
    else if (value > node->getData())
      node->setRight(insertRec(node->getRight(), value));
    return node;
  }

  bool containsRec(Node<T> *node, const T &value) const {
    if (!node)
      return false;
    if (value == node->getData())
      return true;
    if (value < node->getData())
      return containsRec(node->getLeft(), value);
    return containsRec(node->getRight(), value);
  }

  Node<T> *removeRec(Node<T> *node, const T &value) {
    if (!node) {
      return nullptr;
    }

    if (value < node->getData()) {
      node->setLeft(removeRec(node->getLeft(), value));
    } else if (value > node->getData()) {
      node->setRight(removeRec(node->getRight(), value));
    } else {
      // Node found
      if (!node->getLeft() && !node->getRight()) {
        delete node;
        node_count--;
        return nullptr;
      } else if (!node->getLeft()) {
        Node<T> *temp = node->getRight();
        delete node;
        node_count--;
        return temp;
      } else if (!node->getRight()) {
        Node<T> *temp = node->getLeft();
        delete node;
        node_count--;
        return temp;
      } else {
        Node<T> *pred = maxNode(node->getLeft());
        node->setData(pred->getData());
        node->setLeft(removeRec(node->getLeft(), pred->getData()));
      }
    }

    return node;
  }

  Node<T> *minNode(Node<T> *node) {
    while (node->getLeft())
      node = node->getLeft();
    return node;
  }

  Node<T> *maxNode(Node<T> *node) {
    while (node->getRight())
      node = node->getRight();
    return node;
  }
};

#endif

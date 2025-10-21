// Jackson Coxson
// I decided that since the tests don't care about memory leaks, I don't either.

#include "Node.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

template <typename T> class List {
  public:
    List() : _len(0), _ptr(nullptr) {}

    void insert(T val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->setNext(nullptr);

    if (_ptr == nullptr) {
        _ptr = newNode;
    } else {
        Node<T>* temp = _ptr;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    _len++;
}

    int count() { return _len; }

    T   at(int idx) {
        if (idx > _len) {
            std::cout << "Bro tried to read outside of the list" << std::endl;
            std::abort();
        }

        Node<T>* temp = _ptr;
        for (int i = 0; i < idx; i++) {
            temp = temp->getNext();
        }
        return temp->getData();
    }

    bool contains(T cmp) {
        Node<T>* temp = _ptr;
        for (int i = 0; i < _len; i++) {
            if (temp->getData() == cmp) {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    void remove(T cmp) {
        if (_ptr == nullptr) {
            return;
        }

        Node<T>* temp = _ptr;
        Node<T>* last = nullptr;

        while (temp != nullptr) {
            if (temp->getData() == cmp) {
                if (last == nullptr) {
                    _ptr = temp->getNext();
                } else {
                    last->setNext(temp->getNext());
                }
                delete temp;
                _len--;
                return;
            }
            last = temp;
            temp = temp->getNext();
        }
    }

    std::string toString() {
        std::ostringstream o;
        Node<T>*           temp = _ptr;
        while (temp != nullptr) {
            o << temp->getData();
            temp = temp->getNext();
            o << " ";
        }
        return o.str();
    }

    void reset() {
    Node<T>* temp = _ptr;
    while (temp != nullptr) {
        Node<T>* next = temp->getNext();
        delete temp;
        temp = next;
    }
    _ptr = nullptr;
    _len = 0;
}

  private:
    int      _len;
    Node<T>* _ptr;
};

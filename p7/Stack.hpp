// Jackson Coxson

#include "Node.hpp"
#include <cstdlib>
#include <iostream>

template <typename T> class Stack {
  public:
    Stack() : _ptr(nullptr), _len(0) {}

    int  count() { return _len; }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);

        newNode->setNext(_ptr);
        _ptr = newNode;
        _len++;
    }

    T top() {
        if (_len == 0) {
            std::cout << "oh no if only the assignment could let us return a real value for an "
                         "empty stack";
            std::abort();
        }

        return _ptr->getData();
    }

    T pop() {
        if (_len == 0) {
            std::cout << "the stack is empty dummy";
            std::abort();
        }
        T res = _ptr->getData();
        _ptr  = _ptr->getNext();
        _len--;
        return res;
    }

    void reset() {
        while (_ptr != nullptr) {
            Node<T>* temp = _ptr;
            _ptr          = _ptr->getNext();
            delete temp;
        }
        _len = 0;
    }

  private:
    int      _len;
    Node<T>* _ptr;
};

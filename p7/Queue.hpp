// Jackson Coxson

#include "Node.hpp"
#include <cstdlib>

template <typename T> class Queue {
  public:
    Queue() : _ptr(nullptr), _len(0) {}
    void enqueue(T val) {
        Node<T>* newNode = new Node<T>(val);

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

    T   front() {
        if (_len == 0) {
            std::abort();
        }
        return _ptr->getData();
    }

    T dequeue() {
        if (_len == 0) {
            std::abort();
        }
        Node<T>* temp = _ptr;
        T        val  = temp->getData();
        _ptr          = _ptr->getNext();
        delete temp;
        _len--;
        return val;
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

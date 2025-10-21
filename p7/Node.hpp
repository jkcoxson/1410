#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
  public:
    Node(T data)
      : m_data(data)
    {
      // empty
    }

    T getData(void)
    {
      return m_data;
    }

    Node<T>* getNext(void)
    {
      return m_pNext;
    }

    void setNext(Node<T>* next)
    {
      m_pNext = next;
    }

  private:
    Node<T>* m_pNext;
    T m_data;
};

#endif // NODE_HPP
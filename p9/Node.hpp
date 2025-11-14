#ifndef NODE_HPP 
#define NODE_HPP

#include <string>
#include <iostream>
#include <sstream>

template <typename T>
class Node
{
  public:
	Node(T data)
		: m_data(data),
		  m_left(NULL),
		  m_right(NULL)
	{

	}
	T getData(void)
	{
		return m_data;
	}
	Node<T>* getLeft(void)
	{
		return m_left;
	}
	Node<T>* getRight(void)
	{
		return m_right;
	}
	void setLeft(Node<T>* left)
	{
		m_left = left;
	}
	void setRight(Node<T>* right)
	{
		m_right = right;
	}

	void setData(T _d) { m_data = _d; }
  private:
	T m_data;
	Node<T>* m_left;
	Node<T>* m_right;
};



#endif
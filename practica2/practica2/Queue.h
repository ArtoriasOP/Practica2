#ifndef __Queue_H__
#define __Queue_H__

#include <iostream>
#include <assert.h>

template<class Type>
struct Node
{
	Type value;
	Node<Type>* next;
};

template<class Type>
class Queue
{
private:
	Node<Type>* start;

public:

	Queue()
	{
		start = NULL;
	}

	~Queue()
	{
		DelList();
	}

	void Push(Type valor)
	{
		Node<Type>* new_node = new Node<Type>;
		new_node->value = valor;
		new_node->next = NULL;

		if (start != NULL)
		{
			Node<Type>* tmp = start;

			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new_node;
		}
		else
		{
			start = new_node;
		}

	}

	Type Pop()
	{
		if (start != NULL)
		{
			Node<Type>* tmp = start;
			if (start->next != NULL)
			{
				start = start->next;
			}

			return tmp;
		}
		return 1;
	}

	bool DelList()
	{
		if (start != NULL)
		{
			while (start->next != NULL)
			{
				Node<Type>* tmp_Node_delete = start;
				start = start->next;
				delete tmp_Node_delete;
			}
			delete start;
			start = NULL;
			return true;
		}
		return false;
	}
};
#endif // __Queue_H_
#ifndef __TREE_H__
#define __TREE_H__

#include "p2List.h"
#include "Stack.h"

template<class TYPE>
struct Node
{

	TYPE Data;
	Node<TYPE>* Parent;
	p2List<Node<TYPE>*> Children;



	void PreOrder(p2List<Node<TYPE>*>* list)
	{
		list->add(this);
		p2List_item<Node*>* tmp = Children.start;
		for (; tmp != NULL; tmp = tmp->next)
		{
			tmp->data->PreOrder(list);
		}
	}



	void PostOrder(p2List<Node<TYPE>*>* list)
	{
		p2List_item<Node*>* tmp = Children.start;

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->PostOrder(list);

		list->add(this);
	}



	void InOrder(p2List<Node<TYPE>*>* list)
	{
		p2List_item<Node*>* tmp = Children.start;
		unsigned int mid = Children.count() / 2;

		for (unsigned int i = 0; i < mid; ++i, tmp = tmp->next)
		{
			
			tmp->data->InOrder(list);
		}

		list->add(this);

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->InOrder(list);
	}
	


	Node<TYPE>* CheckParent(const TYPE& node)
	{
		if (node == Data)
		{
			return this;
		}

		Node<TYPE>* result = NULL;
		p2List_item<Node*>* tmp = Children.start;

		for (; tmp != NULL; tmp = tmp->next)
		{
			Node* child = tmp->data;
			result = child->CheckParent(node);

			if (result != NULL)
			{
				break;
			}
		}
		return result;
	}
};
	


template<class TYPE>
class Tree
{
	public:
		Node<TYPE>* RootNode;

	
	public:

		//Constructor
		Tree(const TYPE& r_data)
		{
			RootNode = new Node<TYPE>;
			RootNode->Data = r_data;
			RootNode->Parent = NULL;

		}

		//Destructor
		virtual ~Tree()
		{
			//Clear();
		}


		Node<TYPE>*  Add(const TYPE& Data)
		{
			Node<TYPE>* NewNode = new Node<TYPE>;
			NewNode->Data = Data;
			RootNode->Children.add(NewNode);
			NewNode->Parent = RootNode;
			return NewNode;
		}
		
	
		Node<TYPE>* Add(const TYPE& Data,const TYPE& parent)
		{
			Node<TYPE>* NewNode = new Node<TYPE>;
			Node<TYPE>* Parent = RootNode->CheckParent(parent);
			NewNode->Data = Data;
			Parent->Children.add(NewNode);
			return NewNode;
		}
		
		
		

		
		void Clear()
		{
		
		}


				
		
		void PreOrder(p2List<Node<TYPE>*>* list) 
		{
			RootNode->PreOrder(list);
		}

		
		void PostOrder(p2List<Node<TYPE>*>* list) 
		{
			RootNode->PostOrder(list);
		}
		
		
		void InOrder(p2List<Node<TYPE>*>* list)
		{
			RootNode->InOrder(list);
		}

		void PreOrder_iter(p2List<Node<TYPE>*>* list)
		{

			Stack <Node<TYPE>*> stack;
			Node<TYPE>* tmp1 = RootNode;
			

			while (tmp1 != NULL || stack.Pop(tmp1))
			{
				list->add(tmp1);

				p2List_item<Node<TYPE>*>* tmp2 = tmp1->Children.end;
				for (; tmp2 != NULL; tmp2 = tmp2->prev)
					stack.PushBack(tmp2->data);

				tmp1 = (tmp2 != NULL) ? tmp2->data : NULL;
			}
			
			
		}

		void PostOrder_iter(p2List<Node<TYPE>*>* list)
		{
			Stack <Node<TYPE>*> stack;
			Node<TYPE>* tmp1 = RootNode;


			while (tmp1 != NULL || stack.Pop(tmp1))
			{
				p2List_item<Node<TYPE>*>* tmp2 = tmp1->Children.end;

				if (tmp2 != NULL && list->find(tmp2->data) == -1)
				{
					stack.PushBack(tmp1);
					for (; tmp2 != tmp1->Children.start; tmp2 = tmp2->prev)
						stack.PushBack(tmp2->data);

					tmp1 = tmp2->data;
				}
				else
				{
					list->add(tmp1);
					tmp1 = NULL;
				}

			}
		}

		
};	

#endif 


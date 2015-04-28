#ifndef __TREE_H__
#define __TREE_H__

#include "p2List.h"
#include "Stack.h"

template<class TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* Parent;
	p2List<Node<TYPE>*> Children;


	//PreOrder Recursiu
	void PreOrderRecursive(p2List<TYPE>* list)
	{
		list.AddComplex(data);
		for ()
		Node->PreOrder(list);
	}


	//PostOrder Recursiu
	void PostOrderRecursive(p2List<TYPE>* list)
	{
		for ()
		list.AddComplex(data);
		Node->PostOrder(list); 
	}


	//InOrder Recursiu
	void InOrderRecursive(p2List<TYPE>* list)
	{
		for ()
		list.AddComplex(data);
		Node->InOrder(list);
	}
};
	


template<class TYPE>
class Tree
{
	public:
		Node<TYPE>* RootNode;
	public:

		//Constructor
		Tree(const TYPE& RootData)
		{
			RootNode = new Node<TYPE>;
			RootNode->data = RootData;
			RootNode->Parent = NULL;
		}

		//Destructor
		virtual ~Tree()
		{
			
		}
		
		//Add: Create a Node with Data (node information)
		Node<TYPE>* Add(const TYPE& data)
		{
			Node<TYPE>* NewNode = new Node<TYPE>;
			NewNode->data = data;
			RootNode->Children.Add(NewNode);
			NewNode->Parent = RootNode;
			return NewNode;
		}
		
		//ParentSearcher: Find the node with the value introduced
		p2TreeNode<TYPE>* ParentSearcher(const TYPE& node)
		{
			if (node == data)
				return this;

			Tree<TYPE>* result = NULL;
			p2List_item<Tree*>* item = Children.start;
			for (; item != NULL; item = item->next)
			{
				p2TreeNode* child = item->data;
				result = child->ParentSearcher(node);

				if (result != NULL)
					break;
			}

			return result;
		}






		//AddComplex: Create a Node with Data (node information) and Parent
		void AddComplex(const TYPE& data, const TYPE Parent)
		{
			Node<TYPE>* NewNode = new Node<TYPE>;
			Node<TYPE>* Parent = RootNode->//ParentSearcher
		}
		
		

		//Clear All
		void ClearAll()
		{
		
		}

		//Clear Node
		void ClearNode()
		{
			
		}
		
	
				
		//PreOrder Recursiu
		void PreOrderRecursive(p2List<TYPE>* list)
		{
			RootNode.PreOrder(list);
		}

		//PreOrder Recursiu
		void PostOrderRecursive(p2List<TYPE>* list)
		{
			RootNode.PostOrder(list);
		}
		
		//InOrder Recursiu
		void InOrderRecursive(p2List<TYPE>* list)
		{
			RootNode.InOrder(list);
		}
};
#endif // __TREE_H__


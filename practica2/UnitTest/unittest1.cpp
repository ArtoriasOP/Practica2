#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Practica2\Tree.h"
#include "..\Practica2\p2List.h"
#include "..\Practica2\Stack.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestTree)
	{
	public:
		
		TEST_METHOD(Add1)
		{
			Tree<int> t(0);
			
			t.Add(10);
			t.Add(20);
			t.Add(30);
			
			
			Assert::AreEqual(t.RootNode->Children.start->data->Data, 10);
			Assert::AreEqual(t.RootNode->Children.end->data->Data, 30);

		}
		
		TEST_METHOD(Add2)
		{
			Tree<int> t(0);
			unsigned int check1 = 2;
			

			t.Add(5, 0);
			t.Add(3, 0);
			t.Add(2, 5);
			t.Add(4, 5);



			
			Assert::AreEqual(t.RootNode->Children.count(),check1);
			Assert::AreEqual(t.RootNode->CheckParent(5)->Children.count(), check1);
			
		}
		
		TEST_METHOD(ClearAll)
		{
			
		}

		TEST_METHOD(ClearNode)
		{
			
		}



		
		TEST_METHOD(PreOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			p2List<Node<char>*> my_tree;
			tree1.PreOrder(&my_tree);

			Assert::IsTrue(my_tree.count() == 10);

			//Result must be on alphabet order 
			Assert::IsTrue((char)my_tree[0]->Data == 'A');
			Assert::IsTrue((char)my_tree[1]->Data == 'B');
			Assert::IsTrue((char)my_tree[2]->Data == 'C');
			Assert::IsTrue((char)my_tree[3]->Data == 'D');
			Assert::IsTrue((char)my_tree[4]->Data == 'E');
			Assert::IsTrue((char)my_tree[5]->Data == 'F');
			Assert::IsTrue((char)my_tree[6]->Data == 'G');
			Assert::IsTrue((char)my_tree[7]->Data == 'H');
			Assert::IsTrue((char)my_tree[8]->Data == 'I');
			Assert::IsTrue((char)my_tree[9]->Data == 'J');
			
		}

		TEST_METHOD(PostOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			p2List<Node<char>*> my_tree;
			tree1.PostOrder(&my_tree);

			Assert::IsTrue(my_tree.count() == 10);

			Assert::IsTrue((char)my_tree[0]->Data == 'C');
			Assert::IsTrue((char)my_tree[1]->Data == 'D');
			Assert::IsTrue((char)my_tree[2]->Data == 'F');
			Assert::IsTrue((char)my_tree[3]->Data == 'G');
			Assert::IsTrue((char)my_tree[4]->Data == 'E');
			Assert::IsTrue((char)my_tree[5]->Data == 'B');
			Assert::IsTrue((char)my_tree[6]->Data == 'J');
			Assert::IsTrue((char)my_tree[7]->Data == 'I');
			Assert::IsTrue((char)my_tree[8]->Data == 'H');
			Assert::IsTrue((char)my_tree[9]->Data == 'A');
		}

		TEST_METHOD(InOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			p2List<Node<char>*> my_tree;
			tree1.InOrder(&my_tree);

			Assert::IsTrue(my_tree.count() == 10);

			Assert::IsTrue((char)my_tree[0]->Data == 'C');
			Assert::IsTrue((char)my_tree[1]->Data == 'B');
			Assert::IsTrue((char)my_tree[2]->Data == 'D');
			Assert::IsTrue((char)my_tree[3]->Data == 'F');
			Assert::IsTrue((char)my_tree[4]->Data == 'E');
			Assert::IsTrue((char)my_tree[5]->Data == 'G');
			Assert::IsTrue((char)my_tree[6]->Data == 'A');
			Assert::IsTrue((char)my_tree[7]->Data == 'H');
			Assert::IsTrue((char)my_tree[8]->Data == 'I');
			Assert::IsTrue((char)my_tree[9]->Data == 'J');
		}

		
		
		
		TEST_METHOD(PreOrderIterative)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			p2List<Node<char>*> my_tree;
			tree1.PreOrder_iter(&my_tree);

			Assert::IsTrue(my_tree.count() == 10);

			//Result must be on alphabet order 
			Assert::IsTrue((char)my_tree[0]->Data == 'A');
			Assert::IsTrue((char)my_tree[1]->Data == 'B');
			Assert::IsTrue((char)my_tree[2]->Data == 'C');
			Assert::IsTrue((char)my_tree[3]->Data == 'D');
			Assert::IsTrue((char)my_tree[4]->Data == 'E');
			Assert::IsTrue((char)my_tree[5]->Data == 'F');
			Assert::IsTrue((char)my_tree[6]->Data == 'G');
			Assert::IsTrue((char)my_tree[7]->Data == 'H');
			Assert::IsTrue((char)my_tree[8]->Data == 'I');
			Assert::IsTrue((char)my_tree[9]->Data == 'J');
		}
		
		
		TEST_METHOD(PostOrderIterative)
		{
			Tree<char> tree1('F');

			tree1.Add('B', 'F');
			tree1.Add('G', 'F');
			tree1.Add('A', 'B');
			tree1.Add('D', 'B');
			tree1.Add('C', 'D');
			tree1.Add('E', 'D');
			tree1.Add('I', 'G');
			tree1.Add('H', 'I');
			

			p2List<Node<char>*> my_tree;
			tree1.PostOrder_iter(&my_tree);

			Assert::IsTrue(my_tree.count() == 9);

			Assert::IsTrue((char)my_tree[0]->Data == 'A');
			Assert::IsTrue((char)my_tree[1]->Data == 'C');
			Assert::IsTrue((char)my_tree[2]->Data == 'E');
			Assert::IsTrue((char)my_tree[3]->Data == 'D');
			Assert::IsTrue((char)my_tree[4]->Data == 'B');
			Assert::IsTrue((char)my_tree[5]->Data == 'H');
			Assert::IsTrue((char)my_tree[6]->Data == 'I');
			Assert::IsTrue((char)my_tree[7]->Data == 'G');
			Assert::IsTrue((char)my_tree[8]->Data == 'F');
			
		}
		
		/*TEST_METHOD(InOrderIterative)
		{
			Tree<char> tree1('F');

			tree1.Add('B', 'F');
			tree1.Add('G', 'F');
			tree1.Add('A', 'B');
			tree1.Add('D', 'B');
			tree1.Add('C', 'D');
			tree1.Add('E', 'D');
			tree1.Add('I', 'G');
			tree1.Add('H', 'I');

			p2List<Node<char>*> my_tree;
			tree1.InOrder_iter(&my_tree);

			Assert::IsTrue(my_tree.count() == 9);

			Assert::IsTrue((char)my_tree[0]->Data == 'A');
			Assert::IsTrue((char)my_tree[1]->Data == 'B');
			Assert::IsTrue((char)my_tree[2]->Data == 'C');
			Assert::IsTrue((char)my_tree[3]->Data == 'D');
			Assert::IsTrue((char)my_tree[4]->Data == 'E');
			Assert::IsTrue((char)my_tree[5]->Data == 'F');
			Assert::IsTrue((char)my_tree[6]->Data == 'H');
			Assert::IsTrue((char)my_tree[7]->Data == 'I');
			Assert::IsTrue((char)my_tree[8]->Data == 'G');
		}*/

	};
}
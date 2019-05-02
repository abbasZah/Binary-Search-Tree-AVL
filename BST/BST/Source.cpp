#include "Header.h"


int main()
{

	BST Tree;

	Tree.Insertion(10);
	Tree.Insertion(20);
	Tree.Insertion(13);
//	Tree.Insertion(15);
//	Tree.Insertion(16);


	cout << "\n\n\n";
	Tree.Display(Tree.root);

	system("pause");

}
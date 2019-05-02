#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node *parent;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
};

class BST
{
public:
	Node *root;

	BST()
	{
		root = NULL;
	}
	
	void Insertion(int val)
	{
		
		Node *myNode = new Node(val);

		if (root == NULL)
		{
			root = myNode;
			cout << "\nValue entered\n";
		}
		else
		{
			Node *temp = root;

			while (temp != NULL)
			{
				if (val > temp->data)
				{

					if (temp->right == NULL)
					{
						temp->right = myNode;
						myNode->parent = temp;
						cout << "\nValue entered\n";
						break;
					}
					else
					{
						temp = temp->right;
					}

				}
				else
				{
					if (temp->left == NULL)
					{
						temp->left = myNode;
						myNode->parent = temp;
						cout << "\nValue entered\n";
						break;
					}
					else
					{
						temp = temp->left;
					}
				}


				
			}

			AVLRotation(myNode);

		}

		


	}

	void AVLRotation(Node *temp)
	{
		//AVL Algo...
		Node *Copy = temp;

		while (temp != NULL)
		{

			int BF = getBalanceF(temp->left,temp->right);

			Node *p = Copy;
			Node *beta = Copy->parent;
			Node *alpha = Copy->parent->parent;

			if (BF > 1 || BF < -1)
			{
				if (BF < -1)
				{
					if (temp->right->data < Copy->data)
					{
						cout << "//nright-right";
					}
					else
					{
						cout << "//nright-left";

						beta->left = p->right;
						alpha->right = p->left;
						p->right = beta;
						p -> left = alpha;

						root = Copy;

					}
				}
				else if (BF > 1)
				{
					if (BF > 1)
					{
						if (temp->left->data < Copy->data)
						{
							cout << "//nleft-right";
						}
						else
						{
							cout << "//nleft-left";
						}
					}
				}

				break;

			}
			else
				temp = temp->parent;

			//upword mov pending
		}



	}
	void Display(Node *temp)
	{
		if (temp == NULL)
			return;
		Display(temp->left);
		cout << temp->data;
		cout << "\t "<<getBalanceF(temp->left, temp->right)<<endl;
		Display(temp->right);

	}


	int getHeight(Node *temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		int l = getHeight(temp->left);
		int r = getHeight(temp->right);
		
		if (l > r)
			return l + 1;
		else
			return r + 1;
	}

	int getBalanceF(Node *left, Node *right)
	{
		return this->getHeight(left) - this->getHeight(right);
	}

};


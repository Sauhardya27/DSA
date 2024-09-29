#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

void convertToSortedDLL(Node *root, Node *&head)
{
	if (root == NULL)
		return;

	convertToSortedDLL(root->right, head);

	root->right = head;

	if (head != NULL)
		head->left = root;

	head = root;

	convertToSortedDLL(root->left, head);
}

Node *mergeTwoLL(Node *head1, Node *head2)
{
	Node *head = NULL;
	Node *tail = NULL;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			if (head == NULL)
			{
				head = head1;
				tail = head1;
				head1 = head1->right;
			}
			else
			{
				tail->right = head1;
				head1->left = tail;
				tail = head1;
				head1 = head1->right;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = head2;
				tail = head2;
				head2 = head2->right;
			}
			else
			{
				tail->right = head2;
				head2->left = tail;
				tail = head2;
				head2 = head2->right;
			}
		}
	}

	while (head1 != NULL)
	{
		tail->right = head1;
		head1->left = tail;
		tail = head1;
		head1 = head1->right;
	}

	while (head2 != NULL)
	{
		tail->right = head2;
		head2->left = tail;
		tail = head2;
		head2 = head2->right;
	}

	return head;
}

int countNodes(Node *root)
{
	Node *temp = root;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->right;
	}
	return cnt;
}

Node *sortedLLToBST(Node *&head, int n)
{
	if (n <= 0 || head == NULL)
		return NULL;

	Node *left = sortedLLToBST(head, n / 2);

	Node *root = head;
	head = head->right;
	root->left = left;

	root->right = sortedLLToBST(head, n - n / 2 - 1);
	return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
	// Step 1: Convert BST into DLL without using extra space
	Node *head1 = NULL;
	convertToSortedDLL(root1, head1);
	head1->left = NULL;

	Node *head2 = NULL;
	convertToSortedDLL(root2, head2);
	head2->left = NULL;

	// Step 2: Merge Sorted LL
	Node *mergedLL = mergeTwoLL(head1, head2);

	// Step 3: Convert sorted LL to BST
	int n = countNodes(mergedLL);
	return sortedLLToBST(mergedLL, n);
}
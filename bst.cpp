#include "bst.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

void BST::insert(int val)
{
	node *newNode = new node;
	newNode->val = val;

	if (!this->root) {
		this->root = newNode;
		return;
	}

    this->insert_helper(val, this->root, newNode);
}

void BST::insert_helper(int val, node *cur, node *newNode)
{
	if(val < cur->val) {
		if(!cur->left) {
			cur->left = newNode;
			return;
		}
		this->insert_helper(val, cur->left, newNode);
	} else if (val > cur->val) {
		if(!cur->right) {
			cur->right = newNode;
			return;
		}
		this->insert_helper(val, cur->right, newNode);
	}
	return;
}

void BST::inorder()
{
	cout << "INORDER: ";
	this->inorder_helper(this->root);
	cout << "END\n";
}

void BST::inorder_helper(node* inputNode)
{
    if (!inputNode) {
        return;
    }

    this->inorder_helper(inputNode->left);
	cout << inputNode->val << " -> ";
    this->inorder_helper(inputNode->right);
}

void BST::postorder()
{
	cout << "POSTORDER: ";
	this->postorder_helper(this->root);
	cout << "END\n";
}

void BST::postorder_helper(node* inputNode)
{
    if (!inputNode) {
        return;
    }

    this->postorder_helper(inputNode->right);
	cout << inputNode->val << " -> ";
    this->postorder_helper(inputNode->left);
}

void BST::preorder()
{
	cout << "PREORDER: ";
	this->preorder_helper(this->root);
	cout << "END\n";
}

void BST::preorder_helper(node* inputNode)
{
    if (!inputNode) {
        return;
    }

	cout << inputNode->val << " -> ";
    this->preorder_helper(inputNode->right);
    this->preorder_helper(inputNode->left);
}

node* BST::search(int val)
{
	return this->search_helper(val, this->root);
}

node* BST::search_helper(int val, node *cur)
{
	if (!cur) {
		return NULL;
	} else if (val == cur->val) {
		return cur;
	} else if (val < cur->val) {
		return this->search_helper(val, cur->left);
	} else if (val > cur->val) {
		return this->search_helper(val, cur->right);
	}
	return NULL;
}

bool BST::remove(int val)
{

}

node* BST::findMin()
{

}

node* BST::findMax()
{

}

int BST::findHeight()
{
    this->findHeightHelper(this->root, 0);
}

int BST::findHeightHelper(node* cur, int height)
{
    int leftHeight = findHeightHelper(cur->left, height) + height + 1;
    int rightHeight = findHeightHelper(cur->right, height) + height + 1;

    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

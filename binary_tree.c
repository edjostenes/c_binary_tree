#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

BinaryTree* init_binary_tree()
{
	BinaryTree* bTree = (BinaryTree*)malloc(sizeof(BinaryTree));
	bTree->root = NULL;
	bTree->lenght = 0;
	return bTree;
}

Node* create_node(int info, Node* left, Node* right)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->info = info;
	node->left = left;
	node->right = right;
	return node;
}

bool is_tree_empty(Node* node)
{
	return node == NULL;
}

Node* search_position_to_insert(Node* node, int info)
{
	if (node != NULL)
	{
		if (node->info > info)
		{
			if (node->left == NULL)
			{
				return node;
			}

			search_position_to_insert(node->left, info);
		}
		else
		{
			if (node->right == NULL)
			{
				return node;
			}

			search_position_to_insert(node->right, info);
		}
	}
	else
	{
		printf("Que porra é essa?\n");
		return NULL;
	}
}

bool insert_node(BinaryTree* bTree, int info)
{
	if (is_tree_empty(bTree->root))
	{
		bTree->root = create_node(info, NULL, NULL);;
		bTree->lenght++;
		return true;
	}

	Node* parentNode = search_position_to_insert(bTree->root, info);

	if (parentNode == NULL)
	{
		printf("Not inserted: %d\n", info);
		return false;
	}

	Node* newNode = create_node(info, NULL, NULL);

	if (parentNode->info > info)
	{
		parentNode->left = newNode;
	}
	else
	{
		parentNode->right = newNode;
	}

	bTree->lenght++;
	return true;
}

void print_tree(Node* rootNode)
{
	printf("<");

	if(!is_tree_empty(rootNode))
	{
		printf("%d", rootNode->info);
		print_tree(rootNode->left);
		print_tree(rootNode->right);
	}

	printf(">");
}

void dispose(BinaryTree* bTree, Node* node)
{
	if(!is_tree_empty(node))
	{
		dispose(bTree, node->left);
		dispose(bTree, node->right);
		printf("Diposed: %d\n", node->info);
		free(node);
	}
	
	free(bTree);
}

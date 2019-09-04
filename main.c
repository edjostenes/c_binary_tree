#include <stdio.h>
#include "binary_tree.h"

int main(int argc, char** argv)
{
	BinaryTree* bTree = init_binary_tree();
	insert_node(bTree, 5);
	insert_node(bTree, 9812);
	insert_node(bTree, 564);
	insert_node(bTree, 2);
	insert_node(bTree, 232);
	insert_node(bTree, 7);
	insert_node(bTree, 6);
	insert_node(bTree, 540);
	insert_node(bTree, 4);
	insert_node(bTree, 3);
	insert_node(bTree, 50);
	print_tree(bTree->root);
	printf("\n");
	dispose(bTree, bTree->root);
	return 0;
}
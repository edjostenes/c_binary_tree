typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}Node;

typedef struct binaryTree
{
	Node* root;
	int lenght;
}BinaryTree;

BinaryTree* init_binary_tree();
Node* create_node(int info, Node* left, Node* right);
bool insert_node(BinaryTree* bTree, int info);
void print_tree(Node* rootNode);
void dispose(BinaryTree* bTree, Node* node);
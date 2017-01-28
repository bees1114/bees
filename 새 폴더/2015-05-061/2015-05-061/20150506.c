#include <stdio.h>
#include <stdlib.h>

// Define type 'struct _TreeNode' to 'TreeNode'
typedef struct _TreeNode TreeNode;
// Structure
struct _TreeNode
{
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
};
typedef struct _Tree
{
	TreeNode* root;
} Tree;


// Tree Functions
Tree createTree();
void freeTree( Tree* t );
void insertTree( Tree* t, int value );
void printTreePreorder( Tree t );
void printTreeInorder( Tree t );
void printTreePostorder( Tree t );
// Tree Node Functions
void insertTreeNode( TreeNode** n, int value );
void freeTreeNode( TreeNode* n );
void printTreeNodePreorder( TreeNode* n );
void printTreeNodeInorder( TreeNode* n );
void printTreeNodePostorder( TreeNode* n  );




Tree createTree()
{
	Tree newTree;
	newTree.root = NULL;
	return newTree;
}

void freeTree( Tree* t )
{
	freeTreeNode( t->root );
	t->root = NULL;
}

void insertTree( Tree* t, int value )
{
	insertTreeNode( &(t->root), value );
}

void printTreePreorder( Tree t )
{
	printTreeNodePreorder( t.root );
}

void printTreeInorder( Tree t )
{
	printTreeNodeInorder( t.root );
}

void printTreePostorder( Tree t )
{
	printTreeNodePostorder( t.root );
}




// Create Tree Node
TreeNode* createTreeNode( int value )
{
	TreeNode* newNode = (TreeNode*) malloc( sizeof(TreeNode) );

	// Set data value
	newNode->data = value;
	// Set pointer to Null
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	// Return allocated node
	return newNode;
}

void freeTreeNode( TreeNode* p )
{
	if ( p == NULL )
		return;
	freeTreeNode(p->leftChild);
	freeTreeNode(p->rightChild);
	free(p);
	// TODO : free every node
}


void insertTreeNode( TreeNode** p, int value )
{
	if ( ( *p ) == NULL )
	{
		// Create TreeNode with value
		( *p ) = createTreeNode( value );
	}
	else if ( ( *p )->data > value )
	{
		// Recursive call to leftChild
		insertTreeNode( &( ( *p )->leftChild ), value );
	}
	else
	{
		// Recursive call to rightChild
		insertTreeNode( &( ( *p )->rightChild ), value );
	}
}

void printTreeNodePreorder( TreeNode* n )
{
	if ( n == NULL )
		return;
	printf("%d", n->data);
	printTreeNodePreorder(n->leftChild);
	printTreeNodePreorder(n->rightChild);
	// TODO : Print in pre-order
}

void printTreeNodeInorder( TreeNode* n )
{
	if ( n == NULL )
		return;
	
	printTreeNodeInorder(n->leftChild);
	printf("%d", n->data);
	
	printTreeNodeInorder(n->rightChild);
	
	// TODO : Print in in-order
}

void printTreeNodePostorder( TreeNode* n  )
{
	if ( n == NULL )
		return;
	printTreeNodePostorder(n->leftChild);
	
	printTreeNodePostorder(n->rightChild);
	printf("%d", n->data);
	// TODO : Print in post-order
}


int main( int argc, char* argv[] ) {
	
	Tree t = createTree();
 
	setbuf( stdout, NULL );

	insertTree( &t, 4 );
	insertTree( &t, 2 );
	insertTree( &t, 6 );
	insertTree( &t, 1 );
	insertTree( &t, 3 );
	insertTree( &t, 5 );
	insertTree( &t, 7 );

	printf( "Preorder : \t" );
	printTreePreorder( t );
	printf( "\nInorder : \t" );
	printTreeInorder( t );
	printf( "\nPostorder : \t" );
	printTreePostorder( t );
	printf( "\n" );

	freeTree( &t );

	return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct Tree_Node {
	int data;
	struct Tree_Node* leftChild;
	struct Tree_Node* rightChild;
};
typedef struct Tree_Node* PtrToNode;
typedef PtrToNode TreePointer;

TreePointer modSearch(TreePointer root, int key) {
	if(!root)
		return NULL;
	if(key == root->data)
		return root;
	if(key < root->data) {
		if(!(root->leftChild))
			return root;
		return modSearch(root->leftChild, key);
	}
	else {
		if((!root->rightChild))
			return root;
		return modSearch(root->rightChild, key);
	}
}

TreePointer findParent(TreePointer root, int key) {
	if(!(root->leftChild) || !(root->rightChild))
		return NULL;
	if((key == root->leftChild->data) || key == (root->rightChild->data))
		return root;
	if(key < root->data) {
		if(!(root->leftChild))
			return root;
		return modSearch(root->leftChild, key);
	}
	else {
		if((!root->rightChild))
			return root;
		return modSearch(root->rightChild, key);
	}
}

void bstInsert(TreePointer* node, int k) {
	TreePointer ptr, temp;
	temp = modSearch(*node, k);
	if(temp || !(*node)) {
		ptr = (TreePointer)malloc(sizeof(struct Tree_Node));
		ptr->data = k;
		ptr->leftChild = NULL;
		ptr->rightChild = NULL;
		if(*node) {
			if(k < temp->data)
				temp->leftChild = ptr;
			else
				temp->rightChild = ptr;
		} else {
			*node = ptr;
		}
	}
}

void printTreeNodeInorder(TreePointer node) {
	if(node == NULL) 
		return;
	printTreeNodeInorder(node->leftChild);
	printf("%3d", node->data);
	printTreeNodeInorder(node->rightChild);
}

void bstDelete(TreePointer* head, int t) {
	TreePointer target, temp, ptr;
	int tempData;
	target = modSearch(*head, t);
	if(target!= *head) {
	temp = findParent(*head, t);
	if(target == NULL) {}
	else if((target->leftChild == NULL) && (target->rightChild == NULL)) {
		if(temp->leftChild->data == t)
			temp->leftChild = NULL;
		if(temp->rightChild->data == t)
			temp->rightChild = NULL;
		free(target);
	} else if((target->leftChild == NULL) ^ (target->rightChild == NULL)) {
		if(temp->leftChild == target) {
				if(target->leftChild != NULL)
					temp->leftChild = target->leftChild;
				if(target->rightChild != NULL)
					temp->leftChild = target->rightChild;
		}
		if(temp->rightChild == target) {
				if(target->leftChild != NULL)
					temp->rightChild = target->leftChild;
				if(target->rightChild != NULL)
					temp->rightChild = target->rightChild;
		}
		free(target);
		} else if((target->leftChild != NULL) && (target->rightChild != NULL)) {
				ptr = target->leftChild;
				while(ptr->rightChild != NULL) 
					ptr = ptr->rightChild;
				tempData = target->data;
				target->data = ptr->data;
				ptr->data = tempData;
				bstDelete(&(target->leftChild),ptr->data);
				
		}
	}
}

int main(void) {
	char input;
	TreePointer root = NULL;
	
	bstInsert(&root, 20);
	bstInsert(&root, 10);
	bstInsert(&root, 40);
	bstInsert(&root, 6);
	bstInsert(&root, 15);
	bstInsert(&root, 30);
	bstInsert(&root, 2);
	bstInsert(&root, 8);
	bstInsert(&root, 18);
	bstInsert(&root, 25);
	bstInsert(&root, 35);
	bstInsert(&root, 7);
	printTreeNodeInorder(root);
	bstDelete(&root, 6);
	printf("\n");
	printTreeNodeInorder(root);
}
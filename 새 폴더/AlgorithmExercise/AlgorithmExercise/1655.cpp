#include <stdio.h>
#include <stdlib.h>

typedef struct heapNode {
	int number;
	struct heapNode *left;
	struct heapNode *right;
}heapNode;

typedef heapNode* pHeapNode;
pHeapNode head;
int leftNodeCounter;
int rightNodeCounter;

void traversal(pHeapNode node, int i) {
	if(node->left == NULL && node->right == NULL) {
		
	}
	traversal(node->left, i+1);
	traversal(node->right, i+1);
}

pHeapNode addNewNodet(pHeapNode node, int number) {
	if(node->left == NULL && node->number > number) {
		return node;
	}
	if(node->right == NULL && node->number < number)
		return node;
	if(node->left != NULL && node->number > number)
		addNewNodet(node, number);
	if(node->right != NULL && node->number < number)
		addNewNodet(node, number);
}

void addNewNode(int number) {
	pHeapNode node;
	heapNode* newNode = (heapNode*)malloc(sizeof(heapNode));
	newNode->number = number;
	if(number > head->left->number)
		rightNodeCounter++;
	if(number < head->left->number)
		leftNodeCounter++;
	node = addNewNodet(head, number);
	if(node->left == NULL && node->number > number)
		node->left = node;
	if(node->right == NULL && node->number < number)
		node->right = node;
}

void rightMore(pHeapNode node) {

}

void leftMore(pHeapNode node) {

}

int main(void) {
	int N;
	int *arr;
	int i;
	int mid;
	int temp;
	pHeapNode firstNode;
	firstNode = (heapNode*)malloc(sizeof(heapNode));
	firstNode->left = NULL;firstNode->right = NULL;

	scanf("%d", &N);
	scanf("%d", &temp);
	firstNode->number = temp;
	mid = temp;
	head->left = firstNode;
	printf("%d", head->left->number);
	for(i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		addNewNode(arr[i]);
		if(rightNodeCounter - leftNodeCounter >=2) {
			rightMore(head);
		}
		if(leftNodeCounter - rightNodeCounter >=1) {
			leftMore(head);
		}
		printf("%d", head->left->number);
	}

	return 0;
}

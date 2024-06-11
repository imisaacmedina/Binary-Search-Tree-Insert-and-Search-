#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>

typedef struct BstNode{
	int data;
	struct BstNode* left;
	struct BstNode* right;
}BstNode;

BstNode* createNode(int data){
	BstNode* new_node = (BstNode*) malloc (sizeof(BstNode));
	
	if(new_node == NULL) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	
	return new_node;
}

void insert(BstNode** root, int data){
	if(*root == NULL) {
		*root = createNode(data);
	}else if(data <= (*root)->data){
		insert(&(*root)->left, data);
	}else{
		insert(&(*root)->right, data);
	}
}

bool search(BstNode* root, int data){
	if(root == NULL) {
		return false;
	}else if(root->data == data){
		return true;
	}else if(data <= root->data){
		return search(root->left, data);
	}else{
		return search(root->right, data);
	}
}

int main(){
	BstNode* head = NULL;
	
	insert(&head, 5);
	insert(&head, 2);
	insert(&head, 1);
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 0);
	
	
	bool found;
	int inp;
	
	while(true) {
		printf("Type a number (999 to exit): ");
		scanf("%d", &inp);
		
		if(inp == 999){
			break;
		}
		
		found = search(head, inp);
		
		if(found){
			printf("Found.\n");
		}else{
			printf("Not found.\n");
		}
	}
	
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	struct Node *next;
};

typedef struct Node* List;

List root = NULL;

void print_list(){
	if(root == NULL){
		printf("The list is empty");
	}else{
		List cur = root;
		while(cur != NULL){
			printf("%d ", cur->value);
			cur = cur->next;
		}
	}
	printf("\n");
}

// node is given
void insert_node(List node, int value){
	List new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->value = value;
	new_node->next = NULL;
	if(root == NULL){
		root = new_node;
	}else{
		List prev_next = node->next;
		node->next = new_node;
		new_node->next = prev_next;
	}
}

void delete_node(List node){
	if(root == node){
		List cur = root->next;
		free(root);
		root = cur;
	}else{
		List cur = root;
		while(cur->next != node){
			cur = cur->next;
		}
		cur->next = node->next;
		free(node);
	}
}

int main(int argc, char const *argv[])
{
	insert_node(root, 1);
	print_list();
	insert_node(root, 2);
	print_list();
	insert_node(root, 3);
	print_list();
	insert_node(root->next, 4);
	print_list();
	delete_node(root->next);
	print_list();
	delete_node(root);
	print_list();

	return 0;
}
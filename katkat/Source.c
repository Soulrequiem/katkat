#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void displayAll(struct Node* n) {
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

void insertFront(struct Node** head_ref, int x){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = x;
	n->next = (*head_ref);
	(*head_ref) = n;
};

void insertRear(struct Node** head_ref, int x) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = x;
	struct Node* last = *head_ref;
	n->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = n;
		return;
	};
	while (last->next != NULL) 
		last = last->next;
		last->next = n;
		return;
	
};

void insertAt(struct Node*head, int x, int p) {
	struct Node*n, *temp;
	n= (struct Node*)malloc(sizeof(struct Node));
	if (n == NULL) {
		printf("unable to allocate memory");
	}
	else {
		n->data = x;
		n->next = NULL;
		temp = head;

		for (int i = 2; i <= p-1; i++) {
			temp = temp->next;
			if (temp == NULL);
			break;
		}
		if(temp!=NULL){
			n->next = temp->next;
			temp->next = n;
		}
	}

};

void deleteFront(struct Node**n) {

}

void deleteRear(struct Node**n) {

}

void deleteAt(struct Node**n, int p) {

}

int main(int argc, char *argv[])
{

	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	displayAll(head);
	insertFront(&head, 24); 
    displayAll(head);
	insertRear(&head, 4);
	displayAll(head);
	insertAt(head, 21, 2);
	displayAll(head);
	system("PAUSE");
	return 0;
}
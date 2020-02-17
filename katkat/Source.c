#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
}*head,*second,*third;

void displayAll(struct Node* n) {
	while (n != NULL) {
		printf(" %d \n", n->data);
		n = n->next;
	}
}

void insertFront(struct Node** head_ref, int x) {
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
	n = (struct Node*)malloc(sizeof(struct Node));
	if (n == NULL) {
		printf("unable to allocate memory");
	}
	else {
		n->data = x;
		n->next = NULL;
		temp = head;

		for (int i = 2; i <= p - 1; i++) {
			temp = temp->next;
			if (temp == NULL);
			break;
		}
		if (temp != NULL) {
			n->next = temp->next;
			temp->next = n;
		}
	}

};

void deleteFront() {

	struct Node*n;
	if (head == NULL) {
		printf("List is already empty");
	}
	else
	{
		n = head;
		head = head->next;
		free(n);
	}
}

void deleteRear() {
	struct Node *todelete, *secondlast;

	if (head==NULL){
		printf("List is already empty");
	}
	else {
		todelete = head;
		secondlast = head;

		while (todelete->next != NULL) {
			secondlast = todelete;
			todelete = todelete->next;
		}
		if (todelete == head) {
			head = NULL;
		}
		else {
			secondlast->next = NULL;
		}
		free(todelete);

	}
}

void deleteAt(int p) {
	struct Node *todelete, *prenode;

	if (head == NULL) {
		printf("List is already Empty");
	}
	else {
		todelete = head;
		prenode = head;

		for (int i = 2; i <= p; i++) {
			prenode = todelete;
			todelete = todelete->next;
			if (todelete == NULL)
				break;
		}
		if (todelete != NULL) {
			if (todelete == head)
				head = head->next;

			prenode->next = todelete->next;
			todelete->next = NULL;

			free(todelete);
		}
	}

}

int main(int argc, char *argv[])
{
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printf("Displaying all items in list \n");
	displayAll(head);
	printf("Insert 24 in front of list \n");
	insertFront(&head, 24); 
    displayAll(head);
	printf("Insert 4 in rear of list \n");
	insertRear(&head, 4);
	displayAll(head);
	printf("Insert 21 at position 2 in list \n");
	insertAt(head, 21, 2);
	displayAll(head);
	printf("Remove 24 from front of the list \n");
	deleteFront();
	displayAll(head);
	printf("Remove 4 from end of the list \n");
	deleteRear();
	displayAll(head);
	printf("Remove 2 from end of the list \n");
	deleteAt(3);
	displayAll(head);
	system("PAUSE");
	return 0;
}


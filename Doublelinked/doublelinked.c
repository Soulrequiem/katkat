#include <stdio.h>  
#include <stdlib.h>  

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}*head, *last;														//Declaring 2 pointers here for ease of use 

struct Node* createNewNode(int x) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = x;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void insertFront(int x) {						
	struct Node* n = createNewNode(x);
	n->next = head;												
	if (head == NULL) {
		head = n;
		return;
	}
	head->prev = n;
	n->next = head;
	head = n;
};

void insertRear(int x) {						
	struct Node* n = createNewNode(x);
	struct Node* last = head;										

	if (head == NULL) {											
		head = n;													
		return;
	}
	while (last->next != NULL) 									
 		last = last->next;											
		last->next = n;												
		n->prev = last;												
		return;
	
};

void insertAt(int p, int x) {								
	struct Node * temp;
	struct Node * n = createNewNode(x);
	if (head == NULL) {
		printf("List is empty \n");
	}
	else
	{
		temp = head;
		int i = 1;
		while (i < p - 1 && temp != NULL) {
			temp = temp->next;
			i++;
		}
		if (p == 1) {
			insertFront(x);
		}
		else if (temp == last) {
			insertRear(x);
		}
		else if (temp!=NULL) {
			n->next = temp->next;
			n->prev = temp;
			if (temp->next != NULL) {
				temp->next->prev = n;
			}
			temp->next = n;
		}
	}
};

void removeFront() {
	struct Node* n;
	if (head == NULL) {
		printf("List is already empty \n");
	}
	else {
		n = head;
		head = head->next;
		head -> prev = NULL;
		free(n);
	}
}

void removeRear() {
	struct Node* last, *secondlast;
	if (head == NULL) {
		printf("List is already empty \n");
	}
	else {
		last = head;
		secondlast = head;
		while (last->next != NULL) {
			secondlast = last;
			last = last->next;
			
		}
		if (last == head) {
			head = NULL;
			head->prev = NULL;
			head->next = NULL;
		}
		else {
			secondlast->next = NULL;
		}
		free(last);
	}

};

void removeAt(int p) {
	struct Node *todelete, *prenode;
	if (head == NULL) {
		printf("List is already empty");
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
			if (todelete == head) {
				head = head->next;
				head->prev = NULL;
			}
			prenode->next = todelete->next;
			todelete->next->prev = prenode;

			free(todelete);

			//TODO: Remember to do case if it is the last node in the list
		}
	}
};

void printList() {
	struct Node*temp = head;
	printf("From head: \n");
	while (temp != NULL) {											//print every node if it's not NULL
		printf("%d \n", temp->data);
		temp = temp->next;
	}
};

void printMirror() {
	struct Node*temp = head;
	if (temp == NULL)												//check if the list is empty
		return;
	while (temp->next != NULL) {									//traverse the list to the end
		temp = temp->next;
	}
	printf("From tail: \n");						
	while (temp != NULL) {											//While node is not null, print every node followed by previous
		printf("%d \n", temp->data);
		temp = temp->prev;
	}
};

int main() {
	
	insertFront(10);
	printList();

	printf("Insert value of 10 at head \n");
	insertFront(10);
	printList();
	
	printf("Insert value of 11 at head \n");
	insertFront(11);
	printList();

	printf("Insert value of 38 at rear \n");
	insertRear(38);
	printList();
	
	printf("Insert value of 24 at position 2 \n");
	insertAt(2, 24);
	printList();
	printf("printing list in reverse \n");
	
	printf("delete first value in list \n");
	removeFront();
	printList();
	
	printf("delete last value in list \n");
	removeRear();
	printList();

	printf("delete value in the list at position 2 \n");
	removeAt(2);
	printList();

	printMirror();
	
	system("PAUSE");
	return 0;
}
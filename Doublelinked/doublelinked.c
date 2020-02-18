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
	//
	//struct Node *temp;
	//struct Node* n = createNewNode(x);
	//temp = head;
	//for (int i = 2; i <= p - 1; i++) {
	//	temp = temp->next;
	//	if (temp == NULL);
	//	break;
	//}
	//if (temp != NULL) {
	//	n->next = temp->next; 
	//	n->next->prev = n;
	//	n->prev = temp;
	//}
	//
};

void removeFront() {

}

void removeRear() {

};

void removeAt() {

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
	
	system("PAUSE");
	return 0;
}
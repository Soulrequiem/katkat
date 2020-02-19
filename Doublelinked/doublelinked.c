#include <stdio.h>  
#include <stdlib.h>  

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}*head, *last;														//Declaring 2 pointers here for ease of use 

struct Node* createNewNode(int x) {									//created this function for ease of use. creates a node
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = x;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void insertFront(int x) {						
	struct Node* n = createNewNode(x);
	n->next = head;													//declares the next node of n to be head
	if (head == NULL) {												//if conditional to check if it's n is the only node in the list
		head = n;
		return;
	}
	head->prev = n;													//set prev of head to be n
	n->next = head;													//set next of n to be head
	head = n;														//set the new head of the list to be n
};

void insertRear(int x) {						
	struct Node* n = createNewNode(x);
	struct Node* last = head;										//set a temp node 'last' to be the head to help traverse the list

	if (head == NULL) {												//if conditional to check if the list is empty
		head = n;													//if it is, just insert the node and then exit
		return;
	}
	while (last->next != NULL) 										//while loop to traverse the list
 		last = last->next;											//while the next pointer of last is not null, it will search for the last node
		last->next = n;												//at the last node, it will set next of last to point to n
		n->prev = last;												//prev of n to point to last;
		return;														//since we already set the next of n to be NULL, we can exit (see createNewNode())
	
};

void insertAt(int p, int x) {								
	struct Node * temp;												
	struct Node * n = createNewNode(x);
	if (head == NULL) {												//If Conditional to check if list is empty first
		printf("List is empty \n");
	}
	else
	{
		temp = head;												//Assign temp to head to help in traversing the list
		int i = 1;													
		while (i < p - 1 && temp != NULL) {							//while loop to traverse the list
			temp = temp->next;
			i++;
		}
		if (p == 1) {												//if position is the first position
			insertFront(x);
		}
		else if (temp->next==NULL) {								//if position is the last position
			temp->next = n;
			n->prev = temp;
			n->next = NULL;
		}
		else if (temp!=NULL) {										//if temp is not NULL
			n->next = temp->next;									//assign next of n to be the next of temp
			n->prev = temp;											//assign prev of n to be temp
			if (temp->next != NULL) {								//assign the prev of the next of temp to be n 
				temp->next->prev = n;								//we do this previous step because it's a double linked list
			}
			temp->next = n;											//finally assign next of temp to be n
		}
	}
};

void removeFront() {
	struct Node* n;
	if (head == NULL) {												//if conditional to check if list is empty
		printf("List is already empty \n");
	}
	else {
		n = head;													//set head to be n
		head = head->next;											//set head to the next of previous head
		head -> prev = NULL;										//set prev of new head to be null
		free(n);													//free n to remove it
	}
}

void removeRear() {
	struct Node* last, *secondlast;									//initialize 2 nodes to make it easier to traverse list
	if (head == NULL) {												//if conditional to check if list is empty
		printf("List is already empty \n");
	}
	else {
		last = head;												//set last to head
		secondlast = head;											//set secondlast to head
		while (last->next != NULL) {								//traverse the list to find the rear
			secondlast = last;										//while next of the node is not null, set second last to be last
			last = last->next;										//set last to be next of last
			
		}
		if (last == head) {											//if conditional to check if it is the head node
			head = NULL;											//we just empty the entire list
			head->prev = NULL;
			head->next = NULL;
		}
		else {
			secondlast->next = NULL;								//we set secondlast next to be NULL
		}
		free(last);													//free last to remove it
	}

};

void removeAt(int p) {
	struct Node *todelete, *prenode;								//initialize 2 nodes to traverse list
	if (head == NULL) {												//check to see if list is empty
		printf("List is already empty");
	}
	else {
		todelete = head;											//set both nodes to be head
		prenode = head;

		for (int i = 2; i <= p; i++) {								//we start from 2 because for 0th position and 1st because we handle it later 
			prenode = todelete;										
			todelete = todelete->next;
			if (todelete == NULL)									//break if it reaches the end
				break;
		}
		if (todelete != NULL) {
			if (todelete == head) {									//we handle the case if it's 0th position and 1st here
				head = head->next;
				head->prev = NULL;
			} 
			if(todelete->next != NULL) {							//we handle the actual delete node here
				prenode->next = todelete->next;						//set the next of prenode to the next of todelete
				todelete->next->prev = prenode;						//set the prev of next of todelete to be prenode
			}
			else if (todelete->next == NULL) {						//we the case if it's the last position here
				prenode->next = NULL;
			}
			free(todelete);											//finally we delete the node here

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

	printf("delete value in the list at position 3 \n");
	removeAt(3);
	printList();

	printMirror();
	
	system("PAUSE");
	return 0;
}
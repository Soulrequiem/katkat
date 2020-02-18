#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
}*head, *second, *third; // Declaring 3 different nodes here, head, second and third


void displayAll(struct Node* n) {
	while (n != NULL) {
		printf(" %d \n", n->data);
		n = n->next;
	}
}

void insertFront(struct Node** head_ref, int x) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node)); //a temp node N is declared in this function
	n->data = x;												//Data value 'x' is assigned to this node
	n->next = (*head_ref);										//A pointer to the previous head node is assigned to N	
	(*head_ref) = n;											//Head node is then assigned to N
};

void insertRear(struct Node** head_ref, int x) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node)); //a temp node N is declared in this function
	n->data = x;												//Data value 'x' is assigned to this node
	struct Node* last = *head_ref;								//A temp Node 'last' is assigned to the head node temporarily
	n->next = NULL;												//Since it is added to the rear, we set the pointer to the next node to NULL
	if (*head_ref == NULL) {									//This If conditional check is to check if there is only 1 node in the list, if so, we set it and end
		*head_ref = n;
		return;
	};
	while (last->next != NULL)									//The while Loop is to iterate through the entire list to assign the pointer to the 'last' node
		last = last->next;										//As long as the pointer to the next node is not NULL, it will set the pointer to the next node.	
	last->next = n;
	return;

};

void insertAt(int x, int p) {									//int x is for the data value, and int p is for the position value. both in integer values
	struct Node*n, *temp;										//We declare 2 different nodes here, n and temp as we will use them in the function like a game of magical cups
	n = (struct Node*)malloc(sizeof(struct Node));				//We initialize n here so that it can store data
	n->data = x;												//We assign int x as the data value here
	n->next = NULL;												//We set the pointer to the next node as null here temporarily
	temp = head;												//We set the temp node to the head temporarily

	for (int i = 2; i <= p - 1; i++) {							//A for loop is used to iterate through the entire list of nodes
		temp = temp->next;										//We iterate through for i=2 and i less than P because we will be trying to find the place to put the node at.
		if (temp == NULL);										//within the loop, you can see we set the pointer of temp to next, and the loop breaks when it reaches the end of the list
		break;
	}
	if (temp != NULL) {											//The If conditional is to find the exact position of the node and set the new node in between them
		n->next = temp->next;									//It checks if temp is not null, then set pointer to the n
		temp->next = n;											//Set the pointer of the previous node to point to n
	}

};

void deleteFront() {
	struct Node*n;												//We declare a Node n for use within the function
	if (head == NULL) {											//If Condiitional to check if the list is empty
		printf("List is already empty");
	}
	else
	{
		n = head;												//We set head value to n
		head = head->next;										//Assign head value to the next node in the linked list
		free(n);												//We then free n to delete the node
	}
}

void deleteRear() {
	struct Node *todelete, *secondlast;							//We declare 2 nodes to use within the function
	if (head == NULL) {											//If Condiitional to check if the list is empty
		printf("List is already empty");
	}
	else {
		todelete = head;										//Since we are going to iterate through the list of nodes, we assign head to both todelete and secondlast
		secondlast = head;

		while (todelete->next != NULL) {						//While loop to traverse the entire list
			secondlast = todelete;								//secondlast is set todelete
			todelete = todelete->next;							//todelete is set to point to the next node
		}
		if (todelete == head) {									//if todelete is already head node
			head = NULL;										//head is set to null to empty the entire list
		}
		else {
			secondlast->next = NULL;							//set secondlast to point to NULL
		}
		free(todelete);											//free todelete to delete the last node in the linked list

	}
}

void deleteAt(int p) {
	struct Node *todelete, *prenode;							//We declare 2 nodes to use within the function
	if (head == NULL) {											//If Condiitional to check if the list is empty
		printf("List is already Empty");
	}
	else {														//Since we are going to iterate through the list of nodes, we assign head to both todelete and prenode		
		todelete = head;
		prenode = head;

		for (int i = 2; i <= p; i++) {							//For loop to iterate through the list to find the particular node to delete
			prenode = todelete;
			todelete = todelete->next;
			if (todelete == NULL)								//If the todelete Node is NULL, break the for loop
				break;
		}
		if (todelete != NULL) {									//if conditional to check if todelete is not null
			if (todelete == head)								//if conditional to check if todelete is the head node after traversing the list
				head = head->next;

			prenode->next = todelete->next;						//assign prenode pointer to the next pointer after the node to be deleted
			todelete->next = NULL;								//assign pointer of todelete to null

			free(todelete);										//free todelete to delete the particular node
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
	insertAt(21, 2);
	displayAll(head);
	printf("Remove 24 from front of the list \n");
	deleteFront();
	displayAll(head);
	printf("Remove 4 from end of the list \n");
	deleteRear();
	displayAll(head);
	printf("Remove 2 from position 2 \n");
	deleteAt(3);
	displayAll(head);
	system("PAUSE");
	return 0;
}


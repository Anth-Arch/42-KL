#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct {
	Node *head; //They way the pointer work is that it has to be the
	Node *tail; //same type of data to point
	int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue (Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);

int main (void)
{

	return 0;
}

// *create_queue helps to create the tracking for head, tail and size
// but to use this, there needs to be a pointer to point at the output
// of this queue

Queue *create_queue() 
{
	Queue *queue = malloc(sizeof(Queue));

	queue-> head = NULL;
	queue-> tail = NULL;
	queue-> size = 0;
	return(queue);
}

// this function takes in the queue information and then 
// output the queue size

int size(Queue *queue) 
{
	return (queue -> size);
}

bool is_empty(Queue *queue)
{
	return (queue->size == 0);
}

//This function return the head node's value and the status of whether if there are nodes
//Note: we cannot use the return function to return the bool as it is suppose to output the value of the node. This 2nd parameter 'status' is needed.
int peek(Queue *queue, bool *status)
{
	if (is_empty(queue))
	{
		*status = false; //For this to turn to false, the user has to create a value variable status, which will be updated.
		return (NULL);
	}
	*status = true;
	return queue->head->value;
}
void enqueue (Queue *queue, int value)
{
	Node *newNode = malloc(sizeof(Node));

	newNode->value = value;
	newNode->next = NULL;
	
	if (is_empty(queue))
	{
		queue-> head = newNode;
		queue-> tail = newNode;
	}
	else
	{
		// queue->tail->next = newNode;:
		//This line sets the next pointer of the current tail node to point to the new node.
		//Purpose: This links the new node to the end of the queue. The current tail node's next pointer is updated to point to the new node, effectively adding the new node to the end of the queue.
		queue->tail->next = newNode; // Make the CURRENT TAIL node point at NEXT TAIL node.
		//queue->tail = newNode;:
		// This line updates the tail pointer of the queue to point to the new node.
		// Purpose: This makes the new node the new tail of the queue. The tail pointer of the queue is updated to point to the new node, indicating that the new node is now the last node in the queue.
		queue->tail = newNode; // Make the new NODE as the new TAIL Node
	}
	queue->size++;
}

int dequeue(Queue *queue, bool *status)
{
	if (is_empty(queue))
	{
		*status = false;
		return NULL;
	}
	
	*status =  true;
	int value = queue->head->value;
	Node *temp = queue->head;
	if(queue->size == 0)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		queue->head = queue->head->next;
	}
	queue->size--;
	free(temp);
	return (value);
}
void destroy_queue(Queue *queue)
{
	Node *temp;

	while (queue->head != NULL)
	{
		temp = queue->head;
		queue->head = queue->head->next;
		free(temp);
	}
	// if (queue->head == NULL)
	// {
	// 	queue->tail = NULL;
	// 	queue->size = 0;
	// }

	free(queue);
}
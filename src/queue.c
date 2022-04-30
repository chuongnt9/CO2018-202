#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size < MAX_QUEUE_SIZE)
	{	
		q -> proc[q->size] = proc;
		q -> size ++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(!empty(q))
	{
		int highestPriorityP = 0, highestPriority = q -> proc[0] -> priority;
		for(int i = 1; i < q-> size; ++i)
		{
			if(q -> proc[i]-> priority > highestPriority)
			{
				highestPriority = q -> proc[i]-> priority;
				highestPriorityP = i;
			}
		}

		struct pcb_t * res = q -> proc[highestPriorityP];
		
		q -> proc[highestPriorityP] = NULL;
	
		for(int i = highestPriorityP; i < q -> size - 1; ++i)
		{
			q -> proc[i] = q -> proc[i+1];
		}
		q->size --;
		return res;
	}
	
	return NULL;
}
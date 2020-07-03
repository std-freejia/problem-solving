#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct PQNode {
	PriorityType priority;
	void* data;
}PQNode;

typedef struct PQ {
	
	PQNode* nodes;
	int capacity;
	int usedSize;

}PriorityQueue;

PriorityQueue* PQ_Create(int initialSize);
void PQ_Destory(PriorityQueue* PQ);
void PQ_Enqueue(PriorityQueue* PQ, PQNode newNode);
void PQ_Dequeue(PriorityQueue* PQ, PQNode* root);
int PQ_GetParent(int index);
int PQ_GetLeftChild(int index);
void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2);
int PQ_IsEmpty(PriorityQueue* PQ);

#endif
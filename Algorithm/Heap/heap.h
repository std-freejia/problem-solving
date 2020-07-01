#ifndef HEAP_H
#define HEAP_H

// �� 

#include <stdio.h>
#include <memory.h> // memcpy
#include <stdlib.h> // realloc

typedef int ElementType;

typedef struct Node { // ��� 
	ElementType data;
}HeapNode;

typedef struct Heap { // �� 
	HeapNode* nodes;
	int capacity;
	int usedSize;
}Heap;

Heap* Create(int initialSize);
void Destroy(Heap* H); // 
void Insert(Heap* H, ElementType newData);  // ����
void DeleteMin(Heap* H, HeapNode* root); // �ּҰ� ���� 
int GetParent(int index); // �θ� �ε��� ����
int GetLeftChild(int index); // ���� �ڽ� �ε��� ����
void SwapNodes(Heap* H, int index1, int index2);
void PrintNodes(Heap* H);

#endif
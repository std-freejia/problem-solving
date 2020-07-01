#ifndef HEAP_H
#define HEAP_H

// 힙 

#include <stdio.h>
#include <memory.h> // memcpy
#include <stdlib.h> // realloc

typedef int ElementType;

typedef struct Node { // 노드 
	ElementType data;
}HeapNode;

typedef struct Heap { // 힙 
	HeapNode* nodes;
	int capacity;
	int usedSize;
}Heap;

Heap* Create(int initialSize);
void Destroy(Heap* H); // 
void Insert(Heap* H, ElementType newData);  // 삽입
void DeleteMin(Heap* H, HeapNode* root); // 최소값 삭제 
int GetParent(int index); // 부모 인덱스 리턴
int GetLeftChild(int index); // 왼쪽 자식 인덱스 리턴
void SwapNodes(Heap* H, int index1, int index2);
void PrintNodes(Heap* H);

#endif
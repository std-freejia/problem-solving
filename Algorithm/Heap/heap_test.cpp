#include "heap.h"

// �� 

int main(void) {

	Heap* H = Create(3);
	HeapNode minNode;

	Insert(H, 12); // 6�� ���� 
	Insert(H, 87);
	Insert(H, 111);
	Insert(H, 34);
	Insert(H, 16);
	Insert(H, 75);

	PrintNodes(H);

	DeleteMin(H, &minNode); // ���� �� ��� �ϴ� ���� �ݺ� 
	PrintNodes(H);

	DeleteMin(H, &minNode);
	PrintNodes(H);

	DeleteMin(H, &minNode);
	PrintNodes(H);

	DeleteMin(H, &minNode);
	PrintNodes(H);

	DeleteMin(H, &minNode);
	PrintNodes(H);

	DeleteMin(H, &minNode);
	PrintNodes(H);

	Destroy(H);

	return 0;
}
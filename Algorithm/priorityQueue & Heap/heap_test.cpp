#include "heap.h"

// 힙 

int main(void) {

	Heap* H = Create(3);
	HeapNode minNode;

	Insert(H, 12); // 6개 삽입 
	Insert(H, 87);
	Insert(H, 111);
	Insert(H, 34);
	Insert(H, 16);
	Insert(H, 75);

	PrintNodes(H);

	DeleteMin(H, &minNode); // 삭제 후 출력 하는 것을 반복 
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
#include "heap.h"

// 힙 

// 힙 메모리 할당 
Heap* Create(int initialSize) {

	Heap* newHeap = (Heap*)malloc(sizeof(Heap));

	newHeap->nodes = (HeapNode*)malloc(sizeof(HeapNode) * initialSize);
	newHeap->capacity = initialSize;
	newHeap->usedSize = 0;

	printf("size:%d\n", sizeof(HeapNode));

	return newHeap;
}

// 힙 메모리 해제 
void Destroy(Heap* H) {

	free(H->nodes);
	free(H);

	return;
}

// 삽입 
void Insert(Heap* H, int newData) { 

	// 1. 최고 깊이 최 우측 노드와 그 것의 부모 노드 인덱스
	int currentPosition = H->usedSize;
	int parentPosition = GetParent(currentPosition);

	// 2. 만약, 힙이 꽉차있다면, 용량 증가 
	if (H->capacity == H->usedSize) {

		H->capacity *= 2;
		H->nodes = (HeapNode*)realloc(H->nodes, sizeof(HeapNode) * H->capacity);
	}

	// 3. 최고 깊이 최 우측 노드에 새 노드 삽입 
	H->nodes[currentPosition].data = newData; 

	// 4. 힙 순서 속성 유지할 때까지 비교 반복
	// 탈출 조건 : 자신이 루트 노드가 된다(인덱스 0). 또는 자신의 값이 부모보다 크거나 같다. 
	while (currentPosition != 0 && H->nodes[currentPosition].data < H->nodes[parentPosition].data) {
		 
		SwapNodes(H, currentPosition, parentPosition); // 자리 교환 

		currentPosition = parentPosition; // 1번 처럼 인덱스 갱신 
		parentPosition = GetParent(currentPosition);
	}

	// 5. 용량 증가
	H->usedSize++; 

	return;
}


// 최소값 삭제 
void DeleteMin(Heap* H, HeapNode* root) { 

	int parentPosition = 0; // 루트노드 자신이 부모로 시작. 루트니까 인덱스 0.
	int leftPosition = 0;
	int rightPosition = 0;

	// root에 최소값을 저장해둔다. 
	memcpy(root, &H->nodes[0], sizeof(HeapNode));
	memset(&H->nodes[0], 0, sizeof(HeapNode));

	H->usedSize--; // 최우측 노드 인덱스 
	SwapNodes(H, 0, H->usedSize); // 루트 자리에 최고 깊이 최우측 노드를 옮겨온다. 

	leftPosition = GetLeftChild(0); // 루트 노드의 왼쪽 자식, 오른쪽 자식 인덱스 
	rightPosition = leftPosition + 1;

	
	while (1) { // 힙 순서 속성을 만족할 때 까지 루트는 자기 자식과 비교한다.

		int selectedChild = 0; // 1. 부모노드(루트노드)와 교환할 노드의 인덱스를 찾아본다 

		if (leftPosition >= H->usedSize) { 
			// 실제 노드 개수보다 왼쪽자식 인덱스가 같거나 크다 
			// 유의점 : 노드 인덱스는 0부터 시작. 사용량은 1부터 시작
			// 즉, 루트노드는 잎노드가 된 상황. 
			break; 
		}

		if (rightPosition >= H->usedSize) { 
			// 사용 인덱스보다 오른쪽 자식인덱스가 크다
			// 즉, 루트노드에게 오른쪽 자식은 존재하지 않고 왼쪽자식만 있는것임.
			selectedChild = leftPosition; // 타겟은 왼쪽자식 
		}
		else { // 양쪽 자식 존재 

			if (H->nodes[leftPosition].data < H->nodes[rightPosition].data) { 
				// 왼쪽 자식이 작다. 타겟은 왼쪽자식 
				selectedChild = leftPosition; 
			}
			else { // 오른쪽 자식이 작다. 타겟은 오른쪽 자식  
				selectedChild = rightPosition;
			}
		}

		// 2. 값을 보고 교환할 필요가 있는지 확인한다 
		if (H->nodes[selectedChild].data < H->nodes[parentPosition].data) {
			SwapNodes(H, selectedChild, parentPosition);
			parentPosition = selectedChild; // 타겟이 새 부모가 된다. 
		}
		else {
			break;
		}

		// 3. 왼쪽 자식, 오른쪽 자식 인덱스를 갱신한다. 
		leftPosition = GetLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}

	// 4. 용량의 반 이하만 쓰고 있다면, 힙 용량을 반으로 줄인다. 
	if (H->usedSize < (H->capacity/2)) {

		H->capacity /= 2; // 줄일 용량 
		H->nodes = (HeapNode*)realloc(H->nodes, sizeof(HeapNode) * H->capacity);

	}

}

// 현재 노드와 부모 노드 교환 
void SwapNodes(Heap* H, int current, int parent) {

	int copySize = sizeof(HeapNode);
	HeapNode* tempNode = (HeapNode*)malloc(sizeof(HeapNode));

	memcpy(tempNode, &H->nodes[current], copySize);
	memcpy(&H->nodes[current], &H->nodes[parent], copySize);
	memcpy(&H->nodes[parent], tempNode, copySize);

	free(tempNode);

	return;
}

int GetParent(int index) { // 부모의 인덱스를 반환 
	return (int)((index - 1) / 2);
}

int GetLeftChild(int index) { // 왼쪽 자식 인덱스 반환 
	return (index * 2) + 1;
}

void PrintNodes(Heap* H) { // 노드 전체 출력 
	int i = 0;

	for (i = 0; i < H->usedSize; i++) {
		printf("%d ", H->nodes[i].data);
	}
	printf("\n");
}

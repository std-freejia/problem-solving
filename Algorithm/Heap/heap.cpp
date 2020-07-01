#include "heap.h"

// �� 

// �� �޸� �Ҵ� 
Heap* Create(int initialSize) {

	Heap* newHeap = (Heap*)malloc(sizeof(Heap));

	newHeap->nodes = (HeapNode*)malloc(sizeof(HeapNode) * initialSize);
	newHeap->capacity = initialSize;
	newHeap->usedSize = 0;

	printf("size:%d\n", sizeof(HeapNode));

	return newHeap;
}

// �� �޸� ���� 
void Destroy(Heap* H) {

	free(H->nodes);
	free(H);

	return;
}

// ���� 
void Insert(Heap* H, int newData) { 

	// 1. �ְ� ���� �� ���� ���� �� ���� �θ� ��� �ε���
	int currentPosition = H->usedSize;
	int parentPosition = GetParent(currentPosition);

	// 2. ����, ���� �����ִٸ�, �뷮 ���� 
	if (H->capacity == H->usedSize) {

		H->capacity *= 2;
		H->nodes = (HeapNode*)realloc(H->nodes, sizeof(HeapNode) * H->capacity);
	}

	// 3. �ְ� ���� �� ���� ��忡 �� ��� ���� 
	H->nodes[currentPosition].data = newData; 

	// 4. �� ���� �Ӽ� ������ ������ �� �ݺ�
	// Ż�� ���� : �ڽ��� ��Ʈ ��尡 �ȴ�(�ε��� 0). �Ǵ� �ڽ��� ���� �θ𺸴� ũ�ų� ����. 
	while (currentPosition != 0 && H->nodes[currentPosition].data < H->nodes[parentPosition].data) {
		 
		SwapNodes(H, currentPosition, parentPosition); // �ڸ� ��ȯ 

		currentPosition = parentPosition; // 1�� ó�� �ε��� ���� 
		parentPosition = GetParent(currentPosition);
	}

	// 5. �뷮 ����
	H->usedSize++; 

	return;
}


// �ּҰ� ���� 
void DeleteMin(Heap* H, HeapNode* root) { 

	int parentPosition = 0; // ��Ʈ��� �ڽ��� �θ�� ����. ��Ʈ�ϱ� �ε��� 0.
	int leftPosition = 0;
	int rightPosition = 0;

	// root�� �ּҰ��� �����صд�. 
	memcpy(root, &H->nodes[0], sizeof(HeapNode));
	memset(&H->nodes[0], 0, sizeof(HeapNode));

	H->usedSize--; // �ֿ��� ��� �ε��� 
	SwapNodes(H, 0, H->usedSize); // ��Ʈ �ڸ��� �ְ� ���� �ֿ��� ��带 �Űܿ´�. 

	leftPosition = GetLeftChild(0); // ��Ʈ ����� ���� �ڽ�, ������ �ڽ� �ε��� 
	rightPosition = leftPosition + 1;

	
	while (1) { // �� ���� �Ӽ��� ������ �� ���� ��Ʈ�� �ڱ� �ڽİ� ���Ѵ�.

		int selectedChild = 0; // 1. �θ���(��Ʈ���)�� ��ȯ�� ����� �ε����� ã�ƺ��� 

		if (leftPosition >= H->usedSize) { 
			// ���� ��� �������� �����ڽ� �ε����� ���ų� ũ�� 
			// ������ : ��� �ε����� 0���� ����. ��뷮�� 1���� ����
			// ��, ��Ʈ���� �ٳ�尡 �� ��Ȳ. 
			break; 
		}

		if (rightPosition >= H->usedSize) { 
			// ��� �ε������� ������ �ڽ��ε����� ũ��
			// ��, ��Ʈ��忡�� ������ �ڽ��� �������� �ʰ� �����ڽĸ� �ִ°���.
			selectedChild = leftPosition; // Ÿ���� �����ڽ� 
		}
		else { // ���� �ڽ� ���� 

			if (H->nodes[leftPosition].data < H->nodes[rightPosition].data) { 
				// ���� �ڽ��� �۴�. Ÿ���� �����ڽ� 
				selectedChild = leftPosition; 
			}
			else { // ������ �ڽ��� �۴�. Ÿ���� ������ �ڽ�  
				selectedChild = rightPosition;
			}
		}

		// 2. ���� ���� ��ȯ�� �ʿ䰡 �ִ��� Ȯ���Ѵ� 
		if (H->nodes[selectedChild].data < H->nodes[parentPosition].data) {
			SwapNodes(H, selectedChild, parentPosition);
			parentPosition = selectedChild; // Ÿ���� �� �θ� �ȴ�. 
		}
		else {
			break;
		}

		// 3. ���� �ڽ�, ������ �ڽ� �ε����� �����Ѵ�. 
		leftPosition = GetLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}

	// 4. �뷮�� �� ���ϸ� ���� �ִٸ�, �� �뷮�� ������ ���δ�. 
	if (H->usedSize < (H->capacity/2)) {

		H->capacity /= 2; // ���� �뷮 
		H->nodes = (HeapNode*)realloc(H->nodes, sizeof(HeapNode) * H->capacity);

	}

}

// ���� ���� �θ� ��� ��ȯ 
void SwapNodes(Heap* H, int current, int parent) {

	int copySize = sizeof(HeapNode);
	HeapNode* tempNode = (HeapNode*)malloc(sizeof(HeapNode));

	memcpy(tempNode, &H->nodes[current], copySize);
	memcpy(&H->nodes[current], &H->nodes[parent], copySize);
	memcpy(&H->nodes[parent], tempNode, copySize);

	free(tempNode);

	return;
}

int GetParent(int index) { // �θ��� �ε����� ��ȯ 
	return (int)((index - 1) / 2);
}

int GetLeftChild(int index) { // ���� �ڽ� �ε��� ��ȯ 
	return (index * 2) + 1;
}

void PrintNodes(Heap* H) { // ��� ��ü ��� 
	int i = 0;

	for (i = 0; i < H->usedSize; i++) {
		printf("%d ", H->nodes[i].data);
	}
	printf("\n");
}

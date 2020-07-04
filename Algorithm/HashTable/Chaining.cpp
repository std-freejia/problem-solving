#include "Chaining.h"


// [중요] 삽입, 탐색, 해시
void CHT_Set(HashTable* HT, KeyType key, ValueType value) {

	// 주소를 해싱 
	int address = CHT_Hash(key, strlen(key), HT->tableSize);

	Node* newNode = CHT_CreateNode(key, value);

	if (HT->table[address] == NULL) { // 해당 주소가 비어있다 
		HT->table[address] = newNode;
	}
	else { // 해당 주소가 비어있지 않다. (체이닝 발생)
		List head = HT->table[address];
		newNode->next = head;
		HT->table[address] = newNode;

		printf("Collision occured. Key(%s), Value(%s)\n", key, address);
	}

	return;
}

/* 탐색 */
ValueType CHT_Get(HashTable* HT, KeyType key) { // 테이블 주소와 찾을 키를 입력받음

	// 주소를 해싱 
	int address = CHT_Hash(key, strlen(key), HT->tableSize);

	// 해싱한 주소의 리스트 값 
	List list = HT->table[address];

	List target = NULL; // 찾을 노드 

	if (list == NULL) { // 리스트가 비었으면, NULL 리턴하고 종료.
		return NULL;
	}

	while (1) { // key와 같을 때 까지 순차탐색 

		if (strcmp(list->key, key) == 0) { // 그 주소의 키가 찾을 키와 같은지 비교 
			target = list;
			break;
		}

		if (list->next == NULL) { // 리스트의 끝에 도달하면 NULL
			return NULL;
		}
		else { // 더 탐색한다 
			list = list->next;
		}
	}

	return target->value;
}

/* 해시 함수 */
int	CHT_Hash(KeyType key, int keyLength, int tableSize) {

	int i = 0;
	int hashValue = 0;

	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue = hashValue % tableSize;

	return hashValue;
}



/* Hash Table 생성 */
HashTable* CHT_CreateHashTable(int tableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->tableSize = tableSize;
	HT->table = (List*)malloc(sizeof(List) * tableSize);

	// List를 0 으로 초기화 
	memset(HT->table, 0, sizeof(sizeof(List) * tableSize));

	return HT;
}

/* 해시 테이블 삭제 */
void HT_DestroyHashTable(HashTable* HT) {

	int i = 0;

	/* 링크드 리스트를 전부 메모리 해제 */
	for (i = 0; i < HT->tableSize; i++) {

		List targetList = HT->table[i];
		CHT_DestoryList(targetList);
	}
	
	free(HT);

	return;
}

/* 노드 생성 */
Node* CHT_CreateNode(KeyType key, ValueType value) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// key 길이 만큼 할당 
	newNode->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(newNode->key, key);

	// value 길이 만큼 할당 
	newNode->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(newNode->value, value);

	// 다음 노드 포인터 초기화 
	newNode->next = NULL;

	return newNode;
}

/* 노드 삭제 */
void CHT_DestoryNode(Node* target) {

	free(target->key);
	free(target->value);
	free(target);

	return;
}


/* 리스트 삭제  */
void CHT_DestoryList(List list) {

	if (list->next != NULL) { // 자신의 다음것을 메모리 해제 
		CHT_DestoryList(list->next);
	}

	CHT_DestoryNode(list); // 마지막으로 자기 자신을 메모리 해제 

	return; 
}

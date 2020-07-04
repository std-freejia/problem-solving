#include "Chaining.h"


// [�߿�] ����, Ž��, �ؽ�
void CHT_Set(HashTable* HT, KeyType key, ValueType value) {

	// �ּҸ� �ؽ� 
	int address = CHT_Hash(key, strlen(key), HT->tableSize);

	Node* newNode = CHT_CreateNode(key, value);

	if (HT->table[address] == NULL) { // �ش� �ּҰ� ����ִ� 
		HT->table[address] = newNode;
	}
	else { // �ش� �ּҰ� ������� �ʴ�. (ü�̴� �߻�)
		List head = HT->table[address];
		newNode->next = head;
		HT->table[address] = newNode;

		printf("Collision occured. Key(%s), Value(%s)\n", key, address);
	}

	return;
}

/* Ž�� */
ValueType CHT_Get(HashTable* HT, KeyType key) { // ���̺� �ּҿ� ã�� Ű�� �Է¹���

	// �ּҸ� �ؽ� 
	int address = CHT_Hash(key, strlen(key), HT->tableSize);

	// �ؽ��� �ּ��� ����Ʈ �� 
	List list = HT->table[address];

	List target = NULL; // ã�� ��� 

	if (list == NULL) { // ����Ʈ�� �������, NULL �����ϰ� ����.
		return NULL;
	}

	while (1) { // key�� ���� �� ���� ����Ž�� 

		if (strcmp(list->key, key) == 0) { // �� �ּ��� Ű�� ã�� Ű�� ������ �� 
			target = list;
			break;
		}

		if (list->next == NULL) { // ����Ʈ�� ���� �����ϸ� NULL
			return NULL;
		}
		else { // �� Ž���Ѵ� 
			list = list->next;
		}
	}

	return target->value;
}

/* �ؽ� �Լ� */
int	CHT_Hash(KeyType key, int keyLength, int tableSize) {

	int i = 0;
	int hashValue = 0;

	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue = hashValue % tableSize;

	return hashValue;
}



/* Hash Table ���� */
HashTable* CHT_CreateHashTable(int tableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->tableSize = tableSize;
	HT->table = (List*)malloc(sizeof(List) * tableSize);

	// List�� 0 ���� �ʱ�ȭ 
	memset(HT->table, 0, sizeof(sizeof(List) * tableSize));

	return HT;
}

/* �ؽ� ���̺� ���� */
void HT_DestroyHashTable(HashTable* HT) {

	int i = 0;

	/* ��ũ�� ����Ʈ�� ���� �޸� ���� */
	for (i = 0; i < HT->tableSize; i++) {

		List targetList = HT->table[i];
		CHT_DestoryList(targetList);
	}
	
	free(HT);

	return;
}

/* ��� ���� */
Node* CHT_CreateNode(KeyType key, ValueType value) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// key ���� ��ŭ �Ҵ� 
	newNode->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(newNode->key, key);

	// value ���� ��ŭ �Ҵ� 
	newNode->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(newNode->value, value);

	// ���� ��� ������ �ʱ�ȭ 
	newNode->next = NULL;

	return newNode;
}

/* ��� ���� */
void CHT_DestoryNode(Node* target) {

	free(target->key);
	free(target->value);
	free(target);

	return;
}


/* ����Ʈ ����  */
void CHT_DestoryList(List list) {

	if (list->next != NULL) { // �ڽ��� �������� �޸� ���� 
		CHT_DestoryList(list->next);
	}

	CHT_DestoryNode(list); // ���������� �ڱ� �ڽ��� �޸� ���� 

	return; 
}

#include "SimpleHashTable.h"

/* �ؽ� ���̺� ���� */
HashTable* SHT_CreateHashTable(int tableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->tableSize = tableSize;
	HT->table = (Node*)malloc(sizeof(Node) * HT->tableSize);

	return HT;	
}

/* ������ ����  */
void SHT_Set(HashTable* HT, KeyType key, ValueType value) {

	// �ּ� ��� (�ؽ� �Լ��� key, tableSize �ֱ�)
	int address = SHT_Hash(key, HT->tableSize);

	HT->table[address].key = key;
	HT->table[address].value = value;

	return;
}

/* key�� value ���  */
ValueType SHT_Get(HashTable* HT, KeyType key) {

	int address = SHT_Hash(key, HT->tableSize);

	return HT->table[address].value;
}

/* �ؽð�(�ּҰ�) ��ȯ �Լ�  */
int SHT_Hash(KeyType key, int tableSize) 
{
	return key % tableSize;
}	

/* �ؽ� ���̺� �޸� ���� */
void SHT_DestroyHashTable(HashTable* HT) {

	free(HT->table);
	free(HT);

	return;
}

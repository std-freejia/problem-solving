#include "SimpleHashTable.h"

/* 해시 테이블 생성 */
HashTable* SHT_CreateHashTable(int tableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->tableSize = tableSize;
	HT->table = (Node*)malloc(sizeof(Node) * HT->tableSize);

	return HT;	
}

/* 데이터 삽입  */
void SHT_Set(HashTable* HT, KeyType key, ValueType value) {

	// 주소 얻기 (해시 함수에 key, tableSize 넣기)
	int address = SHT_Hash(key, HT->tableSize);

	HT->table[address].key = key;
	HT->table[address].value = value;

	return;
}

/* key로 value 얻기  */
ValueType SHT_Get(HashTable* HT, KeyType key) {

	int address = SHT_Hash(key, HT->tableSize);

	return HT->table[address].value;
}

/* 해시값(주소값) 반환 함수  */
int SHT_Hash(KeyType key, int tableSize) 
{
	return key % tableSize;
}	

/* 해시 테이블 메모리 해제 */
void SHT_DestroyHashTable(HashTable* HT) {

	free(HT->table);
	free(HT);

	return;
}

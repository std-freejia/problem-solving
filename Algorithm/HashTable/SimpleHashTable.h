#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

// 해시테이블 (나눗셈법 예제) // 충돌을 고려하지 않은 간단한 코드

// key, value 둘다 int 형.
typedef int KeyType; 
typedef int ValueType;

typedef struct tagNode
{
	KeyType		key; // key를 해시 함수에 넣어서 '주소'로 사용
	ValueType	value; // 주소에 저장할 '값'
}Node;

typedef struct tagHashTable 
{
	int tableSize;  // 테이블 크기 
	Node* table;	// 테이블 시작 노드 

}HashTable;

// 필요한 함수들 5개 

HashTable* SHT_CreateHashTable(int tableSize); // 해시 테이블 생성
void SHT_Set(HashTable* HT, KeyType key, ValueType value); // 데이터 삽입 
ValueType SHT_Get(HashTable* HT, KeyType key); // key로 value 얻기 
int SHT_Hash(KeyType key, int tableSize); // 해시값(주소값) 반환 함수 
void SHT_DestroyHashTable(HashTable* HT); // 해시 테이블 메모리 해제 

#endif
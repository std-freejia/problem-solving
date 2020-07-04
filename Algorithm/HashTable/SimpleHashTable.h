#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

// �ؽ����̺� (�������� ����) // �浹�� ������� ���� ������ �ڵ�

// key, value �Ѵ� int ��.
typedef int KeyType; 
typedef int ValueType;

typedef struct tagNode
{
	KeyType		key; // key�� �ؽ� �Լ��� �־ '�ּ�'�� ���
	ValueType	value; // �ּҿ� ������ '��'
}Node;

typedef struct tagHashTable 
{
	int tableSize;  // ���̺� ũ�� 
	Node* table;	// ���̺� ���� ��� 

}HashTable;

// �ʿ��� �Լ��� 5�� 

HashTable* SHT_CreateHashTable(int tableSize); // �ؽ� ���̺� ����
void SHT_Set(HashTable* HT, KeyType key, ValueType value); // ������ ���� 
ValueType SHT_Get(HashTable* HT, KeyType key); // key�� value ��� 
int SHT_Hash(KeyType key, int tableSize); // �ؽð�(�ּҰ�) ��ȯ �Լ� 
void SHT_DestroyHashTable(HashTable* HT); // �ؽ� ���̺� �޸� ���� 

#endif
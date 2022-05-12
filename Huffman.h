#ifndef huffman_h
#define huffman_h


#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>


typedef struct{
	char huruf;
	int freq;
}infoH;

#include "BinaryTree.h"
#include "Queue.h"

int CountFrequency(char huruf, char* teks);
void SortQueueByFreq(Queue *queue);
void GenerateHuffmanTree(bTree *tree, Queue *queue);
char* GenerateHuffmanCode(bTree *tree, char huruf);
void PrintCode(bTree hTree, char* teks);

#endif

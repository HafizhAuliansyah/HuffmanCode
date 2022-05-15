#ifndef huffman_h
#define huffman_h


#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>

#include "Queue.h"
#include "BinaryTree.h"

// SALMAN
int CountFrequency(char huruf, char* teks);
void GenerateCharQueue(Queue *queue, char *teks);
void SortQueueByFreq(Queue *queue);
// HAFIZH
void GenerateHuffmanTree(bTree *tree, Queue *queue);
char* GenerateHuffmanCode(bTree *tree, char huruf);

// HAFIZH & SALMAN
void PrintCode(bTree hTree);

#endif

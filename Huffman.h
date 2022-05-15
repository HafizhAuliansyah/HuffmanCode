#ifndef huffman_h
#define huffman_h


#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>

#include "Queue.h"
#include "BinaryTree.h"

// SALMAN
int CountFrequency(char huruf,const char* teks);
void GenerateCharQueue(Queue *queue, char *teks);
void openHelp();

// HAFIZH
void SortQueueByFreq(Queue *queue);
void GenerateHuffmanTree(bTree *tree, Queue *queue);
char* GenerateHuffmanCode(bTree *tree, char huruf);

// HAFIZH & SALMAN
void PrintCode(bTree hTree);

#endif

#ifndef huffman_h
#define huffman_h

/* File			: Huffman.h */
/* Deksripsi	: ADT Huffman, pendefinisian modul modul yang diperlukan dalam pembuatan huffman code */
/* Dibuat Oleh	: Muhammad Hafizh Auliansyah & Salman Alfarisi*/
/* Tanggal		: 12-05-2022, diedit 19-05-2022 */

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <stdbool.h>
#include <windows.h>

#include "Queue.h"
#include "BinaryTree.h"

using namespace std;

int main();

// SALMAN
/* Count Frequency */
// Menghitung freqeuncy kemunculan huruf pada teks, mengembalikan integer
int CountFrequency(char huruf,const char* teks);

/* Generate Char Queue */
// Membuat queue dari karakter unique serta frekuensinya dari suatu teks
void GenerateCharQueue(Queue *queue,const char *teks);

/* Open Help */
// Membuka file help.txt dan menampilkan panduan pengguna
void openHelp();

/*Homepage*/
//sebagai awalan sebelum masuk menu utama
//sebagai menyimpan footer dan header juga
int Homepage();
int header_aplikasi();
int footer_aplikasi();
int Exitapp();		
int WrongInp();
int loading();



// HAFIZH
/* SortQueueByFreq */
// Melakukan sorting dari queue yang telah dibuat berdasarkan jumlah frekuensi secara ascending
void SortQueueByFreq(Queue *queue);

/* Generate Huffman Tree */
// Membuat huffman tree dari queue yang telah dibuat
void GenerateHuffmanTree(bTree *tree, Queue *queue);

/* Generate Huffman Code */
// Mencari huffman code huruf tertentu dari sebuah tree
bool GenerateHuffmanCode(nAddress root, char huruf, string *codes, char code);

/* PrintCode */
// Menampilkan huffman code per-karakter, per-teks, dan menampilkan teks dari code
void PrintCode(bTree hTree, char* teks);


#endif

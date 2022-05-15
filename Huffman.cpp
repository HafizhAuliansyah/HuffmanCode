#include "Huffman.h"

int CountFrequency(char huruf,const char* teks){
	int jumlah;
	int index;
	int panjang_teks = strlen(teks);
	
	while(index < panjang_teks){
		if(huruf==teks[index])
			jumlah++;

		index++;
	}
	
	return jumlah;
	
}
void GenerateCharQueue(Queue *queue, char *teks){
	return;
}
void SortQueueByFreq(Queue *queue){
	return;
}
void GenerateHuffmanTree(bTree *tree, Queue *queue){
	if(!isQueueEmpty(*queue)){
		while(queue->First->next != NULL){
			// Deklarasi Variabel
			infoQ newQueueData;
			infotype newData;
			infoQ leftChild, rightChild;
			
			// Menghapus 2 node pertama queue, untuk dijadikan left child dan right child suatu node baru
			DeleteQueue(queue, &leftChild);
			DeleteQueue(queue, &rightChild);
			// Mengambil frequensi dari 2 node pertama queue
			int jumlah1 = leftChild->info.freq;
			int jumlah2 = rightChild->info.freq;
			// Menjumlahan frequensi
			int sum = jumlah1 + jumlah2;
			
			// Mengisi newData sebagai isi dari node tree baru
			newData.freq = sum;
			newData.huruf = '\0';
			// Membuat node tree baru
			nAddress newTreeNode = bCreateNode(newData);
			
			// Mengisi left child dan right child node tree dengan node hasil DeleteQueue tadi
			newTreeNode->left = leftChild;
			newTreeNode->right = rightChild;
			
			// Menambahkan node baru ke queue
			Enqueue(queue, newTreeNode);
			// Mengsortir kembali isi queue sesuai frequensi
			SortQueueByFreq(queue);
		}
		tree->root = queue->First->info;
	}else{
		printf("FAILED GENERATE HUFFMAN TREE ! QUEUE KOSONG");
	}
}
char* GenerateHuffmanCode(bTree *tree, char huruf){
	return "\0";
}
void PrintCode(bTree hTree, char* teks){
	return;
}

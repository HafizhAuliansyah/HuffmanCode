#include "huffman.h"

int CountFrequency(char huruf,const char* teks){
	// DEKLARASI VARIABEL
	// jumlah  : sebagai penampung frekuensi kemunculan huruf
	// index   : looping huruf dari 0
	// huruf   : variable char yang akan dicari
	// teks    : variable char asal dari huruf
	int jumlah = 0; //dimulai dari 0
	int index = 0; //dimulai dari 0
	int panjang_teks = strlen(teks); // fungsi string length dimasukkan ke dalam variabel panjang_teks  

	
	// PERULANGAN SELAMA PANJANG_TEKS JUMLAHNYA LEBIH BESAR DIBANDING JUMLAH YANG ADA PADA INDEX
	while(index < panjang_teks){
		if(huruf==teks[index]) //jumlah huruf sama dengan teks  
			jumlah++; //jumlah ditambah = 1

		index++; //index ditambah = 1
	}
	
	return jumlah;
	
}
void GenerateCharQueue(Queue *queue,const char *teks){
	// DEKLARASI VARIABEL
	// currentChar : penampung sementara karakter yang akan dibandingkan dan dicari frequensinya
	// exist : penanda yang sudah ada dalam queue
	// index : acuan pengulangan karakter
	// boolean exist : penanda antara ada atau tidak dlm queue
	// temp : variable penampung sementara dalam pengecekan ke dalam queue
	
	char currentChar;
	int index;
	bool exist;
	address_q temp;
	
	// PERULANGAN SELAMA JUMLAH INDEX KURANG DIBANDINGKAN strlen YANG BERISI TEKS
	while(index < strlen(teks)){
		exist = false; 
		currentChar=teks[index]; // jika salah maka lanjut memasukkan teks ke penampung
		temp=queue->First; //node First dimasukkan ke dalam temp
		while(temp!=NULL){ //PERULANGAN SELAMA PENAMPUNG KOSONG
			if(temp->info->info.huruf == currentChar){ // Current char dibandingkan dengan penampung yang diisikan dengan info yang dimasukkan lagi huruf
				exist=true; //maka sudah benar penandanya
				break; //keluar
			}
		temp=temp->next; // penampung diisikan node selanjutnya
		}
		if(exist==false){ //ketika karakter belum terdapat di queue
		
		// newNode penyimpan sementara node
		// newData sebagai penyimpanan sementara karakter dan frekuensi
			nAddress newNode; // nAddress dimasukkan ke dalam newNode
			infotype newData; // infotype dimasukkan ke dalam newData
			
			int freq; //penyimpan frequensi huruf
		
			freq=CountFrequency(currentChar, teks); //itungan frekuensi dari currentchar dan teks dimasukkan kedalam freq
			newData.huruf=currentChar; //currentchar dimasukkan kedalam huruf yang ada dalam newData
			newData.freq=freq; //freq dimasukkan ke dalam newData
			newNode=bCreateNode(newData); //penyimpanan sementara dimasukkan ke dalam node smentara
			Enqueue(queue, newNode); //Penginputan
		}
		index++;
	}
	
}
void openHelp(){
	FILE *data;
	char panduan[600];
	char jawab;
	data = fopen("help.txt", "r");
	
	system("cls");
	while(!feof(data)){
		fgets(panduan, sizeof(panduan), data);
		printf("%s", panduan);
	}
	
	printf("\n\t");
	fclose(data);
	system("pause");
	printf("APAKAH ANDA SUDAH PAHAM? [Y/N]");
	scanf("%s", &jawab);
	if(jawab == 'y'|jawab == 'Y') {
		return; 
	}
	else if(jawab == 'n'|jawab == 'N') {
		return;	
	}
}
void SortQueueByFreq(Queue *queue){
	// INSERTION SORT
	
	// DEKLARASI VARIABEL
	// panjang_q adalah panjang maksimum dari queue
	int panjang_q = LengthQueue(*queue);
	// tempList adalah variabel array sementara yang menampung isi queue untuk di sorting
	nAddress tempList[panjang_q];
	nAddress currentNode, temp;
	int i = 0;
	
	// LOOPING delete queue dan memasukkan hasil node deletion ke tempList
	while(queue->First != NULL){
		DeleteQueue(queue, &tempList[i]);
		i++;
	}
	// LOOPING insertion sort tempList berdasarkan 
	for(i = 1; i < panjang_q; i++){
		for(int j = i; j > 0; j--){
			if(tempList[j]->info.freq < tempList[j -1]->info.freq){
				temp = tempList[j];
				tempList[j] = tempList[j - 1];
				tempList[j - 1] = temp;
				
			}
		}
	}
	// LOOPING enqueue kembali isi queue yang telah di sort
	for(i = 0; i < panjang_q; i++){
		Enqueue(queue, tempList[i]);
	}
	
}
void GenerateHuffmanTree(bTree *tree, Queue *queue){
	// Queue di sorting terlebih dahulu
	SortQueueByFreq(queue);
	if(!isQueueEmpty(*queue)){
		while(queue->First->next != NULL){
			// Deklarasi Variabel
			infotype newData;
			nAddress leftChild, rightChild;
			
			// Menghapus 2 node pertama queue, untuk dijadikan left child dan right child suatu node baru
			DeleteQueue(queue, &leftChild);
			DeleteQueue(queue, &rightChild);
			
			// Mengambil frequensi dari 2 node pertama queue yang tadi dihapus
			int jumlah1 = leftChild->info.freq;
			int jumlah2 = rightChild->info.freq;
			
			// Menjumlahkan frequensi
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
		// Root dari tree adalah info dari First node queue
		tree->root = queue->First->info;
	}else{
		printf("FAILED GENERATE HUFFMAN TREE ! QUEUE KOSONG");
	}
}
bool GenerateHuffmanCode(nAddress root, char huruf, string *codes, char code){
	// Deklarasi Variabel
	// isExist : boolean, true jika huruf ada dalam tree, false jika tidak ada
    bool isExist;
    
    // Start pengkondisian rekursif
	if(root == NULL){
    	return false;
	}else{
		// Jika info.huruf dari node adalah huruf yang dicari, maka nilai codes di prepend dengan code, lalu return true
		if(root->info.huruf == huruf){
			codes->insert(0, 1, code);
			return true;
		}else{
			// Rekursif ke left child, code 0
			isExist = GenerateHuffmanCode(root->left, huruf, codes, '0');
			
			// Jika isExist true, maka codes di prepend kembali dengan code
			if(isExist){
				if(code == '0' || code == '1')
					codes->insert(0, 1 ,code);
				return true;
			}else{
				// Rekursift ke right child, code 1
				isExist = GenerateHuffmanCode(root->right, huruf, codes, '1');
				// Jika isExist true, maka codes di prepend kembali dengan code, jika tidak ada maka false
				if(isExist){
					if(code == '0' || code == '1')
						codes->insert(0, 1 ,code);
					return true;
				}else{
					return false;
				}
			}
		}
	}
}
void PrintCode(bTree hTree, char* teks){
	// Jika tree kosong, muncul peringatan
	if(isTreeEmpty(hTree)){
		printf("\x1b[91m Tree Kosong !! \x1b[m");
	}
	
	char c;
	string codes, showed;
	bool isExist = false, isShowed;
	// PROSES PRINT CODE PER KARAKTER
	printf("\nHuffman Code untuk Setiap Karakter \n");
	for(int i = 0; i < strlen(teks); i++){
		// Reset value isShowed
		isShowed = false;
		// Reset value codes
		codes.clear();
		
		c = teks[i];
		// Cek apakah karakter sudah ditampilkan codenya atau belum
		for(int j = 0; j < showed.length(); j++){
			if(showed[j] == c){
				isShowed = true;
			}
		}
		if(!isShowed){
			isExist = GenerateHuffmanCode(hTree.root, c, &codes, NULL);
			if(isExist){
				if(c == ' ')
					cout << "space" << "\t->" << codes << endl;
				else
					cout << c << "\t->" << codes << endl;
				// Code yang ditampilkan masuk ke string showed
				showed.append(&c);
			}else{
				printf("\n\x1b[91m ERROR ! tidak menemukan huruf %c !! \x1b[m\n", c);
			}

		}

	}
	// PROSES ENCODE TEKS KE HUFFMAN CODE
	printf("\nEncode teks to huffman code\n");
	// Reset value codes jadi kosong
	codes.clear();
	string newCodes;
	// LOOPING tiap huruf, untuk dijadikan code dan diappend ke codes
	for(int i = 0; i < strlen(teks); i++){
		newCodes.clear();
		c = teks[i];
		isExist = GenerateHuffmanCode(hTree.root, c, &newCodes, NULL);
		if(isExist){
			codes.append(newCodes);
		}else{
			printf("\n\x1b[91m ERROR ! tidak menemukan huruf %c !! \x1b[m\n", c);
		}
	}
	// Menampilkan codes
	cout << codes << endl;
	
	// PROSES DECODE HUFFMAN CODE KE TEKS
	printf("\nDecode huffman code to teks\n");
	// LOOPING perbit terhadap tree
	while(!codes.empty()){
		nAddress temp;
		temp = hTree.root;
		while(temp->left != NULL || temp->right != NULL){
			if(codes[0] == '0'){
				temp = temp->left;
			}else{
				temp = temp->right;
			}
			codes.erase(0,1);
		}
		cout << temp->info.huruf;
	}
	cout << endl << endl;
}

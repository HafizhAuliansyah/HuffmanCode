#include "Queue.h"
#include "Huffman.h"



int main() {
	int pilih;
	string teks;
	Queue queue;
	bTree tree;
	char str[] = "";
	Homepage();
	do{
		system("cls");
		header_aplikasi();
		cout << "     TEKS : ";
		if(teks.empty()){
			cout << "\x1b[91m [ Kosong ] \x1b[m" << endl;
		}else{
			cout << "\x1b[92m" << teks << "\x1b[m" <<endl;
		}	
		printf("| 1. Input Kata/Kalimat                                                               |\n");
		printf("| 2. Tampilkan Tree                                                                   |\n");
		printf("| 3. Tampilkan Huffman Code                                                           |\n"); 
		printf("| 4. Panduan Penggunaan                                                               |\n");
		printf("| 5. Keluar                                                                           |\n");
		footer_aplikasi();
		printf("  Masukkan Pilihan : ");
		fflush(stdin);
		scanf("%d" ,&pilih);
		switch(pilih){
			case 1:{
				CreateQueue(&queue);
				bCreate(&tree);
				do{
					printf("  Masukkan Kata/Kalimat : ");
					getline(cin>>ws, teks);
					if(teks.length() < 2){
						printf("  TEKS TIDAK BOLEH KURANG DARI 2 KARAKTER\n\n");
					}
				}while(teks.length() < 2);
				const char* teks_c = teks.c_str();
				GenerateCharQueue(&queue, teks_c);
				GenerateHuffmanTree(&tree, &queue);
				if(tree.root == NULL)
					cout << "\x1b[91m   GAGAL MEMBUAT HUFFMAN TREE \x1b[m" << endl;
				else
					cout << "\x1b[92m   BERHASIL MEMBUAT HUFFMAN TREE \x1b[m" << endl;
				break;
			}
			case 2:
				system("cls");
				header_aplikasi();
				if(!teks.empty())
					bPrint(tree.root, str);
				else 
					cout << "\x1b[91m   MASUKAN TEKS TERLEBIH DAHULU \x1b[m" << endl;
				footer_aplikasi();
				break;
			case 3:
				system("cls");
				header_aplikasi();
				if(!teks.empty())
					PrintCode(tree, strdup(teks.c_str()));
				else
					cout << "\x1b[91m   MASUKAN TEKS TERLEBIH DAHULU \x1b[m" << endl;
				footer_aplikasi();
				break;
			case 4:
				openHelp();
				break;
			default:
				break;
			
		}
		printf("  Tekan apa saja untuk lanjut ....");
		getche();
	}while(pilih != 5);
	return 0;
}

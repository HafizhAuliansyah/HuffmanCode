#include "Queue.h"
#include "Huffman.h"

using namespace std;

int main() {
	int pilih;
	string teks;
	do{
		system("cls");
		printf("1. Input Kata/Kalimat\n");
		printf("2. Tampilkan Tree\n");
		printf("3. Tampilkan Huffman Code\n");
		printf("4. Keluar \n");
		printf("Masukkan Pilihan : ");
		fflush(stdin);
		scanf("%d" ,&pilih);
		switch(pilih){
			case 1:{
				do{
					printf("Masukkan Kata/Kalimat : ");
					getline(cin>>ws, teks);
					if(teks.length() < 2){
						printf("TEKS TIDAK BOLEH KURANG DARI 2 KARAKTER\n\n");
					}
				}while(teks.length() < 2);
				const char* teks_c = teks.c_str();
				
				break;
			}
			case 2:
				break;
			case 3:
				break;
			default:
				break;
			
		}
		getche();
	}while(pilih != 4);
	return 0;
}

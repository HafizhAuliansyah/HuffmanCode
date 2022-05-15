#include "Huffman.h"

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
	main() 
	}
	else(jawab == "n"|jawab == "N") {
	return;	
	}
}

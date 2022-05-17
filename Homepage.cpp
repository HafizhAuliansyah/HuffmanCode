#include "huffman.h"


// deklarasi modul function
int Exitapp();		// keluar app
int WrongInp();		// error handle apabila salah input


// Homepage
int Homepage(){
	// variable lokal
	int menu;

	system("cls");
	header_aplikasi(); // header
	printf("|                                                                                     |\n");
	printf("| Silahkan pilih menu dibawah ini :                                                   |\n");
	printf("|_____________________________________________________________________________________|\n");
	printf("| 1. Mulai aplikasi                                                                   |\n");
	printf("| 2. Keluar aplikasi                                                                  |\n");
	footer_aplikasi(); // footer
    
    printf("\n\n");
    printf("Masukkan pilihan : "); // selain diisi 1 dan 2 maka program akan menunjukan notification alert
	scanf("%d", &menu);

	system("cls");
	
    switch (menu) { 
        case 1:
        	loading();
			return 0; // redirect ke main.cpp
			break;
		case 2:
		    Exitapp(); 	// direct ke exit atau function Exitapp
			break;
	 	default:
	 		WrongInp(); // irect ke exit atau function WrongInp
			break;
    }
}

// function keluar aplikasi
int Exitapp(){
	char pil_out;
	header_aplikasi();
	printf("| Anda yakin untuk keluar aplikasi ini? (Y/N) :                                       |\n");
	footer_aplikasi();
	pil_out = getche(); 

	system("cls");

    printf("\n"); 
    if ((pil_out == 'Y') || (pil_out == 'y'))
    {
    	// exit
    	system("cls");
    	exit(1);
	}
	else{
		// direct ke homepage
		system("cls");
		Homepage(); 
	}
}


// function untuk error handling
int WrongInp(){
	printf("|                                                                                     |\n");
	printf("| Maaf Inputan Salah!                                                                 |\n");
	printf("| Silahkan tekan apapun untuk kembali ke homepage...                                  |");
	getchar();

	// direct ke homepage.cpp
	system("cls");
	Homepage(); 
}


//funcion untuk header aplikasi
int header_aplikasi(){
	printf(" _____________________________________________________________________________________\n");
	printf("|                                                                                     |\n");
	printf("|                                   - HUFFMAN CODE -                                  |\n");
	printf("|_____________________________________________________________________________________|\n");
}
	
//function untuk menampilkan footer aplikasi
int footer_aplikasi(){
	printf(" _____________________________________________________________________________________\n");
	printf("|                                                                                     |\n");
	printf("|                           Copyright 2022 - Hafizh & Salman                          |\n");
	printf("|_____________________________________________________________________________________|\n");
}

int loading(){
	system("cls");
    header_aplikasi();
	printf("                                       Loading....                                     \n");
	for(int i=0;i<=75;i++){
	Sleep(30);
    printf("%c",219);
}
	system("cls");
	header_aplikasi();
    printf("                                    Loading Selesai                                   |\n");
    footer_aplikasi();
    Sleep(700);
}

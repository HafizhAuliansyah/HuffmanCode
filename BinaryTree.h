#ifndef btree_h
#define btree_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
/*
File		: BinaryTree.h
Deskripsi	: Spesifikasi program ADT Binary Tree Dinamis
Author		: M Hafizh Auliansyah & Salman Alfarisi
Created		: 14-1-2022
*/

// Struktur Data Tree
typedef int infotype;
typedef struct TreeNode *nAddress;

typedef struct TreeNode{
	infotype info;
	nAddress left;
	nAddress right;
};

struct bTree{
	nAddress root;
};

/* Constructor */
/* Inisialisasi root tree menjadi NULL */
void bCreate(bTree *tree);

/* Alokasi Node */
/* Mengembalikan address node baru yang sudah ter-Alokasi */
nAddress bCreateNode(infotype x);

/* Check Jika Tree Kosong */
/* Mengembalikan true jika root tree kosong */
bool isTreeEmpty(bTree tree);

// HAFIZH
/* Insert Node */
/* Menambahkan node baru sesuai parent dan posisi yang dituju */
void bInsert(bTree *root, nAddress parent, char position ,infotype x);

/* Seach Node */
/* Mengembalikan address node yang dicari */
nAddress bSearch(nAddress root, infotype src);

/* Seach Parent */
/* Mengembalikan parent dari adress node child yang dicari */
nAddress bSearchParent(nAddress root, nAddress searchChild);

/* Upgrade Node */
/* Upgrade Parent dari node tertentu */
void bUpgrade(bTree *root);

/* Delete Node */
/* Menghapus node tertentu */
void bDelete(bTree *tree, nAddress *nodeDel);

/* Depth Tree */
/* Mengembalikan Depth dari tree */
int bDepth(nAddress root);

// SALMAN
/* ---------------- TRAVERSAL Tree ---------------- */
void bPost(nAddress root); // Postorder traversing
void bPre(nAddress root); // Preorder traversing
void bIn(nAddress root); // Inorder traversing
void bLevelOrder(nAddress root,int level);

/* PRINT TREE */
/* Menampilkan isi tree */
void bPrint(nAddress node, char tab[]);

#endif

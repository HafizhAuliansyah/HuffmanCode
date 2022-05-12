#ifndef queue_h
#define queue_h

/* Library Definition */
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
/* Other Definition*/
#if !defined(LIST_CONSTANT)
	#define LIST_CONSTANT 1
	#define Nil NULL
	#define Info(P) (P)->info
	#define Next(P) (P)->next
	#define First(Q) (Q).First
#endif

/* File			: Queue.h */
/* Deksripsi	: ADT Queue, pendefinisian LinkedList Queue */
/* Dibuat Oleh	: Muhammad Hafizh Auliansyah */
/* Tanggal		: 17-03-2022, diedit 19-03-2022 */
/* Inspired By	: SpNRSLL.h oleh Ade Chandra Nugraha */

typedef nAddress infoQ;
typedef struct tElmtQueue *address_q;
typedef struct tElmtQueue {
	 infoQ info;
	 address_q  next;
} ElmtQueue;

typedef struct {
	  address_q First;
} Queue;

typedef struct{
	address_q head;
	address_q tail;
} QueueTracker;


bool isQueueEmpty (Queue Q);

void CreateQueue (Queue *Q);

address_q AlokasiQ (infoQ X);

void DeAlokasi (address_q P);

void Enqueue(Queue *Q, infoQ x);

void DeleteQueue(Queue *Q, infoQ *x);

void UpdateHead(Queue Q, address_q *head);

void UpdateTail(Queue Q, address_q *tail);

void UpdateQueueTracker(Queue Q, QueueTracker *qt);

void PrintQueue(Queue Q);

#endif

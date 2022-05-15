/* File			: Queue.cpp */
/* Deksripsi	: ADT Queue, implementasi LinkedList Queue */
/* Dibuat Oleh	: Muhammad Hafizh Auliansyah */
/* Tanggal		: 17-03-2022, diedit 19-03-2022 */
/* Inspired By	: SpNRSLL.cpp oleh Haidar Ali Osman Bahafzallah & Muhammad Hafizh Auliansyah */


#include "Queue.h"

bool isQueueEmpty (Queue Q){
	return (First(Q) == Nil);
}

void CreateQueue (Queue *Q){
	First(*Q) = Nil;
}

address_q AlokasiQ (infoQ X){
	address_q P;

	P = (address_q) malloc (sizeof(ElmtQueue));
	if(P != Nil){
		Info(P) = X;
	    Next(P) = Nil;
	    return P;
	}else{
		return Nil;
	}
}

void DeAlokasi (address_q P){
	free(P);
}

void Enqueue(Queue *Q, infoQ x){
	address_q P;
	P = AlokasiQ(x);
	if(P != Nil){
		address_q Last = First(*Q);
		if(Last == Nil){
			First(*Q) = P;
			Next(P) = Nil;
		}else{
			while(Next(Last) != Nil){
				Last = Next(Last);
			}
			Next(Last) = P;
		}
	}
}

void DeleteQueue(Queue *Q, infoQ *x){
	address_q P;
	
	P = First(*Q);
	First(*Q) = Next(First(*Q));
	(*x) = Info(P);
	Next(P) = Nil;
	// DeAlokasi(P);
}

void UpdateHead(Queue Q, address_q *head){
	*head = First(Q);
}

void UpdateTail(Queue Q, address_q *tail){
	address_q P = First(Q);
	if(P != Nil){
		while(Next(P) != Nil){
			P = Next(P);
		}
	}
	
	*tail = P;
}

void UpdateQueueTracker(Queue Q, QueueTracker *qt){
	UpdateHead(Q, &qt->head);
	UpdateTail(Q, &qt->tail);
}
int LengthQueue(Queue Q){
	int len;
	address_q temp = Q.First;
	
	if(temp == NULL)
		return 0;
	
	len = 1;
	while(temp->next != NULL){
		temp = temp->next;
		len++;
	}
	return len;
}

void PrintQueue(Queue Q){
	address_q P;

	P = First(Q);
	if(P == Nil){
	    printf("Queue Kosong\n");
	}else{
	    while(Next(P) != Nil){
	      printf("(%c/%d) ", P->info->info.huruf, P->info->info.freq);
	      P = Next(P);
	    }
	    printf("%c ", Info(P));
	}
}

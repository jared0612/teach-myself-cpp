/*************************************************************************
	> File Name: 3.queue.c
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2022 10:56:43 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Queue{
	int *data;
	int length;
	int head,tail;
	int count;
}Queue;

Queue *init(int n) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->data = (int *)malloc(sizeof(int) * n);
	q->length = n;
	q->tail = 0;
	q->head = 0;
	q->count = 0;
	return q;
}
int push(Queue *q, int val) {
	if (q == NULL) return 0;
	if (q->count == q->length) return 0;
	q->data[q->tail++] = val;
	if (q->tail == q->length) q->tail = 0;
	q->count += 1;
	return 1;
} 

int empty(Queue *q) {
	return !q->count;
}
int front(Queue *q) {
	return q->data[q->head];
}

int pop(Queue *q) {
	if (q == NULL) return 0;
	if (empty(q)) return 0;
	q->head++;
	q->count--;
	if(q->head == q->length) q->head = 0;
	return 1;
}

void clear(Queue *q) {
	if (q== NULL) return ;
	free(q->data);
	free(q);
	return ;
}

void output(Queue *q) {
	if (q == NULL) return;
	if (empty(q)) {
		printf("No Element In This Queue !");
		return;
	}
	printf("Queue(%d,%d)[",q->length, q->count);
	for (int i = q->head, j = 0; j < q->count; j++ ) {
		j && printf(" ");
		printf("%d", q->data[(i + j) % q->length]);
	}
	printf("]\n");

}

int main() {
	srand(time(0));
	#define MAX_OP 4
	Queue *q = init(MAX_OP);
	for(int i = 0; i < MAX_OP+10; i++) {
		int op = rand() % 4;
		int val = rand() % 100;
		switch (op) {
			case 0:
			case 1:
			case 2: {
				printf("push %d to the queue = %d\n", val, push(q, val));
			} break;
			case 3: {
				if(!empty(q)) {
					printf("pop %d from queue\n", front(q));
					pop(q);
				}
				
			}break;
		}
		output(q),printf("\n");	
	}	
	#undef MAX_OP
	clear(q);
	return 0;

}


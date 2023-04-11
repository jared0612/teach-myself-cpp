/*************************************************************************
	> File Name: 2.linklist.c
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2022 10:32:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//定义节点结构
typedef struct ListNode {
	int data;//数据域
	struct	ListNode *next;//指针域
} ListNode;
//通过节点建立链表
typedef struct List {
	ListNode head;
	int length;
}List;

ListNode *getNewNode(int);
List *getNewList();
void clear_node(ListNode *);
void clear(List *);
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *l);

ListNode *getNewNode(int n) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = n;
	p->next = NULL;
	return p;
}

List *getNewList() {
	List *l = (List *)malloc(sizeof(List));
	l->head.next = NULL;
	l->length = 0;
}
void clear_node(ListNode *n) {
	if (n == NULL) return ;
	free(n);
	return ;
}

void clear(List *l) {
	if (l == NULL) return ;
	ListNode *p = l->head.next,*q;
	while(p != NULL) {
		q = p->next;
		clear_node(p);
		p = q;
	}
	free(l);
	return ;
}

int insert(List *l, int ind, int val){
	if (l == NULL) return 0;
	if (ind < 0 || ind > l->length) return 0;
	ListNode *node = getNewNode(val);
	ListNode *p = &(l->head);
	while(ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
}

int erase(List *l, int ind) {
	if (l == NULL) return 0;
	if (ind < 0 || ind >= l->length) return 0;
	ListNode *p = &(l->head), *q;
	while(ind--) p = p->next;
	q = p->next;
	p->next = q->next;
	clear_node(q);
	l->length -= 1;
	return 1;
}

void output(List *l) {
	if (l == NULL) return 0;
	ListNode *p = l->head.next;
	printf("LinkList(%d):", l->length);
	for (;p != NULL; p = p->next){
		printf("%d->", p->data);
	}
	printf("NULL");
}
void reverse(List *l) {
	if (l == NULL) return ;
	ListNode *p = l->head.next, *q;
	while(p != NULL) {
		q = p->next;
		p->next = l->head.next;
		l->head.next = p;
		p = q;
	}
	return ;
}
int main() {
	srand(time(0));
	#define MAX_OP 20
	List *l = getNewList();
	for (int i = 0; i < MAX_OP; i++) {
		int op = rand() % 4;
		int ind = (rand() % (l->length + 3)) - 1;
		int val = rand() % 100;
		switch(op) {
			case 0:
			case 1:
			case 2: {
				printf("insert %d at %d\n", val, ind, insert(l, ind, val));
				break;
			}
			case 3: {
				printf("erase a iterm at %d\n", ind, erase(l, ind));
				break;
			}
		} 
		output(l), printf("\n");
	}
	#undef MAX_OP
	clear(l);
	return 0;
}


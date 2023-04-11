/*************************************************************************
	> File Name: 4.stack.c
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2022 02:58:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Stack {
	int *data;
	int size, top;
}Stack;

Stack *init(int n) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (int*)malloc(sizeof(int) * n);
	s->size = n;
	s->top = -1;
	return s;
}
int empty(Stack *s) {
	return s->top == -1;
}
int top(Stack *s) {
	return s->data[s->top];
}

int expand(Stack *s) {
	if (s == NULL) return 0;
	int extra_size = s->size;
	int *p;
	while (extra_size) {
		p = (int *)realloc(s->data, sizeof(int) * (extra_size + s->size));
		if (p != NULL) break;
		extra_size /= 2; 
	}
	if (p == NULL) return 0;
	s->data = p;
	s->size += extra_size; 
	return 1;
}

int push(Stack *s, int val) {
	if (s->top == s->size - 1) {
		if (!expand(s)) return 0;
		printf("success expand to %d\n", s->size);
	}
	s->data[++(s->top)] = val;
	return 1;
}

int pop(Stack *s) {
	if (s == NULL) return 0;
	if (empty(s)) return 0;
	s->top--;
	return 1;
}
void clear(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
	return ;
}

void output(Stack *s) {
	if (s == NULL) return ;
	printf("Stack(%d) [", s->size);
	for (int i = s->top; i > -1; i--) {
		(i != s->top) && printf(" ");
		printf("%d", s->data[i]);
	}
	printf("]\n\n");
	return ;
}

int main() {
	srand(time(0));
	#define MAX_OP 20
	Stack *s = init(1);
	for (int i = 0; i < MAX_OP; i++) {
		int op = rand() % 4;
		int val = rand() % 100;
		switch(op) {
			case 0:
			case 1:
			case 2: {
				printf("push %d to Stack = %d\n", val, push(s, val));
				break;
			}
			case 3: {
				printf("pop %d ", top(s));
				printf("in Stack = %d\n", pop(s));
				break;
			}
		}
		output(s); 
	}
	#undef MAX_OP
	clear(s);
	return 0;
}

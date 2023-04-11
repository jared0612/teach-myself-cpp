/*************************************************************************
	> File Name: 1.vector.c
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Aug 2022 11:12:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int Type;

typedef struct Vector{
	Type *data;
	int size, length;
}Vec;

Vec *init(int n) {
	Vec *v = (Vec *)malloc(sizeof(Vec));
	v->data = (Type *)malloc(sizeof(Type) * n);
	v->size = n;
	v->length = 0;
	return v;
}

void clear(Vec *v) {
	if(v == NULL) return ;
	free(v->data);
	free(v);
	return ;
}
int expand(Vec *v) {
	if (v == NULL) return 0;
	int extra_size = v->size;
	Type *p = v->data;
	while(extra_size) {
		p = (Type *) realloc(v->data, sizeof(Type) * (v->size + extra_size));
		if (p) break;
		extra_size >> 1;	 
	}
	if (p == NULL) return 0; 
	v->size += extra_size;
	v->data = p;
	printf("success expand Vec to %d\n", v->size);
	return 1;
}
int insert(Vec *v, int ind, Type val) {
	if (v == NULL) return 0;
	if (ind < 0 || ind > v->length ) return 0;
	if (v->length == v->size) {
		if(!expand(v)) return 0;
	}
	for (int i = v->length; i > ind; i--) {
		v->data[i] = v->data[i - 1];
	}
	v->data[ind] = val;
	v->length += 1;

	return 1;
}
int erase(Vec *v, int ind) {
	if (v == NULL) return 0;
	if (ind < 0 || ind >= v->length) return 0;
	for (int i = ind + 1; i < v->length; i++) {
		v->data[i - 1] = v->data[i];
	}
	v->length -= 1;
	return 1;
}

void output(Vec *v) {
	if (v == NULL) return ;
	printf("Vector[%d]: [", v->length);
	for (int i = 0; i < v->length; i++) {
		i && printf(" ,");
		printf("%d", v->data[i]);
	}
	printf("]\n");
	return ;
}
int main() {
	//测试
	#define MAX_N 15
	Vec *v = init(MAX_N + 5);
	srand(time(0));
	for (int i = 0; i < 130; i++) {
		int op = 0;//rand() % 2;
		int ind = rand() % (v->length + 1);
		int val = rand() % 100;
		switch(op) {
			case 0: {
				printf("insert %d at %d\n", val, ind);
				insert(v, ind, val);
			}
				break;
			case 1: {
				printf("erase data at %d\n", ind);
				erase(v, ind);
			}
				break;
		}
		output(v), printf("\n");
	}

	clear(v);
	#undef MAX_N	
	return 0;
}

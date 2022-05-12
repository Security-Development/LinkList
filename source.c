#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node *link;
} NODE;

void init(NODE *inj) {
	inj->data = 0;
	inj->link = NULL;	
}

void push(NODE *inj, int data) {
	NODE *cInj = (NODE *)malloc(sizeof(NODE));
	cInj->data = data;
	cInj->link = inj->link;
	
	inj->link = cInj;
	
}

void pop(NODE *inj) {
	NODE *rInj = inj->link;
	inj->link = rInj->link;
	free(rInj);	
}

void print(NODE *inj) {
	printf("%d ", inj->data);
	if(inj != NULL)
		print(inj->link);
}

int main() {
	NODE *inj = (NODE *) malloc(sizeof(NODE)), *head;
	init(inj);
	
	
	push(inj, 1);

	push(inj->link, 2);
	
	push(inj->link->link, 3);
	pop(inj->link->link);
	print(inj->link);
	
	return 0;
}

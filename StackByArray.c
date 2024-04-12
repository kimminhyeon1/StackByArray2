#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;
int over = 0;

//create : 이미 만들었음
//delete : 할 수 없음

//is_full
int is_full() {
	return(top == MAX_STACK_SIZE - 1);
}

//is_empty
int is_empty() {
	return (top == -1);
}
//push
void push(element item) {
	if (is_full()) {
		over = 1;
		fprintf(stderr, "Stack Overflow\n");	
		return;
	}
	else {
		top = top + 1;
		stack[top] = item;
	}
}

//pop
element pop() {
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow\n");
		return -1;
	}
	else {
		return(stack[top--]);
	}
}

void print_stack() {
	if (top == -1) {
		printf("Stack is empty\n\n");
	}
	else {
		printf("Stack elements : ");
		for (int j = 0; j < top + 1; j++) {
			printf("%d ", stack[j]);
		}
		printf("\n\n");
		
	}
}

int main(int argc, char* argv[]) {
	element rand_num;
	srand(time(NULL));

	for (int i = 0; i < 30; i++) {
		rand_num = (rand() % 100) + 1;
		if (rand_num % 2 == 0) {
			printf("current rand_num : %d | Even\n", rand_num);
			
			over = 0;

			push(rand_num);
			if (over == 0) {
				printf("Push : %d\n", rand_num);
			}
			print_stack();
		}
		else {
			printf("current rand_num : %d | Odd\n", rand_num);
			
			rand_num = pop();
			if (rand_num > -1) {
				printf("Pop : %d\n", rand_num);
			}
			print_stack();
		}
	}
	return 0;
}
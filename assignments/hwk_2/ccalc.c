#include <stdio.h>

/* This is a calculator program for CS 1337 with Dr. Bodily 
   Scott Brown 8/30/22
*/

int main(){
    char op;

    printf("Enter the operation you would like to perform (+ - / *)(q to quit):");
    scanf("%c", &op);

    if(op == '+') {
	printf("Plus\n");
    }
    else if(op == '-') {
	printf("Minus\n");
    }
    else if(op == '/') {
	printf("Divide\n");
    }
    else if(op == '*') {
	printf("Multiply\n");
    }
    else if((op == 'q') || (op == 'Q')) {
	printf("Goodbye!\n");
	return 0;
    }
    else {
	printf("Invalid option! Please enter a valid option.\n");
	main();
    }
    return 0;
}


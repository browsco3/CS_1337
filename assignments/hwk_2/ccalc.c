/*
*	Lab 2 - C calculator
*	Scott Brown
*	Fall 2022 CS1337 with Dr. Paul Bodily
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

	bool is_valid = false;
	char oper, equation[100], sprintf_buff[10];
	int number_of_integers, result, integers[100];
	double div_result;

	// Loop until a valid option is entered.
	while(is_valid == false) {

		printf("Enter operation: ");
		scanf("%c", &oper);

		if((oper == '+') || (oper == '-') || (oper == '/') || (oper == '*') || (oper == 'q')) {
			is_valid = true;
			if(oper == 'q') {
				return 0;
			}
		}
		else {
			printf("Please enter a valid operation\n");
			while (getchar() != '\n');
		}
	}

	// Gets the number of integers to be used and validates the number.
	is_valid = false;
	while(is_valid == false) {
		printf("Enter number of integers: ");
		scanf("%d", &number_of_integers);

		if(number_of_integers <= 1) {
			printf("Please enter a valid integer greater than one\n");
			while(getchar() != '\n');
		}
		else {
			is_valid = true;
		}

	}

	// Gets the integers to be used.
	for(int index = 0; index < number_of_integers; index++) {
		is_valid = false;
		while(is_valid == false) {
			printf("Enter integer %d: ", index + 1);
			scanf("%d", &integers[index]);
			is_valid = true;
		}
	}
	// Now I solve and print the equation.
	printf("\nComputing: ");
	for(int index = 0; index < number_of_integers; index++) {
		printf("%d ", integers[index]);
		if(index == 0) {
			if(oper == '/') {
				div_result = integers[index];
			}
			else {
				result = integers[index];
			}
		}
		else{
			switch(oper) {
				case 43: //Plus
					result = result + integers[index];
					break;
				case 45: //Minus
					result = result - integers[index];
					break;
				case 47: //Divide
					div_result = div_result / integers[index];
					break;
				case 42: //Multiply
					result = result * integers[index];
					break;
				default:
					break;
			}
		}
		if(index < (number_of_integers - 1)) {
			printf("%c ", oper);
		}
		else {
			if(oper == '/') {
				printf("= %f\n\n", div_result);
			}
			else {
				printf("= %d\n\n", result);
			}
		}
	}
	// Clear the stdin buffer.
	while(getchar() != '\n');

	// Call main again.
	main();
}

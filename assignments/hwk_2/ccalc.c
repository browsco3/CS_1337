/*
*	Lab 2 - C calculator
*	Scott Brown  9/9/2022
*	Fall 2022 CS1337 with Dr. Paul Bodily
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {

	bool is_valid = false;
	char oper, holder, equation[100], sprintf_buff[10];
	int number_of_integers, result, current_integer, integers[100];
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
		}
		else {
			is_valid = true;
		}
		while(getchar() != '\n');

	}

	// Gets the integers to be used.
	for(int index = 0; index < number_of_integers; index++) {
		is_valid = false;
		while(is_valid == false) {
			printf("Enter integer %d: ", index + 1);
			scanf("%c", &holder);
			if((((int)holder - '0') >= 1) && (((int)holder - '0') <= 9)) {
				integers[index] = ((int)holder - '0');
				is_valid = true;
			}
			else {
				printf("Please enter an integer");
			}
			while(getchar() != '\n');
		}
	}
	// Now I solve and print the equation.
	printf("\nComputing: ");
	for(int index = 0; index < number_of_integers; index++) {
		printf("%d ", integers[index]);
		if(index == 0) {
			// change the result to handle floats if division is used.
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
		// Print the operator as long as there is another integer.
		if(index < (number_of_integers - 1)) {
			printf("%c ", oper);
		}
		// Print the results if this is the last integer.
		else {
			if(oper == '/') {
				printf("= %f\n\n", div_result);
			}
			else {
				printf("= %d\n\n", result);
			}
		}
	}

	// Call main again.
	main();
}

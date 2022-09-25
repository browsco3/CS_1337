/*
*	Lab 3 - bit calculator
*	Scott Brown  9/18/2022
*	Fall 2022 CS1337 with Dr. Paul Bodily
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*bool check_valid_hex(char[] hex_to_check) {
	for() {

	}
}*/

int int_to_bin(int input) {
	int output;
	
}

int main() {

	bool is_valid = false;
	char oper, holder, equation[100], sprintf_buff[10], hex_integers[10][10], curr_char, integers[100];
	int number_of_integers, result, current_integer;
	double div_result;

	// Loop until a valid option is entered.
	while(is_valid == false) {

		printf("Enter operation: ");
		scanf("%c", &oper);

		if((oper == '|') || (oper == '&') || (oper == '^') || (oper == 'q')) {
			is_valid = true;
			if(oper == 'q') {
				return 0;
			}
		}
		else {
			printf("Please enter |, &, ^, or q\n");
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
		int char_ind = 0;
		curr_char = '\0';
		is_valid = false;
		while(is_valid == false) {
			printf("Enter integer %d: ", (index + 1));
			scanf("%s", hex_integers[index]);
			while(getchar() != '\n');
			is_valid = true;
		}
	}

	// Print the hex representation.
	printf("\nHexadecimal operation:\n");
	for(int index = 0; index < number_of_integers; index++) {
		if(index == 0) {
			printf("\t  %08X\n", ((int) strtol(hex_integers[index], NULL, 16)));
			result = ((int) strtol(hex_integers[index], NULL, 16));
		}
		else {
			printf("%08X\n", ((int) strtol(hex_integers[index], NULL, 16)));
			switch(oper) {
				case 124: //or
					result = result | ((int) strtol(hex_integers[index], NULL, 16));
					break;
				case 38: //and
					result = result & ((int) strtol(hex_integers[index], NULL, 16));
					break;
				case 94: //xor
					result = result ^ ((int) strtol(hex_integers[index], NULL, 16));
					break;
				default:
					break;
			}
		}
		// Print the operator as long as there is another integer.
		if(index < (number_of_integers - 1)) {
			printf("\t%c ", oper);
		}
		// Print the results if this is the last integer.
		else {
			printf("\t= %08X\n\n", result);
		}
	}
	//Print the binary representation
	printf("Binary operation:\n");
	for(int index = 0; index < number_of_integers; index++) {
		printf("\t");
		int padding = (8 - strlen(hex_integers[index]));
		for(int pad = 0; pad < padding; pad++) {
			printf("0000");
			if((pad > 0) && !(pad % 2 == 0)) {printf(" ");}
		}
		
		printf("\n");

	}
	// Call main again.
	main();
}

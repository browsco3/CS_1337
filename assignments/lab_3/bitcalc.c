/*
*	Lab 3 - bit calculator
*	Scott Brown  9/18/2022
*	Fall 2022 CS1337 with Dr. Paul Bodily
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*bool check_valid_hex(char[] hex_to_check) {
	for() {

	}
}*/

int main() {

	bool is_valid = false;
	char oper, holder, equation[100], sprintf_buff[10], hex_integers[10][8], curr_char;
	int number_of_integers, result, current_integer, integers[100];
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
			while(curr_char != '\n') {
				curr_char = getchar();
				if(curr_char != '\n') {
					hex_integers[index][char_ind] = curr_char;
				}
				char_ind++;
			}
			//is_valid = check_valid_hex(hex_integers[index]);
			is_valid = true;
		}
	}

	printf("\nHexadecimal operation:\n");
	for(int index = 0; index < number_of_integers; index++) {
		if(index == 0) {
			printf("\t  %s\n", hex_integers[index]);
		}
		else {
			printf("\t%c %s\n",oper, hex_integers[index]);
		}
	}
	/*
	// Now I solve and print the equation.
	printf("\nHexadecimal operation:\n");
	for(int index = 0; index < number_of_integers; index++) {
		printf("index = %d", index);
		printf("\t%s\n", hex_integers[index]);
		if(index ==0) {
			result = (int) hex_integers[index];
		}
		else {
			switch(oper) {
				case 124: //or
					result = result | (int) &hex_integers[index];
					break;
				case 38: //and
					result = result & (int) &hex_integers[index];
					break;
				case 94: //xor
					result = result ^ (int) &hex_integers[index];
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
			printf("= %d\n\n", result);
		}
	}
	*/
	// Call main again.
	main();
}

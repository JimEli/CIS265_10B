/*************************************************************************
* Title: (CIS265_10B) Macros.
* File: main.c
* Author: James Eli
* Date: 9/2/2017
*
* Write the following parameterized macros.
* (a) CHECK(x, y, n) – Has the value 1 if both x and y fall between zero 
*     and n-1, inclusive.
* (b) MEDIAN(x, y, z) – Finds the median of x, y and z.
* (c) POLYNOMIAL(x) – Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 
*     7x – 6.
* Develop a user menu to select from the three functions (Check, Median, or 
* Polynomial) and prompt for the inputs
*
* Notes:
*  (1) Debug version compiles CUnit test suite.
*  (2) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   09/02/2017: Initial release. JME
*   10/24/2017: Moved macros to separate file. JME
*   10/24/2017: Added CUnit test suite (test_macros.c). JME
*************************************************************************/
#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"

// C/C++ Preprocessor Definitions: _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 

#define MAX_INPUT_ATTEMPTS  3 // Maximum input attempts before abort.
#define MENU_TEXT           "\nMacro Test Program Menu:\n" \
                            "1 - Test CHECK macro.\n"      \
                            "2 - Test POLYNOMIAL macro.\n" \
                            "3 - Test MEDIAN macro.\n"     \
                            "Q - Quit.\nEnter 1, 2, 3 or Q: "

// Get a number from the user.
double getNumber(const char *prompt, const double min, const double max) {
	double n = NAN; // Return value.
	char input[12]; // Holds user input as string.
	double d = NAN; // Temporary holds input number.
	int attempts = MAX_INPUT_ATTEMPTS;

	while (attempts--) {
		// Prompt and grab user input.
		fprintf(stdout, "%s (%g - %g): ", prompt, min, max);
		if (!fgets(input, sizeof input, stdin)) {
			fputs("\nFatal program error!\n", stderr);
			exit(EXIT_FAILURE);
		}
		else if (!strchr(input, '\n')) {
			// input too long, eat remaining characters.
			while (fgets(input, sizeof input, stdin) && !strchr(input, '\n'))
				; // Empty body.
			fputs("Too many characters input.\n", stdout);
		}
		else {
			// Catch special case of null input.
			if (strlen(input) <= 1)
				continue;
			// Attempt to convert from string to int, and validate.
			if (sscanf_s(input, "%lf", &d)) {
				if (d >= min && d <= max) {
					n = d;
					break; // Exit.
				}
				else
					fputs("Value entered is outside allowable range.\n", stdout);
			}
			else
				fputs("Invalid input.\n", stdout);
		}
	}
	return n; // Return number or NaN.
}

// Test CHECK macro.
void cmdCheck(void) {
	double x, y, n;

	fputs("Testing CHECK(x, y, n) macro.\n", stdout);
	if ((x = getNumber("Enter x", -100., 100.)) != NAN &&
		(y = getNumber("Enter y", -100., 100.)) != NAN &&
		(n = getNumber("Enter n", -100., 100.)) != NAN ) 
		fprintf(stdout, "Result of CHECK(%g, %g, %g) = %d\n", x, y, n, CHECK(x, y, n));
}

// Test POLYNOMIAL macro.
void cmdPolynomial(void) {
	double x;

	fputs("Testing POLYNOMIAL(x) macro.\n", stdout);
	if ((x = getNumber("Enter x", -100., 100.)) != NAN)
		fprintf(stdout, "Result of POLYNOMIAL(%g) = %g\n", x, POLYNOMIAL(x));
}

// Test MEDIAN macro.
void cmdMedian(void) {
	double x, y, z;

	fputs("Testing MEDIAN(x, y, z) macro.\n", stdout);
	if ((x = getNumber("Enter x", -100., 100.)) != NAN &&
		(y = getNumber("Enter y", -100., 100.)) != NAN &&
		(z = getNumber("Enter z", -100., 100.)) != NAN)
		fprintf(stdout, "Result of MEDIAN(%g, %g, %g) = %g\n", x, y, z, MEDIAN(x, y, z));
}

// Command entry handled here.
char fetchCommand(void) {
	// Prompt and grab user input.
	fputs(MENU_TEXT, stdout);
	char command = getchar();
	while (getchar() != '\n')
		; // clear remaining characters & newline.
	if (strchr("1234qQ", command))
		return command;
	else
		return '\0';
}

#ifdef NDEBUG

// Program starts here.
int main(void) {
	// Main command dispatch loop.
	while (1) {
		// Dispatch menu command.
		switch (fetchCommand()) {
			case '1':
				// CHECK macro.
				cmdCheck();
				break;
			case '2':
				// POLYNOMIAL macro.
				cmdPolynomial();
				break;
			case '3':
				// MEDIAN macro.
				cmdMedian();
				break;
			case '4':
				/* no break */
			case 'Q':
				/* no break */
			case 'q':
				// Quit.
				fputs("\nTerminating program.\n", stdout);
				exit(EXIT_SUCCESS);
				break;
			case '\0':
				/* no break */
			default:
				// Unsupported command.
				fputs("\nUnsupported command entered.\n", stdout);
				break;
		}
	}
}

#endif

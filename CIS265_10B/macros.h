/*************************************************************************
* Title: (CIS265_10B) Macros.
* File: macros.c
* Author: James Eli
* Date: 10/24/2017
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
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   10/24/2017: Initial release. JME
*************************************************************************/
#ifndef MACROS_H
#define MACROS_H

#include <float.h>
#include <math.h>

// Has the value 1 if both x and y fall between zero and n - 1, inclusive.
#define CHECK(x, y, n)  ((x >= 0 && x <= (n - 1)) && (y >= 0 && y <= (n - 1))) ? 1 : 0 

// Finds the median of x, y and z.
#define MEDIAN(x, y, z) ( (x - y) * (y - z) > -1 ? y : ((x - y) * (x - z) < 1 ? x : z) )

// Computes the polynomial 3x ^ 5 + 2x ^ 4 - 5x ^ 3 - x ^ 2 + 7x – 6.
#define POLYNOMIAL(x)  ( \
	3. * pow(x, 5.)      \
	+ 2. * pow(x, 4)     \
	- 5. * pow(x, 3.)    \
	- x * x              \
	+ 7. * x             \
	- 6.                 \
)

#endif

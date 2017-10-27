# Pima CC CIS265 Week #10 Project B

Write the following parameterized macros.
```C
  CHECK(x, y, n)
```
* Has the value 1 if both x and y fall between zero and n-1, inclusive.
```C
  MEDIAN(x, y, z)
```
* Finds the median of x, y and z.
```C
  POLYNOMIAL(x)
```
* Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x – 6.

Develop a user menu to select from the three functions (Check, Median, or Polynomial) and prompt for the inputs.

Includes a CUnit test file (test_macros.c) that performs unit tests upon the 3 macros. The tests are compiled only under the debug release. To function, this requires the CUnit test framework to be installed on per the instructions located here: https://sourceforge.net/projects/cunit/ 

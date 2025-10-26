Arbitrary Precision Calculator (C, DSA Project)

This project implements a C-based calculator that performs arithmetic operations on very large integers beyond the limits of standard data types. It uses Doubly Linked Lists to store and process each digit efficiently, enabling arbitrary precision arithmetic.

-> Features

Supports Addition, Subtraction, Multiplication, and Division of large integers.

Handles numbers of any size, unrestricted by int or long limits.

Implements custom data structures for digit storage and traversal.

Provides error handling for invalid inputs and edge cases.

Modular design with separate C files for each operation.

-> Data Structure Used

Doubly Linked List (DLL)
Each node stores a single digit, and bidirectional traversal allows easy implementation of arithmetic from least significant to most significant digits.

-> Files Overview

main.c – Handles user input and operation selection

addition.c, subtraction.c, multiplication.c, division.c – Implement arithmetic logic

digtolist.c – Converts input numbers into digit-based linked lists

print_list.c – Prints results in readable format 

apc.h – Header file containing function declarations and structure definitions

-> Compilation & Execution

To compile and run the program:

gcc*.c

Example Usage

Input:
./a.out 987654321987654321 + 123456789123456789

Output:
Result: 1111111111111111110



apc.h – Header file containing function declarati

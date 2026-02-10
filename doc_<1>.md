### <p align="center"> INTRODUCTION </p>

This program serves as a validator for mathematical expressions. It specifically checks if the parentheses, square brackets, and curly braces are properly opened and closed in the correct order using a stack.

---

### <p align="center"> DATA STRUCTURE USED </p>

The logic is built upon a Stack implemented through a C structure. This allows the program to "remember" opening brackets and match them with closing ones encountered later.

top: An integer representing the index of the current element.

collection[100]: An array used to store the characters of the opening brackets.

---

### <p align="center"> FUNCTIONS USED </p>

push(struct BracketStack *s, char value)
Increments the top pointer and stores the character in the array. This is called whenever an opening bracket is detected in the input string.

pop(struct BracketStack *s)
Retrieves the most recent opening bracket from the stack and decrements the top pointer. It returns a null character if the stack is already empty.

verifyBalance(char *str)
This is the core algorithm. It scans the input expression, pushes opening symbols to the stack, and uses the pop function to verify that every closing symbol has a valid partner.

---

### <p align="center"> WORKING ALGORITHM </p>

The expression is scanned from the first character to the last.

Every time an opening bracket ( , { , or [ is found, it is pushed to the stack.

Every time a closing bracket ) , } , or ] is found, the stack is popped.

If the popped item does not match the closing bracket, the process stops and flags the expression as unbalanced.

Finally, if the stack is empty after the scan, the expression is balanced.

---

###  <p align="center"> SAMPLE OUTPUT </p>

Example 1: Enter mathematical expression: a+(b-c)*(d

The expression is not balanced


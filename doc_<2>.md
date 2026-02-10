### <p align="center"> INTRODUCTION </p>

This program converts a standard mathematical infix expression (e.g., A+B) into a postfix expression (e.g., AB+) and subsequently evaluates the numerical result. This process is essential for computer systems to calculate expressions without parentheses ambiguity.

---

### <p align="center"> DATA STRUCTURE USED </p>

The implementation relies on a Stack data structure contained within a structure:

top: Tracks the index of the highest element in the stack.

items[100]: An array used to store operator characters during conversion and floating-point numbers during the evaluation phase.

---

### <p align="center"> FUNCTIONS USED </p>

push(struct CalcStack *s, float val)
Adds a value to the top of the stack. It handles both characters (for operators) and floats (for operands) by utilizing type casting.

pop(struct CalcStack *s)
Removes and returns the top element of the stack. It returns 0 if an underflow is detected.

getPrecedence(char op)
Assigns a numerical rank to operators to determine the order of operations: Exponents (3), Multiplication/Division (2), and Addition/Subtraction (1).

infixToPostfix(char* infix, char* postfix)
Implements the Shunting-yard algorithm to reorder the expression. It uses the stack to temporarily hold operators until their precedence allows them to be added to the output.

---

### <p align="center"> WORKING ALGORITHM </p>

Conversion Phase: The infix string is scanned. Operands are added to the output immediately. Operators are pushed to the stack based on their precedence relative to the operator already at the top.

Parentheses Handling: Opening brackets are pushed. Closing brackets trigger popping until the corresponding opening bracket is found.

Evaluation Phase: The postfix string is scanned. Numbers are pushed to the stack. When an operator is encountered, the top two numbers are popped, the operation is performed, and the result is pushed back.

---

### <p align="center"> SAMPLE OUTPUT </p>

Input Expression: 2+5-9*2/5^6-2-5

Postfix Result: 25+92*56^/-2-5-

Evaluation Result: -2.00

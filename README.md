![image](https://github.com/AndreyMustafin2001/Calculator/assets/150649500/67f036c0-ec1e-49d8-9bd6-c46df43e9f33)
# Simple Qt Calculator

This project is a simple calculator implemented in C++ using the Qt framework. The calculator supports basic arithmetic operations: addition, subtraction, multiplication, and division.

## Method Descriptions

### void Clear();

The `Clear()` method is used to clear the input field of the calculator. When called, this method deletes the last character in the input string.

### bool lastCheck();

The `lastCheck()` method checks the last character in the input string. If the last character is a digit, the method returns `true`; otherwise, it returns `false`. This is used to prevent entering two operators in a row.

### void addSymbol(QChar c);

The `addSymbol(QChar c)` method adds the symbol `c` to the input string of the calculator. If the last character in the string is a digit or `lastCheck()` returns `true`, the symbol is appended to the string; otherwise, the last character is replaced with the new one.

### void OnEq();

The `OnEq()` method performs the calculation of the arithmetic expression entered by the user in the calculator's input string and displays the result in the same input string. The algorithm of the method is as follows:

1. Retrieve the string from the input field.
2. Perform arithmetic calculations. The expression is split into numbers and operators, and then calculated according to the operator precedence.
3. Display the result of the calculations in the input field.

The calculator works only with integers. Floating-point numbers are not supported.

## Usage

1. Enter numbers and operations using the buttons on the calculator or from the keyboard.
2. Press the "=" button to perform the operation.
3. Press the "Clear" button to clear the input field.

## How to Run

1. Make sure you have Qt installed along with its Qt Creator development environment.
2. Open the project in Qt Creator.
3. Build and run the project.

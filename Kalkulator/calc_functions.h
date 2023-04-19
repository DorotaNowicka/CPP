/******************************************************************************
Calculator. Include directive.
Four possible operation: +, -, *, /.
Communication with program by terminal.
Author: Dorota Nowicka, 15.03.2020
*******************************************************************************/
#ifndef calc_functions_h
#define calc_functions_h

//Print given equation
void printOperation(double number1, char char1, double number2);

//Calculate result
double calculate(double number1, char operat_sign, double number2);

//Choosing operation
char inputOpSign();

//Input numbers to calculate
double inputNumber();

#endif
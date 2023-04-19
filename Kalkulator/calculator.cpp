/******************************************************************************
Calculator. Main function.
Four possible operation: +, -, *, /. 
Communication with program by terminal.
Author: Dorota Nowicka, 15.03.2020
*******************************************************************************/
#include <iostream>
#include <cmath>
#include "calc_functions.h"
using namespace std;

int main()
{
    double number1, number2;
    char op_sign;
    //communication with user
    cout << "CALCULATOR. Enter the first number: ";
    number1 = inputNumber();
    op_sign = inputOpSign();
    cout << "Enter the second number: ";
    number2 = inputNumber();

    printOperation(number1, op_sign, number2);
    cout << calculate(number1, op_sign, number2) << endl;
    return 0;
}

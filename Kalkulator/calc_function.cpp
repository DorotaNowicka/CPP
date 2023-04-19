/******************************************************************************
Calculator. Calculator functions:
- printOperation,
- calculate,
- inputOpSign,
- inputNumber
Four possible operation: +, -, *, /.
Communication with program by terminal.
Author: Dorota Nowicka, 15.03.2020
*******************************************************************************/
#include <iostream>
#include "calc_functions.h"

using namespace std;

void printOperation(double number1, char char1, double number2)
{
    cout << number1 << " " << char1 << " " << number2 << " = ";
}

double calculate(double number1, char operat_sign, double number2)
{
    if (operat_sign == '+')
    {
        return number1 + number2;
    }
    else if (operat_sign == '-')
    {
        return number1 - number2;
    }
    else if (operat_sign == '*')
    {
        return number1 * number2;
    }
    else if (operat_sign == '/')
    {
        return number1 / number2;
    }
}

char inputOpSign()
{
    char op_sign;
    cout << "Choose type of operatotion: ";
    cin >> op_sign;
    if (!(op_sign == '+' or op_sign == '-' or op_sign == '*' or op_sign == '/'))
    {
        cout << "There is no such operation. Use {+,-,*,/}." << endl;
        inputOpSign();
    }
    else
    {
        return op_sign;
    }
}

double inputNumber()
{
    double number;
    while (!(cin >> number)) {
        cout << "It isn't number! Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<char>::max(), '\n');
    }
    return number;
}
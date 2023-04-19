#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef statistic_functions_h
#define statistic_functions_h

double average(vector<double> v);

double deviation(vector<double> v);

//Returns True if any of numbers in vector is negative.
bool areNegative(vector<double> v);

//If areNegative(v) == True, prints statement and returns -1.
double geometricAverage(vector<double> v);

double median(vector<double> v);

#endif
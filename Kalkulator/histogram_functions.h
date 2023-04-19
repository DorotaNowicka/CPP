
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef histogram_functions_h
#define histogram_functions_h

//Creates file "histogram.txt" with histogram from data in vector w in range from min to max.
void histogram(vector<double> w, double max, double min = 0, double step = 1.0, int accuracy = 4);

//Finds the lowest number in vector.
double defaultMin(vector<double> v);

//Finds the biggest number in vector.
double defaultMax(vector<double> v);

//Calculates step deviding range from defaultMin(v) to defaltMax(v) to by 10.
double defaultStep(vector<double> v);

//Prints statistics and histogram of statistics in file "statistics.txt"
void print_statistic(vector<double> v);

#endif
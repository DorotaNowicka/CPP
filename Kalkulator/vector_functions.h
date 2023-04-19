
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef vector_functions_h
#define vector_functions_h

//Creates vector of data from datafile d.
vector<double> importData(string d);

void printVec(vector<double> v);

vector<double> bubbleSort(vector<double> v);

#endif
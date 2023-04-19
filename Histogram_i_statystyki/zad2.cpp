/*
Program to create histogram from data and to calculate statistic functions:
-average
-deviation
-geometric average
-median.
Program import data from file which name is inputed by user and save results
in files "histogram.txt" and "statistics.txt".
Author: Dorota Nowicka, 23.03.2020.
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include "vector_functions.h"
#include "statistic_functions.h"
#include "histogram_functions.h"
using namespace std;



int main()
{
    //upload data
    vector<double> vec;
    string datafilename;
    cout << "STATISTICS." << endl;
    cout << "Input name of file with numeric data: "; 
    cin >> datafilename;
    vec = importData(datafilename);

    //creating histogram and statistics
    histogram(vec, defaultMax(vec), defaultMin(vec));
    print_statistic(vec);

    // printing statistics on screen
    cout << "Average = " << average(vec) << endl;
    cout << "Deviation = " << deviation(vec) << endl;
    if(areNegative(vec)==0){
        cout << "Geometric average = " << geometricAverage(vec) << endl;
    }
    else{
        cout << "Geometric average wasn't calculated, due to negatives numbers, so it will be show as -1."<< endl;;
    }
    cout << "Median = " << median(vec) << endl;
    cout << "Histogram saved in file histogram.txt." << endl;
    cout << "Statistics and histogram of statistics saved in file statistics.txt." << endl;

    return 0;
}

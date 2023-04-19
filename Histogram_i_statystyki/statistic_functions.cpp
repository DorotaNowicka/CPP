#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include "vector_functions.h"
#include "statistic_functions.h"
using namespace std;

double average(vector<double> v)
{
    double sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum / v.size();
}

double deviation(vector<double> v)
{
    double sum = 0;
    double averag = average(v);
    for (int i = 0; i < v.size(); i++)
    {
        sum += (v[i] - averag) * (v[i] - averag);
    }
    return sqrt(sum / v.size());
}

bool areNegative(vector<double> v){
    bool areNegative = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i]<0){
            areNegative = 1;
        }
    }
    return areNegative;
}

double geometricAverage(vector<double> v)
{
    if(areNegative(v) == 1){
        return -1;
    }
    else{
        double product = 1;
        for (int i = 0; i < v.size(); i++)
        {
            product = product * v[i];
        }

        return pow(product, 1.0 / double(v.size()));
    }
}


double median(vector<double> v)
{
    vector<double> w = bubbleSort(v);
    if (v.size() % 2 == 0)
    {
        if (v.size() < 2)
        {
            return v[0];
        }
        else
        {
            int index = w.size() / 2 - 1;
            return (w[index] + w[index + 1]) / 2.0;
        }
    }
    else
    {
        return w[v.size() / 2];
    }
}

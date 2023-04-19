#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include "vector_functions.h"
using namespace std;


vector<double> importData(string d)
{
    vector<double> v;
    ifstream file;
    file.open(d);
    double x;

    if (file.good())
    {   
        while (!file.eof())
        {   
            if (!(file >> x))
            {
                continue;
            }
            else{
                v.push_back(x);
            }
        }
        file.close();
    }
    else{
        cout << "There is no such file. Uploading data from defaultdata.txt." << endl;
        return importData("defaultdata.txt");
    }
    
    return v;

}

void printVec(vector<double> v)
{
    cout << "{";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i < v.size() - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

vector<double> bubbleSort(vector<double> v)
{
    int n = v.size();
    while (n > 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                double temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
        n = n - 1;
    }
    return v;
}
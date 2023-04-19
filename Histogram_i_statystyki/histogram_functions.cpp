#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include "vector_functions.h"
#include "statistic_functions.h"
using namespace std;

void histogram(vector<double> w, double max, double min = 0, double step = 1.0, int accuracy = 4)
{
    vector<double> v = bubbleSort(w);
    double indexMin = 0;
    double sectionMax = min + step;
    double sectionNumber = min;
    int maxAmount = 0;
    ofstream saveFile;
    saveFile.open("histogram.txt");
    if (saveFile.good())
    {
        saveFile << "It's horizontal histagram of uploaded data.\n\nrange" << endl;
        while (sectionNumber <= max)
        {
            int amount = 0;
            saveFile << setw(accuracy) << left << sectionNumber;
            for (int i = indexMin; i < v.size(); i++)
            {
                if (v[i] < sectionMax)
                {
                    saveFile << setw(3) << left << "X";
                    indexMin = i + 1;
                    amount++;
                }
                else if (v[i] > sectionMax)
                {
                    break;
                }
            }
            if (amount > maxAmount)
            {
                maxAmount = amount;
            }
            saveFile << endl;
            sectionMax += step;
            sectionNumber += step;
        }

        saveFile << setw(accuracy) << " ";
        for (int i = 1; i <= maxAmount; i++)
        {
            saveFile << setw(3) << left << i;
        }
        saveFile << endl;
        saveFile << setw(accuracy + 2 * maxAmount) << internal << "amount" << endl;
        saveFile.close();
    }
    else
    {
        cout << "File doesn't exist\n";
    }
}

double defaultMin(vector<double> v){
    v = bubbleSort(v);
    return v[0];
}

double defaultMax(vector<double> v)
{
    v = bubbleSort(v);
    return v[v.size()-1];
}

double defaultStep(vector<double> v){
    return (defaultMax(v)-defaultMin(v))/10;
}

void print_statistic(vector<double> v)
{
    vector<double> stat;
    stat.push_back(average(v));
    stat.push_back(deviation(v));
    stat.push_back(geometricAverage(v));
    stat.push_back(median(v));
    vector<double> statsort = bubbleSort(stat);
    int min = int(statsort[0]);
    int max = int(statsort[3]) + 1;
    double step = double(max - min) / 10.0;
    double actual = max;

    ofstream saveFile;
    saveFile.open("statistics.txt");
    if (saveFile.good())
    {
        saveFile << "Statistic of data from uploaded data." << '\n'
                 << endl;
        saveFile << "Average = " << average(v) << endl;
        saveFile << "Deviation = " << deviation(v) << endl;
        saveFile << "Geometric average = " << geometricAverage(v) << endl;
        saveFile << "Median = " << median(v) << endl
                 << endl;

        while (actual > min)
        {
            saveFile.precision(1);
            saveFile << fixed;
            saveFile << setw(5) << left << actual - step;
            for (int i = 0; i < 4; i++)
            {
                if (stat[i] < actual & stat[i] >= actual - step)
                {
                    saveFile << "X ";
                }
                else
                {
                    saveFile << "  ";
                }
            }
            saveFile << endl;
            actual = actual - step;
        }
        saveFile << "     A D G M" << endl;
        saveFile.close();
    }
    else
    {
        cout << "File doesn't exist\n";
    }
}

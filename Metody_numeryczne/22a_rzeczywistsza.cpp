#include <iostream>
#include <fstream>
#include<cmath>
//pozwala na ustalenie dokładności
#include <iomanip>
#include <cstdlib>
#include<vector>
#include <ctime>
#include "gnuplot_i.hpp"
using namespace std;

double dxdt(double K, double k, double r, double D, double x, double y){
  return x*(r*(1-x/K)-k*y/(x+D));
}

double dydt(double s, double h, double x, double y){
  return s*y*(1-h*y/x);
}

double deltax(double K, double k, double r, double D, double x, double y, double dt){
  return dt*dxdt(K,k,r,D ,x+dxdt(K, k, r, D, x, y)*dt/2.,y);
}

double deltay(double s, double h, double x, double y, double dt){
  return dt*dydt(s,h,x,y+dydt(s,h,x,y)*dt/2.);
}



int main (int argc, char *argv[])
{
    double K   = 1;
    double r = 0.5;
    double k   = 1.5;
    double D = 2;
    double s   = 2;
    double h = 0.5;
    double x0 = 1.;
    double y0 = 0.5;
    double tmax   = 40.;
    double dt   = 0.1;

    vector<double> t_data = { 0. } ,
                   x_data = { x0 } ,
                   y_data = { y0 } ;

double x= x0; double y=y0;


    for (double t = dt ; t <= tmax ; t += dt){
      double xpop = x;
      double ypop = y;

      x = x + deltax(K, k, r, D, xpop, ypop, dt);
      y = y + deltay(s, h, xpop, ypop, dt);

      t_data.push_back ( t );
      x_data.push_back ( x );
      y_data.push_back ( y );

      cout << t << '\t' << x << '\t' << y  << endl;

    }

double xmin=0, xmax=4.5, ymin=0, ymax=4.5;




        Gnuplot g1 ("lines");
        g1.set_grid ();
        g1.set_xrange ( -dt , tmax + dt );
        g1.set_yrange ( xmin, xmax );
        g1.set_pointsize (1);
        g1.set_xlabel ("t").set_ylabel ("x(t))");
        g1.set_style ("lines") .plot_xy (t_data, x_data, "x(t)") ;
        g1.set_style ("lines")  .plot_xy (t_data, y_data, "y(t)") ;



    //  g1.set_yrange ( -2. , 2. );
    //  g1.set_style ("lines") .plot_xy (t_data, N_deviation, "Deviation(t)") ;

        cin.ignore();

        return 0;


}

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

double dxdt(double a, double b, double e, double g, double x, double y){
  return (a-b*y)*x-e*x-g*x*x;
}

double dydt(double c, double d, double f, double h, double x, double y){
  return (c*x-d)*y-f*y-h*y*y;
}

double deltax(double a, double b, double e, double g, double x, double y, double dt){
  return dt*dxdt(a,b,e,g,x+dxdt(a,b,e,g,x,y)*dt/2.,y);
}

double deltay(double c, double d,double f, double h, double x, double y, double dt){
  return dt*dydt(c,d,f, h,x,y+dydt(c,d,f,h,x,y)*dt/2.);
}



int main (int argc, char *argv[])
{
    double a   = 1;
    double b   = 1.;
    double c = 0.5;
    double d   = 0.5;
    double e = 0.45;
    double f = 0.25;
    double g=0.1;
    double h=0.3;

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

      x = x + deltax(a, b, e, g, xpop, ypop, dt);
      y = y + deltay(c, d, f, h, xpop, ypop, dt);

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

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/***********************************************************************/
// zadana funkcja -- do interpolacji

double dana_f(double xx)
{
  double wynik;
  double a=0.2;
  wynik = 1/(1+10*(xx-a)*(xx-a));

  return wynik;
}

/***********************************************************************/
// Metoda Lagrange'a
//
// Funkcja zwraca wynik interpolacji wielomianowej w p-cie xx
// Wielomian interpolacyjny zadany jest na punktach (x,y)
// zapisanywch w tablicach: 
//   x[] -- siatka punktow do interppolacji
//   y[] -- wartosc f-cji w tych punktach


double lagrint(double xx, double * x, double * y, int npkt) 
{   
  double suma = 0 , iloczyn;
  
  for (int i=0; i < npkt ; i++) 
  {
    iloczyn = 1;
    for (int j=0; j < npkt ; j++) 
	{
	  if (j != i)
      {
	    iloczyn*=(xx-x[j])/(x[i]-x[j]);
      }
	}
    suma+=iloczyn*y[i];
  }

  return suma;
}

/***********************************************************************/
//Program: interpolacja Lagrange'a

int main (int argc, char*argv[]) 
{
  long int npkt=atoi(argv[1]); //l. punktow wezlowych 
  double xmin=-1, xmax=1; //zakres interpolacji
  double odst=(xmax-xmin)/(npkt-1); //odstep pomiedzy punktami 
  double x[npkt], y[npkt]; //tablica ze wspolrzednymi punktow 
  for(int i=0;i<npkt;i++) //wypelnianie tablicy wartosciami 
    {
      x[i]=xmin+odst*i;
      y[i]=dana_f(x[i]);
    }
    
  for(int i=0;i<npkt;i++)
    {
	  cout << x[i] << " " << y[i] << " " << lagrint(x[i],x,y,npkt) << endl; //sprawdzanie poprawnosci interpolacji w pktach wezlowych 
	}
	
  //wykres:
  
  double nplot=1000;
  double xp=-1, xk=1;
  odst=(xk-xp)/(nplot-1);
  double x0;
  double y0;
  
  ofstream fo0("fn_val.dat"); //plik z rzeczywistymi wartosciami 
  ofstream fo("output.dat"); //plik z wartosciami przyblizonymi 
  for(double i=0;i<nplot;i++)
    {
      x0 = xp+odst*i;
      y0 = lagrint(x0,x,y,npkt);
      fo << x0 << " " << y0 << endl;
      fo0 << x0 << " " << dana_f(x0) << endl;
    }
  fo.close();
  fo0.close();
  
  ofstream fo1("points.dat"); //plik z punktami wezlowymi 
  for(int i=0;i<npkt;i++)
    {
      fo1 << x[i] << " " << y[i] << endl;
    }
  fo1.close();
    
  ofstream wykres("wykres.gp"); //tworzymy plik - skrypt Gnuplota
  wykres << "plot \"fn_val.dat\" w l, \"output.dat\" w l, \"points.dat\" w p"; //wpisujemy tresc skryptu - wykres danych z "simul.dat"
  wykres.close(); //zamykamy plik - skrypt
  system("gnuplot -persist wykres.gp"); //wykonujemy skrypt w Gnuplocie za pomoca komendy system()

  return 0;
}

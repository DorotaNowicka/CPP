// g++ file.cxx -lfftw3 -lm

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "/work/programs/fftw/include/fftw3.h"
//komiplacja /work/programs/fftw/lib/libfftw3.a
using namespace std;

int main()
{
	int M=16;
	int N = 1024, n = N/2 + 1;
	double *in;
	fftw_complex *out;
	fftw_plan p, p2;

	in = (double*) fftw_malloc(sizeof(double) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    p2 = fftw_plan_dft_c2r_1d(N, out, in, FFTW_ESTIMATE);

		srandom(time(0));
		for(int i=0; i<N; i++){
		in[i]=-1 + (2)*(double) rand()/RAND_MAX;
		}


    fftw_execute(p); /* repeat as needed */

		ofstream of("output1.dat");
		for(int i = 0; i < N; i++){
		of << i << " " << in[i]  << endl;
		}
		of.close();

	for(int i = M+1; i < N; i++){
		out[0][i]=0;
		out[1][i]=0;
	}

	fftw_execute(p2);


	ofstream fo("output.dat");
	for(int i = 0; i < N; i++)
	fo << i << " " << in[i]/N  << endl;

fo.close();

    fftw_destroy_plan(p);
    fftw_destroy_plan(p2);
    fftw_free(in); fftw_free(out);

    ofstream wykres("wykres.gp"); //tworzymy plik - skrypt Gnuplota
    //wykres << "set logscale" << endl;
	wykres << "plot \"output1.dat\" u 1:2 w l, \"output.dat\" u 1:2 w l lw 3"; //wpisujemy tresc skryptu - wykres danych z "output.dat"
	wykres.close(); //zamykamy plik - skrypt
	system("gnuplot -persist wykres.gp"); //wykonujemy skrypt w Gnuplocie za pomoca komendy system()

	return 0;
}

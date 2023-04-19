#include<iostream>
using namespace std;

int main()
{
	int N = 6;
	int i;
	int sum;
	for ( i=0; i<N ; i++)
	{
		sum += i * i;
	}

	cout << "suma pierwszych " << N << " liczb naturalnych wynosi " << sum << endl;
	return 0;
}



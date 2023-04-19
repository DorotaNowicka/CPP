#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

//funkcja wypisujaca elementy vectora na ekran
void print_vec(vector<int> v){
	cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	
	}
	cout << "}" << endl;
}


int main()
{	srandom(time(0));
	int N = 10;
	vector<int> v1;
	for (int i = 0; i < N; ++i)
	{
		v1.push_back(rand());

	}


	vector<int> v2(N);
	for (int i = 0; i < N; ++i)
	{
		v2[i]=i*i;
	}

	cout << "v1: ";
	print_vec(v1);
	cout << "v2: ";
	print_vec(v2);



	return 0;
}

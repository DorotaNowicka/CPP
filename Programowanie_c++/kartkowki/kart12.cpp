#include<iostream>
using namespace std;
class Kolo{
    //...
    public:
	double xS;
	double yS;
	double RS;
public:       
 void utworz(double x1, double y1, double R1){
            xS=x1;
            yS=y1;
            RS=R1;
        }
        bool jest_wewnatrz(double x, double y){
            return (((xS-x)*(xS-x)+(yS-y)*(yS-y))<=(RS*RS));
        }
};

int main(){
    Kolo kolo;
    kolo.utworz(1,1,1);
    if(kolo.jest_wewnatrz(1.5,3)==true){
        cout << "Ten punkt lezy wewnatrz kola.\n";
    }
    else{
        cout << "Ten punkt nie lezy wewnatrz kola.\n";
    }
}


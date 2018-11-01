//hm2-simpleQuantiles.cpp
//liyixi
//2018.10.6

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print_vector(vector<double>&input){
    for (int i = 0; i<input.size();i++){
        cout<<input[i]<<" ";
    }
}

void quicksort(vector<double>&input, int p, int r){
    if (p<r){
        double piv = input[r];
        int i = p-1;
        double tmp;
        for (int j=p; j<r; j++){
            if (input[j]<piv){
                i++;
                tmp = input[j];
                input[j]=input[i];
                input[i]=tmp;
            }
        }
        input[r]=input[i+1];
        input[i+1]=piv;
        quicksort(input, p, i);
        quicksort(input, i+2, r);
    }
}

int main(int argc, char const *argv[])
{
	vector<double> Q;
	vector<double> N;
	double number;
	vector<double> O;
	for(int i =1; i<argc; i++){
		Q.push_back(atof(argv[i]));
	}

	while(cin >> number){
		N.push_back(number);
	}

	
	quicksort(N,0,int(N.size())-1);

    for (int i=0; i<Q.size();i++){
        double n = N.size();
        int pt = n*Q[i];
        if (n*Q[i]>0 and (n*Q[i]-pt == 0)){
            O.push_back(N[pt-1]);
        }
        else{
            O.push_back(N[pt]);
        }
    }
    print_vector(O);
    cout<<endl;

	return 0;
}

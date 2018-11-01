// hm1-momentStats  
// 2018.9.15  
// Yixi Li 

#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class momentStats{
public:
	vector<double> argv;
	int n;
	double tpmean,sumvar,std,cubevar,fourvar;

	void Compute(){
	tpmean = argv[0];
	sumvar = 0.0;
	std = 0.0;
	cubevar = 0.0;
	fourvar = 0.0;
	for(int i=2; i<=n; i++){
		//sumvar = sumvar + (i-1)/i * pow((argv[i-1] - tpmean),2);
		tpmean = tpmean + (argv[i-1]  - tpmean)/i;
	}
	for(int i=1; i<=n; i++){
			sumvar = sumvar + pow((argv[i-1]  - tpmean),2);
		}
	std = sqrt(sumvar/(n-1));
	for(int i=1; i<=n; i++){
			cubevar = cubevar + pow((argv[i-1]  - tpmean)/std,3);
			fourvar = fourvar + pow((argv[i-1]  - tpmean)/std,4);
		}
}

	double Mean(){
		return tpmean;
	}

	double Variance(){
		return sumvar/(n-1);
	}	
	
	double Skewness(){
			return cubevar/n;
		}

	double Kurtosis(){
			return fourvar/n-3;
		}
		
};

int main(int argc, char* argv[]){
	vector<double> list;

	int n = argc-1;
	for(int i=1; i<=n; i++){
		list.push_back(atof(argv[i]));
	}
		
	momentStats ms;
	ms.argv = list;
	ms.n = n;
	//cout << ms.n << "\n";

	ms.Compute();
	double mean = ms.Mean();
	double var = ms.Variance();
	cout << setprecision (8) << mean << "\n";
	cout << setprecision (8) << var << "\n";
	if (var>0){
		double skew = ms.Skewness();
		double kurt = ms.Kurtosis();
		cout << setprecision (8) << skew << "\n";
		cout << setprecision (8) << kurt << "\n";
	}
	
return 0;
}


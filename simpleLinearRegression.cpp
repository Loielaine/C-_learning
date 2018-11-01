// hm1-simpleLinearRegression 
// 2018.9.18  
// Yixi Li 

#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class simpleLinearRegression{
public:
	vector<double> v;
	int n;
	double xmean,ymean,sumvarxx,sumvarxy,beta0,beta1;

	void Compute(){
	xmean = double(n*(n+1))/double((2*n*n));
	//cout << xmean << "\n";
	ymean = v[0]; 
	sumvarxx = 0.0;
	sumvarxy = 0.0;
	for(int i=2; i<=n; i++){
		ymean = ymean + (v[i-1]  - ymean)/i;
	}
	//cout << ymean << "\n";
	//cout << "n:" << n << "\n";
	for(int i=1; i<=n; i++){
		    //cout << "i/n: " << double(i/n) << " v: " << v[i-1] <<"\n";
			sumvarxx = sumvarxx + pow((double(i)/double(n) - xmean),2);
			sumvarxy = sumvarxy + (double(i)/double(n) - xmean) * (v[i-1] - ymean);
			//cout << "sumxy: " << sumvarxy << " sumxx: " << sumvarxx <<"\n";
		}	
}

	
	double Beta1(){	
		//cout << "sumxy: " << sumvarxy << " sumxx: " << sumvarxx <<"\n";
 		beta1 = sumvarxy/sumvarxx;
 		//cout << beta1 << "\n";
 		return sumvarxy/sumvarxx;
	}

	double Beta0(){
		beta0 = ymean - beta1 * xmean;
		return beta0;
	}
	
};

int main(int argc, char* argv[]){
	vector<double> Y;

	int n = argc-1;
	//cout << argv[0] << "\n";
	for(int i=1; i<=n; i++){
		Y.push_back(atof(argv[i]));
	}

	// print vector
	/*
	for(std::vector<double>::const_iterator i = Y.begin(); i != Y.end(); ++i){
		cout << *i << ' ';
	}
	*/
	
	simpleLinearRegression slr;
	slr.v = Y;
	slr.n = n;
	
	slr.Compute();
	double beta1 = slr.Beta1();
	double beta0 = slr.Beta0();

	cout << setprecision (8) << beta0 << " " << beta1 << "\n";

return 0;
}



// hm1-floatBinaryRep
// 2018.9.25
// Yixi Li


#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> reverse(vector<int> str){
        vector<int> str_reverse;
        int n = str.size();
        for(int i = 0; i<n; i++){
                str_reverse.push_back(str[n-1-i]);
        }
        return str_reverse;
}

class floatBinaryRep{
public:
	int sign;
	double input;
	double exp;
	int exp_real;
	vector<int> significand;
	vector<int> exponent_real;

	void Sign(){
        if(input<0){
           sign = 1;
           input = -input;
        }
        else{
            sign = 0;
        }
	}

	void BiggestBin(){
		exp =1024;
		int k = 0;
	    while (k == 0) {
	        exp--;
	        if (input >= pow(2, exp)){
	            k = 1;
	        }
	        else{
	            k = 0;
	        }
	    }
    	exp_real = exp+127;
    	//cout << "exp_real: " << exp_real << endl;
	}

	void Significand(){
		int t = 25;
    	int bin = 0;
	    	while (t>0) {
	       		 t--;
	            if (input >= pow(2, exp)){
	                bin = 1;
	            }
	            else{
	                bin = 0;
	            }
	            input = input - double(bin)*pow(2, exp);
	            significand.push_back(bin);
	            exp--;
	        }
	        
		    if (significand[24]==1){
		        int q = 23;
		        if (significand[q]==0){
		            significand[q] = significand[q]+1;
		        }
		        else{
		            while (significand[q-1]==1) {
		                significand[q] = significand[q]-1;
		                q--;
		            }
		            significand[q] = 0;
		            significand[q-1] = significand[q-1]+1;
		        }
		    }
    
	}

	void Exponent(){
		int exp_size = 8;
		vector<int> exponent;
        //cout << "exp: " << exp_real << "\n";
        while(exp_real !=0 or exp_size>0){
              int j = exp_real%2;
              exp_real = (exp_real - j)/2;
              exponent.push_back(j);
              exp_size--;
              //cout << j << "\n";
        }
       exponent_real  = reverse(exponent);
	}

	void Print(){
		cout << sign;
		for (int i = 0; i<8; i++) {
        cout << exponent_real[i];
    	}
    	for(int i=1; i<significand.size()-1;i++){
        cout << significand[i];
    	}
    
	    cout << endl;
	  	cout << (input==0) << endl;  
	}

	};

	int main(int argc, char* argv[]){
        double v;
        v = atof(argv[1]);

        floatBinaryRep flb;
        flb.input = v;
        flb.Sign();
        flb.BiggestBin();
        flb.Significand();
        flb.Exponent();
        flb.Print();
return 0;
}


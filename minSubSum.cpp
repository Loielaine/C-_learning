//hm2-minSubSum.cpp
//liyixi
//2018.9.27

#include<iostream>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<climits> 

using namespace std;

class minSubSum {
public:
	vector<int> N;

	minSubSum(vector<int> Ni){
		N=Ni;
	}
	

	int Subsequence(){
		int min_ending_here, min_so_far;
		min_ending_here = min_so_far = N[0];
    for(int x=1; x<N.size(); x++){
        min_ending_here = min(N[x], min_ending_here + N[x]);
        min_so_far = min(min_so_far, min_ending_here);
        //cout << "N[x]: " << N[x] << endl;
        //cout << "min_ending_here: " << min_ending_here << endl;
        //cout << "min_so_far: " << min_so_far << endl;
    }
    if(min_so_far>0){return 0;}
    else {return min_so_far;}
	}
};

int main(int argc, char const *argv[])
{

	vector<int> N;
	int sum;
	int number;
	while(cin >> number){
		N.push_back(number);
	}

	minSubSum mss(N);
	sum = mss.Subsequence();
	cout << sum << endl;

	return 0;
}
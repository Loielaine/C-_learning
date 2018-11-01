//hm3-matMult.cpp
//liyixi
//2018.10.16

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


void moveRowCol(vector<int>& a, vector<int>& v, int i){
	for (std::vector<int>::iterator it=a.begin()+i-1; it!=a.begin(); --it){
		v.push_back(*it);
	}
	for (std::vector<int>::iterator it=a.begin(); it!=a.end()-i+1; ++it){
		v.push_back(*it);
	}
  }


int main(int argc, char const *argv[])
{
	int k,i,j;
	cin >> k;
	cin >> i;
	cin >> j;
	
	vector<int> A;
	int input;
	while(cin >> input){
		A.push_back(input);
	}

	int n = A.size();

	vector<int> Ai;
	vector<int> AiUpdate(n,0);

	moveRowCol(A,Ai,i);

	
	//cout << "k: " << k << endl;
	//cout << "i: " << i << endl;
	//cout << "j: " << j << endl;
	
	
	while((k-1)>0){
		//cout << "k: " << k << endl;

		for(int p=0; p<n; p++){

			vector<int> tmpt;
			moveRowCol(A,tmpt,p+1);

			AiUpdate[p] = 0;
			/*
			for(int c=0; c<n; c++){
				cout<< tmpt[c] << " ";
			}
			cout << endl;
			*/
			//cout << "p: " << p << endl;
			//cout << "AiUpdate[p]: " << AiUpdate[p] << endl;
			for(int a=0; a<n; a++){
				AiUpdate[p] = AiUpdate[p] + Ai[a] * tmpt[a];
				//cout << "a: " << a << endl;
			}
			AiUpdate[p] = AiUpdate[p]%10000;
			//cout << "AiUpdate[p] after: " << AiUpdate[p] << endl;
			
		}
		Ai.assign(AiUpdate.begin(),AiUpdate.end());

		/*
	for(int c=0; c<n; c++){
				cout<< Ai[c] << " ";
			}
			cout << endl;
	*/

		k--;
	} 

	cout << Ai[j-1] << endl;
	return 0;
	
}




	
	


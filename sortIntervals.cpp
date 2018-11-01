//hm2-sortIntervals.cpp
//liyixi
//2018.10.6

#include<iostream>
#include<vector>
#include <math.h> 
#include <cstdlib>
#include <climits>

using namespace std;

/*
	vector<int> push(vector<int>& v, int l, int r){
		vector<int> target;
		for(int i =l; i<r; i++){
			target.push_back(v[i]);
		}
		return target;
	}



	void replace(vector<int>& l, vector<int>& u, vector<int>& s, int k, int i){
		L[k] = l[i];
		U[k] = u[i];
		seq[k] = s[i];
		i++;
	}
	*/


	void merge(vector<int>& L, vector<int>& U, vector<int>& seq, int p, int q, int r){
		vector<int> ll,lr,ul,ur,sl,sr;
	/*	
		ll = push(L,p,q);
		lr = push(L,q+1,r);
		ul = push(U,p,q);
		ur = push(U,q+1,r);
		sl = push(seq,p,q);
		sr = push(seq,q+1,r);
	  */

		for (int i=p; i<=q; i++){
	        ll.push_back(L[i]);
	        ul.push_back(U[i]);
	        sl.push_back(seq[i]);
    }
	    for (int i=q+1; i<=r; i++){
	        lr.push_back(L[i]);
	        ur.push_back(U[i]);
	        sr.push_back(seq[i]);
	    }

	    
	    ll.push_back(INT_MAX);
	    lr.push_back(INT_MAX);
	    ul.push_back(INT_MAX);
	    ur.push_back(INT_MAX);
	    sl.push_back(INT_MAX);
	    sr.push_back(INT_MAX);
			
		for(int k=p, i=0, j=0; k<=r; ++k){
			if(ll[i]==lr[j]){
				if(ul[i]<=ur[j]){
				L[k] = ll[i];
				U[k] = ul[i];
				seq[k] = sl[i];
				i++;
			}
				else{
					L[k] = lr[j];
					U[k] = ur[j];
					seq[k] = sr[j];
					j++;
				}
			}
			else if(ll[i]<lr[j]){
				L[k] = ll[i];
				U[k] = ul[i];
				seq[k] = sl[i];
				i++;
			}
			else{
				L[k] = lr[j];
				U[k] = ur[j];
				seq[k] = sr[j];
				j++;
			}

		}



/*
		for(int k=p, i=0, j=0; k<=r; ++k){
			if(ll[i]==lr[j]){
				if(ul[i]<=ur[j]){
				replace(ll,ul,sl,k,i);
			}
				else{
					replace(lr,ur,sr,k,j);
				}
			}
			else if(ll[i]<lr[j]){
				replace(ll,ul,sl,k,i);
			}
			else{
				replace(lr,ur,sr,k,j);
			}

		}
*/


	}

	void mergeSort(vector<int>& L, vector<int>& U, vector<int>& seq,int p, int r)
	{
		if(p<r){
			int q = (p+r)/2;
			mergeSort(L,U,seq,p,q);
			mergeSort(L,U,seq,q+1,r);
			merge(L,U,seq,p,q,r);
		}


}

	void printSeq(vector<int>& L, vector<int>& U, vector<int>& seq){
		for(int i=0; i<seq.size(); i++){
			cout << L[i] << " " << U[i]<< " ";
		}
		cout << endl;
		for(int i=0; i<seq.size(); i++){
			cout << seq[i] << " ";
		}
		cout << endl;

	}



int main(int argc, char const *argv[])
{
	vector<int> L;
	vector<int> U;
	vector<int> seq;
	int number;
	int i=0;
	while(cin >> number){
		i++;
		//cout << "i: " << i << endl;
		//cout << "n: " << number << endl;
		if(i%2==1){
			L.push_back(number);
			seq.push_back((i+1)/2);

		}
		else{
			U.push_back(number);
		}
	}
	int length = L.size()-1;
	mergeSort(L,U,seq,0,length);
	printSeq(L,U,seq);
	return 0;
}



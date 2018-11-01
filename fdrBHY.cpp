//hm3-fdrBHY.cpp
//liyixi
//2018.10.29

#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void merge(vector<double>&lower, vector<int>&index, int p, int q, int r);
void mergesort(vector<double>&lower, vector<int>&index, int p, int r);
void print(vector<double>&lower);

int main(int argc, char* argv[]){
    
    double alpha = atof(argv[1]);
    vector<int> index;
    vector<double> input;
    
    double value;
    int p = 1;
    while(cin>>value){
        input.push_back(value);
        index.push_back(p);
        p++;
    }
    
    double m = input.size();
    double sum = 0;
    for (double i=1;i<=m;i++){
        sum+=1/i;
    }
    double q = exp(log(alpha)-log(sum));
    
    mergesort(input, index, 0, input.size()-1);

    double i = m;

    while (i>0){
       
        if (input[i-1]<=q*(double(i)/m)){
            break;
        }
        i--;
    }
    
    for (int j=0; j<i; j++){
        cout<<index[j]<<" ";
    }
    if (i == 0){
        cout<<0;
    }
    cout<<endl;
}


void merge(vector<double>&lower, vector<int>&index, int p, int q, int r){
    vector<double> ll, lr, il, ir;
    for (int i=p; i<=q; i++){
        ll.push_back(lower[i]);
        il.push_back(index[i]);
    }
    for (int i=q+1; i<=r; i++){
        lr.push_back(lower[i]);
        ir.push_back(index[i]);
    }
    
    ll.push_back(INT_MAX);
    lr.push_back(INT_MAX);
    il.push_back(INT_MAX);
    ir.push_back(INT_MAX);
    
    for (int k=p, i=0, j=0; k<=r; k++){
        if (ll[i]<=lr[j]) {
            lower[k] = ll[i];
            index[k] = il[i];
            i++;
        }
        else {
            lower[k] = lr[j];
            index[k] = ir[j];
            j++;
        }
    }
}

void mergesort(vector<double>&lower, vector<int>&index, int p, int r){
    if (p<r){
        int q = (p+r)/2;
        mergesort(lower, index, p, q);
        mergesort(lower, index, q+1, r);
        merge(lower, index, p, q, r);
    }
}


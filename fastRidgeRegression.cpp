//hm3-fastRidgeRegression.cpp
//liyixi
//2018.10.28

#include <stdio.h>
#include "ReadMatrix615.h"

/*
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<boost/tokenizer.hpp>
#include<fstream>
#include<boost/lexical_cast.hpp>
#include<Eigen/Dense>
#include <stdio.h>

using namespace std;
using namespace boost;
using namespace Eigen;

template <class T>
Matrix<T,Dynamic, Dynamic> readFromFile(const char* fileName) {
      vector<T> temp; 
      ifstream ifs(fileName);
      if ( ! ifs.is_open() ) {
            cerr<< "Cannot open file" <<fileName<< endl;
            abort();
       }
       string line;
       char_separator<char> sep(", \t \"");
       typedef tokenizer<char_separator<char> > wsTokenizer;
       temp.clear();
       int nr=0, nc=0, nc_check = 0;
       while(getline(ifs, line) ) {
            if (line[0]=='#') continue;
             wsTokenizer t(line,sep);
             nc_check = 0;
             for(wsTokenizer::iterator i=t.begin(); i !=t.end(); ++i) {
                 temp.push_back(lexical_cast<T>(i->c_str()));
                 //temp.push_back(lexical_cast<T>(*i));
                 if (nr==0) ++nc;
                 ++nc_check;
              }
             
             if (nc != nc_check ) {
              cerr<<"The input file is not rectabgle at line "<<nr<<endl;
              abort();
        }
            ++nr;
        }
        
        Map<Matrix<T, Dynamic, Dynamic,RowMajor> > mf(&temp[0],nr,nc);
        return mf;
}
*/

int main(int argc, char *argv[]){
	
    MatrixXd X = readFromFile<double>(argv[1]);
    MatrixXd Y = readFromFile<double>(argv[2]);
    double lambda = atof(argv[3]);


	JacobiSVD<MatrixXd> svd(X,ComputeThinV | ComputeThinU);
	MatrixXd U = svd.matrixU();
	MatrixXd V = svd.matrixV();
  int p = svd.singularValues().rows();
  vector<double> sv;
  int i=0;
  while(i<p){
	sv.push_back(svd.singularValues()(i,0));
  i++;
  }

	/*cout << "Its singular values are:" << endl << svd.singularValues() << endl;
  for(int i=0;i<p;i++){
    cout<<sv[i]<<" ";
  }
  */

  MatrixXd id = MatrixXd::Identity(p,p);
	
  //vector<double> sv_inverse;
  for (int i=0; i<p; i++){
    id(i,i) = sv[i]/(pow(sv[i],2)+lambda);
    }
    //cout<<"V"<<V.rows()<<" "<<V.cols()<<endl;
    //cout<<"p"<<p<<endl;
    //cout<<"U"<<U.rows()<<" "<<U.cols()<<endl;
    //cout<<"Y"<<Y.size()<<endl;
    
    MatrixXd Beta = V * id * U.transpose() * Y;
    //cout << "Beta:" << Beta.rows() << "*" << Beta.cols();

    for (int i=0; i<Beta.rows(); i++){
        int out = floor(Beta(i,0));
        if ((double)Beta(i,0)-out>0.5){
            out++;
        }
        if (out!=0) {
            cout<<i+1<<" "<<out<<endl;
        }
    }
  
  }

    












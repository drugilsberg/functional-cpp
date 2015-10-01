#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){

    
  
  vector<int> test={1, 3, 34, 50};
  
  cout << "Test map..." << endl;
  vector<double> expectedMap={2, 6, 68, 100};
  function< double(int) > func= [] (const int & element){return 2.0*element;};   
  vector<double> output= Functional::map( test,  func );
  assert(expectedMap==output);
  cout << "passed!" << endl;
 
  return 0;

}

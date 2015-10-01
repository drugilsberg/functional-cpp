#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){
    
  cout << "Test fold..." << endl;
  vector<double> test={1.0, 1.2};     
  double expectedFold = 2.2;
  function< double(double,double)  > func= [](double  a, double  b){return a+b;};
  auto folded = Functional::foldLeft(test, func);  
  assert(expectedFold==folded);
  cout << "passed!" << endl;
  return 0;

}

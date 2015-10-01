#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){

  vector<double> test={1.0, 1.2, 2.0, 2.3, 3.0};
  function< bool(double) > func= [] (const double & element){return element<2.0;};
  vector<double> expectedFilter={ 1.0, 1.2};
  cout << "Test filter..." << endl;
  auto filtered = Functional::filter(test,func); 
  assert( expectedFilter==filtered);
  cout << "passed!" << endl;
  
  return 0;

}

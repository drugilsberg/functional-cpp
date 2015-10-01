#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){

    
  cout << "Test reduceByKey..." << endl;
  unordered_map<int, vector<double> > test={
      make_pair(1, vector<double>{1.0, 1.2}),      
      make_pair(2, vector<double>{2.0, 2.3}),      
      make_pair(3, vector<double>{3.0})      
  };
  unordered_map<int, double > expectedReduceByKey={
      make_pair(1, 2.2),      
      make_pair(2, 4.3),      
      make_pair(3, 3.0)      
  };
  function< double(double,double)  > func= [](double  a, double  b){return a+b;};
  auto reduced = Functional::reduceByKey(test, func);  
  assert(expectedReduceByKey==reduced);
  cout << "passed!" << endl;
 
  return 0;

}

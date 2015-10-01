#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){
   
  vector<double> test={1.0, 1.2, 2.0, 2.3, 3.0};
  function< int(double) > func= [] (const double & element){return (int)element;};
  unordered_multimap<int, double> expectedKeyBy={
      make_pair(1,1.0),
      make_pair(1,1.2),
      make_pair(2,2.0),
      make_pair(2,2.3),
      make_pair(3, 3.0)      
  };
  cout << "Test keyBy..." << endl;
  auto keyed = Functional::keyBy(test,func); 
  assert( expectedKeyBy==keyed);
  cout << "passed!" << endl;
  

  return 0;

}

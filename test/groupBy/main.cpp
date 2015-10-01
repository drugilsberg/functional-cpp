#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){
     
  vector<double> test={1.0, 1.2, 2.0, 2.3, 3.0};
  function< int(double) > func= [] (const double & element){return (int)element;};
  
  cout << "Test groupBy..." << endl;
  unordered_map<int, vector<double> > expectedGroupBy={
      make_pair(1, vector<double>{1.0, 1.2}),      
      make_pair(2, vector<double>{2.0, 2.3}),      
      make_pair(3, vector<double>{3.0})      
  };
  auto grouped = Functional::groupBy(test, func);  
  
  for( auto & kv : grouped ){
      sort(kv.second.begin(), kv.second.end());
  }  
  for( auto & kv : expectedGroupBy ){
      sort(kv.second.begin(), kv.second.end());
  }
  
  assert(expectedGroupBy==grouped);
  cout << "passed!" << endl;
  
  return 0;

}

#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){

    
  
  vector<int> test1={1, 3, 34, 50};
  vector<double> test2={1.0, 2.0, 3.0};

  cout << "Test zip..." << endl;
  vector< pair<int,double> > expectedZip={
      make_pair(1,1.0),
      make_pair(3,2.0),
      make_pair(34, 3.0)      
  };
  auto outputZip = Functional::zip(test1, test2);  
  assert( expectedZip==outputZip);
  cout << "passed!" << endl;

  return 0;

}

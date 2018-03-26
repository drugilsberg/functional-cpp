#include<iostream>
#include<vector>
#include<math.h>
#include "Functional.hpp"

#include<cassert>

using namespace std;

int main(){

    
  
  vector<int> test={1, 3, 34};
  
  cout << "Test mkString..." << endl;
  string expectedString="1 3 34";
  assert(expectedString==Functional::mkString(test));
  cout << "passed!" << endl;
  
  return 0;

}

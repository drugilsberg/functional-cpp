#include<iostream>
#include<vector>
#include<math.h>
#include "FunctionalUtils.hpp"

#include<cassert>

using namespace std;

int main(){

    
  
  vector<int> test1={1, 3, 34, 50};
  vector<double> test2={1.0, 2.0, 3.0};

  
  cout << "Test map..." << endl;
  vector<double> expectedMap={2, 6, 68, 100};
  function< double(int) > func1= [] (const int & element){return 2.0*element;};   
  vector<double> output= FunctionalUtils::map( test1,  func1 );
  FunctionalUtils::mkString(output);
  assert(expectedMap==output);
  cout << "passed!" << endl;
  
  cout << "Test zip..." << endl;
  vector< std::pair<int,double> > expectedZip={
      std::make_pair(1,1.0),
      std::make_pair(3,2.0),
      std::make_pair(34, 3.0)      
  };
  auto outputZip = FunctionalUtils::zip(test1, test2);  
  for( const auto & couple : outputZip){
    std::cout << couple.first << " "<< couple.second << std::endl;
  }
  assert( expectedZip==outputZip);
  cout << "passed!" << endl;
  
  vector<double> test3={1.0, 1.2, 2.0, 2.3, 3.0};
  function< int(double) > func2= [] (const double & element){return (int)element;};
  multimap<int, double> expectedKeyBy={
      std::make_pair(1,1.0),
      std::make_pair(1,1.2),
      std::make_pair(2,2.0),
      std::make_pair(2,2.3),
      std::make_pair(3, 3.0)      
  };
  cout << "Test keyBy..." << endl;
  auto keyed = FunctionalUtils::keyBy(test3,func2); 
  for( const auto & d : keyed){
      cout << d.first << " -> " << d.second << endl;
  }
  assert( expectedKeyBy==keyed);
  cout << "passed!" << endl;
  
  cout << "Test groupBy..." << endl;
  map<int, vector<double> > expectedGroupBy={
      std::make_pair(1, std::vector<double>{1.0, 1.2}),      
      std::make_pair(2, std::vector<double>{2.0, 2.3}),      
      std::make_pair(3, std::vector<double>{3.0})      
  };
  auto grouped = FunctionalUtils::groupBy(test3, func2);  
  for ( const auto & d : grouped){
      cout << d.first << " -> ";      
      FunctionalUtils::mkString(d.second, ",");
  }
  assert(expectedGroupBy==grouped);
  cout << "passed!" << endl;

  return 0;

}

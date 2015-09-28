#include<iostream>
#include<vector>
#include "FunctionalUtils.hpp"

using namespace std;


template <typename C>
static void printContainer(const C & container, const char* separator=" ", std::ostream & out=std::cout) {
  std::for_each(container.begin(), container.end()-1, [&separator, &out](const typename C::value_type & element) {
      out << element << separator;
      });
  out << container.back() << std::endl;
}



int main( int argc, char** argv){

  vector<int> test={1, 3, 34, 50};
  vector<double> testBis={1.0, 2.0, 3.0};

  printContainer(test);

  function< double(int) > func= [] (const int & element){return 2.0*element;};

  vector<double> output= FunctionalUtils::map( test,  func );

  printContainer(output,"#",std::cout);

  auto outputZip = FunctionalUtils::zip(test, testBis);

  for( const auto & couple : outputZip){
    std::cout << couple.first << " "<< couple.second << std::endl;
  }

  return 0;

}

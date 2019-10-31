#include "simulations.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
  Simulations test;
  vector<string> change = {"1","2","3","4"};
  test.set_poblation(change);
  vector<string> pob = test.get_poblation();
  int sz = pob.size();
  for(int i = 0; i < sz; ++i)
    cout << pob[i] << " ";

  cout << endl;
  test.nodes();
  test.print_nodes();
  cout << endl;

  return 0;
}

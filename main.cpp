#include "simulations.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
  Simulations test;
  vector<int> change;
  int u = 1000;
  for(int i = 1; i < u; i++){change.push_back(i);}
  test.set_population(change);
  test.nodes();
  vector<int> pob = test.get_population();
  cout << endl;
  test.doing_simulations(100);
  test.display_tree();
  test.create_txt();
  test.create_txtcount();
  ofstream iterations;
  iterations.open("iterations.txt");
  iterations << u;
  iterations.close();

  return 0;
}

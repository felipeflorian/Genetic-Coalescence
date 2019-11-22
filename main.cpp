#include "simulations.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
  Simulations test;
  vector<int> change;
  for(int i = 1; i < 6; i++){change.push_back(i);}
  test.set_population(change);


  test.nodes();
  //test.do_simulation();
  vector<int> pob = test.get_population();
  //for(unsigned int u = 0; u < pob.size(); u++){cout << pob[u] << " ";}
  cout << endl;
  //test.doing_simulations(3);
  test.doing_simulations(5);
  test.display_tree();
  //lo hace 5 veces
  test.create_txt();
  test.create_txtcount();
  return 0;
}

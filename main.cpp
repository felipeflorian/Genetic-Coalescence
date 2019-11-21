#include "simulations.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
  Simulations test;
  vector<int> change = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
  test.set_population(change);


  test.nodes();
  //test.do_simulation();
  vector<int> pob = test.get_population();
  //for(unsigned int u = 0; u < pob.size(); u++){cout << pob[u] << " ";}
  cout << endl;
  //test.doing_simulations(3);
  test.doing_simulations(20);
  test.display_tree();
  //lo hace 5 veces

  return 0;
}

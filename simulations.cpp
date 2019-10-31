#include "simulations.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;






//Private functions
void Simulations::doing_nodes( vector<string> nw){
  int sz = nw.size();
  for(int i = 0; i < sz; ++i){
    string k = nw[i];
    Node *temp;
    temp = new Node;
    temp->key = k;
    roots.push_back(temp);
  }
}




//Public functions




void  Simulations:: set_poblation(const vector<string> nw){
  int sz = nw.size();
  for(int i = 0; i < sz;++i){
    poblation.push_back(nw[i]);
  }

}
vector<string> Simulations::get_poblation(){
  return poblation;
}

void Simulations::print_nodes(){
  int sz = roots.size();
  for(int i = 0; i < sz; ++i){
    cout << roots[i]->key << endl;
  }
}

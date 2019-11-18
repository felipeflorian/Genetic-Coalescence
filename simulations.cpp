#include "simulations.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
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

void Simulations::create_count(){
  int sz = population.size();
  for(int i = 0; i < sz; i++){
    count.push_back(0);
  }
}


void  Simulations:: set_population(const vector<string> nw){
  int sz = nw.size();
  if(population.empty()){
    for(int i = 0; i < sz;++i){
      population.push_back(nw[i]);
    }
  }else{
    for(int i = 0; i < sz;++i){
      population[i] = nw[i];
    }
  }
}

vector<string> Simulations::get_population(){
  return population;
}

void Simulations::print_nodes(){
  int sz = roots.size();
  for(int i = 0; i < sz; ++i){
    cout << roots[i]->key << endl;
  }
}


void Simulations::do_simulation(){
  int sz = population.size();
  int szRoots = roots.size();
  vector<string> newpopulation;
  if(roots.empty())
    throw runtime_error(" No roots :( ");
  else{
    create_count();
    for(int i = 0; i < sz; i++){
      int ran = 1 + rand() % (sz-1);
      cout << ran << " ";
      count[ran-1]++;
    }
    int x = count.size();
    cout << endl;
    for(int i = 0; i < x ; i++){
      cout << count[i] << " ";
    }
    cout << endl;
  for(int j = 0; j < x; j++){
    if(count[j]>=1){
      string son = to_string(j+1)+":"+to_string(j+1)+"´";
      newpopulation.push_back(son);
      for(int k = 1; k< count[j];k++){
        string primas = "´";
        for(int g = 1; g <= k; g++){
          primas += primas;
        }
        son = to_string(j+1) + ":" +to_string(j+1) + primas;
        newpopulation.push_back(son);
      }


    }

  }
  cout << "se hace set_population\n";
  cout << endl;
  set_population(newpopulation);
  }
  for(unsigned int y = 0; y < population.size();y++){
    string p = population[y];
    //cout << p.at(0) << endl;
    char temp2 = p.at(0);
    string s(1,temp2);
    //cout << s << endl;
    for(unsigned int r = 0; r < roots.size();r++){
      if(roots[r]->key == s){
        Node *nw;
        nw = new Node;
        nw->key = p;
        roots[r]->sons.push_back(nw);
      }
    }
  }
}

// Node* Simulations::find_node(string key,vector<Node *> x){
//   for(unsigned int i = 0; i < x.size();i++ ){
//     if(x[i]->key == key){
//       cout << x[i]->key << endl;
//       return x[i];
//     }else{
//       char k = key.at(0);
//       string s(1,k);
//       for(unsigned int i = 0; i < x.size(); i++){
//           if(x[i]->key == s){
//             find_node(key, x[i]->sons);
//             break;
//           }
//
//       }
//
//     }
//
//   }
//   return nullptr;
// }

void Simulations:: simulation(){
  do_simulation();
}

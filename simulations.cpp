#include "simulations.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <list>
using namespace std;

//Private functions
void Simulations::doing_nodes( vector<string> nw){
  int sz = nw.size();
  for(int i = 0; i < sz; ++i){
    string k = nw[i];
    Node *temp;
    temp = new Node;
    temp->key = k;
    temp->sons = nullptr;
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




// Node* Simulations::find_node(vector<Node *> &x,string key,string temp){
//   vector<string> Keys;
//   for(unsigned int i = 0; i < x.size();i++ ){
//     if(x[i]->key == key){
//       return x[i];
//       }
//     }
//     char k = key.at(0);
//     string s = "";
//     for(int j = 0; j < key.length();j++){
//       char r = key.at(j);
//
//       if( r == ':'){
//         cout << "pushing ..." ;
//         Keys.push_back(s);
//         cout << s << endl;
//         s = "";
//       }
//       if(r != ':'){
//         s += r;
//
//       }
//     }
//     Keys.push_back(s);
//     cout << endl;
//     cout << Keys.size() << endl;
//     for(unsigned int y = 0; y < Keys.size(); y++){
//       cout << Keys[y] << " ";
//     }
//     cout << endl;
//     string newKey = "";
//     for(unsigned int o = 1; o < Keys.size();o++){
//       newKey =":"+ Keys[o];
//     }
//     string r = Keys[0];
//     temp += r;
//     cout << temp << endl;
//     cout << newKey << endl;
//     // cout << newKey << endl;
//     // cout << temp << endl;
//     for(unsigned int u = 0; u < x.size(); u++){
//       if(x[u]->key == temp){
//         // cout << "holi " << endl;
//         // cout << x[u]->key << endl;
//         return x[u];
//       }
//     }
//     return x[0];
//
//   return nullptr;
// }

void create_sons(int n, string s, vector<Node *> roots){
  Node * copy;
  for(unsigned int i = 0; i < roots.size(); i++){
    if(roots[i]->key == s){
      copy = roots[i];
      break;
    }
  }

  vector<Node *> find_son;
  find_son = copy->sons;
  if(find_son == nullptr){
    for(int j = 0; j < n; j++){
      Node *nw;
      nw->key = s;
      nw->sons = nullptr;
      copy.push_back(nw);
    }
  }else{
    for(unsigned int p = 0; p < find_son.size(); p++){
      if(find_son[i]->sons == nullptr){
        for(int j = 0; j < n; j++){
          Node *nw;
          nw->key = s;
          nw->sons = nullptr;
          copy.push_back(nw);
        }
      }else{
        Node *x;
        vector<Node *> copy2;
        copy2 = x->sons;
        create_sons(n, s, copy2);
      }
    }
  }

}

void Simulations:: simulation(int k){
  do_simulation();
  for(int i = 0; i < k -1 ; i++){

  }
}


// string Simulations:: take_last(Node * &t){
//   string temp = t->key;
//   string final = "";
//   for(int j = 0; j < temp.length();j++){
//     char p = temp.at(j);
//     final += p;
//     cout << final << endl;
//     if(p == ':'){
//       final = "";
//     }
//   }
//   cout << final << endl;
//   return final;
// }

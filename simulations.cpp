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
  vector<string> population2;
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
      string f = to_string(j+1)+"´";
      string son = to_string(j+1)+":"+to_string(j+1)+"´";
      newpopulation.push_back(son);
      population2.push_back(f);
      for(int k = 1; k< count[j];k++){
        string primas = "´";
        for(int g = 1; g <= k; g++){
          primas += primas;
        }
        string primas2 = "´";
        for(int u = 1; u < k; u++){
          primas2 += primas2;
        }
        son = to_string(j+1) + ":" +to_string(j+1) + primas;
        f = f + primas2;
        newpopulation.push_back(son);
        population2.push_back(f);


      }


    }

  }
  cout << "se hace set_population\n";
  cout << endl;
  set_population(population2);
  }
  for(unsigned int t = 0; t < newpopulation.size(); t++){
    cout << newpopulation[t] << " ";
  }cout << endl;
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
  set_population(newpopulation);
  cout << "Finding ... " << endl;
  Node *t = find("2:2´");
  if(t != nullptr)
    cout << t->key << endl;
  else
    cout << "esta mal  " << endl;
  // if(t->sons.size()>0){
  //   for(unsigned int c = 0; c < t->sons.size();c++){
  //     cout << t->sons[c]->key << endl;
  //   }
  // }
  // else{
  //   cout << t->key << endl;
  // }
}

Node* Simulations::find_node(vector<Node *> &x,string key,string temp){
  vector<string> Keys;
  for(unsigned int i = 0; i < x.size();i++ ){
    if(x[i]->key == key){
      return x[i];
      }
    }
    char k = key.at(0);
    string s = "";
    for(int j = 0; j < key.length();j++){
      char r = key.at(j);

      if( r == ':'){
        cout << "pushing ..." ;
        Keys.push_back(s);
        cout << s << endl;
        s = "";
      }
      if(r != ':'){
        s += r;

      }
    }
    Keys.push_back(s);
    cout << endl;
    cout << Keys.size() << endl;
    for(unsigned int y = 0; y < Keys.size(); y++){
      cout << Keys[y] << " ";
    }
    cout << endl;
    string newKey = "";
    for(unsigned int o = 1; o < Keys.size();o++){
      newKey =":"+ Keys[o];
    }
    string r = Keys[0];
    temp += r;
    cout << temp << endl;
    cout << newKey << endl;
    // cout << newKey << endl;
    // cout << temp << endl;
    for(unsigned int u = 0; u < x.size(); u++){
      if(x[u]->key == temp){
        // cout << "holi " << endl;
        // cout << x[u]->key << endl;
        return x[u];
      }
    }
    return x[0];

  return nullptr;
}

void Simulations:: simulation(){
  do_simulation();
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

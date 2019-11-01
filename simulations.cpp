#include "simulations.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include<stdexcept>
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
  int sz = poblation.size();
  for(int i = 0; i < sz; i++){
    count.push_back(0);
  }
}


void  Simulations:: set_poblation(const vector<string> nw){
  int sz = nw.size();
  if(poblation.empty()){
    for(int i = 0; i < sz;++i){
      poblation.push_back(nw[i]);
    }
  }else{
    for(int i = 0; i < sz;++i){
      poblation[i] = nw[i];
    }
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


void Simulations::do_simulation(){
  int sz = poblation.size();
  int szRoots = roots.size();
  vector<string> newPoblation;
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
    }for(int i = 0; i < szRoots; i++){
      roots[i]->p = poblation;
    }
    string number = "´";
    for(int j = 0 ; j < x; j++){
      string f = to_string(count[j]);
      newPoblation.push_back(f);
      if(count[j] != 0){
        cout << "COUNT[J]: ";
        cout << count[j] << endl;
        cout << "J: ";
        cout << j << endl;
        string f = to_string(j+1);
        cout << "F: ";
        cout << f << endl;
        if(count[j] == 1){newPoblation.push_back(f);}
      /*  else{
            for(int i = 1; i < count[j]; i++){
              string number = "´";
              for(int j = 0; j < i; j++){
                f += number;
              }
              newPoblation.push_back(f);
            }
          }
        }*/

    }
  }
  for(unsigned int i = 0; i < newPoblation.size();i++){cout << newPoblation[i] << " ";}
  cout << endl;
  //set_poblation(newPoblation);
  }
}

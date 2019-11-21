#ifndef __SIMULATIONS__HPP
#define __SIMULATIONS__HPP

#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

struct Node{
  int key;
  vector<Node *> sons;
};

class Simulations{
private:
  Node *parent;
  vector<Node *> roots;
  vector<int> population;
  vector<int> count;
  void doing_nodes( vector<int> p);
  void create_count();
  void display(Node *root);

public:
  Simulations(){}
  //~Simulations();
  void set_population(const vector<int> nw);
  vector<int> get_population();
  void nodes() {doing_nodes(population);}
  void print_nodes();
  void do_simulation();//Number o iterations
  void doing_simulations(int k);
  void create_sons(int n, int s, vector<Node *>  roots);
  void display_tree();

};



#endif

#ifndef __SIMULATIONS__HPP
#define __SIMULATIONS__HPP

#include <vector>
#include <string>
using namespace std;

struct Node{
  string key;
  vector<Node *> sons;
};

class Simulations{
private:
  Node *parent;
  vector<Node *> roots;
  vector<string> population;
  vector<int> count;
  void doing_nodes( vector<string> p);
  void create_count();
  Node* find_node(string key,vector<Node *> x);

public:
  Simulations(){}
  //~Simulations();
  void set_population(const vector<string> nw);
  vector<string> get_population();
  void nodes() {doing_nodes(population);}
  void print_nodes();
  void do_simulation();//Number o iterations
  Node* find(string key){return find_node(key, roots);}
  void simulation();

};



#endif

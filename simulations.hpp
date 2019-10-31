#ifndef __SIMULATIONS__HPP
#define __SIMULATIONS__HPP

#include <vector>
#include <string>
using namespace std;

class Simulations{
private:
  struct Node{
    string key;
    vector<Node *> sons;
  };
  Node *parent;
  vector<Node *> roots;
  vector<string> poblation;
  vector<int> count;
  void doing_nodes( vector<string> p);

public:
  Simulations(){}
  //~Simulations();
  void set_poblation(const vector<string> nw);
  vector<string> get_poblation();
  void nodes() {doing_nodes(poblation);}
  void print_nodes();



};



#endif

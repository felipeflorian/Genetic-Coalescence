#include "simulations.hpp"



void Simulations::destroy(vector<Node *> p){
  for(unsigned int i = 0; i < p.size();i++){
    if(p[i]->sons.size() != 0){
      destroy(p[i]->sons);
      delete p[i];
    }else{
      delete p[i];
    }
  }
}


bool Simulations:: only_one_element(vector<int> p){
  int sz = p.size();
  int f = p[0];
  for(int h = 1; h < sz; h++){
    if(p[h] == f)
      f = p[h];
    else
      return false;
  }
  return true;

}

//Private functions
void Simulations::doing_nodes( vector<int> nw){
  int sz = nw.size();
  for(int i = 0; i < sz; ++i){
    int k = nw[i];
    Node *temp;
    temp = new Node;
    temp->key = k;
    roots.push_back(temp);
  }
}

void Simulations::create_count(){
  int sz = population.size();
  if(count.size() == 0){
    for(int i = 0; i < sz; i++){
      count.push_back(0);
    }
  }else{
    for(int y = 0; y < sz; y++){
      count[y] = 0;
    }
  }
}


void  Simulations:: set_population(const vector<int> nw){
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

vector<int> Simulations::get_population(){
  return population;
}

void Simulations::print_nodes(){
  int sz = roots.size();
  for(int i = 0; i < sz; ++i){
    cout << roots[i]->key << endl;
  }
}

void Simulations::create_sons(int n, int s, vector<Node *>  r){
  Node *copy;
  for(unsigned int i = 0; i < r.size(); i++){
    if(r[i]->key == s){
      copy = r[i];
      break;
    }
  }
  vector<Node *> find_son = copy->sons;
  if(copy->sons.size()==0){
    for(int y = 0; y < n; y++){
      Node *nw;
      nw = new Node;
      nw->key = s;
      copy->sons.push_back(nw);
    }
  }
  else{
     create_sons(n,s,copy->sons);
  }
}


void Simulations::do_simulation(){
  int sz = population.size();
  vector<int> newpopulation;
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
      final_count.push_back(count[i]);
    }
    cout << endl;
    for(int j = 0; j < x; j++){
      if(count[j]>=1){
        int son = j+1;
        for(int k = 1; k<= count[j];k++){
          final_population.push_back(son);
          newpopulation.push_back(son);
        }
      }
    }

  set_population(newpopulation);
  for(unsigned int k = 0; k <population.size();k++){cout << population[k] << " ";}
  }
  cout << endl;
  bool all =only_one_element(population);
  if(all == true){
    create_sons(sz, population[0], roots);
  }
  for(int r = 0; r < sz; r++){
    int x = r+1;
    if(count[r] != 0)
      create_sons(count[r],x,roots);
  }
}

void Simulations:: doing_simulations(int k){

  do_simulation();
  cout << endl;
  int sz = population.size();
  for(int i = 0; i < k -1 ; i++){
    cout << "doing simulation " << endl;
    vector<int> newpopulation(sz,0);
    vector<int> lastpopulation(sz,0);
    for(int l = 0; l < sz; l++){lastpopulation[l] = population[l];}
    create_count();
    for(int i = 0; i < sz; i++){
      int ran = 1 + rand() % (sz-1);
     cout << ran << " ";
      count[ran-1]++;
    }
    int x = count.size();
    cout << endl;
    cout << "Printing count ..." << endl;
    for(int i = 0; i < x ; i++){
      cout << count[i] << " ";
      final_count.push_back(count[i]);
    }
    cout << endl;
    int count2 = 0;
    for(int j = 0; j < x; j++){
      if(count[j] >= 1){
        for(int f = 0; f < count[j]; f++){
          newpopulation[count2] = population[j];
          count2++;
        }
      }
    }
    cout << endl;
    for(unsigned int a = 0; a < newpopulation.size();a++){final_population.push_back(newpopulation[a]);}
    for(unsigned int h = 0; h < population.size();h++){cout << population[h] << " ";}
    cout << endl;
    cout << "printing population" << endl;
    set_population(newpopulation);
    for(unsigned int k = 0; k <population.size();k++){cout << population[k] << " ";}
    cout << endl;
    cout << "creating sons " << endl;
    bool all = only_one_element(population);
    if(all == true){
      create_sons(sz, population[0], roots);
      break;
    }
    for(int r = 0; r <sz ;r++){
      int x = lastpopulation[r];
      if(count[r] != 0)
        create_sons(count[r],x,roots);
    }
  }
}

void Simulations::display(Node *root){
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    while(n>0){
      Node *p = q.front();
      q.pop();
      cout << p->key << " ";

      for(unsigned int i = 0; i < p->sons.size(); i++){
        q.push(p->sons[i]);
      }
      n--;
    }
    cout << endl;
  }
  cout << endl;
}

void Simulations:: display_tree(){
  for(unsigned int i = 0; i < roots.size(); i++){
    display(roots[i]);
  }


}
void Simulations:: create_txt(){
  ofstream final;
  final.open("populations.txt");
  string e = " ";
  int c = 0;
  int sz = population.size();
  string p = "";
  for(unsigned int i = 0; i < final_population.size();i++){
    p += to_string(final_population[i]);
    p += e;
    c++;
    if(c == sz){
      c = 0;
      final << p + '\n';
      p = "";
    }
  }
  final.close();
}


void Simulations:: create_txtcount(){
  ofstream final, average;
  final.open("counts.txt");
  average.open("average.txt");
  string e = " ";
  int c = 0;
  int b = 0;
  int sz = population.size();
  average << sz << endl;
  string p = "";
  for(unsigned int i = 0; i < final_count.size();i++){
    p += to_string(final_count[i]);
    p += e;
    c++;
    if(final_count[i] == 2)
      b += 1;
    if(c == sz){
      c = 0;
      final << p + '\n';
      average << b << endl;
      b = 0;
      p = "";
    }
  }
  final.close();
}

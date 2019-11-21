#include "simulations.hpp"


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

void Simulations::create_sons(int n, int s, vector<Node *>  roots){
  Node * copy;
  for(unsigned int i = 0; i < population.size(); i++){
    if(roots[i]->key == s){
      copy = roots[i];
      break;
    }
  }

  vector<Node *> find_son;
  find_son = copy->sons;
  if(find_son.size()==0){
    for(int j = 0; j < n; j++){
      Node *nw;
      nw = new Node;
      nw->key = s;
      copy->sons.push_back(nw);
    }
  }else{
    for(unsigned int p = 0; p < find_son.size(); p++){
      Node *e = copy->sons[p];
      if(e->sons.size() == 0){
        if(n%2 == 0){
          for(int j = 0; j < n; j++){
            Node *nw;
            nw = new Node;
            nw->key = s;
            e->sons.push_back(nw);
          }
        }else{
          for(int j = 0; j <= n; j++){
            Node *nw;
            nw = new Node;
            nw->key = s;
            e->sons.push_back(nw);
          }
        }
      }else{
          cout << "entre al else " << endl;
          int sz = copy->sons.size();
          for(int i = 0; i < sz; i++){
            Node *temp;
            temp = copy->sons[i];
            Node *temp2 = nullptr;
            while(temp->sons.size() != 0){
              create_sons(n,s temp->sons);
            }
          }
      }
    }
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
    }
    cout << endl;
    for(int j = 0; j < x; j++){
      if(count[j]>=1){
        int son = j+1;
        for(int k = 1; k<= count[j];k++){
          newpopulation.push_back(son);
        }
      }
    }

  set_population(newpopulation);
  for(unsigned int k = 0; k <population.size();k++){cout << population[k] << " ";}
  }
  cout << endl;
  for(int r = 0; r < sz; r++){
    int x = r+1;
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
    }
    cout << endl;
    int count2 = 0;
    for(int j = 0; j < x; j++){
      if(count[j] >= 1){
        for(int f = 0; f < count[j]; f++){
          cout << population[j] << " ";
          newpopulation[count2] = population[j];
          count2++;
        }
      }
    }
    cout << "printing population" << endl;
    set_population(newpopulation);
    for(unsigned int k = 0; k <population.size();k++){cout << population[k] << " ";}
    cout << endl;
    cout << "creating sons " << endl;
    for(int r = 0; r <sz ;r++){
      int x = population[r];
      create_sons(count[r],x,roots);
    }
    cout << endl;
  }
  cout << endl;
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
  cout << endl << endl;
}

void Simulations:: display_tree(){
  for(unsigned int i = 0; i < roots.size(); i++){
    display(roots[i]);
  }


}

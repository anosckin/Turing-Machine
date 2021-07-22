#include<bits/stdc++.h>
using namespace std;

struct edge{
	int to;
	char read,write,tapeDirection;
}; 

class turingMachine{
  public:
  	vector <char> tape;
   	vector < vector<edge> > edges;
   	int current_state,state_num,accept_state;
   	int tape_position;
   	
   	turingMachine(){};
   	
   	turingMachine(int n){
   		state_num=n;
   		current_state=0;
   		accept_state=n-1;
		}
	
   	void createInputTape(string s){
   		for (int i=0;i<s.size();i++){
   			tape.push_back(s[i]);
			}
		}
};

void start(turingMachine& machine){
	while (machine.current_state != machine.accept_state){
		char cur_symbol = machine.tape[machine.tape_position];
		bool found=false;
		
		for (int i=0;i<machine.edges[machine.current_state].size();i++){
			edge cur_edge = machine.edges[machine.current_state][i];
			
			if (cur_edge.read != cur_symbol) continue;
			
			found=true;
			
			machine.current_state = cur_edge.to;
			machine.tape[machine.tape_position] = cur_edge.write;
			
			if (cur_edge.tapeDirection=='R') machine.tape_position++;
			else machine.tape_position--;
			
			break;
		}
		
		if(!found){
			cout<<-1<<endl;
			return;
		}
		
		if (machine.tape_position >= machine.tape.size()) {
			cout<<-1<<endl;
			return ;
		}
		
		cout<<machine.current_state<<endl;
	}
}
int main () {
	int n;
	cin>>n;
	
	turingMachine machine(n);
	
	vector <edge> edges_of_node_i;
	for (int i=0;i<n-1;i++){
		int k;
		cin>>k;
		
		edges_of_node_i.clear();
		
		for (int j=0;j<k;j++){
			edge cur_edge;
			cin>>cur_edge.read>>cur_edge.to>>cur_edge.write>>cur_edge.tapeDirection;
			
			edges_of_node_i.push_back(cur_edge);
		}
		
		machine.edges.push_back(edges_of_node_i);
	}
	
	string input_tape;
	cin>>input_tape;
	
	machine.createInputTape(input_tape);
	
	start(machine);
	return 0;
}




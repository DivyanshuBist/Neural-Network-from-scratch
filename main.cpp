#include<bits/stdc++.h>
using namespace std;

class Neuron{};
class NeuralNetwork{};
//<---------------- Neuron Class----------------------------------->
class Neuron{
	int bias=1;
	double output=0;
	int size=0;
	vector<double> weight;
	public:
	       Neuron(int prev_layer_size){
		  weight.resize(prev_layer_size,1);
	       }
	       
       			       
};
//<---------------Neural Network Class------------------------------>
typedef vector<Neuron> layer;
class NeuralNetwork{
	vector<layer> m_network;
	public:
	NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology);
};
NeuralNetwork::NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology){
	for(int new_layer=0;new_layer<topology.size();new_layer++){
	  m_network.push_back(layer());
	  for(int new_neuron=0;new_neuron<topology[new_layer];new_neuron++){

		int previous_layer_size=(new_layer==0)?inputsize:topology[new_layer-1];
		
	  	m_network.back().push_back(Neuron(previous_layer_size));
//		cout<<"done\n";
	  }
	  cout<<"\n";
	}

}
int main(){
	vector<unsigned int> topology={4,2,1};//A Neural Network topology descriptor which contains no. of neuron in each layer e.g. {4,2,1} 4 neuron in first layer,2 in second layer and 1 in last layer.
	unsigned int inputsize=4;
	 NeuralNetwork net(inputsize,topology);

}

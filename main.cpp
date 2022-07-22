#include<bits/stdc++.h>
using namespace std;


//<---------------- Neuron Class----------------------------------->
class Neuron{
	vector<double> weight;
	public:
		double bias=1.00d;
	        double output=0.00d;
	       Neuron(int prev_layer_size){
		  weight.resize(prev_layer_size,1);
	       }
	       int get_weight(int idx){
	        if(idx>=0 && weight.size()>idx) return weight[idx];
		return -1;
	       }

	       
       			       
};
//<---------------Neural Network Class------------------------------>
typedef vector<Neuron> layer;
class NeuralNetwork{
	vector<layer> m_network;
	int inputlayersize;
	public:
	NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology);
	void FeedForward(vector<double>inputs,double output);

};
NeuralNetwork::NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology){
	inputlayersize=inputsize;
	for(int new_layer=0;new_layer<topology.size();new_layer++){
	  m_network.push_back(layer());
	  for(int new_neuron=0;new_neuron<topology[new_layer];new_neuron++){

		int previous_layer_size=(new_layer==0)?inputsize:topology[new_layer-1];
		
	  	m_network.back().push_back(Neuron(previous_layer_size));
//		cout<<"done\n";
	  }
	}

}

void NeuralNetwork::FeedForward(vector<double>input,double output){
	if(input.size()!=inputlayersize){
		cout<<"the size of input is not equal to the input size provided in the topology.Please try again\n";
		return ;
	}
	for(int l=0;l<m_network.size();l++){
		for(int neuron=0;neuron<m_network[l].size();neuron++){
		  if(l==0){
			double f=0.00d;
      			for(int i=0;i<input.size();i++){
			  f+=(double)(input[i]*m_network[l][neuron].get_weight(i));
			}
			f+=m_network[l][neuron].bias;
			cout<<f<<"\n";
			m_network[l][neuron].output= (double) (1/ (1 + exp(-f) ) );
		  }
		  else{
   			double f=0.00d;
                        for(int i=0;i<m_network[l-1].size();i++){
                          f+=(double)(m_network[l-1][i].output*m_network[l][neuron].get_weight(i));
                        }
                        f+=m_network[l][neuron].bias;
                        m_network[l][neuron].output= (double) (1/ (1 + exp(-f) ) );

		  }
		  cout<<m_network[l][neuron].output<<"  ";
		}
		cout<<"\n";

	}
}
int main(){
	vector<unsigned int> topology={1};//A Neural Network topology descriptor which contains no. of neuron in each layer e.g. {4,2,1} 4 neuron in first layer,2 in second layer and 1 in last layer.
	unsigned int inputsize=2;
	 NeuralNetwork net(inputsize,topology);
	 net.FeedForward({0.000d,1.00d},1.00);

}

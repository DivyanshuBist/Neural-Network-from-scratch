#include<bits/stdc++.h>
#include "Nnet.hpp"
#include<stdlib.h>
#include<time.h>
using namespace std;

//<---------------- Neuron Class----------------------------------->
//class Neuron{
//	vector<double> weight;
//	public:
//		double rate_wrt_n;
//		double bias=1.00d;
//	        double output=0.00d;
//	       Neuron(int prev_layer_size){
//		  weight.resize(prev_layer_size,1);
//	       }
//	       int get_weight(int idx){
//	        if(idx>=0 && weight.size()>idx) return weight[idx];
//		return -1;
//	       }
//
//	       
//       			       
//};
////<---------------Neural Network Class------------------------------>
//typedef vector<Neuron> layer;
//class NeuralNetwork{
//	void backpropagation(double target);
//	vector<layer> m_network;
//	int inputlayersize;
//	public:
//	NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology);
//	void FeedForward(vector<double>inputs,double target);
//
//};
//NeuralNetwork::NeuralNetwork(unsigned int inputsize,vector<unsigned int>& topology){
//	inputlayersize=inputsize;
//	for(int new_layer=0;new_layer<topology.size();new_layer++){
//	  m_network.push_back(layer());
//	  for(int new_neuron=0;new_neuron<topology[new_layer];new_neuron++){
//
//		int previous_layer_size=(new_layer==0)?inputsize:topology[new_layer-1];
//		
//	  	m_network.back().push_back(Neuron(previous_layer_size));
////		cout<<"done\n";
//	  }
//	}
//
//}
//
//void NeuralNetwork::FeedForward(vector<double>input,double output){
//	if(input.size()!=inputlayersize){
//		cout<<"the size of input is not equal to the input size provided in the topology.Please try again\n";
//		return ;
//	}
//	for(int l=0;l<m_network.size();l++){
//		for(int neuron=0;neuron<m_network[l].size();neuron++){
//		  if(l==0){
//			double f=0.00d;
//      			for(int i=0;i<input.size();i++){
//			  f+=(double)(input[i]*m_network[l][neuron].get_weight(i));
//			}
//			f+=m_network[l][neuron].bias;
//			cout<<f<<"\n";
//			m_network[l][neuron].output= (double) (1/ (1 + exp(-f) ) );
//		  }
//		  else{
//   			double f=0.00d;
//                        for(int i=0;i<m_network[l-1].size();i++){
//                          f+=(double)(m_network[l-1][i].output*m_network[l][neuron].get_weight(i));
//                        }
//                        f+=m_network[l][neuron].bias;
//                        m_network[l][neuron].output= (double) (1/ (1 + exp(-f) ) );
//
//		  }
//		  cout<<m_network[l][neuron].output<<"  ";
//		}
//		cout<<"\n";
//
//	}
//}
//void NeuralNetwork::backpropagation(double target){
//	for(int l=m_network.size()-1;l>0;l--){
//		for(int n=0;n<m_network[l].size();n++){
//			if(l==m_network.size()-1){
//				m_network[l][n].rate_wrt_n=(target-m_network[l][n].output)*(1-m_network[l][n].output)*m_network[l][n].output
//					*m_network[l-1][];
//			}
//			else{
//				m_network[l][n]=0;
//				for(int nn=0;nn<m_network[l+1];nn++){
//					m_network[l][n].rate_wrt_n+=m_network[l+1][nn].rate_wrt_n*m_metwork[l+1][nn].get_weight(n); //check
//				}
//			}
//			m_network[l][n].rate_wrt_n;
//		}
//	}	
//}
int main(){
	srand(time(0));
//	vector<unsigned int> topology={1};//A Neural Network topology descriptor which contains no. of neuron in each layer e.g. {4,2,1} 4 neuron in first layer,2 in second layer a
	Neural_Network net;
	net.add(2);
	net.add(1);
	net.feedforward({1,0},{1});
}

#pragma once
#include"Matrix.hpp"
#include<vector>
#include<assert.h>
#include<math.h>
using namespace std;
class Neural_Network{
	float learning_rate=0.5;
	void backpropagate(const vector<float>&output);
        public:
                vector<Matrix> layer;
                vector<Matrix> Weights;
                vector<Matrix> delta;
		vector<Matrix>bias;
                void add(int neurons);
		void feedforward(const vector<float>& input,const vector<float>&output);


};
void Neural_Network::add(int neurons){
	assert(neurons>=0);
	Matrix mat(neurons,1);
	layer.push_back(mat);
	bias.push_back(mat);
	delta.push_back(mat);

	if(layer.size()==1){return; }

	Matrix wt(neurons,layer[layer.size()-2]._row);
	Weights.push_back(wt);
}

void Neural_Network::feedforward(const vector<float>& input,const vector<float>&output){
	assert(input.size()==layer[0]._row && output.size()==layer.back()._row);
	if(layer.size()<=1){
		cout<<"\natleast two layer are required for feedback\n.";
		return ;
	}
	for(int n=0;n<layer[0]._row;n++){
		layer[0].mat[n][0]=input[n];
	}

	for(int i=1;i<layer.size();i++){
	  Weights[i-1].mult(layer[i-1],layer[i]);
	  layer[i].add(bias[i],layer[i]);
	  for(int n=0;n<layer[i]._row;n++){
	  	layer[i].mat[n][0]= 1 / (1 + exp(-layer[i].mat[n][0]));
	  }
	}

	

	backpropagate(output);
	
}
void Neural_Network::backpropagate(const vector<float>&target){
	float error=0.0f;
	cout<<" target " ;
	for(float i:target) cout<<i<<"  ";
	cout<<"\n";
	for(int n=0;n<layer.back()._row;n++){
//		cout<<target[i]<<" "<<layer.back().mat[n][0]<<"\n";
		error+=0.5*pow((target[n]-layer.back().mat[n][0]),2);
	}
	cout<<"actual values: ";
	for(int n=0;n<layer.back()._row;n++){
		cout<<layer.back().mat[n][0]<<"    ";
	}
	cout<<"\n";
	cout<<"target values: ";
	for(int n=0;n<layer.back()._row;n++){
		cout<<target[n]<<"    ";
	}
	cout<<"\n";
	cout<<"error is :"<<error<<"\n";
	for(int n=0;n<layer.back()._row;n++){
		float val=layer.back().mat[n][0];
		delta.back().mat[n][0]=-(target[n]-val);
	//	delta.back().mat[n][0]*=(target[i]>val)?-1:1;
		cout<<delta.back().mat[n][0]<<" ---  "<<target[n]<<" -  "<<val<<" ";
		bias.back().mat[n][0]-=delta.back().mat[n][0];
	}
	cout<<"\n";
	for(int i=layer.size()-2;i>=0;i--){
	  Matrix wt_updation(layer[i+1]._row,layer[i]._row);
	  Matrix l_tpose(1,layer[i]._row);
	  layer[i].transpose(l_tpose);
	  delta[i+1].mult(l_tpose,wt_updation);
	  wt_updation.mult(-learning_rate,wt_updation);

	  for(int r=0;r<Weights[i]._row;r++){
	  	for(int c=0;c<Weights[i]._col;c++){
			wt_updation.mat[r][c]*=layer[i+1].mat[r][0]*(1-layer[i+1].mat[r][0]);
		}
	  }
	  Weights[i].add(wt_updation,Weights[i]);

	  Matrix wt_transpose(Weights[i]._col,Weights[i]._row);
	  Weights[i].transpose(wt_transpose);
	  wt_transpose.mult(delta[i+1],delta[i]);

	  Matrix bias_upd(bias[i]._row,1);
	  bias_upd.add(delta[i],bias_upd);
	  bias_upd.mult(-learning_rate,bias_upd);
	  bias[i].add(bias_upd,bias[i]);
	}
//	cout<<"delta";
//	for(int i=0;i<delta.size();i++){
//		delta[i].print();
//		cout<<"\n";
//	}
}

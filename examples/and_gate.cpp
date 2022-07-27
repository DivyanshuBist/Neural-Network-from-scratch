#include<iostream>
#include "../Nnet.hpp"
#include<time.h>
#include <stdlib.h>
#include<unistd.h>
int main(){
srand(time(0));
	Neural_Network mynet;
	mynet.add(2);
	mynet.add(2);
	mynet.add(1);
	 for(int i=0;i<mynet.Weights.size();i++){
              mynet. Weights[i].print();
              cout<<"\n";
	 }
	 sleep(1);
	for(int i=0;i<20;i++){
		cout<<"Iteration no "<<i+1<<"\n";
		int a=1;
		int b=1;
		int val=a xor b;
		val=float(val);
		cout<<"Input is :"<<a<<" "<<b<<"\n";
//		cout<<"Target Output is :"<<(a and b)<<"\n";
		mynet.feedforward({a,b},{val});
		cout<<"\n";
	}

	 for(int i=0;i<mynet.Weights.size();i++){
              mynet. Weights[i].print();
              cout<<"\n";
	 }


}

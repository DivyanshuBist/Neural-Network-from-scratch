#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
class Matrix{
	public:
	int _row,_col;
	vector<vector<float>> mat;
	public:
	Matrix(int rows,int cols);
	void mult(const Matrix &M2,Matrix &result);
	void mult(float val,Matrix &result);
	void add(const Matrix &M2,Matrix &result);
	void add(float val,Matrix & result);
	void transpose(Matrix &result);
	void print();
	void set(int i,int j,float val);
};
Matrix::Matrix(int rows,int cols){
	_row=rows;
	_col=cols;
	mat.resize(rows,vector<float>(cols,0.00f));
}
void Matrix::mult(const Matrix &M2,Matrix & result){
	assert(_col==M2._row && _row==result._row && result._col==M2._col);
	for(int i=0;i<_row;i++){
	 	for(int j=0;j<M2._col;j++){
			for(int k=0;k<_col;k++){
			 	result.mat[i][j]+=this->mat[i][k]*M2.mat[k][j];
			}
		}
	}
}
void Matrix::mult(float val,Matrix& result){
	assert(result._row==_row && result._col==_col);
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			result.mat[i][j]=mat[i][j]*val;
		}
	}
}
void Matrix::add(const Matrix &M2,Matrix &result){
	assert(_row==M2._row && _col==M2._col && _row==result._row && _col==result._col);
	for(int i=0;i<_row;i++){
	 	for(int j=0;j<_col;j++){
			result.mat[i][j]=this->mat[i][j]+M2.mat[i][j];
		}
	}
}
void Matrix::transpose(Matrix &result){
	assert(result._row==_col && result._col==_row);
	Matrix temp(_col,_row);
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			temp.mat[i][j]=mat[j][i];
		}
	}
	result=temp;
}

void Matrix::add(float val,Matrix &result){

	assert(_row==result._row && _col==result._col);
	for(int i=0;i<_row;i++){
	 	for(int j=0;j<_col;j++){
			result.mat[i][j]=this->mat[i][j]+val;
		}
	}
}
void Matrix::print(){
	for(int i=0;i<_row;i++){
		for(int j=0;j<_col;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void Matrix::set(int i,int j,float val){
       assert((i>=0 or i<_row) && (j>=0 or j<_col));
       mat[i][j]=val;
}

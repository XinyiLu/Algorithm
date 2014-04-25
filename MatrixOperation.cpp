#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()==0)
			return;
		int row=matrix.size(),col=matrix[0].size();
		bool isRowZero=false,isColZero=false;

		for(int i=0;i<row;i++){
			if(matrix[i][0]==0){
				isRowZero=true;
				break;
			}
		}

		for(int j=0;j<col;j++){
			if(matrix[0][j]==0){
				isColZero=true;
				break;
			}
		}

		for(int i=1;i<row;i++){
			for(int j=1;j<col;j++){
				if(matrix[i][j]==0){
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}

		for(int i=1;i<row;i++){
			if(matrix[i][0]==0){
				for(int j=1;j<col;j++){
					matrix[i][j]=0;
				}
			}
		}

		for(int j=1;j<col;j++){
			if(matrix[0][j]==0){
				for(int i=1;i<row;i++){
					matrix[i][j]=0;
				}
			}
		}

		if(isRowZero){
			for(int i=0;i<row;i++){
				matrix[i][0]=0;
			}
		}

		if(isColZero){
			for(int j=0;j<col;j++){
				matrix[0][j]=0;
			}
		}
    }

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.size()==0)
			return false;
		int row=matrix.size(),col=matrix[0].size();
		return searchMatrixHelper(matrix,target,0,row*col-1);
    }


	bool searchMatrixHelper(vector<vector<int>> &matrix,int target,int start,int end){
		if(end<start)
			return false;

		int row=matrix.size(),col=matrix[0].size();
		if(start==end)
			return matrix[start/col][start%col]==target;

		int mid=start+(end-start)/2,midValue=matrix[mid/col][mid%col];
		if(midValue==target)
			return true;
		else if(midValue<target)
			return searchMatrixHelper(matrix,target,mid+1,end);
		else
			return searchMatrixHelper(matrix,target,start,mid-1);
	}

};
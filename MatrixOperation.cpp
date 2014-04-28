#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
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


	int maximalRectangle(vector<vector<char> > &matrix) {
		 if(matrix.size()==0)
			 return 0;
		 int area=0;
		 vector<int> prevList(matrix[0].size(),0);
		 for(int i=0;i<matrix.size();i++){
			vector<int> list;
			for(int j=0;j<matrix[i].size();j++){
				list.push_back(matrix[i][j]=='0'?0:1+prevList[j]);
			}
			area=max(area,matrixRectangleHelper(list));
			prevList=list;
		 }
		 return area;
    }

	class Node{
	public:
		int width;
		int height;
	public:
		Node(int h){
			width=1;
			height=h;
		}
		Node(int w,int h){
			width=w;
			height=h;
		}
	};

	int matrixRectangleHelper(vector<int> &list){
		stack<Node> s;
		if(list.size()==1){
			return list[0];
		}
		int area=0;
		s.push(Node(list[0]));
		for(int i=1;i<=list.size();i++){
			int curHeight=(i==list.size())?(-1):list[i];
			if(curHeight>=s.top().height){
				s.push(Node(curHeight));
			}else{
				int w=0;
				while(!s.empty()&&s.top().height>=curHeight){
					Node node=s.top();
					s.pop();
					w+=node.width;
					int temp=w*node.height;
					if(temp>area)
						area=temp;
				}
				s.push(Node(w+1,curHeight));
			}
		}

		return area;
	}
};
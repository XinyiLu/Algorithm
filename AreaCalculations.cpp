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
    int trap(int A[], int n) {
		if(n<3)
			return 0;
		vector<int> left(n,0);
		vector<int> right(n,0);

		int maxValue=A[0];
		for(int i=1;i<n;i++){
			maxValue=max(maxValue,A[i]);
			left[i]=maxValue;
		}

		maxValue=A[n-1];
		for(int i=n-2;i>0;i--){
			maxValue=max(A[i],maxValue);
			right[i]=maxValue;
		}

		int area=0;
		for(int i=1;i<n-1;i++){
			int height=min(left[i],right[i]);
			if(height>A[i]){
				area+=(height-A[i]);
			}
		}
		return area;
    }

	class Unit{
	public:
		int w;
		int h;
	public:
		Unit(){}
		Unit(int a,int b){
			w=a;
			h=b;
		}
	};

	int largestRectangleArea(vector<int> &height) {
		if(height.size()==0){
			return 0;
		}   

		stack<Unit> st;
		Unit first(1,height[0]);
		st.push(first);
		int area=height[0];

		for(int i=1;i<=height.size();i++){
			int curHeight=(i==height.size())?-1:height[i];
			if(curHeight>=st.top().h){
				Unit newUnit(1,curHeight);
				st.push(newUnit);
			}else{
				int curWidth=0;
				while(!st.empty()&&st.top().h>=curHeight){
					Unit curUnit=st.top();
					st.pop();
					curWidth+=curUnit.w;
					int curArea=curWidth*curUnit.h;
					area=max(area,curArea);
				}
				Unit newUnit(curWidth+1,curHeight);
				st.push(newUnit);
			}
		}
		return area;
    }

	void rotate(vector<vector<int> > &matrix) {
		for(int i=0;i<matrix.size()/2;i++){
			for(int j=i;j<matrix.size()-i-1;j++){
				int temp=matrix[i][j];
				matrix[i][j]=matrix[matrix.size()-1-j][i];
				matrix[matrix.size()-1-j][i]=matrix[matrix.size()-1-i][matrix.size()-1-j];
				matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[j][matrix.size()-1-i];
				matrix[j][matrix.size()-1-i]=temp;
			}
		}
    }


	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		    vector<int> list;
        if(matrix.size()==0)
            return list;
		   for(int r=0;r<=matrix.size()/2;r++){
			  int row=matrix.size(),col=matrix[0].size();
			  if(r<=(row-1-r)){
    			  for(int j=r;j<col-r;j++){
    				  list.push_back(matrix[r][j]);
    			  }
			  }
			  if(r<=(col-1-r)){
    			  for(int i=r+1;i<row-r-1;i++){
    			 		list.push_back(matrix[i][col-r-1]);
    			  }
			  }

			  if((row-1-r)>r){
				  for(int j=col-r-1;j>=r;j--){
					list.push_back(matrix[row-1-r][j]);
				  }
			  }

			  if(r<(col-r-1)&&(row-1-r)>r){
				  for(int k=row-r-2;k>r;k--){
					  list.push_back(matrix[k][r]);
				  }
			  }
		   }

        
		   
		   return list;
    }
    

	vector<vector<int> > generateMatrix(int n) {
		vector<int> unit(n,0);
		vector<vector<int>> list(n,unit);
		if(n==0)
			return list;

		int count=1;
		for(int r=0;r<n/2;r++){
			if(r<=n-1-r){
				for(int i=r;i<n-r;i++){
					list[r][i]=count++;
				}

				for(int j=r+1;j<n-1-r;j++){
					list[j][n-1-r]=count++;
				}
			}

			if(r<n-1-r){
				for(int i=n-1-r;i>=r;i--){
					list[n-1-r][i]=count++;
				}

				for(int j=n-r-2;j>r;j--){
					list[j][r]=count++;
				}
			}
		}

		if(n%2==1){
			list[n/2][n/2]=count++;	
		}
		return list;
		
    }

};






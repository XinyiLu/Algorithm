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
};
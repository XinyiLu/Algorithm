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

	int totalNQueens(int n) {
        vector<vector<int>> list=solveNQueensHelper(n,n-1);
		return list.size();
    }


    vector<vector<string> > solveNQueens(int n) {
		vector<vector<int>> list=solveNQueensHelper(n,n-1);
		vector<vector<string>> result;
		for(int i=0;i<list.size();i++){
			vector<int> unit=list[i];
			vector<string> strList;
			for(int j=0;j<n;j++){
				string str="";
				for(int k=0;k<unit[j];k++){
					str+=".";
				}
				str+="Q";
				for(int k=unit[j]+1;k<n;k++){
					str+=".";
				}
				strList.push_back(str);
			}

			result.push_back(strList);
		}
		return result;
    }

	vector<vector<int>> solveNQueensHelper(int n,int index){
		vector<vector<int>> result;
		if(index==-1){
			vector<int> unit;
			result.push_back(unit);
			return result;
		}
		vector<vector<int>> subset=solveNQueensHelper(n,index-1);
		for(int i=0;i<subset.size();i++){
			set<int> values=getNextPositions(subset[i],n);
			for(set<int>::iterator iter=values.begin();iter!=values.end();iter++){
				vector<int> list(subset[i]);
				list.push_back(*iter);
				result.push_back(list);
			}
		}
		return result;
	}


	set<int> getNextPositions(vector<int> list,int n){
		set<int> result;
		for(int i=0;i<n;i++){
			result.insert(i);
		}
		int row=list.size();
		for(int i=0;i<list.size();i++){
			result.erase(list[i]);
			result.erase(list[i]+(row-i));
			result.erase(list[i]-(row-i));
		}
		return result;
	}
};
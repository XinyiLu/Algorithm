#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
		return subsetsWithDupHelper(S,0);
    }

	vector<vector<int>> subsetsWithDupHelper(vector<int> &S,int start){
		vector<vector<int>> result;
		if(start==S.size()){
			vector<int> sub;
			result.push_back(sub);
			return result;
		}

		for(int index=start;index<S.size();index++){
			if(index>0&&S[index]==S[index]-1)
				continue;
			vector<vector<int>> subset=subsetsWithDupHelper(S,index+1);
			result.insert(result.begin(),subset.begin(),subset.end());
			for(int i=0;i<subset.size();i++){
				vector<int> temp(subset[i]);
				temp.insert(temp.begin(),S[index]);
				bool contains=false;
				for(int j=0;j<result.size();j++){
					if(result[j].size()==temp.size()&&result[j]==temp){
						contains=true;
						break;
					}
				}
				if(!contains){
					result.push_back(temp);
				}
			}
			break;
		}
		return result;
	}
};


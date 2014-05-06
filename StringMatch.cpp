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
    string minWindow(string S, string T) {
        if(T.length()>S.length()||T.length()==0)
			return "";

		map<char,int> hashmap;
		for(int i=0;i<T.length();i++){
			if(hashmap.find(T[i])==hashmap.end()){
				hashmap.insert(std::pair<char,int>(T[i],1));
			}else{
				hashmap.find(T[i])->second++;
			}
		}
		string window=S+" ";
		queue<int> q;
		for(int i=0;i<S.length();i++){
			map<char,int>::iterator iter=hashmap.find(S[i]);
			if(iter==hashmap.end())
				continue;
			iter->second--;
			q.push(i);
			int start=q.front();
			while(iter->second<=0&&checkWindow(hashmap)){
				if(window.length()>(i-start+1)){
					window=S.substr(start,i-start+1);
					if(window.length()==T.length())
					    return window;
				}
				iter=hashmap.find(S[start]);
				iter->second++;
				q.pop();
				start=q.front();
			}
		}

		return (window.length()==S.length()+1)?"":window;
    }

	bool checkWindow(map<char,int> hashmap){
		for(map<char,int>::iterator iter=hashmap.begin();iter!=hashmap.end();iter++){
			if(iter->second>0)
				return false;
		}
		return true;
	}
};	



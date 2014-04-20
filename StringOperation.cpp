#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		if(*needle==NULL&&*haystack==NULL){
            return haystack;
        }
		if(*needle==NULL||*haystack==NULL){
			return *haystack==NULL?NULL:haystack;
		}
		
		int haylen=strlen(haystack);
		int neelen=strlen(needle);

		int time=haylen-neelen;
		int i=0;
		while(i<=time){
			i++;
			char *pneedle=needle;
			char *phaystack=haystack;
			while(*phaystack!=NULL&&*pneedle!=NULL&&*phaystack==*pneedle){
				phaystack++;
				pneedle++;
			}
			if(*pneedle==NULL){
				return haystack;
			}
			haystack++;
		}
		return NULL;
    }

	bool strStrHelper(char *haystack, char *needle){
		while(*haystack!=NULL&&*needle!=NULL){
			if(*haystack!=*needle){
				return false;
			}
			haystack++;
			needle++;
		}
		return *needle==NULL;
	}

	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if(L.size()==0||S.length()<L.size()*L[0].length()){
			return result;
		}
		
		map<string,int> lmap;
		for(int i=0;i<L.size();i++){
			map<string,int>::iterator iter=lmap.find(L[i]);
			if(iter==lmap.end()){
				lmap.insert(std::pair<string,int>(L[i],1));
			}else{
				(iter->second)++;
			}
		}

		int unitLen=L[0].length();
		for(int i=0;i<=S.length()-L.size()*unitLen;i++){
			map<string,int> newMap(lmap);
			int j=0;
			for(;j<L.size();j++){
				string str=S.substr(j*unitLen+i,unitLen);
				map<string,int>::iterator iter=newMap.find(str);
				if(iter==newMap.end()||iter->second==0){
					break;
				}else{
					(iter->second)--;
				}
			}

			if(j==L.size()){
				result.push_back(i);
			}
		}
		return result;

    }

	

};

int main(){

	Solution sol;
	vector<string> vec;
	vec.push_back("is");
	sol.findSubstring("mississippi",vec);
	int value;
	cin>>value;
}
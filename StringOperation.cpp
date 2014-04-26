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

	string multiply(string num1, string num2) {
		   string str="";
		   if(num1.length()==0||num2.length()==0){
				return str;
		   }

		   if(num1.length()<num2.length()){
				string temp=num1;
				num1=num2;
				num2=temp;
		   }

		   for(int i=num2.length()-1;i>=0;i--){
				string tstr=multiplyHelper(num1,num2[i]-'0');
				for(int j=0;j<num2.length()-1-i;j++){
					tstr+='0';
				}
				str=add(str,tstr);
		   }
		   return str;
    }

	string multiplyHelper(string num1,int number){
		if(number==0||num1.compare("0")==0){
			return "0";
		}
		int advance=0;
		string str="";
		for(int i=num1.length()-1;i>=0;i--){
			int sum=advance+number*(num1[i]-'0');
			advance=sum/10;
			str=to_string((long long)sum%10)+str;
		}

		if(advance>0){
			str=to_string((long long)advance)+str;
		}
		return str;
	}

	string add(string num1,string num2){
		if(num1.length()*num2.length()==0){
			return num1.length()==0?num2:num1;
		}
		string str="";
		int minLen=min(num1.length(),num2.length());
		int advance=0;
		for(int i=0;i<minLen;i++){
			int sum=(num1[num1.length()-1-i]-'0')+(num2[num2.length()-1-i]-'0')+advance;
			advance=sum/10;
			str=to_string((long long)sum%10)+str;
		}

		if(num1.length()!=num2.length()){
			string num3=num1.length()>minLen?num1:num2;
			for(int i=minLen;i<num3.length();i++){
				int sum=(num3[num3.length()-1-i]-'0')+advance;
				advance=sum/10;
				str=to_string((long long)sum%10)+str;
			}
		}

		if(advance>0){
			str=to_string((long long)advance)+str;
		}

		return str;
	}


 bool isMatch(const char *s, const char *p) {
		if(*p==NULL){
			return *s==NULL;
		}else if(*s==NULL){
			return isPNull(p);
		}

		//first the index of the first *
		while(*s!=NULL&&*p!=NULL&&*p!='*'){
			if(*s==*p||*p=='?'){
				s++;
				p++;
			}else{
				return false;
			}
		}

		if(*s==NULL){
			return isPNull(p);
		}else if(*p==NULL){
			return *s==NULL;
		}
		const char *sbegin=s,*pbegin=p;

		//the index of the last *
		s+=strlen(s)-1;
		p+=strlen(p)-1;
		while(s>=sbegin&&p>pbegin&&*p!='*'){
			if(*s==*p||*p=='?'){
				s--;
				p--;
			}else{
				return false;
			}
		}
		if(p==pbegin){
			return true;
		}else if(s<sbegin){
			while(p>pbegin&&*p=='*'){
				p--;
			}
			return p==pbegin;
		}

		const char *send=s+1,*pend=p;
		//split p from pbegin to pend by *
		const char *pch=pbegin;
		while(pch<pend){
			pbegin=pch+1;
			pch=strchr(pbegin,'*');
			const char *sindex=matchSegment(sbegin,send,pbegin,pch);
			if(sindex==send+1){
				return false;
			}
			sbegin=sindex+(pch-pbegin);
		}

		return true;
    }

	const char* matchSegment(const char *sbegin,const char *send,const char *pbegin,const char *pend){
		while((send-sbegin)>=(pend-pbegin)){
			int i=0;
			for(;i<pend-pbegin;i++){
				if(*(sbegin+i)!=*(pbegin+i)&&*(pbegin+i)!='?'){
					break;
				}
			}
			if(i==pend-pbegin)
				return sbegin;
			sbegin++;
		}
		return send+1;
	}



	bool isPNull(const char* p){
		while(*p!=NULL&&*p=='*'){
				p++;
			}
		return *p==NULL;
	}


	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		map<string,vector<int>> hashmap;
		for(int i=0;i<strs.size();i++){
			string str(strs[i]);
			sort(str.begin(),str.end());
			map<string,vector<int>>::iterator iter=hashmap.find(str);
			if(hashmap.find(str)==hashmap.end()){
				vector<int> unit;
				unit.push_back(i);
				hashmap.insert(std::pair<string,vector<int>>(str,unit));
			}else{
				iter->second.push_back(i);
			}
		}   

		for(map<string,vector<int>>::iterator iter=hashmap.begin();iter!=hashmap.end();iter++){
			vector<int> indices=iter->second;
			if(indices.size()>1){
				for(int i=0;i<indices.size();i++){
					result.push_back(strs[indices[i]]);
				}
			}
		}

		return result;
    }


	string addBinary(string a, string b) {
        int advance=0;
		int i=a.length()-1,j=b.length()-1;
		string str="";
		for(;i>=0&&j>=0;i--,j--){
			int sum=a[i]-'0'+b[j]-'0'+advance;
			advance=sum/2;
			str=to_string((long long)sum%2)+str;
		}
		
		if(i>=0||j>=0){
			string c=(i<0)?b.substr(0,j+1):a.substr(0,i+1);
			for(int k=c.length()-1;k>=0;k--){
				int sum=c[k]-'0'+advance;
				str=to_string((long long)sum%2)+str;
				advance=sum/2;
			}
		}

		if(advance>0){
			str=to_string((long long)advance)+str;
		}

		return str;
    }



};



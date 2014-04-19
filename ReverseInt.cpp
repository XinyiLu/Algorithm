//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
using namespace std;


int reverse(int x) {
	bool negative=false;
	if(x<0){
		negative=true;
		x=-x;
	}
	string str=std::to_string((long long)x);
	string restr;
	for(int i=str.length()-1;i>=0;i--){
		restr.push_back(str[i]);
	}
	int result;
	stringstream(restr)>>result;
	return negative?(-result):result;
}

int atoi(const char *str) {
	if(*str==NULL)
		return 0;

	while(*str!=NULL&&*str==' '){
		str++;
	}
	bool negative=false;
	if(*str=='-'||*str=='+'){
		negative=(*str=='-')?true:false;
		str++;
	}else{
		while(*str!=NULL&&*str==' '){
			str++;
		}
	}
	
	long long result=0;
	while(*str!=NULL){
		if(*str>='0'&&*str<='9'){
			result=result*10+(*str)-'0';
		}else{
			break;
		}
		str++;
	}

	result=negative?(-result):result;
	if(result>INT_MAX){
		result=INT_MAX;
	}else if(result<INT_MIN){
		result=INT_MIN;
	}

	return (int)result;
}


bool isPalindrome(int x) {
	long long result=x;
	if(x<0){
		return false;
	}

	string str=std::to_string(result);
	int i=0,j=str.length()-1;
	while(i<j){
		if(str[i]!=str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}



bool isMatch(const char *s, const char *p) {
	 if(*p==NULL)
		return *s==NULL;
	

	while(*p!=NULL){
		if(*s!=NULL&&*(p+1)!='*'&&(*s==*p||*p=='.')){
			s++;
			p++;
		}else if(*(p+1)=='*'){
		    p++;
			const char *ps=s;
			if(*s!=NULL){
				while(*s!=NULL&&(*s==*(p-1)||(*(p-1)=='.'))){
					s++;
					if(isMatch(s,p+1)){
						return true;
					}
				}
			}
			return isMatch(ps,p+1);

		}else{
			return false;
		}
	}

	return isMatch(s,p);
}

int main(){
	int value;
	cout<<isMatch("ab",".*c");
	cin>>value;
	return 1;
}





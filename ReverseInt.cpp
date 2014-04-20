//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <algorithm>
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

int maxArea(vector<int> &height) {
	if(height.size()<2){
		return 0;
	}
	int area=0;
	int i=0,j=height.size()-1;
	while(i<j){
		int tempArea=min(height[i],height[j])*(j-i);
		area=max(area,tempArea);
		if(height[i]<height[j]){
			int tHeight=height[i];
			while(i<j&&height[i]<=tHeight){
				i++;
			}
		}else{
			int tHeight=height[j];
			while(i<j&&height[j]<=tHeight){
				j--;
			}
		}

	}


	return area;
}



string longestCommonPrefix(vector<string> &strs) {
	if(strs.size()==0){
		return "";
	}
	string prefix=strs[0];
	for(int i=1;i<strs.size();i++){
		if(strs[i].length()<prefix.length()){
			prefix=strs[i];
		}
	}

	for(int i=0;i<strs.size();i++){
		for(int j=0;j<prefix.length();j++){
			if(prefix[j]!=strs[i][j]){
				prefix=prefix.substr(0,j);
				break;
			}
		}
	}

	return prefix;
}

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int>> result;
    if(num.size()<3)
        return result;
	sort(num.begin(),num.end()); 

	return threeSumHelper(num,0,3,0);
}


vector<vector<int>> threeSumHelper(vector<int> &num,int start,int index,int sum){
	vector<vector<int>> result;
	if(index==0){
		if(sum==0){
			vector<int> newVector;
			result.push_back(newVector);
		}
		return result;
	}

	for(int i=start;i<=num.size()-index&&num[i]<=sum;i++){
		if(i>start&&num[i]==num[i-1]){
			continue;
		}
		vector<vector<int>> subset=threeSumHelper(num,i+1,index-1,sum-num[i]);
		for(int j=0;j<subset.size();j++){
			vector<int> temp=subset[j];
			temp.insert(temp.begin(),num[i]);
			result.push_back(temp);
		}
	}
	return result;
}

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int>> result;
	if(num.size()<4){
		return result;
	}
	sort(num.begin(),num.end());
	for(int i=0;i<=num.size()-4;i++){
		if(i>0&&num[i]==num[i-1]){
			continue;
		}
		for(int j=i+1;j<=num.size()-3;j++){
			if(j>i+1&&num[j]==num[j-1]){
				continue;
			}
			int x=j+1,y=num.size()-1;
			int remain=target-num[i]-num[j];
			while(x<y){
				while(x<y&&x>j+1&&num[x]==num[x-1]){
					x++;
				}

				while(x<y&&y<num.size()-1&&num[y]==num[y+1]){
					y--;
				}

				if(x>=y){
					break;
				}
				int tempSum=num[x]+num[y];
				if(tempSum==remain){
					int tempUnit[]={num[i],num[j],num[x],num[y]};
					vector<int> unit(tempUnit,tempUnit+sizeof(tempUnit)/sizeof(int));
					result.push_back(unit);
					x++;
					y--;
				}else if(tempSum<remain){
					int originX=num[x];
					while(x<y&&num[x]<=originX){
						x++;
					}
					
				}else{
					int originY=num[y];
					while(x<y&&num[y]>=originY){
						y--;
					}
				
				}
			
			}
			
		}
	
	}

	return result;

}

void threeSumClosestHelper(vector<int> &num,int target,int sum,int start,int index,int *closest){
        if(index==0){
			if(abs(sum-target)<abs((*closest)-target)){
				*closest=sum;
			}
			return;
        }
        
		for(int i=start;i<=num.size()-index;i++){
			if(i>start&&num[i]==num[i-1])
				continue;
			threeSumClosestHelper(num,target,sum+num[i],i+1,index-1,closest);
			if(*closest==target){
			    return;
			}
		}

 }

int threeSumClosest(vector<int> &num, int target) {
		if(num.size()<3)
			return 0;
        int closest=num[0]+num[1]+num[2];
		int *pointer=&closest;
		threeSumClosestHelper(num,target,0,0,3,pointer);
		return *pointer;
}
    


int main(){
	int value;
	int a[]={0,1,2};
	vector<int> v(a,a+sizeof(a)/sizeof(int));
	cout<<threeSumClosest(v,0);
	cin>>value;
	return 1;
}





#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
		 if(s.length()%2==1)
			 return false;
		 stack<char> st;
		 for(int i=0;i<s.length();i++){
			 if(s[i]=='('||s[i]=='['||s[i]=='{'){
				st.push(s[i]);
			 }else if(!st.empty()&&((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='[')||(s[i]=='}'&&st.top()=='{'))){
				st.pop();
			 }else{
				return false;
			 }
		 
		 }
		 return st.empty();
    }

	vector<string> generateParenthesis(int n) {
		 return generateParenthesisHelper(n,n); 
    }

	vector<string> generateParenthesisHelper(int left,int right){
		vector<string> result;
		if(left==0&&right==0){
			result.push_back("");
			return result;
		}

		if(left>0){
			vector<string> subset=generateParenthesisHelper(left-1,right);
			for(int i=0;i<subset.size();i++){
				result.push_back("("+subset[i]);
			}
		}
		if(right>left){
			vector<string> subset=generateParenthesisHelper(left,right-1);
			for(int i=0;i<subset.size();i++){
				result.push_back(")"+subset[i]);
			}
		}
		return result;
	}

	int longestValidParentheses(string s) {
		if(s.length()<2)
			return 0;
        stack<int> st;
		int maxNum=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('){
				st.push(-1);
			}else{
				int count=0;
				while(!st.empty()&&st.top()!=-1){
					count+=st.top();
					st.pop();
				}
				if(st.empty()){
					maxNum=max(maxNum,count);
				}else{
					st.pop();
					count+=2;
					while(!st.empty()&&st.top()!=-1){
						count+=st.top();
						st.pop();
					}
					maxNum=max(maxNum,count);
					st.push(count);
				}
			}
		}
		return maxNum;
    }

};
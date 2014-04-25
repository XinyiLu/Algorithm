#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	 int sqrt(int x) {
        return sqrtHelper(x,0,x/2+1);
		
    }
    
    int sqrtHelper(int x,long long start,long long end){
        if(start==end){
            if(x<start*start)
                return start-1;
            return start;
        }
        
        long long mid=start+(end-start)/2;
        if(mid*mid==x){
            return mid;
        }else if(mid*mid<x){
            return sqrtHelper(x,mid+1,end);
        }else{
            if(start==mid)
                return start-1;
            return sqrtHelper(x,start,mid-1);
        }
        
    }

	vector<int> plusOne(vector<int> &digits) {
		int advance=1;
		vector<int> result;
		for(int i=digits.size()-1;i>=0;i--){
			int sum=digits[i]+advance;
			advance=sum/10;
			result.insert(result.begin(),sum%10);
		}

		if(advance>0){
			result.insert(result.begin(),advance);
		}
		return result;
    }

    int divide(int dividend, int divisor) {
		long long ldividend=dividend,ldivisor=divisor;
	    bool negative=(dividend>0&&divisor<0)||(dividend<0&&divisor>0)?true:false;
	    ldividend=abs((long long)dividend);
	    ldivisor=abs((long long)divisor);
		if(ldividend<ldivisor){
			return 0;
		}
        if(ldivisor==1){
            if((negative&&dividend<0)||(!negative&&dividend>0)){
                return dividend;
            }
            return -dividend;
        }
		int result=0;
		for(int i=31;i>=0;i--){
			if(ldividend>=(ldivisor<<i)){
				ldividend-=ldivisor<<i;
				result+=1<<i;
			}
		}

		return negative?-result:result;
    }
	
	void nextPermutation(vector<int> &num) {
			if(num.size()<2){
			return;
		}

		int start=num.size()-2,highest=num[num.size()-1];
		int hindex=num.size()-1;
		while(start>=0&&num[start]>=highest){
			highest=num[start];
			hindex=start;
			start--;
		}
		if(start<0){
			sort(num.begin(),num.end());
		}else{
			int minNum=num[start];
			for(int j=start+1;j<num.size();j++){
				if(num[j]>minNum&&num[j]<highest){
					highest=num[j];
					hindex=j;
				}
			}

			num[start]=highest;
			num[hindex]=minNum;
			sort(num.begin()+(start+1),num.end());
		}
    }


};
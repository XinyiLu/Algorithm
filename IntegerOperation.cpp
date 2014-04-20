#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

class Solution {
public:
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
};
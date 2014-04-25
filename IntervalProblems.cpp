#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;



struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };


class Solution {
public:

	static bool compare(Interval v1,Interval v2){
		if(v1.start==v2.start)
			return v1.end<v2.end;
		else
			return v1.start<v2.start;
	}

    vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(),intervals.end(),Solution::compare);
		if(intervals.size()<2){
			return intervals;
		}
		
		vector<Interval> result;
		int start=0,curIndex=1;
		while(start<intervals.size()){
			Interval inter=intervals[start];
			while(curIndex<intervals.size()&&intervals[curIndex].start<=inter.end){
				inter.end=max(inter.end,intervals[curIndex].end);
				curIndex++;
			}
			
			result.push_back(inter);
			start=curIndex;
			curIndex++;
		
		}

		return result;
    }

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {  

		vector<Interval> result; 
		int curIndex=0;
		while(curIndex<intervals.size()&&newInterval.start>intervals[curIndex].end){
			result.push_back(intervals[curIndex]);
			curIndex++;
		}

		if(curIndex==intervals.size()){
			result.push_back(newInterval);
			return result;
		}
		Interval inter=intervals[curIndex];
		inter.start=min(inter.start,newInterval.start);
		inter.end=newInterval.end;
		while(curIndex<intervals.size()&&newInterval.end>=intervals[curIndex].start){
			inter.end=max(inter.end,intervals[curIndex].end);
			curIndex++;
		}

		result.push_back(inter);
		result.insert(result.end(),intervals.begin()+curIndex,intervals.end());
		return result;
    }

	int lengthOfLastWord(const char *s) {
		const char *pch=s;
		const char *begin=s,*end=begin;
		while(*pch!=NULL&&*s!=NULL){
			pch=strchr(s,' ');
			if(pch==NULL){
				break;
			}
			if(pch-s>0){
				begin=s;
				end=pch;
			}
			s=pch+1;
			
		}
        if(*s==NULL){
            return (end-begin);
            
        }
		return strlen(s);
    }


};


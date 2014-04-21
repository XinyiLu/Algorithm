#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

	int search(int A[], int n, int target) {
		return searchHelper(A,n,target,0,n-1);   
    }

	int searchHelper(int A[],int n,int target,int start,int end){
		if(end<start){
			return -1;
		}else if(start==end){
			return (A[start]==target)?start:-1;
		}

		int mid=start+(end-start)/2;
		if(A[mid]==target){
			return mid;
		}else if(A[mid]<target){
			if(A[end]>A[mid]&&A[end]<target){
				return searchHelper(A,n,target,start,mid-1);
			}else{
				return searchHelper(A,n,target,mid+1,end);
			}
		}else{
			if(A[start]>target&&A[start]<=A[mid]){
				return searchHelper(A,n,target,mid+1,end);
			}else{
				return searchHelper(A,n,target,start,mid-1);
			}
		}
	}

    int removeElement(int A[], int n, int elem) {
		int index=0;
		for(int i=0;i<n;i++){
			if(A[i]==elem){
				continue;
			}
			A[index++]=A[i];
		}

		return index;
    }

	int removeDuplicates(int A[], int n) {
		if(n<2){
			return n;
		}
        int index=1;
		int prevValue=A[0];
		for(int i=1;i<n;i++){
			if(A[i]==prevValue)
				continue;
			prevValue=A[i];
			A[index++]=A[i];
		}
		return index;
    }

	 	vector<int> searchRange(int A[], int n, int target) {
		int arr[]={-1,-1};
		   vector<int> result(arr,arr+sizeof(arr)/sizeof(int));
		   searchRangeHelper(&result,A,0,n-1,target);
		   return result;
		   
    }

	void searchRangeHelper(vector<int> *indices,int A[],int start,int end,int target){
		if(end<start){
			return;
		}else if(start==end){
			if(A[start]!=target){
				return;
			}

			if(indices->at(0)==-1||indices->at(0)>start){
				indices->at(0)=start;
			}
			if(indices->at(1)==-1||indices->at(1)<start){
				indices->at(1)=start;
			}
			return;
		}

		int mid=start+(end-start)/2;
		if(A[mid]==target){
			searchRangeHelper(indices,A,start,mid-1,target);
			if(indices->at(0)==-1){
				indices->at(0)=mid;
			}
			searchRangeHelper(indices,A,mid+1,end,target);
			if(indices->at(1)==-1||indices->at(1)<mid){
				indices->at(1)=mid;
			}
		}else if(A[mid]<target){
			searchRangeHelper(indices,A,mid+1,end,target);
		}else{
			searchRangeHelper(indices,A,start,mid-1,target);
		}
	}
};


int main(){
	Solution sol;
	int range[]={2,2};
	sol.searchRange(range,2,2);

	return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <set>
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


	int searchInsert(int A[], int n, int target) {
		  return searchInsertHelper(A,0,n-1,target); 
    }

	int searchInsertHelper(int A[],int start,int end,int target){
		if(start>end){
			return start;
		}else if(start==end){
			if(A[start]==target){
				return start;
			}else if(A[start]<target){
				return start+1;
			}else{
				return start;
			}
		}

		int mid=start+(end-start)/2;
		if(A[mid]==target){
			return mid;
		}else if(A[mid]>target){
			return searchInsertHelper(A,start,mid-1,target);
		}else{
			return searchInsertHelper(A,mid+1,end,target);
		}
		
	}


	int firstMissingPositive(int A[], int n) {
		if(n==0){
			return 1;
		}

		for(int i=0;i<n;i++){
			if(A[i]>0&&A[i]<=n&&A[i]!=i+1){
			    if(A[A[i]-1]==A[i]){
			        A[i]=0;
			    }
				else if(A[i]>i+1){
					int temp=A[A[i]-1];
					A[A[i]-1]=A[i];
					A[i]=temp;
					i--;
				}else if(A[i]<i+1){
					A[A[i]-1]=A[i];
					A[i]=0;
				}
			}
		}

		int m=n+1;
		for(int i=0;i<n;i++){
			if(A[i]!=i+1){
				m=i+1;
				break;
			}
		}
		return m;
    }


	bool canJump(int A[], int n) {
		if(n<=1)
			return true;

		int index=n-1;
		while(index>=0){
			int minIndex=index;
			for(int i=index-1;i>=0;i--){
				if((index-i)<=A[i]){
					minIndex=i;
				}
			}
			if(minIndex==index){
				break;
			}
			index=minIndex;
		}
		return index<=0;
    }

	int jump(int A[], int n) {
        if(n<=1)
			return 0;
		set<int> list;
		list.insert(n-1);
		return jumpHelper(A,list,n-1,0);
    }

	int jumpHelper(int A[],set<int> list,int index,int level){
		if(index==0){
			return level; 
		}
		set<int> result;
		int smallest=index-1;
		for(set<int>::iterator iter=list.begin();iter!=list.end();iter++){
			for(int j=0;j<index;j++){
				if(((*iter-j)<=A[j])){
					result.insert(j);
					smallest=min(smallest,j);
				}
			}
		}

		return jumpHelper(A,result,smallest,level+1);
	}
};


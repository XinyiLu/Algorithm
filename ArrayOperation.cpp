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
};
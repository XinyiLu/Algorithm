#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
			return "1";
		}    
		string str="";
		string substr=countAndSay(n-1);
		
		char number=substr[0],count=1;
		for(int i=1;i<substr.length();i++){
			if(number==substr[i]){
				count++;
			}else{
			    stringstream ss;
			    string c;
				ss<<number;
				ss>>c;
				str+=(to_string((long long)count)+c);
				count=1;
				number=substr[i];
			}
		}
		stringstream ss;
		string c;
		ss<<number;
		ss>>c;
		str+=(to_string((long long)count)+c);
		return str;
    }


	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		  sort(candidates.begin(),candidates.end());
		  return combinationSumHelper(candidates,target,0);
    }

	vector<vector<int>> combinationSumHelper(vector<int> &candidates,int target,int start){
		vector<vector<int>> result;
		if(target==0){
    		vector<int> newSet;
    		result.push_back(newSet);
    		return result;
    	}

		for(int i=start;i<candidates.size()&&candidates[i]<=target;i++){
			if(i>start&&candidates[i-1]==candidates[i])
				continue; 
			for(int j=1;j*candidates[i]<=target;j++){
				vector<vector<int>> subset=combinationSumHelper(candidates,target-candidates[i]*j,i+1);
				vector<int> subvalue(j,candidates[i]);
				for(int k=0;k<subset.size();k++){
					subset[k].insert(subset[k].begin(),subvalue.begin(),subvalue.end());
				}
				result.insert(result.begin(),subset.begin(),subset.end());
			}
		}

		return result;
	}


	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(),num.end());
		return combinationSum2Helper(num,target,0);
    }

	vector<vector<int>> combinationSum2Helper(vector<int> &num,int target,int index){
		vector<vector<int>> result;
		if(target==0){
			vector<int> newSet;
			result.push_back(newSet);
			return result;
		}

		for(int i=index;i<num.size()&&target>=num[i];i++){
			if(i>index&&num[i]==num[i-1])
				continue;
			vector<vector<int>> subset=combinationSum2Helper(num,target-num[i],i+1);
			for(int j=0;j<subset.size();j++){
				subset[j].insert(subset[j].begin(),num[i]);
			}
			result.insert(result.end(),subset.begin(),subset.end());
		}
		return result;
	}


	vector<vector<int> > permute(vector<int> &num) {
		sort(num.begin(),num.end());
		return permuteHelper(num,0);
    }

	vector<vector<int>> permuteHelper(vector<int> &num,int start){
		vector<vector<int>> result;
		if(start==num.size()){
			vector<int> unit;
			result.push_back(unit);
			return result;
		}

		for(int i=start;i<num.size();i++){
			vector<int> newNum(num);
			int temp=newNum[i];
			newNum[i]=newNum[start];
			vector<vector<int>> subset=permuteHelper(newNum,start+1);
			for(int j=0;j<subset.size();j++){
				subset[j].insert(subset[j].begin(),temp);
			}
			result.insert(result.end(),subset.begin(),subset.end());
		}
		return result;
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(),num.end()); 
		return permuteUniqueHelper(num,0);
    }

	vector<vector<int>> permuteUniqueHelper(vector<int> &num,int start){
		vector<vector<int>> result;
		if(start==num.size()){
			vector<int> unit;
			result.push_back(unit);
			return result;
		}

		for(int i=start;i<num.size();i++){
			if(i>start&&num[i]==num[i-1])
				continue;
			vector<int> newNum(num);
			int temp=newNum[i];
			newNum[i]=newNum[start];
			sort(newNum.begin()+start+1,newNum.end());
			vector<vector<int>> subset=permuteUniqueHelper(newNum,start+1);
			for(int j=0;j<subset.size();j++){
				subset[j].insert(subset[j].begin(),temp);
			}
			result.insert(result.end(),subset.begin(),subset.end());
		}
		return result;
	}


	double pow(double x, int n) {
		  bool negative=n<0?true:false;
		  n=abs(n);
		  double number=(n%2==1)?x:1;
		  if(n/2>0){
			number*=pow(x*x,n/2);
		  }
		  return negative?(1.0/number):number;
    }


	int uniquePaths(int m,int n) {
		if(m<2||n<2){
            return 1;
        }
		int path[m][n];
		for(int i=0;i<m;i++){
		    path[i][0]=1;
		}
		for(int j=1;j<n;j++){
		    path[0][j]=1;
		}
		
		for(int i=1;i<m;i++){
		    for(int j=1;j<n;j++){
		        path[i][j]=path[i-1][j]+path[i][j-1];  
		    }
		    
		}
		
	    return path[m-1][n-1];	
    }

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0)
            return 1;
        
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int path[m][n];
        path[0][0]=obstacleGrid[0][0]==1?0:1;
        for(int i=1;i<m;i++){
            path[i][0]=obstacleGrid[i][0]==0?path[i-1][0]:0;
        }
        
        for(int j=1;j<n;j++){
            path[0][j]=obstacleGrid[0][j]==0?path[0][j-1]:0;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                path[i][j]=obstacleGrid[i][j]==0?(path[i-1][j]+path[i][j-1]):0;
            }
        }
        
        return path[m-1][n-1];
    }


	string getPermutation(int n, int k) {
		vector<int> result;
		vector<int> factor;
		factor.push_back(0);
		int f=1;
		for(int i=1;i<n;i++){
			f*=i;
			factor.push_back(f);
			result.push_back(i);
		}
		result.push_back(n);

		int findex=n-1;
		int index=0;
		k--;
		while(k>0){
			int tempIndex=k/factor[findex];
			k=k%factor[findex];
			int tempValue=result[tempIndex+index];
			result.erase(result.begin()+tempIndex+index);
			result.insert(result.begin()+index,tempValue);
			index++;
			findex--;
		}
		string str="";
		for(int i=0;i<result.size();i++){
			str+=to_string((long long)result[i]);
		}
		return str;
    }


	int minPathSum(vector<vector<int> > &grid) {
		if(grid.size()==0)
			return 0;
		int row=grid.size(),col=grid[0].size();
		int **a=(int **)malloc(sizeof(int *)*row);
		for(int i=0;i<row;i++){
			*a=(int *)malloc(sizeof(int)*col);
		}

		a[0][0]=grid[0][0];
		for(int i=1;i<row;i++){
			a[i][0]=a[i-1][0]+grid[i][0];
		}

		for(int j=1;j<col;j++){
			a[0][j]=a[0][j-1]+grid[0][j];
		}

		for(int i=1;i<row;i++){
			for(int j=1;j<col;j++){
				a[i][j]=min(a[i-1][j],a[i][j-1])+grid[i][j];
			}
		}
		int result=a[row-1][col-1];
		for(int i=0;i<row;i++){
			free(*a);
		}
		free(a);
		return result;
    }

	int minDistance(string word1, string word2) {
        int row=word1.length(),col=word2.length();
        
        int mat[row+1][col+1];
        mat[0][0]=0;
        for(int i=1;i<row+1;i++){
            mat[i][0]=mat[i-1][0]+1;
        }
        for(int j=1;j<col+1;j++){
            mat[0][j]=mat[0][j-1]+1;
        }
        
        for(int i=1;i<row+1;i++){
            for(int j=1;j<col+1;j++){
                mat[i][j]=min(mat[i-1][j],mat[i][j-1])+1;
                mat[i][j]=min(mat[i][j],(word1[i-1]==word2[j-1]?mat[i-1][j-1]:(mat[i-1][j-1]+1)));
            }
        }
        
        return mat[row][col];
    }

};



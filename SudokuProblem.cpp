#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>


using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++){
			set<int> row;
			set<int> col;
			for(int j=0;j<9;j++){
				char rc=board[i][j],cc=board[j][i];
				if(rc!='.'){
					if(row.find(rc-'0')==row.end()){
						row.insert(rc-'0');
					}else{
						return false;
					}
				}
				if(cc!='.'){
					if(col.find(cc-'0')==col.end()){
						col.insert(cc-'0');
					}else{
						return false;
					}
				}

			}
		
		}



		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				int x=i*3,y=3*j;
				set<int> square; 
				for(int ii=0;ii<3;ii++){
					for(int jj=0;jj<3;jj++){
						char c=board[x+ii][y+jj];
						if(c=='.')
							continue;
						if(square.find(c-'0')==square.end()){
							square.insert(c-'0');
						}else{
							return false;
						}
					}
				}
			
			}
		}
		return true;
			
    }

	void solveSudoku(vector<vector<char> > &board){
		solveSudokuHelper(board);
	}

	bool solveSudokuHelper(vector<vector<char> > &board) {
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.'){
					vector<int> values=getPossibleValues(board,i,j);
					for(int k=0;k<values.size();k++){
						board[i][j]=values[k]+'0';
						if(solveSudokuHelper(board)){
							break;
						}
						board[i][j]='.';
					}
					if(board[i][j]=='.')
						return false;
				}
			}
		
		}
		return true;
    }

	vector<int> getPossibleValues(vector<vector<char>> &board,int x,int y){
		vector<int> result;
		int sx=(x/3)*3,sy=(y/3)*3;
		set<int> valueSet;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i+sx][j+sy]!='.'){
					valueSet.insert(board[i+sx][j+sy]-'0');
				}
			}
		}

		for(int i=0;i<9;i++){
			if(board[i][y]!='.'){
				valueSet.insert(board[i][y]-'0');
			}
			if(board[x][i]!='.'){
				valueSet.insert(board[x][i]-'0');
			}
		}

		for(int value=1;value<=9;value++){
			if(valueSet.find(value)==valueSet.end()){
				result.push_back(value);
			}
		}
		return result;
	
	}


};


int main(){

	Solution sol;
	string str[]={".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
	vector<vector<char>> board;
	for(int i=0;i<9;i++){
		vector<char> row(str[i].begin(),str[i].end());
		board.push_back(row);
	}
	bool result=sol.isValidSudoku(board);
	cout<<result;
	cin>>result;
	return 1;

}
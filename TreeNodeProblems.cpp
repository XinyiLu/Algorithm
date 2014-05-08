#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1,n);
    }

	vector<TreeNode *> generateTreesHelper(int start,int end){
		vector<TreeNode *> result;
		if(start>end){
			result.push_back(NULL);
			return result;
		}

		for(int index=start;index<=end;index++){
			vector<TreeNode *> leftTreeSet=generateTreesHelper(start,index-1);
			vector<TreeNode *> rightTreeSet=generateTreesHelper(index+1,end);

			for(int left=0;left<leftTreeSet.size();left++){
				for(int right=0;right<rightTreeSet.size();right++){
					TreeNode *root=new TreeNode(index);
					root->left=leftTreeSet[left];
					root->right=rightTreeSet[right];
					result.push_back(root);
				}
			}
		}
		return result;
	}

	vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
		inorderTraversalHelper(root,result);
		return result;
    }

	void inorderTraversalHelper(TreeNode *root,vector<int> &list){
		if(root==NULL){
			return;
		}

		inorderTraversalHelper(root->left,list);
		list.push_back(root->val);
		inorderTraversalHelper(root->right,list);
	}

	bool isValidBST(TreeNode *root) {
		vector<int> list=inorderTraversal(root);
		for(int i=0;i<list.size()-1;i++){
			if(list[i]>list[i+1])
				return false;
		}
		return true;
    }

	vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
		if(root==NULL)
			return result;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		vector<int> curLevel;
		while(!q.empty()){
			TreeNode *node=q.front();
			q.pop();
			if(node==NULL){
				vector<int> newLevel(curLevel);
				result.push_back(newLevel);
				curLevel.clear();
				if(q.empty())
					break;
				q.push(NULL);
			}else{
				curLevel.push_back(node->val);
				if(node->left!=NULL){
					q.push(node->left);
				}
				if(node->right!=NULL){
					q.push(node->right);
				}
			}
		}
		
		return result;
    }

	vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
		if(root==NULL)
			return result;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		vector<int> curLevel;
		while(!q.empty()){
			TreeNode *node=q.front();
			q.pop();
			if(node==NULL){
				vector<int> newLevel(curLevel);
				result.insert(result.begin(),newLevel);
				curLevel.clear();
				if(q.empty())
					break;
				q.push(NULL);
			}else{
				curLevel.push_back(node->val);
				if(node->left!=NULL){
					q.push(node->left);
				}
				if(node->right!=NULL){
					q.push(node->right);
				}
			}
		}
		
		return result;
    }

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
         vector<vector<int>> result;
		if(root==NULL)
			return result;
		vector<TreeNode *> s;
		
		s.push_back(NULL);
		s.push_back(root);
		vector<int> curLevel;
		vector<TreeNode *> nextLevel;
		bool reverse=false;
		while(!s.empty()){
			TreeNode *node=s[s.size()-1];
			s.erase(s.end()-1);
			if(node==NULL){
				vector<int> newLevel(curLevel);
				result.push_back(newLevel);
				curLevel.clear();
				if(nextLevel.empty())
					break;
				s.insert(s.begin(),NULL);
				s.insert(s.end(),nextLevel.begin(),nextLevel.end());
				nextLevel.clear();
				reverse=!reverse;
			}else{
				curLevel.push_back(node->val);
				TreeNode *first=(reverse?node->right:node->left);
				TreeNode *second=(reverse?node->left:node->right);
				
				if(first!=NULL){
					nextLevel.push_back(first);
				}
				if(second!=NULL){
					nextLevel.push_back(second);
				}
			}
		}
		
		return result;
	}


	TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder) {
		int index=postorder.size()-1;
        return buildTreeHelper1(inorder,postorder,index,0,index);
    }
	
	TreeNode *buildTreeHelper1(vector<int> &inorder,vector<int> &postorder,int &index,int start,int end){
		if(start>end||index<0)
			return NULL;

		int midIndex=findPosition(inorder,postorder[index--]);
		TreeNode *right=buildTreeHelper1(inorder,postorder,index,midIndex+1,end);
		TreeNode *left=buildTreeHelper1(inorder,postorder,index,start,midIndex-1);
		TreeNode *root=new TreeNode(inorder[midIndex]);
		root->left=left;
		root->right=right;
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int index=0;
		return buildTreeHelper(inorder,preorder,index,0,inorder.size()-1);
    }

	TreeNode *buildTreeHelper(vector<int> &inorder,vector<int> &preorder,int &index,int start,int end){
		if(start>end||index<0)
			return NULL;

		int midIndex=findPosition(inorder,preorder[index++]);
		TreeNode *left=buildTreeHelper(inorder,preorder,index,start,midIndex-1);
		TreeNode *right=buildTreeHelper(inorder,preorder,index,midIndex+1,end);
		TreeNode *root=new TreeNode(inorder[midIndex]);
		root->left=left;
		root->right=right;
		return root;
	}
	int findPosition(vector<int> a,int value){
		for(int i=0;i<a.size();i++){
			if(a[i]==value)
				return i;
		
		}
		return -1;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		  return sortedArrayToBSTHelper(num,0,num.size()-1);
    }
	
	TreeNode *sortedArrayToBSTHelper(vector<int> &num,int start,int end){
		if(end<start)
			return NULL;

		int mid=(end-start)/2+start;
		TreeNode *root=new TreeNode(num[mid]);
		root->left=sortedArrayToBSTHelper(num,start,mid-1);
		root->right=sortedArrayToBSTHelper(num,mid+1,end);
		return root;
	}


	TreeNode *sortedListToBST(ListNode *head) {
       return sortedListToBSTHelper(head,NULL);
    }

	TreeNode *sortedListToBSTHelper(ListNode *head,ListNode *end){
		if(head==end){
			return NULL;
		}
		
		if(head->next==end){
			return (new TreeNode(head->val));
		}

		ListNode *midNode=head,*fNode=head->next;
		while(fNode!=end&&fNode->next!=end){
			fNode=fNode->next->next;
			midNode=midNode->next;
		}
		TreeNode *root=new TreeNode(midNode->val);
		root->left=sortedListToBSTHelper(head,midNode);		
		root->right=(midNode==end?NULL:sortedListToBSTHelper(midNode->next,end));
		return root;
	}
	
	int minDepth(TreeNode *root) {
        if(root==NULL)
			return 0;

        if(root->left==NULL)
            return minDepth(root->right)+1;
        else if(root->right==NULL)
            return minDepth(root->left)+1;
        else
		    return min(minDepth(root->left),minDepth(root->right))+1;
    }


	bool isBalanced(TreeNode *root) {
        return isBalancedHelper(root)>=0;
    }

	int isBalancedHelper(TreeNode *root){
		if(root==NULL)
			return 0;

		int left=isBalancedHelper(root->left);
		if(left<0)
			return left;
		int right=isBalancedHelper(root->right);
		if(right<0||abs(left-right)>1){
			return -1;
		}

		return max(left,right)+1;
	}

	int maxDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }

	bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL||q==NULL){
            return (p==NULL&&q==NULL);
        }
        
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }

	vector<int> preorderTraversal(TreeNode *root) {
        vector<int> list;
		preorderTraversalHelper(root,list);
		return list;
    }

	void preorderTraversalHelper(TreeNode *root,vector<int> &list){
		if(root==NULL)
			return;
		
		list.push_back(root->val);
		preorderTraversalHelper(root->left,list);
		preorderTraversalHelper(root->right,list);
	}
};

int main(){

	Solution sol;
	TreeNode *root=new TreeNode(1);
	sol.zigzagLevelOrder(root);
	int value;
	cin>>value;
}
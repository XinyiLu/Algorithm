#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *newHead=new ListNode(0);;
		newHead->next=head;
		ListNode *pEnd=head,*phead=newHead;
		for(int i=0;i<n;i++){
			pEnd=pEnd->next;
		}
		

		while(pEnd!=NULL){
			pEnd=pEnd->next;
			phead=phead->next;
		}

		phead->next=phead->next->next;
		return newHead->next;
    }


	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.size()==0){
			return NULL;
		}
		if(lists.size()==1){
			return lists[0];
		}

		vector<ListNode *> newList;
		for(int i=0;i<lists.size()-1;i+=2){
			newList.push_back(mergeTwoLists(lists[i],lists[i+1]));
		} 

		if(lists.size()%2==1){
			newList.push_back(lists[lists.size()-1]);
		}

		return mergeKLists(newList);
    }

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
		if(l1==NULL||l2==NULL){
			return l1==NULL?l2:l1;
		}

		ListNode *head=new ListNode(0);
		ListNode *plist=head;
		while(l1!=NULL&&l2!=NULL){
			if(l1->val>l2->val){
				plist->next=l2;
				l2=l2->next;
			}else{
				plist->next=l1;
				l1=l1->next;
			}
			plist=plist->next;
		}
		
		if(l1!=NULL||l2!=NULL){
			plist->next=(l1==NULL)?l2:l1;
		}
		return head->next;
	}

	ListNode *swapPairs(ListNode *head) {
		if(head==NULL||head->next==NULL){
			return head;
		}   

		ListNode *newHead=new ListNode(0);
		newHead->next=head;
		ListNode *pprev=newHead,*pcur=head,*pnext=head->next;

		while(pcur!=NULL&&pnext!=NULL){
			ListNode *tempNext=pnext->next;
			pnext->next=pcur;
			pprev->next=pnext;
			pcur->next=tempNext;
			pprev=pcur;
			pcur=tempNext;
			pnext=(pcur==NULL)?NULL:pcur->next;
		}

		pprev->next=pcur;
		return newHead->next;
    }


	ListNode *rotateRight(ListNode *head, int k) {
		   if(head==NULL)
				return NULL;
		   ListNode *newHead=new ListNode(0);
		   newHead->next=head;
		   ListNode *prevNode=newHead,*curNode=head;
		   int count=0;
		   while(curNode!=NULL){
			curNode=curNode->next;
			count++;
		   }
		   k=k%count;
		   if(k==0)
			   return head;

		   curNode=head;
		   for(int i=1;i<k;i++){
				curNode=curNode->next;
		   }

		   while(curNode->next!=NULL){
				curNode=curNode->next;
				prevNode=prevNode->next;
		   }

		   newHead->next=prevNode->next;
		   prevNode->next=NULL;
		   curNode->next=head;

		   return newHead->next;
    }


	ListNode *reverseKGroup(ListNode *head, int k) {
		if(k==1||head==NULL||head->next==NULL){
			return head;
		}
        int total=0;
		ListNode *pNode=head;
		while(pNode!=NULL){
			total++;
			pNode=pNode->next;
		}
		ListNode *newHead=new ListNode(0);
		newHead->next=head;
		int round=total/k;
		ListNode *pprev=newHead,*pcur=head,*pnext=head->next;
		for(int i=0;i<round;i++){
			ListNode *thead=pcur;
			for(int j=1;j<k;j++){
				ListNode *tnext=pnext->next;
				pnext->next=pcur;
				pcur=pnext;
				pnext=tnext;
			}

			thead->next=pnext;
			pprev->next=pcur;
			pprev=thead;
			pcur=pnext;
			pnext=(pnext==NULL)?NULL:pnext->next;
		}

		pprev->next=pcur;
		return newHead->next;
    }


	ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        ListNode *head=new ListNode(0);
		ListNode *curNode=head;
		while(l1!=NULL&&l2!=NULL){
			if(l1->val<l2->val){
				curNode->next=l1;
				l1=l1->next;
			}else{
				curNode->next=l2;
				l2=l2->next;
			}
			curNode=curNode->next;
		}

		if(l1!=NULL){
			curNode->next=l1;
		}else if(l2!=NULL){
			curNode->next=l2;
		}
		return head->next;
    }

	ListNode *deleteDuplicates(ListNode *head) {
		if(head==NULL||head->next==NULL)
			return head;

		int value=head->val;
		ListNode *prevNode=head,*curNode=head->next;
		while(curNode!=NULL){
			if(curNode->val!=value){
				value=curNode->val;
				prevNode->next=curNode;
				prevNode=prevNode->next;
			}
			curNode=curNode->next;
		}

		prevNode->next=curNode;
		return head;
    }

	ListNode *deleteDuplicates1(ListNode *head) {
		if(head==NULL||head->next==NULL)
			return head;
        ListNode *newHead=new ListNode(0);
		newHead->next=head;
		ListNode *prevNode=newHead,*curNode=head;
		int value=head->val;

		while(curNode!=NULL&&curNode->next!=NULL){
			if(curNode->next->val!=value){
				value=curNode->next->val;
				prevNode->next=curNode;
				prevNode=prevNode->next;
			}
			
			curNode=curNode->next;
		}
		
		prevNode->next=curNode;
		return newHead->next;
    }
};
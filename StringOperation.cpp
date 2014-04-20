#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		if(*needle==NULL&&*haystack==NULL){
            return haystack;
        }
		if(*needle==NULL||*haystack==NULL){
			return *haystack==NULL?NULL:haystack;
		}
		
		int haylen=strlen(haystack);
		int neelen=strlen(needle);

		int time=haylen-neelen;
		int i=0;
		while(i<=time){
			i++;
			char *pneedle=needle;
			char *phaystack=haystack;
			while(*phaystack!=NULL&&*pneedle!=NULL&&*phaystack==*pneedle){
				phaystack++;
				pneedle++;
			}
			if(*pneedle==NULL){
				return haystack;
			}
			haystack++;
		}
		return NULL;
    }

	bool strStrHelper(char *haystack, char *needle){
		while(*haystack!=NULL&&*needle!=NULL){
			if(*haystack!=*needle){
				return false;
			}
			haystack++;
			needle++;
		}
		return *needle==NULL;
	}
};
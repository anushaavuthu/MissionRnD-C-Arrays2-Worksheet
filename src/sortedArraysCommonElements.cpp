/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A != NULL) && (B != NULL)){
		int flag = 0, ptr = 0, count = 0;
		struct transaction* res = (struct transaction*)malloc(sizeof(struct transaction) * 3);
		for (int i = 0; i < ALen; i++){
			for (int j = 0; j < BLen; j++){
				flag = 0;
				for (int k = 0; k < 11; k++){
					if (A[i].date[k] != B[j].date[k]){
						flag = 1;
						break;
					}
				}
				if (flag == 0){
					count++;
					res[ptr++] = A[i];
				}
			}
		}
		if (count == 0){
			return NULL;
		}
		return res;
	}
		
	return NULL;
}
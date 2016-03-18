/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int length(char* str){
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int isOlder(char *dob1, char *dob2) {
	int i, j, date1 = 0, date2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0;
	if (length(dob1) == 10 && length(dob2) == 10){
		for (i = 0; i < 10; i++)
		{
			if (i != 2 && i != 5){
				if ((dob1[i] >= '0' && dob1[i] <= '9') && (dob2[i] >= '0' && dob2[i] <= '9')){

					//conversion
					for (j = 0; j < 2; j++){
						date1 = (date1 * 10) + (dob1[j] - '0');
						date2 = (date2 * 10) + (dob2[j] - '0');
					}
					j++;
					while (j < 5){
						month1 = (month1 * 10) + (dob1[j] - '0');
						month2 = (month2 * 10) + (dob2[j] - '0');
						j++;
					}
					j++;
					while (j < 10){
						year1 = (year1 * 10) + (dob1[j] - '0');
						year2 = (year2 * 10) + (dob2[j] - '0');
						j++;
					}

					//validation
					if (month1 < 13 && month2 < 13){
						if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12){
							if (date1 >= 32){
								return -1;
							}
						}
						else if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11){
							if (date1 >= 31){
								return -1;
							}
						}
						else{
							if (year1 % 4 == 0){
								if (date1 >= 30){
									return -1;
								}
							}
							else{
								if (date1 >= 29){
									return -1;
								}
							}
						}
						if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12){
							if (date2 >= 32){
								return -1;
							}
						}
						else if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11){
							if (date2 >= 31){
								return -1;
							}
						}
						else{
							if (year2 % 4 == 0){
								if (date2 >= 30){
									return -1;
								}
							}
							else{
								if (date2 >= 29){
									return -1;
								}
							}
						}
					}
					else{
						return -1;
					}

					//comparision
					if (year1 < year2){
						return 1;
					}
					else if (year2 < year1){
						return 2;
					}
					else{
						if (month1 < month2){
							return 1;
						}
						else if (month2 < month1){
							return 2;
						}
						else{
							if (date1 < date2){
								return 1;
							}
							else if (date2 < date1){
								return 2;
							}
							else{
								return 0;
							}
						}
					}
				}
				else{
					return -1;
				}
			}
		}
	}
	else{
		return -1;
	}
	return 0;
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A != NULL) && (B != NULL)){
		int ptr = 0, i = 0, j = 0;
		struct transaction* res = (struct transaction*)malloc(sizeof(struct transaction) * 6);
		while ((i < ALen) && (j < BLen)){
			int m = isOlder(A[i].date, B[j].date);
			printf("%d ", m);
			if (m == 1){
				res[ptr++] = A[i];
				i++;
			}
			else{
				res[ptr++] = B[j];
				j++;
			}
		}
		if (i == ALen){
			for (int k = j; k < BLen; k++){
				res[ptr++] = B[k];
			}
		}
		else{
			for (int k = i; k < ALen; k++){
				res[ptr++] = A[k];
			}
		}
		return res;
	}
	return NULL;
}

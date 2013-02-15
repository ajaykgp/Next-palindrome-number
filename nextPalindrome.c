/*

This program takes a natural number as input and computes
the smallest palindrome number greater than the input. It doesn't
compute the correct output for a number having all 9's. For such numbers
the correct output is input + 2.

*/

#include <stdio.h>
#define MAX 50

void nextPalindrome(char s[], int length);

int main(void)
{
	char c, s[MAX];
	int i = 0, length;
	while((c = getchar()) != '\n') s[i++] = c; 
	length = i;
	nextPalindrome(s, length);
	for(i = 0; i < length; i++) printf("%c", s[i]);
	printf("\n");
	return 0;
}

void nextPalindrome(char s[], int length)
{
	int flag = 0, i = 0, j = length - 1;
	while(((j - i) != 1) && ((j - i) != 0)){
		if(s[j] < s[i]) flag = 1;
		else if(s[j] > s[i]) flag = 0;
		s[j--] = s[i++]; 
	}
	if((j - i) == 1){
		if(s[i] < s[j]) s[i] = s[j];
		else if(s[i] > s[j]) s[j] = s[i];
		else if((s[i] == s[j]) && (flag == 0)){
			if(s[i] != '9'){
				s[i]++;
				s[j]++;
			}
			else{
				do{
					s[i] = '0';
					s[j] = '0';
					i--;
					j++;
				}while((i >= 0) && (j < length) && (s[i] == '9') && (s[j] == '9'));
				s[i]++;
				s[j]++;
			}
		}
	}
	if((j - i) == 0){
		if((flag == 0) && (s[j] != '9')) s[j]++;
		else if((flag == 0) && (s[j] == '9')){
			do{
				s[i] = '0';
				s[j] = '0';
				i--;
				j++;
			} while((i >= 0) && (j < length) && (s[i] == '9') && (s[j] == '9'));
			s[i]++;
			s[j]++;
		}
	}
} 
	


/*************************************************************************
	> File Name: brackets.c
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2022 02:33:26 PM CST
 ************************************************************************/

#include<stdio.h>
bool judgeOne(char *s, int *i, int d) {
	bool flag = true;
	int j = d;
	printf("in %d\n", *i);
	while(s[*i] && flag) {
		switch(s[*i]) {
			case '(' :
				++(*i);
				flag = judgeOne(s, i, d + 1);
				if (s[*i] == ')') {
					++(*i);
					flag &= true;
				} 
				else if (s[*i] == ']' || s[*i] == '}' || s[*i] == '\0') {flag = false;}
				break;
			case '[': {
				++(*i);
				flag = judgeOne(s, i, d + 1);
				if (s[*i] == ']') {
					++(*i);
					flag &= true;
				} 
				else if (s[*i] == ')' || s[*i] == '}' || s[*i] == '\0') {flag = false;}
				

			} break;
			case '{': {
				++(*i);
				flag = judgeOne(s, i, d + 1);
				if (s[*i] == '}') {
					++(*i);
					flag &= true;
				} 
				else if (s[*i] == ']' || s[*i] == ')' || s[*i] == '\0') {flag = false;}
				

			}break;
			case ')':
			case '}': return j == 0 ? false :true && flag;
			case ']':
			default :
				return false;
		}
	}
	return flag;
}


int main() {


	return 0;
}



/**
 * @author: SEKin 
 * @Date: 2022-09-20 14:54:58 
 * @description:  KMP 模式匹配算法
 * @Last Modified time: 2022-09-20 14:54:58 
 */
#include "./mystring.h";

void GetNextArr(Str s, int next[]){
	int j,k;
	j = 0, k = -1;
	next[0] = -1;

	while (j < s.length - 1)
	{
		if(k == -1 || s.str[k] == s.str[j]){ //能形成新的前后缀
			k++;
			j++;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

//  s: 主串 t:子串
int kmpIndex(Str s, Str t){
	int i = 0,j = 0;
	int next[MAXSIZE];
	GetNextArr(t, next);

	while (i < s.length && j < t.length)
	{
		if(j == -1 || s.str[i] == t.str[j]){
			j++;
			i++;
		}else{
			j = next[j];
		}
	}

	if(j >= t.length){
		return i - t.length;
	}else{
		return -1;
	}
}


// 改进算法 就是在主串和子串的当前位置不相同时，子串要移动到当前位置所对应的next中的位置next[j]，要是子串中 s[next[j]] = s[j],相当于又回来了，还是不相等，还是得再移动。索性就移动到最先第一次遇到得那个字符上。

void GetNextVal(Str s, int nextval[]){
	int j,k;
	j = 0, k = -1;
	nextval[0] = -1;

	while (j < s.length - 1)
	{
		if(k == -1 || s.str[k] == s.str[j]){ //能形成新的前后缀
			k++;
			j++;
			if(s.str[k]!=s.str[j]){ // 提前判断下一位，在不相同时，跳到一开始不相同的处
				nextval[j] = k;
			}else{
				nextval[j] = nextval[k];
			}
		} else {
			k = nextval[k];
		}
	}
}

//  s: 主串 t:子串
int kmpIndexPro(Str s, Str t){
	int i = 0,j = 0;
	int next[MAXSIZE];
	GetNextVal(t, next);

	while (i < s.length && j < t.length)
	{
		if(j == -1 || s.str[i] == t.str[j]){
			j++;
			i++;
		}else{
			j = next[j];
		}
	}

	if(j >= t.length){
		return i - t.length;
	}else{
		return -1;
	}
}

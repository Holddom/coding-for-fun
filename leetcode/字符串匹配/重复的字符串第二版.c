bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);   //双倍字符串法
	//原汁原味的c语言
	//原字符串加倍，去头去尾得k，如果能从中找到子串的话，那么一定是
	//重复的字符串
	char* k = (char*)malloc((2 * len + 1) * sizeof(char));
	k[0] = '\0';
	strcat(k, s);
	strcat(k, s);
	int flag = (strstr(k + 1, s) - k != len);
	//追加两次后从k+1处遍历相当于去头，如果差为len说明到了尾部必定重合的地方，判断不等于len就是
	//相当于去尾
	free(k);
	return flag;
}
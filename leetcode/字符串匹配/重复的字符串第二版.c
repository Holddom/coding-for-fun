bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);   //˫���ַ�����
	//ԭ֭ԭζ��c����
	//ԭ�ַ����ӱ���ȥͷȥβ��k������ܴ����ҵ��Ӵ��Ļ�����ôһ����
	//�ظ����ַ���
	char* k = (char*)malloc((2 * len + 1) * sizeof(char));
	k[0] = '\0';
	strcat(k, s);
	strcat(k, s);
	int flag = (strstr(k + 1, s) - k != len);
	//׷�����κ��k+1�������൱��ȥͷ�������Ϊlen˵������β���ض��غϵĵط����жϲ�����len����
	//�൱��ȥβ
	free(k);
	return flag;
}
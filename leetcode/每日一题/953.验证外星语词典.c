int getpos(char c1,char c2,char* order)
{
    if(c1!='\0'&&c2=='\0') return -1;
    if(c1=='\0'&&c2!='\0') return 1;
    if(c1==c2)  return 0;
    int pos1;
    int pos2;
    for(int i=0;order[i]!='\0';i++)
    {
        if(order[i]==c1)
        pos1=i;
        if(order[i]==c2)
        pos2=i;
    }
    return pos2-pos1;
}

bool isAlienSorted(char ** words, int wordsSize, char * order){
    //bool ret;
    if(wordsSize==1)
    return true;

    for(int i=1;i<wordsSize;i++)
    {
        int j;
        int k;
        int len1=strlen(words[i-1]);
        int len2=strlen(words[i]);
        for( j=0,k=0; j<=len1&&k<=len2;j++,k++)
        {
            int flag=getpos(words[i-1][j],words[i][k],order);
            if(flag>0)
            break;
            if(flag==0)
            continue;
            if(flag<0)
            {
                return false;
            }
        }
    }
    return true;
}




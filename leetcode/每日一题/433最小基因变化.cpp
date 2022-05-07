class Solution {
private: 
    int minNum=INT_MAX , num=0;
    unordered_set <string> set;

public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end)               //dfs
        {
            minNum=min(minNum,num);
            return minNum;
        }
        for(string &str: bank)
        {
            int dif=0;
            for(int i=0;i<str.size();i++)
            {
                if(str[i]!=start[i])
                dif++;
                if(dif>1)
                break;
            }
            if(dif==1&&set.find(str)==set.end())
            {
                set.insert(str);
                num++;
                minMutation(str,end,bank);
                set.erase(str);
                num--;
            }
        }
        return minNum==INT_MAX?-1:minNum;
    }
};


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set <string> set_for_bank(bank.begin(),bank.end());
        queue<string> q;
        q.push(start);                   //bfs
        unordered_set <string> visited;
        visited.insert(start);
        int nums=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string cur=q.front();
                q.pop();
                if(cur==end)
                return nums;
                
                string ch="ACGT";
                for(char c : ch)
                {
                    for(int j=0;j<cur.size();j++)
                    {
                        string next=cur;
                        next[j]=c;
                        if(set_for_bank.count(next)&&!visited.count(next))
                        {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            nums++;
        }
        return -1;
    }
};




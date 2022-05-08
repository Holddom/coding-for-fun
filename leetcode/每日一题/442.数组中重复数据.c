class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set <string> set_for_bank(bank.begin(),bank.end());
        queue<string> q;
        q.push(start);
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


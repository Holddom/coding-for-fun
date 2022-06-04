class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans=0;
        unordered_set <string> map;
        for(auto &i:emails)
        {
            string log;
            for(char ch:i)
            {
                if(ch=='+'||ch=='@')
                break;

                if(ch!='.')
                log+=ch;
            }
            map.emplace(log+i.substr(i.find('@')));
        }
        return map.size();
    }
};


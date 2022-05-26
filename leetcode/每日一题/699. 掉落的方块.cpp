class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size();
        vector<int> height(n);
        for(int i=0;i<n;++i)
        {
            height[i]=positions[i][1];
            int left1=positions[i][0];
            int right1=positions[i][1]+left1-1;
            for(int j=0;j<i;++j)
            {

                int left2=positions[j][0];
                int right2=positions[j][1]+left2-1;
                if(right1>=left2&&right2>=left1)
                {
                 height[i]=max(height[i],height[j]+positions[i][1]);
                }
            }
        }
        for(int k=1;k<n;k++)
        {
            height[k]=max(height[k],height[k-1]);
        }
        return height;
    }
};
//±©Á¦½â·¨ 

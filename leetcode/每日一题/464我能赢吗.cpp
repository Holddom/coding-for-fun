class Solution {
private:
    // visited[i] == 0，说明没有计算过
    // visited[i] == 1，说明计算过，结果为 true
    // visited[i] == 2，说明计算过，结果为 false
    int visited[1 << 21];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal)
            return false;
        // 判断当前做选择的玩家（先手），是否一定赢
        // 开始时，state = 0，表示「公共整数集」中的所有数字都未被使用过
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
    
    // 当前做选择的玩家是否一定赢
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        if (visited[state] == 1) return true;
        if (visited[state] == 2) return false;
        // 遍历可选择的公共整数
        for (int x = 1; x <= maxChoosableInteger; ++x) {
            // 如果 x 已经被使用过了，则不能选择
            if ((1 << x) & state) continue;
            // 如果选择了 x 以后，大于等于了 desiredTotal，当前玩家赢
            if (sum + x >= desiredTotal) {
                visited[state] = 1;
                return true;
            }
            // 当前玩家选择了 x 以后，判断对方玩家一定输吗？
            if (!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) {
                visited[state] = 1;
                return true;
            }
        }
        visited[state] = 2;
        return false;
    }
    
};





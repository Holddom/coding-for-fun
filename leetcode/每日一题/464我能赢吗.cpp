class Solution {
private:
    // visited[i] == 0��˵��û�м����
    // visited[i] == 1��˵������������Ϊ true
    // visited[i] == 2��˵������������Ϊ false
    int visited[1 << 21];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal)
            return false;
        // �жϵ�ǰ��ѡ�����ң����֣����Ƿ�һ��Ӯ
        // ��ʼʱ��state = 0����ʾ���������������е��������ֶ�δ��ʹ�ù�
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
    
    // ��ǰ��ѡ�������Ƿ�һ��Ӯ
    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal) {
        if (visited[state] == 1) return true;
        if (visited[state] == 2) return false;
        // ������ѡ��Ĺ�������
        for (int x = 1; x <= maxChoosableInteger; ++x) {
            // ��� x �Ѿ���ʹ�ù��ˣ�����ѡ��
            if ((1 << x) & state) continue;
            // ���ѡ���� x �Ժ󣬴��ڵ����� desiredTotal����ǰ���Ӯ
            if (sum + x >= desiredTotal) {
                visited[state] = 1;
                return true;
            }
            // ��ǰ���ѡ���� x �Ժ��ж϶Է����һ������
            if (!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) {
                visited[state] = 1;
                return true;
            }
        }
        visited[state] = 2;
        return false;
    }
    
};





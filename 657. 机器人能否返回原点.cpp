// https://leetcode-cn.com/problems/robot-return-to-origin/
// 这题 HelloWorld 级别吧...

class Solution {
public:
    bool judgeCircle(string moves) {
        int count[4] = {0};
        for(int i=0;i<moves.length();i++){
            switch(moves[i]){
                case 'R':
                    count[0]++;
                    continue;
                case 'L':
                    count[1]++;
                    continue;
                case 'U':
                    count[2]++;
                    continue;
                case 'D':
                    count[3]++;
                    continue;           
            }
        }
        return !(count[0]^count[1])&&!(count[2]^count[3]);
    }
};
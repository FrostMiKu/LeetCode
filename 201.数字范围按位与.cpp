// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
// 这题明显就是找规律题
// 因为是按位与，所以只要有一个数该位为0，则最终结果为零。
// 又因为数组是连续的，所以零从最低位开始向高位..扩散？蔓延？（完了语文老师哭了）
// 总之，找到二进制串的前缀，然后补零就好了 =。=

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};
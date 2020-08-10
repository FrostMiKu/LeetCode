// https://leetcode-cn.com/problems/count-binary-substrings/
// 题目要求0或者1连续出现，则连续的x个0和连续的y个1，总共可产生 fmin(x,y) 个符合要求的子串

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int last=0;
        int j = 0;
        int i = 1;
        for(;i<s.length(); i++){
            char c = s[i-1];
            if(s[i]!=c){
                count += fmin(last,i-j);
                last= i-j;
                j=i;
            }
        }
        count += fmin(last,i-j);
        return count;
    }
};
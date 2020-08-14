// https://leetcode-cn.com/problems/valid-parentheses/
// 经典括号匹配题，大家都懂，就是个栈，直接用STL光速签到了（

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())return true;

        stack<char> stk;

        for(int i=0;i<s.size();i++){
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }

            if((stk.top()=='('&&s[i]==')')||(stk.top()+2==s[i])){
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }

        return stk.empty()?true:false;
    }
};
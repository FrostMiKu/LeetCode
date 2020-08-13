// https://leetcode-cn.com/problems/multiply-strings/

// 前几天大数加法，今天大数乘法 囧rz
// 想到两种思路，一个是复用之前大数加法的代码，另一个就是直接进行大数乘法。
// 看了题解之后才想起来，这个可以看成是 x=10 的多项式乘法，而多项式乘法其实就是数值计算意义上的卷积。
// 然后卷积计算可以用快速傅里叶变换加速，然鹅现在的我不会了:(越活越倒退...
// 下面给出第二种思路的解法：

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.length();
        int n = num2.length();
        
        auto arr = vector<int>(m+n);

        for(int i=n-1;i>=0;i--){
            int x = num2[i] - '0';
            for(int j=m-1;j>=0;j--){
                int y = num1[j] - '0';
                arr[i+j+1]+=x*y;
            }
        }
        for(int i=m+n-1;i>0;i--){
            if(arr[i]>=10){
                arr[i-1]+=arr[i]/10;
                arr[i]=arr[i]%10;
            }
        }

        string ans = "";
        for(int i = arr[0]==0?1:0;i<m+n;i++){
            ans.push_back(arr[i]+'0');
        }

        return ans;        
    }
};
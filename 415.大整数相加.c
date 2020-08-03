// https://leetcode-cn.com/problems/add-strings/
char * addStrings(char * num1, char * num2){
    int i = strlen(num1)-1, j = strlen(num2)-1, c = 0;

    char* ans = (char*)malloc(sizeof(char) * (fmax(i,j)+3));

    int len = 0;

    while(i>=0||j>=0||c!=0){
        int x = i>=0?num1[i]-'0':0;
        int y = j>=0?num2[j]-'0':0;
        int add = x + y + c;
        ans[len++] = add % 10 + '0';
        c = add/10;
        i--;j--;
    }

    for(int i=0 ; 2*i<len; i++){
        int tmp = ans[i];
        ans[i]=ans[len-1-i];
        ans[len-1-i]=tmp;
    }

    ans[len++]=0;
    return ans;
}
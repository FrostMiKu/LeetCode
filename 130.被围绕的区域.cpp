// https://leetcode-cn.com/problems/surrounded-regions/
// 从边界往里面搜索，吧和边界相连的O全部替换成C，最后遍历整个数组把C变成O；把O变成X
// 今天的代码有点丑（

class Solution {

    queue<pair<int,int>> que;

public:
    void bfs(vector<vector<char>>& board){
        if(que.size() == 0) return;
        pair<int,int> tmp = que.front();
        que.pop();
        int x=tmp.first;
        int y=tmp.second;

        if(!(x>=board.size()||y>=board[0].size())){
            if(board[x][y]=='O'){
                board[x][y]='C';

                que.emplace(x-1,y);
                que.emplace(x,y+1);
                que.emplace(x+1,y);
                que.emplace(x,y-1);
            }
        }

        bfs(board);
    }

    void solve(vector<vector<char>>& board) {
        int w = board.size();
        if(!w) return;
        int h = board[0].size();

        for(int i=1;i<h-1;i++){
            if(board[0][i]=='O'){
                que.emplace(0,i);
            }
            if(board[w-1][i]=='O'){
                que.emplace(w-1,i);
            }
        }
        for(int i=0;i<w;i++){
            if(board[i][0]=='O'){
                que.emplace(i,0);
            }
            if(board[i][h-1]=='O'){
                que.emplace(i,h-1);
            }
        }
        bfs(board);
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='C'){
                    board[i][j]='O';
                }
            }
        }
    }
};
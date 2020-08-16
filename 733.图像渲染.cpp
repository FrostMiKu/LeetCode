// https://leetcode-cn.com/problems/flood-fill/
// 这题不就是最基本的bfs么（
// 昨天dp太难，忘写了（

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int w = image.size();
        if(w==0) return image;
        int h = image[0].size();

        int target = image[sr][sc];
        if(target == newColor) return image;

        queue<pair<int,int>> que;
        que.emplace(sr,sc);

        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(x>=w||x<0||y>=h||y<0) continue;
            if(image[x][y]==target){
                image[x][y]=newColor;
                que.emplace(x+1,y);
                que.emplace(x-1,y);
                que.emplace(x,y+1);
                que.emplace(x,y-1);
            }
        }

        return image;
    }
};
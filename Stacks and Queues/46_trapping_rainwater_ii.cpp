class Solution {
public:
    vector<vector<int>>dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    struct node{
        int height;
        int x;
        int y;
    };

    struct Compare{
        bool operator()(node const& a, node const& b){
            return a.height > b.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));

        priority_queue<node, vector<node>, Compare>pq;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!(i == 0 || j == 0 || i == n-1 || j == m-1)){
                    continue;
                }

                vis[i][j] = true;
                node t;
                t.x = i;
                t.y = j;
                t.height = heightMap[i][j];
                pq.push(t);

            }
        }

        int ans = 0;
        int maxHeight = INT_MIN;
        while(!pq.empty()){
            node front = pq.top();
            pq.pop();
            maxHeight = max(maxHeight, front.height);

            int curr_x = front.x;
            int curr_y = front.y;

            for(int i = 0; i < 4; i++){
                int new_x = curr_x + dir[i][0];
                int new_y = curr_y + dir[i][1];

                if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || vis[new_x][new_y]){
                    continue;
                }  

                int height = heightMap[new_x][new_y];
                if(height < maxHeight){
                    ans += (maxHeight - height);
                }   

                node temp;
                temp.x = new_x;
                temp.y = new_y;
                temp.height = height;
                pq.push(temp);
                vis[new_x][new_y] = true;       
            }
        }
        return ans;
    }
};
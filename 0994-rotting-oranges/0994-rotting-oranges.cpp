class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
                
            }
        }
        int count=0;
        q.push({-1,-1});
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            if(i==-1 && j==-1 && q.size()==1)
            {
                q.pop();
                break;
            }
            else if(i==-1 && j==-1 && q.size()>1)
            {
                count++;
                q.pop();
                q.push({-1,-1});
                
            }
            else{
                if((i-1)>=0 && grid[i-1][j]==1)
                {grid[i-1][j]=2;
                 q.push({i-1,j});}
                if((i+1)<r && grid[i+1][j]==1)
                { grid[i+1][j]=2;
                 q.push({i+1,j});}
                if((j-1)>=0 && grid[i][j-1]==1)
                 {
                     grid[i][j-1]=2;
                     q.push({i,j-1});}
                if((j+1)<c && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                q.pop();
            }
            
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return count; 
    }
};
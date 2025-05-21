#include <iostream>
using namespace std;


int Dijkstra(vector<vector<int>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = grid[0][0];
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({grid[0][0], {0, 0}});
    
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    while (!pq.empty()) {
        auto [cost, cell] = pq.top();
        pq.pop();
        
        int x = cell.first;
        int y = cell.second;
        
        if (x == n - 1 && y == m - 1) {
            return cost;
        }
        
        for (auto dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                if (cost + grid[newX][newY] < dist[newX][newY]) {
                    dist[newX][newY] = cost + grid[newX][newY];
                    pq.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
    }
    
    return -1; // If no path found
    
}
   

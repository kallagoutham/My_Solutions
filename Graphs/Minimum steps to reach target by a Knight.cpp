#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(pair<int,int> knightPos, pair<int,int> targetPos,
                         int N){
    if(knightPos==targetPos){
        return 0;
    }
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    queue<pair<int,int>> q;
    q.push(knightPos);
    int size=q.size();
    bool visit[N + 1][N + 1]={false};
    visit[knightPos.first][knightPos.second]=true;
    pair<int,int> t;
    int counter=0;
    int x,y;
    while(!q.empty()){
        while(size>0){
            t=q.front();
            if(t==targetPos){
                return counter;
            }
            for(int i=0;i<8;i++){
                x = t.first + dx[i];
                y = t.second + dy[i];
                if (isInside(x, y, N) && !visit[x][y]) {
                    visit[x][y] = true;
                    auto p = make_pair(x, y);
                    q.push(p);
                }
            }
            q.pop();
            size--;
        }
        size=q.size();
        counter++;
    }
    return -1;
}
int main()
{
    int N = 30;
    pair<int,int> knightPos = { 1, 1 };
    pair<int,int> targetPos = { 30, 30 };

    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}
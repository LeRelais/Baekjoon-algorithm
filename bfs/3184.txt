#include iostream

#include vector

#include queue

#include string

#include cstring

using namespace std;

 

const int MAX = 250;

 

int R, C;

int sheep, wolf;

string graph[MAX];

bool visited[MAX][MAX];

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

void BFS(int y, int x)

{

        int curSheep = 0, curWolf = 0;

        queue pairint, int q; y, x

        q.push({ y, x });

        visited[y][x] = true;

        if (graph[y][x] == 'o')

                 curSheep++;

        else if (graph[y][x] == 'v')

                 curWolf++;

 

        같은 칸 안에 있는 양과 늑대의 수를 센다

        while (!q.empty())

        {

                 int curY = q.front().first;

                 int curX = q.front().second;

                 q.pop();

 

                 for (int i = 0; i  4; i++)

                 {

                         int nextY = curY + moveDir[i].y;

                         int nextX = curX + moveDir[i].x;

 

                         if (0 = nextY && nextY  R && 0 = nextX && nextX  C && !visited[nextY][nextX] && graph[nextY][nextX] != '#')

                         {

                                 visited[nextY][nextX] = true;

                                 if (graph[nextY][nextX] == 'o')

                                          curSheep++;

                                 else if (graph[nextY][nextX] == 'v')

                                          curWolf++;

                                 q.push({nextY, nextX});

                         }

                 }

        }

        양이 더 많으면 늑대가 죽고

        if (curSheep  curWolf)

                 wolf -= curWolf;

        양이 적거나 같으면 양이 죽는다

        else

                 sheep -= curSheep;

}

 

int main(void)

{

        ios_basesync_with_stdio(0);

        cin.tie(0);

        cin  R  C;

 

        미리 양과 늑대 마리수 센다

        for (int i = 0; i  R; i++)

        {

                 cin  graph[i];

                 for (int j = 0; j  C; j++)

                         if (graph[i][j] == 'o')

                                 sheep++;

                         else if (graph[i][j] == 'v')

                                 wolf++;

        }

 

        아직 방문하지 않은 칸이고 양이나 늑대일 때 BFS 호출

        for (int i = 0; i  R; i++)

                 for (int j = 0; j  C; j++)

                         if ((graph[i][j] == 'o'  graph[i][j] == 'v') && !visited[i][j])

                                 BFS(i, j);

 

        cout  sheep     wolf  n;

        return 0;

}
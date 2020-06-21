#include <string>
#include <vector>

using namespace std;
int mn[31][31];
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    char arr[31][31];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    vector<pair<int, int>> index;
    index.push_back(pair<int, int>(1, 0));
    index.push_back(pair<int, int>(0, 1));
    index.push_back(pair<int, int>(1, 1));
    int keep = 1;
    while (keep == 1)
    {

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {

                char temp = arr[i][j];
                if (temp == 0)continue;
                int temp_x = 0;
                if (arr[i + 1][j] == 0)
                {
                    temp_x++;
                    while (arr[i + temp_x][j] == 0)
                    {
                        if (i + temp_x == m - 1)break;
                        temp_x++;

                    }
                    temp_x--;

                }
                int match = 0;
                vector<pair<int, int>> v;

                for (int z = 0; z < 3; z++)
                {
                    int x = index[z].first + i;
                    int y = index[z].second + j;
                    if (z == 1)
                    {
                        if (arr[x + 1][y] != 0)
                        {
                            if (arr[i + 1][j] == 0)
                                x = index[z].first + temp_x + i;

                        }
                    }
                    if (z == 2)
                    {
                        x = v[v.size() - 1].first + 1;
                    }
                    while (arr[x][y] == 0)
                    {
                        if (x == m - 1)break;
                        x++;

                    }
                    v.push_back(pair<int, int>(x, y));
                    if (temp == arr[x][y]) {
                        match++;

                    }
                    else break;

                }
                if (match == 3)
                {
                    mn[i][j] = 1;
                    mn[v[0].first][j] = 1;
                    mn[v[1].first][j + 1] = 1;
                    mn[v[2].first][j + 1] = 1;
                }

            }
        }
        keep = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != 0)
                {
                    if (mn[i][j] == 1)
                    {
                        arr[i][j] = 0;
                        keep = 1;
                    }

                }
            }
        }

    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mn[i][j] == 1)answer++;
        }
    }
    return answer;
}
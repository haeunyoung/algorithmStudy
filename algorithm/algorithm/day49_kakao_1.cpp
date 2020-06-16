#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> v;
    
    for (int i = 1; i <=food_times.size(); i++)
    {
        int temp = food_times[i];
        v.push_back(pair<int, int>(i, temp));
    }
    sort(v.begin(), v.end(), cmp);

    long long sum_time = 0;
    int temp_answer;
    for (int i = 0; i < food_times.size(); i++)
    {
        sum_time += v[i].second * (food_times.size() - i);
        if (sum_time > k)
        {
            sum_time -= v[i].second;
            for (int j = i; j < food_times.size(); j++)
            {
                v[j].second -=1;
            }
            temp_answer = (k - sum_time) % (food_times.size() - i);

            sort(v.begin()+i, v.end());
            answer = v[temp_answer + i-1].first;
            break;

        }
        else if (sum_time = k)
        {
            answer = v[i].first;
        }
        else
        {
            int temp = v[i].second;
            for (int j = i; j < food_times.size(); j++)
            {
                v[j].second -= temp;
            }
        }
    }

    return answer;
}
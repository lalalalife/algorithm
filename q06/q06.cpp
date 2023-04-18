#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second; 
}

int solution(vector<int> food_times, long long k)
{	
	vector<pair<int, int>> foods; 
	int n = food_times.size(); 

	for (int i = 0; i < n; i++) {
		foods.push_back({ food_times.at(i), i + 1 }); 
	}

	sort(foods.begin(), foods.end()); 

	int pretime = 0; 

	for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); ++it, --n) {
		long long spend = (long)(long)(it->first - pretime) * n; 

		if (spend == 0)
			continue; 
		if (spend <= k) {
			k -= spend; 
			pretime = it->first; 
		}
		else {
			k %= n; 
			sort(it, foods.end(), compare); 
			return (it + k)->second; 
		}
	}

	return -1; 
}

int main()
{
	vector<int> food_times;
	food_times.push_back(3); 
	food_times.push_back(5);
	food_times.push_back(1);
	food_times.push_back(6);
	food_times.push_back(5);
	food_times.push_back(3);
	
	cout << solution(food_times, 20) << endl; 
}

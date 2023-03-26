#include <iostream>
#include <vector>
using namespace std;




// 특정부분합을 구하는 부분 연속 수열찾기
void twoPointer()
{
	int n = 5;
	int s = 5; // 찾으려는 부분합 
	int v[] = {1,2, 3, 2, 5};
	
	int intervalSum = 0; 
	int count = 0; 
	int end = 0; 

	for (int i = 0; i < n; i++) {
		while (intervalSum < s && end < n) {
			intervalSum += v[end];
			end++; 
		}
		if (intervalSum == s) {
			count++; 
		}
		intervalSum -= v[i]; 
	}

	cout << count << endl; 
}

// 투포인터를 이용한 정렬된 두리스트의 합집합 구하기 
void unionSum()
{
	int n = 3, m = 4; 
	int a[] = { 1, 3, 5 }; 
	int b[] = { 2, 4, 6, 8 }; 

	vector<int> result; 

	int i = 0, j = 0; 
	while (i < n or j < m) {
		
		if ( j >= m || (i < n && a[i] <= b[j])) {
			result.push_back(a[i]); 
			i++; 
		} 
		else {
			result.push_back(b[j]); 
			j++; 
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' '; 
	}
	cout << endl; 
}

// 접두사합을 활용한 구간합 계산 
void prefixSum()
{
	int n = 5; 
	int data[] = { 10, 20, 30, 40, 50 }; 
	int sum = 0; 
	vector<int> prefixSum; 
	for (int i = 0; i < n; i++) {
		sum += data[i]; 
		prefixSum.push_back(sum); 
	}

	// 구간합 3번째 4번째 사이의 구간합
	int left = 3, right = 4; 
	cout << prefixSum[right] - prefixSum[left - 1] << endl; 
}

int main()
{			
	//twoPointer(); 

	//unionSum(); 

	prefixSum(); 
}
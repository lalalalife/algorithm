// q28.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 
vector<int> v; 

int binary_search(int start, int end) 
{
    if (start > end)
        return -1; 

    int mid = (start + end) / 2; 

    if (v[mid] == mid)
        return mid;
    else if (v[mid] > mid)          // 중간점값보다 중간점이 작으면 (중간점을 값으로 갖고 있는 인덱스를 찾아야하므로..??
        return binary_search(start, mid-1);
    else
        return binary_search(mid+1, end);     
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp; 
        v.push_back(tmp); 
    }

    int index = binary_search(0, n - 1); 
    cout << index << endl; 
}


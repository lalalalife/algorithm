#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sequentialSearch()
{
    printf("생성할 원소개수입력 한칸띄고 찾을 문자열입력\n");
    int n;
    string str;
    cin >> n >> str;

    printf("원소개수만큼 문자열 입력\n");
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        if (v[i].compare(str) == 0)
        {
            cout << i + 1 << "번째" << endl;
            break;
        }
    }
}

int binary_search(int arr[], int start, int end, int target)
{
    if (start > end)
        return -1; 

    int mid = (start + end) / 2; 

    if (arr[mid] == target)
        return mid; 

    if (arr[mid] > target) {
        end = mid - 1; 
    }
    else  {
        start = mid + 1; 
    }    

    binary_search(arr, start, end, target); 
}

int binary_search_while(int arr[], int start, int end, int target)
{
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
            return mid; 

        if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }     
    }

    return -1; 
}

int main()
{
    //sequentialSearch(); 

    int arr[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 }; 
    int n = 10; 
    int target = 4; 

    // 재귀함수이용
    //cout << binary_search(arr, 0, n - 1, target) << endl;

    // 반복문이용
    cout << binary_search_while(arr, 0, n - 1, target) << endl;    
}

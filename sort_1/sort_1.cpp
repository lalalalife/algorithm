// sort_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

void selectionSort()
{
    int array[] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

    for (int i = 0; i < 10; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 10; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }

        if (array[i] > array[minIndex]) {
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << array[i] << ' ';
    }
}

void insertSort()
{
    int array[] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

    for (int i = 1; i < 10; i++) {        
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                swap(array[j], array[j - 1]); 
            }
            else {
                break; 
            }
        }            
    }

    for (int i = 0; i < 10; i++) {
        cout << array[i] << ' ';
    }
}

void quick_sort(int array[], int start, int end)
{
    // 종료조건 : 원소가 1개인 경우
    if (start >= end)
        return; 

    int pivot = start; 
    int left = pivot; 
    int right = end; 

    while (left <= right) {
        // pivot 보다 큰 데이터 찾기
        while (left <= end && array[left] <= array[pivot])
            left++; 
        // pivot 보다 작은 데이터 찾기
        while (right > start && array[right] >= array[pivot])
            right--; 

        if (left > right)
            swap(array[pivot], array[right]);
        else
            swap(array[left], array[right]); 
    }

    quick_sort(array, start, right - 1); 
    quick_sort(array, right + 1, end); 
}

void quickSort()
{
    int n = 10; 
    int array[] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

    quick_sort(array, 0, n - 1); 

    for (int i = 0; i < n; i++) {
        cout << array[i] << ' '; 
    }
}

void countSort()
{
    int n = 15; 
    int array[] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
    int maxValue = 9;     

    vector<int> v(maxValue+1, 0); 

    for (int i = 0; i < n; i++) {
        v[array[i]] += 1; 
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << ' ';
        }        
    }
}

int main()
{
    // selectionSort(); 

    //insertSort(); 

    //quickSort(); 

    countSort(); 
}

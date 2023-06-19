#include <iostream>
using namespace std; 
#include <algorithm>

int n; 
int asis[100000]; 
int tobe[100000];
int tmp[100000];

int cnt = 0;
int result = 987654321;

void light(int idx)
{
    cnt++; 

    if (idx > 0) {
        asis[idx - 1] == 0 ? asis[idx - 1] = 1 : asis[idx - 1] = 0; 
    }
    if (idx < n - 1) {
        asis[idx + 1] == 0 ? asis[idx + 1] = 1 : asis[idx + 1] = 0;
    }

    asis[idx] == 0 ? asis[idx] = 1 : asis[idx] = 0; 
}

bool check()
{
    // replace
    for (int i = 1; i < n; i++) {
        if (asis[i - 1] != tobe[i - 1]) {
            light(i); 
        }
    }

    // check
    for (int i = 0; i < n; i++) {
        if (asis[i] != tobe[i]) {
            return false; 
        }
    }
    return true; 
}

int main()
{
    cin >> n; 

    for (int i = 0; i < n; i++) {
        scanf_s("%1d", &asis[i]); 
        tmp[i] = asis[i]; 
    }
    for (int i = 0; i < n; i++) {
        scanf_s("%1d", &tobe[i]);
    }

    light(0);       // 첫번째 스위치 켜기 
    
    if (check()) {
        // 첫번재 스위치켜고 작업하고 성공 시, 
        result = min(result, cnt);         
    }

    // 첫번재 스위키 켜지 않고 작업해보기 
    
    // 데이터 원복
    cnt = 0; 
    for (int i = 0; i < n; i++) {
        asis[i] = tmp[i]; 
    }
    //
    if (check()) {
        result = min(result, cnt);
    }
    
    if (result == 987654321)
        cout << "-1" << endl;
    else
        cout << result << endl; 
}

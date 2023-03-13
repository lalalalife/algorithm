
#include <iostream>
#include <vector>
using namespace std;

int n;
int ugly[1000]; 

int main()
{
    cin >> n; 
    
    // ugly배열에서 몇번째 인덱스까지 곱했는지?
    int i2 = 0, i3 = 0, i5 = 0; 

    // 곱셉한 결과 임시보관
    int next2 = 2, next3 = 3, next5 = 5; 

    ugly[0] = 1; 

    for (int l = 1; l < n; l++) {

        // 마지막으로 곱해진 2,,3, 5 중에 작은값부터 배열에 넣는다. 
        ugly[l] = min(next2, min(next3, next5)); 

        if (ugly[l] == next2) {
            i2++; 
            next2 = ugly[i2] * 2; 
        }
        if (ugly[l] == next3) {
            i3++; 
            next3 = ugly[i3] * 3; 
        }
        if (ugly[l] == next5) {
            i5++; 
            next5 = ugly[i5] * 5; 
        }
    }

    cout << ugly[n - 1] << '\n'; 
}
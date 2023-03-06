// q19.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std; 

int n; 
vector<int> v; 
int op[4]; 

int maxValue = -1e9;
int minValue = 1e9;

//void dfs(int i, int now) 
//{    
//    if (i == n)
//    {
//        minValue = min(minValue, now); 
//        maxValue = max(maxValue, now); 
//    }
//    else
//    {
//        if (add > 0) {
//            add -= 1; 
//            dfs(i + 1, now + v[i]); 
//            add += 1; 
//        }
//        if (sub > 0) {
//            sub -= 1;
//            dfs(i + 1, now - v[i]);
//            sub += 1;
//        }
//        if (mul > 0) {
//            mul -= 1;
//            dfs(i + 1, now * v[i]);
//            mul += 1;
//        }
//        if (divi > 0) {
//            divi -= 1;
//            dfs(i + 1, now / v[i]);
//            divi += 1;
//        }
//    }
//}

void dfs(int result, int count)
{
    cout << "result : " << result << ", count : " << count << endl; 
    if (count == n - 1) {
        minValue = min(result, minValue); 
        maxValue = max(result, maxValue); 

        cout << "min : " << minValue << ", max : " << maxValue << endl; 
        return; 
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            --op[i]; 
            ///
            if (i == 0) {
                cout << result << " + " << v[count + 1] << endl;
                dfs(result + v[count + 1], count+1); 
            } 
            else if (i == 1) {
                cout << result << " - " << v[count + 1] << endl;
                dfs(result - v[count + 1], count + 1);
            }
            else if (i == 2) {
                cout << result << " * " << v[count + 1] << endl;
                dfs(result * v[count + 1], count + 1);
            }
            else if (i == 3) {
                cout << result << " / " << v[count + 1] << endl;
                dfs(result / v[count + 1], count + 1);
            }
            ///
            ++op[i];            // 이걸 더하는게 .. 
        }
    }
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x; 
        v.push_back(x);        
    }
    
    for (int i = 0; i < 4; i++)
        cin >> op[i]; 

    dfs(v[0], 0);

    cout << maxValue << endl << minValue << endl;
}

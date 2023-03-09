// q23.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public :
    Student(string name, int korean, int english, int math) {
        this->name = name; 
        this->korean = korean; 
        this->english = english; 
        this->math = math; 
    }

    string name; 
    int korean; 
    int english; 
    int math; 

    bool operator < (Student& other) {
        if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
            return this->name < other.name; 
        }
        if (this->korean == other.korean && this->english == other.english) {
            return this->math > other.math; 
        }
        if (this->korean == other.korean) {
            return this->english < other.english; 
        }
        return this->korean > other.korean; 
    }
};

int n;
vector<Student> v; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        string name;
        int k, e, m; 
        cin >> name >> k >> e >> m; 
        v.push_back(Student(name, k, e, m)); 
    }

    sort(v.begin(), v.end()); 

    for (int i = 0; i < n; i++) {
        cout << v[i].name << endl;
    }
}


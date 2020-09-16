#include <iostream>
#include <vector>
#include "editor/cn/[60]第k个排列.cpp"

using namespace std;

template<class TV>
void print(vector<TV> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<class TVV>
void print(vector<vector<TVV>> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        print(*it);
    }
    cout << endl;
}

template<class T>
void print(T v){
    cout << v << endl;
}

void print(){
    cout << "Hello, World!" << endl;
}

int main() {
    print(result());
    return 0;
}
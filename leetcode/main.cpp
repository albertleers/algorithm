//
// Created by 李武峰 on 2020-09-13.
//
#include <iostream>
#include <vector>
#include "editor/cn/[1]两数之和.cpp"

using namespace std;

template<class TV>
void print(vector<TV> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
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
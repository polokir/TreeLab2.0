#pragma once
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

template<typename T>
bool operator<(vector<T>& vec1,vector<T>& vec2) {
    int i = 0;
    while (vec1[i] == vec2[i]) {
        i++;
    }
    return vec1[i] < vec2[i];
}

template<typename T>
bool operator>(vector<T>& vec1, vector<T>& vec2) {
    return vec2 < vec1;
}

template<typename T>
bool operator<=(vector<T>& vec1, vector<T>& vec2) {
    return !(vec1 > vec2);
}

template<typename T>
bool operator>=(vector<T>& vec1, vector<T>& vec2) {
    return !(vec1 < vec2);
}

template<typename T>
bool operator==(vector<T>& vec1, vector<T>& vec2) {
    return !(vec1 < vec2) && !(vec1 > vec2);
}

template<typename T>
bool operator!=(vector<T>& vec1, vector<T>& vec2) {
    return !(vec1 == vec2);
}

template<typename T>
vector<T> operator+(vector<T>& vec1, vector<T>& vec2) {
    std::vector<T> res;
    int size = (vec1.size() < vec2.size()) ? vec2.size() : vec1.size();
    res.reserve(size);
    for (int i = 0; i < size; i++) {
        res.emplace_back(vec1[i] + vec2[i]);
    }
    return res;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    for (auto& i : vec) {
        os << i << ' ';
    }
    os << endl;
    return os;
}
#include <bits/stdc++.h>
using namespace std;

#ifndef CSES_SLIDING_MIN_H
#define CSES_SLIDING_MIN_H
#endif //CSES_SLIDING_MIN_H

class RangeMin{
    deque<long long> arr;

public:

    int front(){
        if(arr.empty()) return INT_MAX;
        return arr.front();
    }

    void push(int n){
        while(arr.size() && arr.back()>n) arr.pop_back();
        arr.push_back(n);
    }

    void pull(int n){
        if(arr.empty()) throw underflow_error("Cannot pull from empty queue");
        if(arr.front() == n) arr.pop_front();
    }
};

class RangeMax{
    deque<long long> arr;

public:

    int front(){
        if(arr.empty()) return INT_MIN;
        return arr.front();
    }

    void push(int n){
        while(arr.size() && arr.back()<n) arr.pop_back();
        arr.push_back(n);
    }

    void pull(int n){
        if(arr.empty()) throw underflow_error("Cannot pull from empty queue");
        if(arr.front() == n) arr.pop_front();
    }
};


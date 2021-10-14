#include<bits/stdc++.h>
using namespace std;

class QUEUE{
private:
    stack<int> s1, s2;
public:
    void Push( const int a);
    void Pop();
    void Top();
    void Print();
};

void QUEUE::Push(const int a){
    s1.push(a);
    return;
}

void QUEUE::Pop(){
    while(s1.empty() == false){
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(s2.empty() == false){
        s1.push(s2.top());
        s2.pop();
    }
}

void QUEUE::Top(){
    int temp;
    while(s1.empty() == false ){
        s2.push(s1.top());
        s1.pop();
    }
    temp = s2.top();
    while(s2.empty() == false){
        s1.push(s2.top());
        s2.pop();
    }
    cout << temp <<endl;
}


int main(){
    QUEUE q1;
    q1.Push(8);
    q1.Push(9);
    q1.Push(12);
    q1.Push(93);
    q1.Push(84);
    q1.Push(99);
    //q1.Pop();
    //q1.Pop();
    q1.Top();
    q1.Push(100);
    q1.Pop();
    q1.Pop();
    q1.Pop();
    q1.Pop();
    q1.Top();
    q1.Pop();
    q1.Pop();
    q1.Top();
}

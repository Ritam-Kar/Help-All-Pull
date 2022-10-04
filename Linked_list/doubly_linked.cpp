#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
} *first = NULL;

void create(int A[], int n){
    Node* t, *last;

    first = new Node;
    first -> prev = NULL;
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = new Node;
        t -> prev = last;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void disp(Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
}

int len(Node *p){
    int leng=0;
    while(p){
        leng++;
        p = p->next;
    }

    return leng;

}

list<int> l;

int main(){
    fastIO;
    Node *t = new Node;
    int A[] = {2, 4, 6, 3, 10};
    create(A, 5);
    cout << len(first) << endl;
    disp(first);



    return 0;
}
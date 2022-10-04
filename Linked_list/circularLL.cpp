#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

class Circular{
    public:
    struct Node{
        int data;
        struct Node* next;
    } *first = NULL;

    Circular(int A[], int n){
        Node *p;
        Node *last;

        first = new Node;
        first -> data = A[0];
        first -> next = NULL;
        last = first;

        for(int i = 1; i < n; i++){
            p = new Node;
            p -> data = A[i];
            p -> next = NULL;
            last -> next = p;
            last = p;
        }
        last -> next = first;
    }

    void disp(Node *p){
        Node *head = p;
        
        do{
            cout << p -> data << " ";
            p = p -> next;
        }while(p != head);
    }

    void dispRecurs(Node *p){
        static int flag = 0;
        
        if(p != first || flag == 0){
            flag = 1;
            cout << p -> data << " ";
            dispRecurs(p -> next);
        }

    }

};

int main(){
    fastIO;
    int A[] = {2, 5, 8, 10, 12};
    Circular ob(A, 5);
    // ob.disp(ob.first);
    ob.dispRecurs(ob.first);
    return 0;
}
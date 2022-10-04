#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


class LinkedList{
    public:

    struct Node{
        int data;
        struct Node *next;
    } *first = NULL;


    LinkedList(int A[], int n){
        Node *t, *last;
        first = new Node;
        first -> data = A[0];
        first -> next = NULL;
        last = first;

        for(int i = 1; i < n; i++){
            t = new Node;
            t -> data = A[i];
            t -> next = NULL;
            last -> next = t;
            last = t;
        }
    }

    void display(Node *p){
        while(p != NULL){
            cout << p -> data << " ";
            p = p -> next;
        }
    }

    void disp_recursive(Node *p){
        if(p != NULL){
            cout << p -> data << " ";
            disp_recursive(p -> next);
        }
    }


    int count_nodes(Node *p){
        int count = 0;
        while(p != NULL){
            count++;
            p = p -> next;
        }
        return count;
    }

    int count_nodes_recurs(Node *p){
        if(p == NULL)
            return 0;
        else
            return count_nodes_recurs(p -> next) + 1;
    }

    int count_recurs_2(Node *p){
        int x = 0;
        if(p){
            x = count_recurs_2(p -> next);
            return x + 1;
        }else{
            return 0;
        }
    }

    int add(Node *p){
        int sum = 0;
        while(p){
            sum += p -> data;
            p = p -> next;
        }

        return sum;
    }

    int add_recurs(Node *p){
        if(p){
            return add_recurs(p -> next) + p -> data;
        }else{
            return 0;
        }
    }

    int maxElement(Node *p){
        int res = p -> data;
        while(p != NULL){
            res = max(res, p -> data);
            p = p -> next;
        }

        return res;
    }

    int maxElement_recurs(Node *p){
        if(p){
            return max(maxElement_recurs(p -> next), p -> data);
        }else
            return INT_MIN;
    }

    Node* linSearch(Node *p, int ser){
        int x = 0;
        while(p){
            if(p -> data == ser)
                return p;
            x++;
            p = p->next;
        }
        
        return NULL;
    }

    Node* linSearchRecurs(Node *p, int ser){
        int x = 0;
        if(p == NULL)
            return NULL;

        if(ser == p -> data)
            return p;
        else{
            return linSearchRecurs(p -> next, ser);
        }

    }

    Node* moveToHeadSearch(Node *p, int key){
        Node *q = NULL; 

        while(p){
            if(p->data == key){
                q -> next = p -> next;
                p -> next = first;
                first = p;
                return p;
            }
            
            q = p;
            p = p -> next;
        }

        return NULL;
    }

    void insert(int x, int index){
        if(index == 0){
            Node *t = new Node;
            t -> data = x;
            t->next = first;
            first = t;
        }else{
            int i = 0;
            Node *t = new Node;
            t -> data = x;
            Node *p = first;

            for(int i = 0; i < index && p; i++)
                p = p->next;
            
            t -> next = p -> next;
            p -> next = t;
        }
    }

    void push_back(int x){
        insert(x, count_nodes(first) - 1);
    }

    void insert_sorted(int x){
        Node* p = first;
        int i = 0;
        if (x < first -> data){
            insert(x, 0);
        }else{
            while(p){
                if(x >= p -> data && x < (p -> next) -> data){
                    insert(x, i);
                    break;
                }
                i++;
                p = p->next;
            }
        }
    }

    void delete_node(int x){
        int index = 0;
        Node *p, *q;

        p = first;

        if(x == first -> data){
            first = first -> next;
            int x = p -> data;
            delete p;
        }else{
            while(p){
                if(p -> data == x){
                    q -> next = p -> next;
                    int x = p -> data;
                    delete p;
                    // p = NULL;
                    break;
                }
                q = p;
                p = p->next;
            }
        }
    }

    bool isSorted(Node *p){
        int x = p -> data;
        p = p -> next;

        while(p){
            if(p -> data < x){
                return false;
            }
            x = p -> data;
            p = p -> next;
        }

        return true;
    }

    void revLinkedList(Node *p){
        p = first;
        Node *q, *r;
        q = NULL; 
        r = NULL;

        while(p){
            r = q;
            q = p;
            p = p -> next;

            q -> next = r;
        }

        first = q;

    }

    Node* concat(Node *p, Node *q){
        Node* firstConcat = p;
        while(p)
            p = p-> next;

        p -> next = q;

        q = NULL;

        return firstConcat;
    }

};

int main(){
    fastIO;
    // int A[] = {3, 5, 7, 10, 15};
    int A[] = {3, 5, 8, 13, 20};
    int B[] = {10, 15, 32, 45, 100};

    LinkedList obj1(A, 5);
    LinkedList obj2(B, 5);
    // obj1.create(A, 5);
    obj1.disp_recursive(obj1.first);
    cout << endl;
    obj2.disp_recursive(obj2.first);
    // cout << endl << obj1.count_nodes(obj1.first);
    // cout << endl << obj1.count_nodes_recurs(obj1.first);
    // cout << endl << obj1.add(obj1.first);
    // cout << endl << obj1.add_recurs(obj1.first);
    // cout << endl << obj1.maxElement(obj1.first);
    // cout << endl << obj1.maxElement_recurs(obj1.first);
    // cout << endl << obj1.linSearch(obj1.first, 6);
    // cout << endl << obj1.linSearchRecurs(obj1.first, 10);
    // *Binary Search -> Not Possible
    // cout << endl << obj1.moveToHeadSearch(obj1.first, 10);
    // obj1.disp_recursive(obj1.first);
    // obj1.insert(9, 4);
    // obj1.insert(11, 5);
    // obj1.push_back(11);
    // obj1.insert_sorted(15);
    // obj1.delete_node(8);
    // obj1.delete_node(20);
    // cout << obj1.isSorted(obj1.first);
    // obj1.revLinkedList(obj1.first);
    // cout << endl;
    // obj1.disp_recursive(obj1.first);
    obj1.disp_recursive(obj1.concat(obj1.first, obj2.first));


    return 0;
}

// q = p;    // Two pointers on same node
    // p = p -> next;  // The address of next node
    // p = p -> next   //* p moves to next node

    // p -> data = 10;
    // p -> next = NULL;

    // * Methods to check if pointer is NULL
    // if(p == NULL){

    // }
    // if(p == 0){

    // }
    // if(!p){

    // }
    // *

    // if(p != NULL){

    // }
    
    // if(p -> next == NULL){
    //     cout << "Last Node";
    // }

    // if(p -> next != NULL){
    //     cout << "Something present";
    // }


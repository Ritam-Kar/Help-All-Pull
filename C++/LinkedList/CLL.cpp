#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

Node* Head = NULL;

Node* makeNode(int x){
    Node* temp = new Node;
    temp->data = x;
}

int length(){
    int count = 0;
    Node* temp = Head;
    while (temp->next != Head)                            // Iterate till temp == NULL 
    {
        count ++;
        temp = temp->next;                  // changing values of temp pointer
    }
    return count;
}

void Insert(int x, int pos){
    if(pos > length()){
        cout << "Desired Postion DNE" << endl;
        return;
    }
    Node* temp = makeNode(x);
    if(pos == 1){
        if(Head == NULL){
            temp->next = Head;
            Head = temp;
            return;
        }
        temp->next = Head;
        Head = temp;
        return;
    }
    Node* temp2 = Head;
    if( pos == length()){
        while (temp2->next != Head)
        {
            temp2 = temp2->next;
        }
        temp->next = Head;
        temp2->next = temp;
        return;
    }
    
    for(int i =0; i < pos -2; i++){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return;
}

void Print(){
    Node* temp = Head;
    if(Head = NULL){
        cout << "List Empty " <<endl;
        return;
    }
    for (int i = 0; i < length(); i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}   

int main(){
    Print();
    //Insert(5, 1);
    Print();
}

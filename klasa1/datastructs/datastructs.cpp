#include<bits/stdc++.h>

using namespace std;

struct list{
    struct node{
        int value;
        node* next = 0;
    }
    node* head = 0;
    int size = 0;
    
    void print(){
        list::node curr = head;
        while(curr != 0){
            cout << curr.value << ' ';
            curr = curr.next;
        }
    }
};

int main(){
    cout << "XD\n";
    return 0;
}

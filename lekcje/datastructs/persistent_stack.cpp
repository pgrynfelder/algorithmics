#include<bits/stdc++.h>

using namespace std;

struct pstack{
    struct node{
        int value = 0;
        node* next = 0;
        bool placeholder = 0;
        node(int _value, node* _next, bool _placeholder){
            value = _value;
            next = _next;
            placeholder = _placeholder;
        }
        node(){}
        void print(){
            cout << value << ", " << next->value << ", " << placeholder << "\n";
        }
    };
    
    node* t = 0;
    int n = 1;
    pstack(){
        t = new node[200007];
        t[0] = node();
        t[0].placeholder = 0;
        t[0].value = -1;
        t[0].next = t;
    }

    void add(int x){
        node* curr = t+n-1;
        while (curr->placeholder){
            curr = curr->next;
        }
        t[n] = node(x, curr, 0);
        n++;
    }
    void del(){
        node* curr = t+n-1;
        while (curr->placeholder){
            curr = curr->next;
        }
        t[n] = node(0, curr->next, 1);
        n++;
    }
    void undo(int x){
        node* curr = t+n-1-x;
        while (curr->placeholder){
            curr = curr->next;
        }
        t[n] = node(0, curr, 1);
        n++;
    }
    int top(){
        node *curr = t+n-1;
        while (curr->placeholder){
            curr = curr->next;
        }
        return curr->value;
    }
    void print(){
        for (int i = 0; i < n; i++){
            cout << t[i].value << ' ';
        }
        cout << '\n';
    }
    void vprint(){
        for (int i = 0; i < n; i++){
            t[i].print();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pstack s;
    int q;
    cin >> q;
    while (q-->0){
        char c;
        cin >> c;
        if (c == '+'){
            int x;
            cin >> x;
            s.add(x);
        }
        else if (c == '-'){
            s.del();
        }
        else if (c == '*'){
            int x;
            cin >> x;
            s.undo(x);
        }
        //s.print();
        cout << s.top() << '\n';
    }
    
    return 0;
}
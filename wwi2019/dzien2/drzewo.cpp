int sumtree(int a, int b, int l, int r, int i) 
// ab - asked for, lr - currently considered, x - current node
    if (a <= l and r <= b){
        return T[i];
    }
    int mid = (l+r)/2;
    int result = 0;
    if (a <= mid){
        result += sumtree(a,b,l,mid,2*i);
    }
    if (mid < b){
        result += sumtree(a,b,mid+1, r, 2*i+1);
    }
    return result;

}
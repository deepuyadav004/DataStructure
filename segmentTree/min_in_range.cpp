#include<bits/stdc++.h>
using namespace std;

class segTree{
    public:
    vector<int>seg;
    segTree(int n){
        seg.resize(4*n+1);
    }
    
void build(int i, int l, int r, int arr[]){
if(l == r){
    seg[i]=arr[l];
    return;
}

int mid = (l+r)/2;
build(i*2+1, l, mid, arr);
build(i*2+2, mid+1, r, arr);
seg[i]=min(seg[2*i+1], seg[2*i+2]);
}

int query(int i, int l, int r, int left, int right, int arr[]){
if(r < left || l > right){
    return INT_MAX;
}
if(l >= left && r<=right){
    return seg[i];
}

int mid = (l+r)>>1;
int lhs = query(2*i+1, l, mid, left, right, arr);
int rhs = query(2*i+2, mid+1, r, left, right, arr);
return min(lhs, rhs);
}

void update(int idx, int l, int r, int i, int val, int arr[]){
if(l == r){
    seg[idx]=val;
    return;
}
int mid=(l+r)/2;
if(mid <= l){
    update(2*idx+1, l, mid, i, val, arr);
}else{
    update(2*idx+2, mid+1, r, i, val, arr);
}
seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

};

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n1;
    cin>>n1;
    int arr[n1];
    for(int i=0; i<n1; i++){
        cin>>arr[i];
    }
    segTree one = segTree(n1); 
    one.build(0, 0, n1-1, arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int l,r;
            cin>>l>>r;
            cout<<one.query(0, 0, n1-1, l, r, arr)<<endl;
        }else{
            int i,val;
            cin>>i>>val;
            one.update(0, 0, n1-1, i, val, arr);
        }
    }
    return 0;
}

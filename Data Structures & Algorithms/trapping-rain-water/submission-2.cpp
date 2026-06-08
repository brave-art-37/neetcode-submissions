class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> ind(n), pf(n+1);
        for(int i=0;i<n;i++) ind[i] = i;
        for(int i=1;i<=n;i++){
            pf[i] = pf[i-1]+h[i-1];
        }
        sort(ind.begin(),ind.end(),[&](int l, int r){
            return h[l] > h[r]; //desc order ht
        });
        int res = 0;
        cout<<"ind: ";for(int num:ind) cout<<num<<' ';cout<<"\n";
        int l = ind[0], r=ind[0];
        for(int j=1;j<n;j++){
            int i = ind[j];
            cout<<i<<" "<<h[i]<<"\n";
            if(i<l) res += (l-i-1)*h[i]-(pf[l]-pf[i+1]), l=i;
            else if(i>r) res += (i-r-1)*h[i]-(pf[i]-pf[r+1]), r=i;
            else ; //nothing as already fill
        }
        return res;
    }
};
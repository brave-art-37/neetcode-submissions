class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> data;
        int n=position.size();
        for(int i=0;i<n;i++){
            data.push_back({position[i],speed[i]});
        }
        sort(data.begin(),data.end());
        stack<double> st;
        for(int i=0;i<n;i++){
            double time=(double)(target-data[i].first)/data[i].second;
            while(!st.empty() && st.top()<=time) st.pop();
            st.push(time);
        }
        int fleets=0;
        while(!st.empty()) fleets++, st.pop();
        return fleets;
    }
};
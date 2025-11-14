class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], dep[i]};
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() < v[i].first) {
                pq.pop();
            }
            pq.push(v[i].second);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};

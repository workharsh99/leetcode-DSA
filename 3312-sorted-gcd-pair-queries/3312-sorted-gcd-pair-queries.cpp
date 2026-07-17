class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);

        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            for (int x = g; x <= mx; x += g)
                cnt += freq[x];

            exact[g] = cnt * (cnt - 1) / 2;

            for (int x = g + g; x <= mx; x += g)
                exact[g] -= exact[x];
        }

        vector<long long> pref(mx + 1);

        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {

            q++;

            int g = lower_bound(pref.begin() + 1,
                                pref.end(),
                                q) - pref.begin();

            ans.push_back(g);
        }

        return ans;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
 
#define ll long long
 
using namespace std;
 
int main() {
    int n, b, attack_input, defense_input, wizard;
    cin >> n >> b;
    vector<ll> vector1;
    vector<pair<ll, ll>> vector2;  // Use vector of pairs
 
    for (int i = 0; i < n; i++) {
        cin >> attack_input;
        vector1.push_back(attack_input);
    }
 
    for (int j = 0; j < b; j++) {
        cin >> defense_input >> wizard;
        vector2.push_back({defense_input, wizard});
    }
 
    if (vector1.empty() || vector2.empty()) {
        return 0; // Indicate an error
    }
 
    sort(vector2.begin(), vector2.end());
 
    vector<ll> prefixSum(b);
    prefixSum[0] = vector2[0].second;
 
    for (int i = 1; i < b; i++) {
        prefixSum[i] = prefixSum[i - 1] + vector2[i].second;
    }
 
    for (int j = 0; j < n; j++) {
        int element = vector1[j];
        ll sum = 0;
 
        // Binary search for the element in the sorted vector2
        int start = 0, end = b - 1, max_index = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (element >= vector2[mid].first) {
                max_index = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
 
        if (max_index != -1) {
            sum = prefixSum[max_index];
        }
 
        cout << sum << " ";
    }
 
    return 0;
}

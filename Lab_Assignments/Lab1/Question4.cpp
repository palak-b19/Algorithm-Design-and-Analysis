#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#include <algorithm>
#define ll long long
using namespace std;
 
void breakAndSum(vector<ll> &arr, set<ll> &result)
{
 
    if (arr.size() <= 1)
    {
        result.insert(arr[0]);
        return;
    }
 
    double avg = (arr.front() + arr.back()) / 2.0;
    auto it = upper_bound(arr.begin(), arr.end(), avg);
    ll splitIndex = it - arr.begin();
    
    vector<ll> leftArray(arr.begin(), it);
    vector<ll> rightArray(it, arr.end());
 
    
    ll leftSum = accumulate(leftArray.begin(), leftArray.end(), 0);
    ll rightsum = accumulate(rightArray.begin(), rightArray.end(), 0);
    
    result.insert(leftSum);
    result.insert(rightsum);
    
    if (rightsum == 0 || leftSum == 0)
    {
        return;
    }
 
    breakAndSum(leftArray, result);
    breakAndSum(rightArray, result);
}
 
int main()
{
    ll Total_no, N, total_list, a, b_ele;
    vector<ll> elements;
    cin >> Total_no;
 
    for (ll i = 0; i < Total_no; i++)
    {
        cin >> N >> total_list;
 
        elements.clear();
        for (ll j = 0; j < N; j++)
        {
            cin >> a;
            elements.push_back(a);
        }
 
        sort(elements.begin(), elements.end());
        set<ll> answer;
        answer.insert(accumulate(elements.begin(),elements.end(),0));
        breakAndSum(elements, answer);
        for (ll j = 0; j < total_list; j++)
        {
            cin >> b_ele;
            auto pos = answer.find(b_ele);
            if (pos == answer.end())
            {
                cout << "No" << endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
 
    return 0;
}

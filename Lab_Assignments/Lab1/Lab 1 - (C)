using namespace std;
#define ll long long
#include <bits/stdc++.h>
 
 
ll string_check(char char_to_check, string string_input, int sum)
{
    
 
    if (string_input.size() == 1)
    {
        if(string_input==string(1,char_to_check)){
            return 0;
        }
        else{
            return 1;
        }
    }
    
 
    ll count1 = 0;
    for (ll i = 0; i <string_input.size()/2; i++) {
        if (string_input[i] == char_to_check) {
            count1++;
        }
    }
    // ll count1 = 0;
    // for (ll i = 0; i <string_input.size()/2; i++) {
    //     if (string_input[i] == char_to_check) {
    //         count1++;
    //     }
    // }
 
    ll Total_left_changes = string_input.size()/2- count1;
    
 
    ll count2 = 0;
    for (ll i = string_input.size()/2; i <string_input.size(); i++) {
        if (string_input[i] == char_to_check) {
            count2++;
        }
    }
    ll count3 = 0;
    for (ll i = string_input.size()/2; i <string_input.size(); i++) {
        if (string_input[i] == char_to_check) {
            count3++;
        }
    }
 
    // count3 not used, alag sai store karni thi val
 
    ll Total_right_changes = string_input.size()/2- count2;
 
    ll min_left_check = string_check(char_to_check + 1,string_input.substr(0, string_input.size() / 2),0);
    ll min_right_check = string_check( char_to_check + 1,string_input.substr((string_input.size()) / 2),0);
 
    return min(min_left_check + Total_right_changes, min_right_check + Total_left_changes);
}
 
 
 
int main()
{
    ll no_of_testcaes;
    cin >> no_of_testcaes;
    for(int i=0;i<no_of_testcaes;i++)
    {
        ll length=0;
        string string_input;
        // input array
        cin >> length >> string_input;
        ll res = string_check('a',string_input,0);
        cout << res << endl;
    }
}

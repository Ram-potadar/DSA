/*

Longest Balances Parenthesis

*/

#include<iostream>
#include<stack>
using namespace std;

int longestBalancedParenthesis(string& s){

    stack<int> st;
    int maxLen = 0;
    st.push(-1);

    for(int i = 0; i < s.size(); i++){

        if(s[i] == '('){
            st.push(i);
        }else{
            if(st.empty()) st.push(i);
            else{
                maxLen = max(maxLen, i-st.top());
            }
        }
    }
    return maxLen;
}

int main(){

    string s = "(())";
    cout<<longestBalancedParenthesis(s);

return (0);
}
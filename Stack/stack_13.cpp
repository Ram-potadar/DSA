/*
    K removing 
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>

using namespace std;

string removing(string& str, int k){

    stack<char> st;

    for(int i = 0; i< str.size(); i ++){


        while (!(st.empty()) && k > 0 && st.top() > str[i]) {

            st.pop();
            k = k- 1;
        }
        st.push(str[i]);
    }

    while(k>0){
        st.pop();
        k = k -1;
    }

    if(st.empty()) return "0";
    string res ="";

    while(!(st.empty())){
        res = res + st.top();
        st.pop();
    }

    while(res.size() != 0 && res.back() == '0'){
        res.pop_back();
    }

    reverse(res.begin(), res.end());


    if(res.empty()) return "0";
    return res;
    
}

int main(){

    string str = "00000";
    cout<<removing(str, 5);


return (0);
}
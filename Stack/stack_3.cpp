/*
Balanced parenthesis using stack

*/

#include<iostream>
#include<stack>
using namespace std;
  
bool isBalance(string& str){
    stack<char> st;
    for(int i = 0; i < str.size(); i++){

        if(str[i] == '(' || str[i] == '{' || str[i] == '[')  // push onto stack
        {
            st.push(str[i]);
        }
        else{

            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
          if((str[i] == ')' && ch=='(') || 
            (str[i] == '}' && ch=='{') || 
            (str[i] == ']' && ch=='[')) {
            }
            else return false;
        }
    }
    return st.empty();
}
int main(){

    string str = "[()]";
    cout<<isBalance(str);

return (0);
}
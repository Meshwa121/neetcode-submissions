class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens){
            if(token !="+" && token != "*" && token != "-" && token !="/"){
                st.push(stoi(token));
            }
            else if(token == "+" || token == "*" || token == "-" ||token == "/"){
                int b= st.top();
                st.pop();
                int a= st.top();
                st.pop();
                int c;
                if(token=="+"){
                    c= a+b;
                }
                else if(token=="*"){
                    c= a*b;
                }
                else if(token=="-"){
                    c= a-b;
                }
                else if(token=="/"){
                    c= a/b;
                }
                st.push(c);
            }  
        }
        return st.top();
    }
};

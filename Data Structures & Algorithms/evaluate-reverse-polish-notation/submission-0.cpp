class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int>st;
        for(int i = 0;i<v.size();i++){
            if(v[i]=="+"||v[i]=="-"||v[i]=="*"||v[i]=="/"){
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                if(v[i]=="+")st.push(a+b);
                if(v[i]=="-")st.push(b-a);
                if(v[i]=="*")st.push(b*a);
                if(v[i]=="/")st.push(b/a);
            }
            else{
                int a = stoi(v[i]);
                st.push(a);
            }
        }
        return st.top();
    }
};

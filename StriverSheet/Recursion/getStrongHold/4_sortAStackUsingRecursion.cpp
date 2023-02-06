//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int printStack(stack<int>& s1)
{
    if(s1.empty())
        return -1;

    cout<<s1.top()<<" ";
    int temp=s1.top();
    s1.pop();

    printStack(s1);
    s1.push(temp);

    return 0;
}


int put_sorted(stack<int> &st, int val){

    if(st.empty() || st.top() > val) {
        st.push(val);
        return 0;
    }
    int a = st.top();
    st.pop();
    put_sorted(st,val);

    st.push(a);
    return 1;
}


void sort(stack<int> &st){

    if(st.empty()){
        return ;
    }

    int a = st.top();
    st.pop();

    //this function will empty the whole stack and then we will insert the value a in the sorted order
    sort(st);
    put_sorted(st,a);
    return ;
}


void reverse(stack<int > &st){

    vector<int> v;

    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }

    for(auto it : v){
        st.push(it);
    }

}

int main()
{
    stack<int> s ;
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);
    printStack(s);
    sort(s);
    cout<<endl<<"stack after sort : "<<endl;
    reverse(s);
    printStack(s);
}



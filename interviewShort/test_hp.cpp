

#include<bits/stdc++.h> 
using namespace std;



bool input_verify(string &s){
   
   //  ()[]{}
   //  ((((( [])

   //stack to check for opening brackets
   stack<char> st;

   
   // traverse over brackets 
   for(char bracket : s){

      //check for opening brackets and pushing to stack
      if(bracket == '(' ||  bracket == '[' || bracket == '{'){
         st.push(bracket);
      }else{
         //contains opening bracket
         char top_bracket = st.top();
         st.pop();
         
         if(bracket == ')' && top_bracket != '(' ){
            return false;
         }
         else if(bracket == ']' && top_bracket != '['){
            return false;
         }else if(bracket == '}' && top_bracket != '{'){
            return false;
         }
      }
   }

   //if stack is not empty which means we still have opening brackets, which are not closed. [RETURN FALSE]
   if(!st.empty()){
      return false;
   }

   // RETURN TRUE (STACK DOES NOT CONTAINS Opening Bracket | all brackest are Closed  [RETURN TRUE])
   return true;
}

int main(){

   // Test Example 
   string s = "((()]";
   
   //Checking and Printing if testcase s is correct.
   if(input_verify(s)){
      cout<< "true"<<endl;
   }
   else cout<<"false"<<endl;

   return 1;
}

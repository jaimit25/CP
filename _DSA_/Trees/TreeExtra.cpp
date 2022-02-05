#include "bits/stdc++.h"
// #include<iostream>
// #include<stdlib.h>

// cmd+shift+b
using namespace std;


class tree_node{

    public :
    int val  ;
    int child ;
    tree_node *left , *right ;

    tree_node(int d1){
        left=nullptr ;
        right=nullptr ;
        child=0 ;
        val = d1 ;
    }
};


class b_tree{
    
    public :
    tree_node *root=nullptr ;
    int size=0;
    b_tree(queue<int> data ){

        if(data.size() == 0){
            return ;
        }

        queue<tree_node*> temp_ptr ;

        root = new tree_node(data.front()) ;
        data.pop() ;
        temp_ptr.push(root) ;

        while( !temp_ptr.empty() and !data.empty() ){
            
            tree_node *tmp = temp_ptr.front(); 
            
            if(data.front()!=-1){   
                tmp->left = new tree_node(data.front()) ;
                temp_ptr.push(tmp->left) ;
            }
                data.pop();

            if(data.empty() ){
                return;
            }

            if(data.front()!=-1){
                tmp->right = new tree_node(data.front()) ;
                temp_ptr.push(tmp->right) ;
            }
                data.pop();

            temp_ptr.pop() ;

        }      

        while(!temp_ptr.empty()){
            temp_ptr.pop() ;
        }

    }


    void print(tree_node *ptr1 ){
        if(ptr1!=nullptr){
            cout<< ptr1->val <<"\n" ;
            print(ptr1->left) ;
            print(ptr1->right) ;

        }
    }
};

void input(queue<int> &v1 , int n1){

    for(int i=0 , tp ; i<n1 ; i++){
        cin>>tp;
        v1.push(tp) ;
    }
}


int main(void){
    
    int n1 ;
    cin>>n1;
    queue<int> v1;

    input(v1 , n1) ;
    b_tree t1(v1) ;
    t1.print(t1.root);
    
}
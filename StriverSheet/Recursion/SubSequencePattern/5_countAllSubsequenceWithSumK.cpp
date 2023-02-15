#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vvi vector<vector<int>>

using namespace std;
 
void print(vi &a){
for(auto it : a){
	cout<<it<<" ";
}
cout<<endl;
}

int add(vector<int> v){
	int sum = 0;
	for(auto it : v){
		sum += it;
	}
	return sum;
}

//Approach 2 without ans vector
// void helper(int *arr, int n, int i , vector<vector<int> > &ans ,vector<int> &temp , int &sum){
	
// 		cout<<"f("<<add(temp)<<","<<i<<")"<<endl;


// 	if(add(temp) == sum && i <= n){
// 		ans.push_back(temp);
// 		return ;
// 	}
// 	if(i == n || add(temp) > sum) return ;

// 	temp.push_back(arr[i]);
// 	helper(arr,n,i+1,ans,temp,sum);

// 	temp.pop_back();
// 	helper(arr,n,i+1,ans,temp,sum);

// 	return ;
// }

// int perfectSum(int arr[], int n, int sum)
// {		
// 		vector<vector<int>> ans;
// 		vector<int> temp;
//         helper(arr, n ,0 , ans ,temp , sum);
//         return ans.size();
// }


//Approach 2 without ans vector
// void helper(int *arr, int n, int i ,int &temp , int &sum, int &count){

// 	if(temp == sum && i <= n){
// 		count++;
// 		return ;
// 	}
// 	if(i >= n || temp > sum) return ;

// 	temp = temp+arr[i];
// 	helper(arr,n,i+1,temp,sum,count);

// 	temp = temp - arr[i];
// 	helper(arr,n,i+1,temp,sum,count);

// 	return ;
// }


// int perfectSum(int arr[], int n, int sum)
// {		

// 		int tmp = 0;
// 		int count = 0;
//         helper(arr, n ,0 ,tmp , sum,count);

//         return count;
// }



void helper(int *arr, int n , int sm , int &sum , int &count , int i,bool &flg){
	

	if(sm == sum){
		count++;
		// return;
	}

	if(i >= n){
		return;
	}


	helper(arr,n,sm+arr[i],sum,count,i+1,flg);
	helper(arr,n,sm,sum,count,i+1,flg);
	return;
}

int perfectSum(int arr[], int n, int sum)
{		

		int tmp = 0;
		int count = 0;
		bool flg = false;
        helper(arr, n ,tmp ,sum,count,0,flg);

        return count;
}

 
int main()
{

// int arr[] = {1, 2, 3, 4, 5};
// int sum = 10;
// cout<<perfectSum(arr,5,sum)<<endl;

int arr[] = {2, 3, 5, 6, 8, 10};
int sum = 10;
cout<<perfectSum(arr,6,sum)<<endl;

 
return 0;
}
 
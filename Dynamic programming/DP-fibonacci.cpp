//Dynamic programmig refers to optimiztion of programs of very high time complexity
//the normal program to find factorial using recursion comes with a very hight complexity
// the call structure of a normal recursive method for computing a factorial can be imagined as this tree:
//                            fib(5)
//                       /             \
//               fib(4)                   fib(3)
//             /          \               /       \
//         fib(3)        fib(2)        fib(2)     fib(1)
//        /   \         /     \       /     \
//     fib(2) fib(1)  fib(1) fib(0) fib(1) fib(0)
//    /    \
// fib(1) fib(0)
//so we can see that event though fibonacci of several numbers had already been calculated the have been repeatedly calculated again again
//since the time complexity of a recursive code depends on the number of times the function has been called as we can make out from the tree stucture
//manyyyyy recursive calls is required even for computation of fibonnaci  of 5
//in order to optimize the solution we maintain a data structre to store the pre computed values
//this procedure is known as memoization

// time complexity of the program changes from O(N^2) ---> O(n) ps:yes its a drastic reduction :)
#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
//array for memoiztion i.e storing fibonnaci values of numbers which were already computed
int dp[N];
int fib(int n){
	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<fib(n)<<"\n";
	cout<<dp[0]<<dp[1]<<"\n";
}

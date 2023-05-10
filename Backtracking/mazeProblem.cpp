#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
vector<string> ans;
void fun(int i , int j , int n , vector<vector<int>> m , vector<vector<bool>>&vis , string s){
    if(i<0 || j<0 || i>=n || j>=n||m[i][j]==0||vis[i][j]==1)
        return ;
    if(i==n-1&&j==n-1){ 
        ans.push_back(s);
        return;
    }
    vis[i][j]=1;
    fun(i+1,j,n,m,vis ,s+'D');
    fun(i,j-1,n,m,vis ,s+'L');
    fun(i-1,j,n,m,vis ,s+'U');
    fun(i,j+1,n,m,vis ,s+'R');
    vis[i][j]=0; 
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<vector<bool>>vis(n , vector<bool>(n,0));
    string s="";
    fun( 0,0,n,m,vis , s);
    return ans;
}
};
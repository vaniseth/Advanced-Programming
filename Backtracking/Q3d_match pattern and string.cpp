#include <iostream>
#include <vector>
using namespace std;

bool patternMatchUtil(string str, int n, int i,string pat, int m, int j, unordered_map<char, string>& map){
    if (i == n && j == m)
    return true;
    if (i == n || j == m)
    return false;
    char ch = pat[j];
    if (map.find(ch)!= map.end()){
        string s = map[ch];
        int len = s.size();
        string subStr = str.substr(i, len);
        if (subStr.compare(s))
            return false;
            return patternMatchUtil(str, n, i + len, pat, m,j + 1, map);
    }
    for (int len = 1; len <= n - i; len++){ 
        map[ch] = str.substr(i, len);
        if (patternMatchUtil(str, n, i + len, pat, m,j + 1, map))
        return true;
        map.erase(ch);
    }
    return false;
}
bool patternMatch(string str, string pat, int n, int m){ 
    if (n < m)
    return false;
    unordered_map<char, string> map;
    bool res = patternMatchUtil(str, n, 0, pat, m, 0, map);
    for (auto it = map.begin(); res && it != map.end(); it++)
    cout << it->first << "->" << it->second << endl;
    return res;
}
int main(){
    string str = "Hello there, how are you?", pat = "Ask";
    int n = str.size(), m = pat.size();
    if (!patternMatch(str, pat, n, m))
    cout << "No Solution exists";
    return 0;
}

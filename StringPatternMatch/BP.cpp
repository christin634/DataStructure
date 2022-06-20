//
// @author: Christinlj
// @date: 2022/6/20 14:33
// @description: 字符串模式匹配--暴力算法(BP)
//

#include<iostream>
#include<string>
using namespace std;
/**
 * 字符串模式匹配--BP算法
 * @param s 主串
 * @param t 子串
 * @return 子串在主串中的位置，匹配失败返回-1
 */
int BruteMatch(string s,string t){
    int i=0,j=0;
    while(i<s.length()&&j<t.length()){
        if(s[i]==t[j]){
            ++i;++j;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==t.length())   return i-j+1;
    return -1;
}

int main() {
    string s1="ababcabcacbab",s2="abcac";
    cout<<"s1:"<<s1<<" s2:"<<s2<<endl<<BruteMatch(s1,s2);
    return 0;
}
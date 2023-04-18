#include<iostream>
#include<cstdio>
#include<cstring>
#include "../../Stack/Stack.h"
using namespace std;
#define ll long long
const int maxn=100001;
ll arr[maxn];
ll ans=0;//用ans记录矩形最大的面积
Stack<int> st;
int main()
{
    ll n;
    cout<<"输入数组个数:"<<endl;
	cin>>n;
    cout<<"输入数组:"<<endl;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    arr[n+1]=-1; 
    for(int i=1;i<=n+1;++i)
    {
        if(st.empty()||arr[st.top()]<=arr[i])
            st.push(i);
        else
        {
            int tmp;//用来记录被弹掉矩形的高度
            while(st.size()&&arr[st.top()]>arr[i])
            {
                tmp=st.top(); 
                ans=max(arr[st.top()]*(i-st.top()),ans);//拓展
                st.pop();
            }
            //重点：修改弹出元素的高度
            st.push(tmp);
            arr[tmp]=arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

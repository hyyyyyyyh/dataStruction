#include<iostream>
#include<cstdio>
#include<cstring>
#include "../../Stack/Stack.h"
using namespace std;
#define ll long long
const int maxn=100001;
ll arr[maxn];
ll ans=0;//��ans��¼�����������
Stack<int> st;
int main()
{
    ll n;
    cout<<"�����������:"<<endl;
	cin>>n;
    cout<<"��������:"<<endl;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    arr[n+1]=-1; 
    for(int i=1;i<=n+1;++i)
    {
        if(st.empty()||arr[st.top()]<=arr[i])
            st.push(i);
        else
        {
            int tmp;//������¼���������εĸ߶�
            while(st.size()&&arr[st.top()]>arr[i])
            {
                tmp=st.top(); 
                ans=max(arr[st.top()]*(i-st.top()),ans);//��չ
                st.pop();
            }
            //�ص㣺�޸ĵ���Ԫ�صĸ߶�
            st.push(tmp);
            arr[tmp]=arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include <iostream>
#include "queue.h"
#include <stdlib.h>
#include "../Stack/Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long
using namespace std;
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
            int tmp; //������¼���������εĸ߶�
            while(st.size()&&arr[st.top()]>arr[i])
            {
                tmp=st.top(); 
                ans=max(arr[st.top()]*(i-st.top()),ans); //��չ
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

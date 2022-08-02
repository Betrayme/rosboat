#include "Client4.h"
#include "UDP4.h"
#include "Clntinteraction.h"

int main(int argc, char** argv) {
    while(1)
    {
    if(argc==4)
    {
        int i=clntinteraction(argv[1],argv[2],argv[3]);
        if(i==-1)
            break;
        if(i==0)
            continue;
    }
    if(argc==3)
     {
        int i=clntinteraction(argv[1],argv[2],argv[3]);
        if(i==-1)
            break;
        if(i==0)
            continue;
    }
    else
    {
        cout<<"请输入正确的参数~"<<endl;
        cout<<"-参数 ip port或 -参数 port"<<endl;
        cout<<"-tcp     以tcp套接字创建客户端"<<endl;
        cout<<"-udp     以udp套接字创建客户端"<<endl;
        cout<<"-shutdown      结束程序"<<endl;
        continue;
    }
    }
    
    return 0;
}


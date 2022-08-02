#include "Clntinteraction.h"
void _umail(const char*argv2,const char* argv3);
void _umail(const char*argv2);
void _tcp(const char*argv2,const char* argv3);
void _tcp(const char*argv2);
int clntinteraction(const char* argv1,const char*argv2,const char* argv3)
{
    if(argv1=="-tcp")
    {
        _tcp(argv2,argv3);
        return -1;
    }else if(argv1=="-udp")
    {
        _umail(argv2,argv3);
        return -1;
    }else if(argv1=="-shutdown")
    {
        return -1;
    }else
    {
        cout<<"请输入正确的参数~"<<endl;
        cout<<"-参数 ip port或 -参数 port"<<endl;
        cout<<"-tcp     以tcp套接字创建客户端"<<endl;
        cout<<"-udp     以udp套接字创建客户端"<<endl;
        cout<<"-shutdown      结束程序"<<endl;
        return 0;
    }
}

int clntinteraction(const char* argv1,const char* argv2)
{
    if(argv1=="-tcp")
    {
        _tcp(argv2);
        return -1;
    }else if(argv1=="-udp")
    {
         _umail(argv2);
        return -1;
    }else if(argv1=="-shutdown")
    {
        return -1;
    }else
    {
        cout<<"请输入正确的参数~"<<endl;
        cout<<"-参数 ip port或 -参数 port"<<endl;
        cout<<"-tcp     以tcp套接字创建客户端"<<endl;
        cout<<"-udp     以udp套接字创建客户端"<<endl;
        cout<<"-shutdown      结束程序"<<endl;
        return 0;
    }
}

void _umail(const char*argv2,const char* argv3)
{
    Umail4 serv(argv2,argv3);     
}

void _umail(const char*argv2)
{

}

void _tcp(const char*argv2,const char* argv3)
{

}

void _tcp(const char*argv2)
{

}
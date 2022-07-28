#ifndef _Server_
#define _Server_
#include "Common.h"

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

class TCPServer4{
public:
    string ip;
    string port;
    TCPServer4(const char*);
    TCPServer4(const char*,const char*);
    int addclnt();  //接收队列中的第一个客户端的连接请求
    int sendmsg(int,char*);  //从服务端向指定已连接的客户端发送数据
    int readmsg(int);   //从服务端读取指定已连接的客户端的发送的数据
    void Close(){       //关闭所有套接字
        close(serv_sock);
        for(auto i=clnt_sock.begin();i!=clnt_sock.end();i++)
            close(*i);
    }
private:
    int serv_sock;  //存放服务端套接字
    int newclnt_sock;    //存放当前客户端套接字
    vector<int> clnt_sock;  //存放所有客户端套接字
    sockaddr_in serv_addr;   //存放服务器地址端口等信息
    sockaddr_in newclnt_addr;   //存放当前客户端地址端口等信息
    socklen_t newclnt_addr_size;   //存放当前clnt_addr大小
    vector<sockaddr_in> clnt_addr;  //存放所有客户端地址端口等信息
    vector<socklen_t> clnt_addr_size;    //存放所有客户端地址结构体大小
    char temsg[MAXMSG];       //存放缓冲消息
    vector<string> msgfclnt; //存放来自客户端消息
};

inline TCPServer4::TCPServer4(const char* port)
{
    this->port=port;
    if((serv_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)   //创建服务端套接字
    {
        cerr<<"socket()->server失败!"<<endl;
        exit(1);
    }
    memset(&serv_addr,0,sizeof(serv_addr)); //初始化服务器地址结构体为0
    serv_addr.sin_family=AF_INET;   //设置存放服务器地址端口等信息的结构体的地址族为IPv4
    serv_addr.sin_port=htons(atoi(port));   //设置存放服务器地址端口等信息的结构体的端口
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);    //设置存放服务器地址端口等信息的结构体的IP为自动分配
    ip=inet_ntoa(serv_addr.sin_addr);  //获取服务器的ip并存储

    if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)  //将服务器信息结构体分配给套接字
    {
        perror("bind error:");
        cerr<<"bind()->服务端失败!"<<endl;
        exit(1);
    }
    if(listen(serv_sock,QUEUE)==-1) //服务端套接字进入连接等待请求状态
    {
        cerr<<"listen()->服务端失败!"<<endl;
    }
}
inline TCPServer4::TCPServer4(const char* IP,const char* port)
{
    if(serv_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)==-1)
    {
         cerr<<"创建服务器套接字失败！"<<endl;
         exit(1);
    }
    memset(&serv_addr,0,sizeof(serv_addr)); 
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(atoi(port));
    serv_addr.sin_addr.s_addr=inet_addr(port);
    //inet_aton(port,serv_addr);
     serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);    //设置存放服务器地址端口等信息的结构体的IP为自动分配
    ip=inet_ntoa(serv_addr.sin_addr);  //获取服务器的ip并存储

    if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)  //将服务器信息结构体分配给套接字
    {
        cerr<<"bind()->服务端失败!"<<endl;
        exit(1);
    }
    if(listen(serv_sock,QUEUE)==-1) //服务端套接字进入连接等待请求状态
    {
        cerr<<"listen()->服务端失败!"<<endl;
    }
}
inline int TCPServer4::addclnt()
{
    if(newclnt_sock=accept(serv_sock,(struct sockaddr*)&newclnt_addr,&newclnt_addr_size)==-1)
    {
        cout<<"accepct()->失败！"<<endl;
        return -1;
    }
    clnt_sock.push_back(newclnt_sock);
    clnt_addr.push_back(newclnt_addr);
    clnt_addr_size.push_back(newclnt_addr_size);
    return 0;
}
inline int TCPServer4::sendmsg(int sock,char* msg)
{
    if(write(sock,msg,sizeof(msg))==-1)
    {
        cerr<<"write()->客户端失败!"<<endl;
        return -1;
    }
    return 0;
}
inline int TCPServer4::readmsg(int sock)
{
    int cnt=0;
    int i=0;
    if(read(sock,temsg,sizeof(temsg)-1)==-1)
    {
        cerr<<"read()->clntmsg失败!"<<endl;
        return -1;
    }
    for(i=0;(temsg[i])!='\0';i++,cnt++); //判断缓存字符组是否被充满
    if(cnt==sizeof(temsg)-1)
    {
        string s(temsg);
        fstream fs("./data/msg.txt",ofstream::out|ofstream::ate);
        fs<<s;
        strcpy(temsg,"\0");
    }
}
#endif
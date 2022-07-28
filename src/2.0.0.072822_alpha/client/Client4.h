#ifndef _Client_
#define _Client_
#include "Common.h"

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

class TCPClient4
{
public:
    string ip;
    string port;
    TCPClient4(const char*,const char*);
    int sendmsg(char*);
    int readmsg();
private:
    int clnt_sock;  //客户端套接字
    sockaddr_in serv_addr;  //目标连接服务器信息结构体
};
inline TCPClient4::TCPClient4(const char* ip,const char* port)
{
    if(clnt_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)==-1)
    {
        cerr<<"socket()->client失败!"<<endl;
        exit(1);
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(ip);
    serv_addr.sin_port=htons(atoi(port));
    if(connect(clnt_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)));
}
#endif
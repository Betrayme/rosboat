#ifndef _Server_
#define _Server_
#include "Common.h"
#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

void servinteract(const char* argv1,const char* argv2,const char* argv3);
void servinteract(const char* argv1,const char* argv2);
/**************************************************TCP****************************************************/
class TCPServer4{
public:
    string ip;
    string port;

    TCPServer4(const char*);
    TCPServer4(const char*,const char*);
     ~TCPServer4()
    {
        Close();
    }

    int addclnt();  //接收队列中的第一个客户端的连接请求
    int Sendmsg(int,char*);  //从服务端向指定已连接的客户端发送数据     
    int Readmsg(int);   //从服务端读取指定已连接的客户端的接收的数据    成功返回0失败返回-1
    int& getclntsock()
    {
        return newclnt_sock;
    }
    int& getservsock()
    {
        return serv_sock;
    }

    void Close(){       //关闭所有套接字
        close(serv_sock);
        for(auto i=clnt_sock.begin();i!=clnt_sock.end();i++)
            close(*i);
    }
    // void showclnt();    //显示已连接客户端
private:
    int serv_sock;  //存放服务端套接字
    int newclnt_sock;    //存放当前客户端套接字
    vector<int> clnt_sock;  //存放所有客户端套接字

    sockaddr_in serv_addr;   //存放服务器地址端口等信息
    sockaddr_in newclnt_addr;   //存放当前客户端地址端口等信息
    socklen_t newclnt_addr_size=sizeof(newclnt_addr);   //存放当前clnt_addr大小

    char temsg[MAXMSG];       //存放缓冲消息
    vector<string> msgfclnt; //存放本次来自客户端消息
};

inline TCPServer4::TCPServer4(const char* port)
{
    this->port=port;

    serv_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(serv_sock==-1)   //创建服务端套接字
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
    cout<<"@"<<ip<<":"<<port<<" ："<<endl;
}

inline TCPServer4::TCPServer4(const char* IP,const char* port)
{
    this->port=port;
    serv_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(serv_sock==-1)
    {
         cerr<<"创建服务器套接字失败！"<<endl;
         exit(1);
    }

    memset(&serv_addr,0,sizeof(serv_addr)); 
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(atoi(port));
    serv_addr.sin_addr.s_addr=inet_addr(IP);
    inet_aton(port,&serv_addr.sin_addr);
    //  serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);    //设置存放服务器地址端口等信息的结构体的IP为自动分配
    ip=inet_ntoa(serv_addr.sin_addr);  //获取服务器的ip并存储

    if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)  //将服务器信息结构体分配给套接字
    {
        perror("bind:");
        cerr<<"bind()->服务端失败!"<<endl;
        exit(1);
    }

    if(listen(serv_sock,QUEUE)==-1) //服务端套接字进入连接等待请求状态
    {
        cerr<<"listen()->服务端失败!"<<endl;
    }
    cout<<"@"<<ip<<":"<<port<<" ："<<endl;
}

inline int TCPServer4::addclnt()
{
    newclnt_sock=accept(serv_sock,(struct sockaddr*)&newclnt_addr,&newclnt_addr_size);
    if(newclnt_sock==-1)
    {
        perror("accept");
        cout<<"accepct()->失败！"<<endl;
        return -1;
    }
    clnt_sock.push_back(newclnt_sock);
    cout<<"客户端接入成功！"<<endl;
    return 0;
}

inline int TCPServer4::Sendmsg(int sock,char* msg) 
{
    cout<<"sending to client id: "<<sock<<"..."<<flush;
    int bit=write(sock,msg,strlen(msg));    //bug(settled):无法全部传出数据 原因:sizeof(char *)的大小恒为8!
    if(bit==-1)
    {
        cerr<<"write()->客户端失败!"<<"客户端描述字为"<<sock<<endl;
        return -1;
    }
    cout<<"sending successfully!"<<endl;
    fstream ws("./data/log/wmsg.txt",ofstream::out|ofstream::app);
    ws<<"/TCP"<<strtime()<<":"<<msg<<"size: "<<bit<<endl;
    ws.close();

    return 0;
}

inline int TCPServer4::Readmsg(int sock)
{
    int cnt=0;
    while(1)
    {
        if(read(sock,temsg,sizeof(temsg)-1)==-1)
        {
        cerr<<"read()->clntmsg失败!"<<endl;
        return -1;
        }
        for(cnt=0;(temsg[cnt])!='\0';cnt++); //判断缓存字符组是否被充满
        if(cnt==sizeof(temsg)-1)
        {
        fstream fs("./data/msg.txt",ofstream::out|ofstream::ate);
        fs<<temsg;
        temsg[0]='\0';
        fs.close();
        continue;
        }else 
        {
            fstream fs("./data/msg.txt",ofstream::in);
            fstream rs("./data/log/rmsg.txt",ofstream::out|ofstream::ate);
            string s;
            fs>>s;
            rs<<"/TCP"<<strtime()<<":"<<s<<endl;
            msgfclnt.push_back(s);
            fs.close();
            rs.close();

            //清空暂存文件夹
            fstream rfs("./data/msg.txt",ofstream::out);
            rfs.close();
            return 0;
        }
    }
   
}

// inline void TCPSever4::showclnt()
// {

// }

#endif
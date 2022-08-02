#ifndef _Client_
#define _Client_
#include "Common.h"

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

/**************************************************TCP****************************************************/
class TCPClient4
{
public:
    string ip;
    string port;

    static TCPClient4* clnt(const char* ip,const char* port);

    int Readmsg();
    int Sendmsg(const char*);

    ~TCPClient4()   //析构函数
    {
        close(clnt_sock);
    }
    string& retmsg()
    {
        return msg;
    }
private:
    TCPClient4(int&,sockaddr_in&);  //构造函数

    int clnt_sock;  //客户端套接字
    sockaddr_in serv_addr;  //目标连接服务器信息结构体

    char temsg[MAXMSG]; //暂存信息
    string msg; //存储本次接收的全部信息
};

TCPClient4* TCPClient4::clnt(const char* ip,const char* port)
{
    int clnt_sock=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    sockaddr_in serv_addr;

    if(clnt_sock==-1)
    {
        cerr<<"socket()->client失败!"<<endl;
        exit(1);
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(ip);
    serv_addr.sin_port=htons(atoi(port));
    cout<<"connecting..."<<flush;
     if(connect(clnt_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
    {
        cerr<<"connect failed!"<<endl;
        return NULL;
    }
    cout<<endl;
    cout<<"connect successfully!"<<endl;
    static TCPClient4 client(clnt_sock,serv_addr);
    return &client;
}

inline TCPClient4::TCPClient4(int& clntsock,sockaddr_in& servaddr)
:clnt_sock(clntsock),serv_addr(servaddr)
{

}

inline int TCPClient4::Readmsg()
{
    msg.clear();
    while(1)
    {
        while(1)
        {
            int t=read(clnt_sock,temsg,sizeof(temsg)-1);
             if(t==-1)
            {
                cerr<<"read failed!"<<endl;
                return -1;
            }else if(t!=0)
            {
                continue;
            }
            break;
        }

        int i=0;
        for(i=0;temsg[i]!='\0';i++);    //bug(settled):i=8,只读到了"hello wo" 分析:TCP传输数据无边界,当内容比较长时操作系统会将数据分成多个数据包发送，
        if(i==MAXMSG-1)                 //而客户端可能未全部接收所有的数据包就调用read函数导致信息部分丢失!
        {
            fstream fs("./data/msg.txt",ifstream::out|ofstream::app);
            fs<<temsg;
            fs.close();
            temsg[0]='\0';
        }else
        {
            fstream ofs("./data/msg.txt",ifstream::out|ofstream::app);
            ofs<<temsg;
            ofs.close();
            fstream oofs("./data/msg.txt",ifstream::in);
            fstream rs("./data/log/rmsg.txt",ofstream::out|ofstream::app);
            getline(oofs,msg); //bug(settled):这个语句从文件中以空格为分界输出给了msg   //原码为:oofs>>msg;
            oofs.close();
            rs<<"TCP"<<msg<<"/TIME:"<<strtime()<<endl;
            rs.close();
            fstream rofs("./data/msg.txt",ifstream::out);
            rofs.close();
            return sizeof(temsg)-1;
        }
    }
}

inline int TCPClient4::Sendmsg(const char* msg)
{
    while(1)
    {
        if(write(clnt_sock,msg,sizeof(msg))==-1)
        {
        cerr<<"write failed!"<<endl;
        return -1;
        }
        fstream fs("./data/log/wmsg",ifstream::out|ifstream::app);
        fs<<"TCP"<<strtime()<<":"<<msg<<endl;
        fs.close();
    }
}
//声明
TCPClient4* makeclnt4();

#endif
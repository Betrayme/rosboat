//请包含头文件"TCPServ4.h"和"UDP4.h"
#include "TCPServ4.h"
#include "UDP4.h"

void _tcpserv(const char*,const char*);
void _tcpserv(const char*);
void _udpserv(const char*,const char*);
void _udpserv(const char*);
void rosboat(Umail4*);
void rosboat(TCPServer4* pserv);

void servinteract(const char* argv1,const char* argv2,const char* argv3)
{
    if(strcmp(argv1,"-tcp")==0)
    {
        _tcpserv(argv2,argv3);
    }else if(strcmp(argv1,"-udp")==0)
    {
        _udpserv(argv2,argv3);
    }else
    {
        cout<<"请输入正确的参数~"<<endl;
        cout<<"-参数 ip port"<<"或 -参数 port"<<endl;
        cout<<"参数列表:"<<endl;
        cout<<"-tcp 以tcp套接字创建服务端"<<endl;
        cout<<"-udp 以udp套接字创建服务端"<<endl;
    }
}

void servinteract(const char* argv1,const char* argv2)
{
    if(strcmp(argv1,"-tcp")==0)
    {
        _tcpserv(argv2);
    }else if(strcmp(argv1,"-udp")==0)
    {
        _udpserv(argv2);
    }else
    {
        cout<<"请输入正确的参数~"<<endl;
        cout<<"-参数 ip port"<<"或 -参数 port"<<endl;
        cout<<"参数列表:"<<endl;
        cout<<"-tcp     以tcp套接字创建服务端"<<endl;
        cout<<"-udp     以udp套接字创建服务端"<<endl;
    }
}

void _tcpserv(const char* ip,const char* port)
{
    TCPServer4 serv(ip,port);
    cout<<"@"<<ip<<":"<<port<<":"<<flush;
    if(serv.addclnt()==-1)
        exit(1);
    while(1)
    {
        char order[MAXMSG];
        cout<<"请输入指令(输入/help以查看帮助):"<<flush;
        cin>>order;
        if(strcmp(order,"/help")==0)
        {
            cout<<"/rosboat"<<"     "<<"进入控制客户端无人船界面"<<endl;
            cout<<"/sendmsg"<<"     "<<"向客户端发送消息"<<endl;
            cout<<"/readmsg"<<"     "<<"接收客户端的消息"<<endl;
            cout<<"/shutdown"<<"     "<<"关闭服务端以结束"<<endl;    
        }else if(strcmp(order,"/rosboat")==0)
        {
            rosboat(&serv);
        }else if(strcmp(order,"/shutdown")==0)
        {
            break;
        }else
        {
            cout<<"请输入正确指令!"<<endl;
            continue;
        }
    }
}

void _tcpserv(const char* port)
{
    TCPServer4 serv(port);
    cout<<"@"<<serv.ip<<":"<<port<<":"<<flush;
    if(serv.addclnt()==-1)
        exit(1);
    while(1)
    {
        char order[MAXMSG];
        cout<<"请输入指令(输入/help以查看帮助):"<<flush;
        cin>>order;
        if(strcmp(order,"/help")==0)
        {
            cout<<"/rosboat"<<"     "<<"进入控制客户端无人船界面"<<endl;
            cout<<"/sendmsg"<<"     "<<"向客户端发送消息"<<endl;
            cout<<"/readmsg"<<"     "<<"接收客户端的消息"<<endl;
            cout<<"/shutdown"<<"     "<<"关闭服务端以结束"<<endl;    
        }else if(strcmp(order,"/rosboat")==0)
        {
            rosboat(&serv);
        }else if(strcmp(order,"/shutdown")==0)
        {
            break;
        }else
        {
            cout<<"请输入正确指令!"<<endl;
            continue;
        }
    }
}

void _udpserv(const char* ip,const char* port)
{
    Umail4 serv(ip,port);
    char clnt_ip[MAXMSG/2];
    char clnt_port[MAXMSG/2];
    cout<<"@"<<ip<<":"<<port<<":"<<"请输入目标连接客户端的ip地址和端口号(格式：ip port):"<<flush;
    cin>>clnt_ip;
    cin>>clnt_port;
    serv.addobj(clnt_ip,clnt_port);
    while(1)
    {
        char order[MAXMSG];
        cout<<"请输入指令(输入/help以查看帮助):"<<flush;
        cin>>order;
        if(strcmp(order,"/help")==0)
        {
            cout<<"/rosboat"<<"     "<<"进入控制客户端无人船界面"<<endl;
            cout<<"/sendmsg"<<"     "<<"向客户端发送消息"<<endl;
            cout<<"/readmsg"<<"     "<<"接收客户端的消息"<<endl;
            cout<<"/shutdown"<<"     "<<"关闭服务端以结束"<<endl;    
        }else if(strcmp(order,"/rosboat")==0)
        {
            rosboat(&serv);
        }else if(strcmp(order,"/shutdown")==0)
        {
            break;
        }else
        {
            cout<<"请输入正确指令!"<<endl;
            continue;
        }
    }
}

void _udpserv(const char* port)
{
    Umail4 serv(port);
    char clnt_ip[MAXMSG/2];
    char clnt_port[MAXMSG/2];
    cout<<"@"<<serv.ip<<":"<<port<<":"<<"请输入目标连接客户端的ip地址和端口号(格式：ip port):"<<flush;
    cin>>clnt_ip;
    cin>>clnt_port;
    serv.addobj(clnt_ip,clnt_port);
    while(1)
    {
        char order[MAXMSG];
        cout<<"请输入指令(输入/help以查看帮助):"<<flush;
        cin>>order;
        if(strcmp(order,"/help")==0)
        {
            cout<<"/rosboat"<<"     "<<"进入控制客户端无人船界面"<<endl;
            cout<<"/sendmsg"<<"     "<<"向客户端发送消息"<<endl;
            cout<<"/readmsg"<<"     "<<"接收客户端的消息"<<endl;
            cout<<"/shutdown"<<"     "<<"关闭服务端以结束"<<endl;    
        }else if(strcmp(order,"/rosboat")==0)
        {
            rosboat(&serv);
        }else if(strcmp(order,"/shutdown")==0)
        {
            break;
        }else
        {
            cout<<"请输入正确指令!"<<endl;
            continue;
        }
    }
}

void rosboat(Umail4* pserv)
{
    cout<<"ps:按住8前进,4左转,6右转,0退出控制"<<endl;
    cout<<"We're taking control of the drone ship in real time..."<<flush;
    char KeyV=0;
    while(1)
    {
        KeyV=getch();
        if((KeyV==CANCEL))
        {
            break;
        }else
        {
            (*pserv).Sendmsg(&KeyV);
        }
    }
}

void rosboat(TCPServer4* pserv)
{
    cout<<"ps:按住8前进,4左转,6右转,0退出控制"<<endl;
    cout<<"We're taking control of the drone ship in real time..."<<flush;
    char KeyV=0;
    while(1)
    {
        KeyV=getch();
        if((KeyV==CANCEL))
        {
            break;
        }else
        {
            (*pserv).Sendmsg((*pserv).getclntsock(),&KeyV);
        }
    }
}

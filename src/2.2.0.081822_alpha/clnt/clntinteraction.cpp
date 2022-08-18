#include "Clntinteraction.h"
/********************头文件接口***********************/
#include "Engine.h"
/*****************************************************/
void _udpclnt(const char* argv2, const char* argv3);
void _udpclnt(const char*argv2);
void _tcpclnt(const char*argv2,const char* argv3);
void _tcpclnt(const char*argv2);
TCPClient4* makeclnt4(const char* ip,const char* port);

int clntinteraction(const char* argv1,const char*argv2,const char* argv3)
{
    if(strcmp(argv1,"-tcp")==0)
    {
        cout<<"-tcp暂不支持port创建!"<<endl;
        return 0;
    }else if(strcmp(argv1,"-udp")==0)
    {
        _udpclnt(argv2,argv3);
        return -1;
    }else if(strcmp(argv1,"-shutdown")==0)
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
        cout<<"-tcp暂不支持port创建!"<<endl;
        return 0;
    }else if(argv1=="-udp")
    {
         _udpclnt(argv2);
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

void _udpclnt(const char* ip,const char* port)
{
    Umail4 serv(ip,port);
    char serv_ip[MAXMSG/2];
    char serv_port[MAXMSG/2];
    cout<<"@"<<ip<<":"<<port<<":"<<"请输入目标连接服务端的ip地址和端口号(格式：ip port):"<<flush;
    cin>>serv_ip;
    cin>>serv_port;
    serv.addobj(serv_ip,serv_port);
    cout<<"服务器注册成功!"<<endl;
    while(1)
    {
        serv.Readmsg();
        /**************************接口****************************/
        enginerun(serv.getTemsg());
        /**********************************************************/
        break;
    }
}

void _udpclnt(const char* port)
{
    Umail4 serv(port);
    char serv_ip[MAXMSG/2];
    char serv_port[MAXMSG/2];
    cout<<"@"<<serv.ip<<":"<<port<<":"<<"请输入目标连接服务端的ip地址和端口号(格式：ip port):"<<flush;
    cin>>serv_ip;
    cin>>serv_port;
    serv.addobj(serv_ip,serv_port);
    cout<<"服务器注册成功!"<<endl;
    while(1)
    {
        serv.Readmsg();
        /**************************接口****************************/
        if (enginerun(serv.getTemsg()) == -1)
            break;
        /**********************************************************/
    }
}

void _tcpclnt(const char*argv2,const char* argv3)
{
   TCPClient4* clnt=makeclnt4(argv2,argv3);
   clnt->Sendmsg("already connect?");
   clnt->Readmsg();
   if(clnt->rettmsg()=="already connect!");
   {
        cout<<"connect successfully!"<<endl;
        /****************接口****************/
        delete clnt;
   }
    
}

TCPClient4* makeclnt4(const char* ip,const char* port)
{
    TCPClient4* clnt;
    while(1)
    {
        clnt=TCPClient4::clnt(ip,port);//创建clnt
        if(clnt==NULL)
        {
            char q='n';
            cout<<"是否重新连接?(y/n?)"<<endl;
            while(1)
            {
                cin>>q;
                if(q=='y'||q=='Y')
                {
                    break;
                }else if(q=='n'||'N')
                {
                    return 0;
                }else
                {
                    cout<<"请输入有效值!"<<endl;
                    continue;
                }
            }
        }else
        {
            break;
        }
    }
    return clnt;
}
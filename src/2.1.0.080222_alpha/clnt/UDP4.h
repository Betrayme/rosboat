//请包含头Common.h!
#ifndef _UDP4_
#define _UDP4_
#include"Common.h"

/**************************************************UDP****************************************************/
class Umail4
{
public:
    string ip;
    string port;

    Umail4();
    Umail4(const char*);
    Umail4(const char*,const char*);
    ~Umail4()
    {
        close(sock);
    }
    int addobj(const char*,const char*);
    int getsock()
    {
        return sock;
    }

    int Sendmsg(const char*);
    // int Sendmsg(FILE*);
    // int Readmsg(FILE*);
    int Readmsg();
private:
    int sock;
    sockaddr_in sock_addr;
    sockaddr_in obj_addr;
    socklen_t obj_addr_size;
    char temsg[MAXMSG];

    const char* obj_ip;
    const char* obj_port;
};

inline Umail4::Umail4()   //若未分配ip端口,首次调用sendto()会自动分配
{

}

inline Umail4::Umail4(const char* port)
{
    sock=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);

    memset(&sock_addr,0,sizeof(sock_addr));
    sock_addr.sin_family=AF_INET;
    sock_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    sock_addr.sin_port=htons(atoi(port));
    

    if(bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr))==-1)
    {
        perror("bind");
        cerr<<"bind failed!"<<endl;
        exit(1);
    }
    this->ip=inet_ntoa(sock_addr.sin_addr);
    cout<<this->ip;
    this->port=port;
}

inline Umail4::Umail4(const char* ip,const char* port)
{
    sock=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
    memset(&sock_addr,0,sizeof(sock_addr));
    sock_addr.sin_family=AF_INET;
    sock_addr.sin_addr.s_addr=inet_addr(ip);
    sock_addr.sin_port=htons(atoi(port));

    if(bind(sock,(struct sockaddr*)&sock_addr,sizeof(sock_addr))==-1)
    {
        perror("bind");
        cerr<<"bind failed!"<<endl;
        exit(1);
    }
    ip=inet_ntoa(sock_addr.sin_addr);
    this->port=port;
}

inline int Umail4::addobj(const char* ip,const char* port)
{
    memset(&obj_addr,0,sizeof(obj_addr));
    obj_addr.sin_family=PF_INET;
    obj_addr.sin_addr.s_addr=inet_addr(ip);
    obj_addr.sin_port=htons(atoi(port));
    if(connect(sock,(sockaddr*)&obj_addr,sizeof(obj_addr))==-1)
    {
        perror("connect");
        cerr<<"connect register failed!"<<endl;
        return -1;
    }
    obj_ip=ip;
    obj_port=port;
    return 0;
}

int Umail4::Sendmsg(const char* msg)
{
    int bit=sendto(sock,msg,strlen(msg),0,(sockaddr*)&obj_addr,sizeof(obj_addr));
    if(bit==-1)
    {
        perror("send");
        cerr<<"send msg failed!"<<endl;
        return -1;
    }
    fstream ws("./data/log/wmsg.txt",ofstream::out|ofstream::app);
    ws<<strtime()<<"/UDP"<<"@"<<ip<<":"<<port<<" :"<<msg<<" to"<<obj_ip<<":"<<obj_port<<endl;
    ws.close();

    return 0;
}

// int Umail4::Sendmsg(FILE* fp)
// {
//     int bit=sendto(sock,fp,sizeof(fp),0,(sockaddr*)&obj_addr,sizeof(obj_addr));
//     if(bit==-1)
//     {
//         perror("send");
//         cerr<<"send msg failed!"<<endl;
//         return -1;
//     }

//     fstream ws("./data/log/wmsg.txt",ofstream::out|ofstream::app);
//     ws<<"/UDP"<<strtime()<<":"<<"a file "<<"size: "<<bit<<endl;
//     ws.close();

//     return 0;
// }

// int Umail4::Readmsg(FILE* fp)
// {
//     if(recvfrom(sock,fp,sizeof(fp),0,(sockaddr*)&obj_addr,&obj_addr_size)==-1)
//     {
//         perror("recieve");
//         cerr<<"reciecve msg failed!"<<endl;
//         return -1;
//     }
    
//     return 0;
// }

int Umail4::Readmsg()
{
    int bit=0;
    while(1)
    {
       bit=recvfrom(sock,temsg,MAXMSG,0,(struct sockaddr*)&obj_addr,&obj_addr_size);
       cout<<"接收了"<<bit<<"字节"<<endl;
       if(bit==-1)
       {
        perror("recieve");
        cerr<<"recieve failed!"<<endl;
        return -1;
       }else if(bit==MAXMSG)
       {
        fstream fp("./data/msg.txt",ofstream::out|ofstream::app);
        fp<<temsg;
        fp.close();
        continue;
       }else if(bit==0)
       {
        break;
       }else
       {
        fstream rp("./data/log/rmsg.txt",ofstream::out|ofstream::app);
        fstream fp("./data/msg.txt",ofstream::in);
        string s;
        getline(fp,s);
        s.append(temsg);
        rp<<strtime()<<"/UDP"<<"@"<<ip<<":"<<port<<" :"<<s<<" from"<<obj_ip<<":"<<obj_port<<endl;
        rp.close();
        fp.close();
        fstream rfp("./data/msg.txt",ofstream::out);
        rfp.close();
        break;
       }
    }
    return bit; //返回最后一次读取的字节数
}
#endif
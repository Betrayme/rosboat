#ifndef _Winudp_
#define _Winudp_
#include "Wincommon.h"

int interudp4(const char* argv1, const char* argv2, const char* argv3);
int interudp4(const char* argv1, const char* argv2);

class Winudp4
{
public:
    Winudp4(const char*, const char*);
    Winudp4(const char*);
    ~Winudp4();
    int addobj(const char*, const char*);
    int Sendmsg(const char*);
    int Readmsg(int);

    string ip;
    string port;
    string obj_ip;
    string obj_port;
private:
    WSADATA wsaData;    //WSADATA，一种数据结构。 这个结构被用来存储被 WSAStartup 函数调用 后返回的 Windows Sockets 数据。
    SOCKET sock;    //本机socket
    SOCKET obj;     //目标socket
    SOCKADDR_IN hostaddr;
    SOCKADDR_IN objaddr;
    socklen_t objaddrsize;
    char temsg[BUF_SIZE];
};

inline Winudp4::Winudp4(const char* ip, const char* port)
{
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        perror("WSAStartup");
        exit(1);
    }
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(1);
    }
    memset(&hostaddr, 0, sizeof(hostaddr));
    hostaddr.sin_family = AF_INET;
    hostaddr.sin_addr.s_addr = inet_addr(ip);
    hostaddr.sin_port = htons(atoi(port));
    if (bind(sock, (SOCKADDR*)&hostaddr, sizeof(hostaddr)) == SOCKET_ERROR)
    {
        perror("bind()");
        exit(1);
    }
    this->ip = ip;
    this->port = port;
}

inline Winudp4::Winudp4(const char* port)
{
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        perror("WSAStartup");
        exit(1);
    }
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(1);
    }
    memset(&hostaddr, 0, sizeof(hostaddr));
    hostaddr.sin_family = AF_INET;
    hostaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    hostaddr.sin_port = htons(atoi(port));
    if (bind(sock, (SOCKADDR*)&hostaddr, sizeof(hostaddr)) == SOCKET_ERROR)
    {
        perror("bind()");
        exit(1);
    }
    this->ip = ip;
    this->port = port;
}

inline Winudp4::~Winudp4()
{
    closesocket(sock);
    WSACleanup();
}

inline int Winudp4::addobj(const char* ip, const char* port)
{
    memset(&objaddr, 0, sizeof(objaddr));
    objaddr.sin_family = AF_INET;
    objaddr.sin_addr.s_addr = inet_addr(ip);
    objaddr.sin_port = htons(atoi(port));
    if (connect(sock, (SOCKADDR*)&objaddr, sizeof(objaddr)) == -1)
    {
        perror("connect");
        return -1;
    }
    this->obj_ip = ip;
    this->obj_port = port;
    return 0;
}

inline int Winudp4::Sendmsg(const char* msg)
{
    int i = sendto(sock, msg, sizeof(msg), 0, (SOCKADDR*)&objaddr, sizeof(objaddr));
    if (i == SOCKET_ERROR)
    {
        perror("sendto()");
        return i;
    }
    return i;
}

inline int Winudp4::Readmsg(int)
{
    int i = recvfrom(sock, temsg, sizeof(temsg) - 1, 0,(SOCKADDR*)&objaddr,&objaddrsize);
    temsg[1] = '\0';
    if (i == SOCKET_ERROR)
    {
        perror("recvfrom()");
        return i;
    }
    return i;
}
#endif

#include <iostream>
#include "Winudp4.h"

int main(int argc,char**argv)
{
    if(argc==4)
   {
      if(interudp4(argv[1],argv[2],argv[3])==-1)
      {
         cout<<"请输入正确的参数~"<<endl;
         cout<<"-参数 ip port"<<"或 -参数 port"<<endl;
         cout<<"参数列表:"<<endl;
         cout<<"-tcp     以tcp套接字创建服务端"<<endl;
         cout<<"-udp     以udp套接字创建服务端"<<endl;
      }
   }
   if(argc==3)
   {
      if(interudp4(argv[1],argv[2])==-1)
      {
         cout<<"请输入正确的参数~"<<endl;
         cout<<"-参数 ip port"<<"或 -参数 port"<<endl;
         cout<<"参数列表:"<<endl;
         cout<<"-tcp     以tcp套接字创建服务端"<<endl;
         cout<<"-udp     以udp套接字创建服务端"<<endl;
      }
   }
   else
   {
      char jud;
      cout << "无外部参数，将以默认参数启动(udp@192.168.137.1:8888)(y/n)?" << endl;
      cin >> jud;
      if(jud=='y'||jud=='Y')
         interudp4("-udp", "192.168.137.1", "8888");
   }
    return 0;
}

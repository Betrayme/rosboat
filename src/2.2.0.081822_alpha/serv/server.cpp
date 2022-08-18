#include "UDP4.h"



int main(int argc,char** argv)
{
   if(argc==4)
   {
      if(servinteract(argv[1],argv[2],argv[3])==-1)
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
      if(servinteract(argv[1],argv[2])==-1)
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
   cout<<"请输入正确的参数~"<<endl;
   cout<<"-参数 ip port"<<"或 -参数 port"<<endl;
   cout<<"参数列表:"<<endl;
   cout<<"-tcp     以tcp套接字创建服务端"<<endl;
   cout<<"-udp     以udp套接字创建服务端"<<endl;
   }
   return 0;
}

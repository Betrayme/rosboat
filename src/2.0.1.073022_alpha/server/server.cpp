#include "Common.h"
#include "Server4.h"

int main(int argc,char** argv)
{
   if(argc!=3&&argc!=2)
   {
      cerr<<"参数应为2或3!"<<endl;
      exit(1);
   }else if(argc==3)
   {
      TCPServer4 serv(argv[1],argv[2]);
      char s[]="hello world!";
      serv.addclnt();
      serv.sendmsg(serv.getclntsock(),s);
   }else if(argc==2)
   {
      TCPServer4 serv(argv[1]);
      char s[]="hello world!";
      serv.addclnt();
      serv.sendmsg(serv.getclntsock(),s);
   }
   cout<<"输入任意整数以结束"<<endl;   //bug:此句话不显示
   int j;
   cin>>j;
   return 0;
}

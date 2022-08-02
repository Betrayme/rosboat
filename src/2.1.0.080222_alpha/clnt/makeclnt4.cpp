#include "Client4.h"
#include "UDP4.h"

TCPClient4* makeclnt4(char* ip,char* port)
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

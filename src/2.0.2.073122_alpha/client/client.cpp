#include "Common.h"
#include "Client4.h"

int main(int argc, char** argv) {
    if(argc!=3)
    {
        cerr<<"参数应为3!"<<endl;
        exit(1);
    }

    static TCPClient4* clnt;
    while(1)
    {
        clnt=TCPClient4::clnt(argv[1],argv[2]);//创建clnt
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
    // sleep(2);
    if((*clnt).Readmsg()==-1)
    {
        perror("read");
        cerr<<"read failed"<<endl;
        exit(1);
    }
    cout<<(*clnt).retmsg()<<endl; 
    return 0;
}

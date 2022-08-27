# Unmanned ship system
## 文件介绍
* 通过C++中的wiringPi库函数模拟pwm信号进行输出以达到控制树莓派的目的
* 1.X_alpha版本采用putty远程控制,上位机上显示树莓派系统的terminal,直接在terminal上运行控制程序,这样做虽然能达到控制目的,但传输数据量较大,会存在比较大的控制延迟
* beta版本采用TCP/IP协议通过上位机直接传输控制指令,下位机接收控制指令发出相应动作,大大减小了数据传输量,使控制延迟更低,操作精度更高
## 文件架构
* 只介绍beta版本
在src文件中,选择beta版本
```
-rosboat
	-.vscode vscode编辑调试配置文件
	-clnt
		-.vscode	vscode编辑调试配置文件
		-bin	可运行二进制文件
			-data	客户端运行日志
		-build
		-data	客户端调试运行日志
		...		源代码
	-serv
		-.vscode	vscode编辑调试配置文件
		-bin	可运行二进制文件
			-data	客户端运行日志
		-build
		-data	客户端调试运行日志
		...		源代码
	-terminal port	终端最终控制程序,结合clnt留有的接口使用
	...		源代码
```
## 使用教程
* 树莓派安装wiringPi和其库函数,复制clnt/bin下的所有文件到树莓派的工作空间中
* `./二进制文件 参数`运行客户端
* 上位机使用linux系统,复制serv/bin下的所有文件到工作空间中
* `./二进制文件 参数`运行服务端
* 依据程序指示进行相关参数输入已完成服务端创建和控制运行
* 具体编译链接过程不再赘述,如有问题咨询: 496199270@qq.com

##WARNING
* 请将客户端和服务端运行到同一局域网上,目前3.X版本不支持互联网连接和tcp连接

贡献人:	Alvari

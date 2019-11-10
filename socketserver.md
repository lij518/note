
#### 网络编程之socketserver
* python把网络服务抽象成两个主要的类
* 1、Server类用于处理连接相关的网络操作
* 2、RequestHandle类用于处理数据相关的操作，提供两个MixIn类，用于扩展Server，实现多进程或者多线程。
* ThreadingTCPServer实现的Socket服务器内部会为每个client创建一个"线程"，该线程用来和客户端进行交互。
* 首先，必须通过继承BaseRequestHandler类并重写handle()方法来创建请求处理程序类，这个方法将处理传入的请求。
* 其次，必须实例化其中一个服务器类，并将其传递给服务器的地址和请求处理程序类
* 然后，调用服务器对象的handle_request() or serve_forever()方法来处理一个或多个请求


```python
import socketserver
import json,os
import hashlib
class MyTCPHandler(socketserver.BaseRequestHandler):
    def put(self,*args):
        server_md5 = hashlib.md5()
        # 接收客户端文件
        print('args:%s' % args)
        cmd_dic = args[0]
        filename = cmd_dic['filename']
        filesize = cmd_dic['size']
        if os.path.isfile(filename):
            f = open(filename + '.new','wb')
        else:
            f = open(filename,'wb')
        self.request.send(b'200 OK')
        received_size = 0
        while received_size < filesize:
            data = self.request.recv(1024)
            server_md5.update(data)
            f.write(data)
            received_size += len(data)
            
        
        print('file [%s] has uploaded...' % filename)
        self.request.send(server_md5.hexdigest().encode())
    def get(self,*args):
        md5_server = hashlib.md5()
        cmd_dic = args[0]
        filename = cmd_dic['filename']
        if os.path.isfile(filename):
            file_size = os.stat(filename).st_size
            self.request.send(str(file_size).encode())
            #等待客户端的回应
            self.request.recv(1024)
            #开始发送文件
            f = open(filename,'rb')
            for line in f:
                self.request.send(line)
                md5_server.update(line)
            #将md5值发送客户端
            print(md5_server.hexdigest())
            self.request.send((md5_server.hexdigest().encode))
        else:
            print('服务端没此文件')
    def handle(self):
        while True:
            try:
                self.data = self.request.recv(1024).strip()
                print('{} wrote:'.format(self.client_address[0]))
                print(self.data)
                cmd_dic = json.loads(self.data.decode())
                print('cmd_dic:%s' % cmd_dic)
                action = cmd_dic['action']
                if hasattr(self,action):
                    func = getattr(self,action)
                    func(cmd_dic)
            except ConnectionResetError as e:
                print('err',e)
                break

if __name__ == '__main__':
    HOST,PORT = 'localhost',9000
    server = socketserver.ThreadingTCPServer((HOST,PORT),MyTCPHandler)
    server.serve_forever()
```

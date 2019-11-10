
#### 客户端 上传、下载


```python
import socket
import json
import os
import hashlib
#用于打印进度条
import sys,time

class Ftpclient(object):
    def __init__(self):
        self.client = socket.socket()
    def help(self):
        msg = '''
        ls
        pwd
        cd ../..
        get filename
        put filename
        '''
        print(msg)
    def connect(self,ip,port):
        self.client.connect((ip,port))
    #利用反射，通过输入的字符串来调用不同的方法
    def interactive(self):
        md5_client = hashlib.md5()
        
        while True:
            cmd = input('>>>').strip()
            if len(cmd) ==0:continue
            cmd_str = cmd.split()[0]
            if hasattr(self,'cmd_%s' % cmd_str):
                func = getattr(self,'cmd_%s' % cmd_str)
                func(cmd)
            else:
                self.help()
    def cmd_put(self,*args):
        cmd_split = args[0].split()
        if len(cmd_split)>1:
            filename = cmd_split[1]
            if os.path.isfile(filename):
                filesize = os.stat(filename).st_size
                msg_dic = {
                    'action':'put',
                    'filename':filename,
                    'size':filesize,
                    'overridden':True
                }
                # encode()转为字节对象
                self.client.send(json.dumps(msg_dic).encode('utf-8'))
                print('send',json.dumps(msg_dic).encode('utf-8'))
                # 防止粘包，等服务器确认
                server_response = self.client.recv(1024)
                print('server_response:%s' % server_response)
                f = open(filename,'rb')
                # 用于MD5校验
                client_md5 = hashlib.md5()
                # 用于计算发送了多少数据
                client_size = 0
                b = 0
                for line in f:
                    self.client.send(line)
                    client_md5.update(line)
                    client_size += len(line)
                    
                    #计算接收的数据 占 总文件的百分比
                    a = int(client_size / filesize * 100)
                    if b != a and a % 2 == 0:
                        sys.stdout.write('#')
                        sys.stdout.flush()
                    else:
                        pass
                    b = a
                print('100%')
                f.close()
                # 客户端发送数据的md5值
                client_md5 = client_md5.hexdigest()# 获取加密后的16进制字符串
           
                server_md5 = self.client.recv(1024)
                server_md5 = server_md5.decode()
                #判断 两边的md5值是否一致的
                if server_md5 == client_md5:
                    print('文件成功上传至服务器')
                else:
                    print('上传出错')
            else:
                print(filename,'is not exit')
    def cmd_get(self,*args):
        #用md5对比文件是否一致
        md5_client = hashlib.md5()
        #把输入的命令 按空格分割 切成列表
        cmd_split = args[0].split()
        if len(cmd_split) > 1:
            filename = cmd_split[1]
        msg_dic = {
            'action':'get',
            'filename':filename
        }
        print(msg_dic)
        self.client.send(json.dumps(mag_dic).encode('utf-8'))
        print('发送完毕')
        
        #获取服务端文件的大小
        size = self.client.recv(1024).decode()
        print(type(size))
        print(size)
        server_size = int(size)
        print('获取服务器文件的大小是'%s % server_size)
        #随便写一个，防止粘包
        self.client.send(b'200 OK')
        #准备接收服务端发来的数据
        #已经获取文件的大小
        client_size = 0
        if os.path.isfile(filename):
            f = open(filename + 'new','wb')
        else:
            f = open(filename,'wb')
        #防止重复出现相同的百分比，而设置的变量
        b = 0
        while client_size < server_size:
            if server_size - client_size > 1024:
                data_size = 1024
            else:
                data_size = server_size - client_size
            
            data = self.client.recv(data_size)
            md5_client.update(data)
            f.write(data)
            #计算接收过来的数据长度
            client_size += len(data)
            
            #计算接收的数据 占 总文件的百分比
            a = int(client_size/server_size*100)
            if b!=a and a%2==0:
                sys.stdout.write('#')
                sys.stdout.flush()
            else:
                pass
            b=a
        #接收server过来的md5值
        server_md5 = self.client.recv(1024)
        server_md5 = server_md5.decode()
        client_md5 = md5_client.hexdigest()
        if server_md5 == client_md5:
            print('100%')
        else:
            print('文件可能被篡改，请重新下载')
ftp = Ftpclient()
ftp.connect('localhost',9000)
ftp.interactive()
```

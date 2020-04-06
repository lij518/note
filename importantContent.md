#### gmail用户名：student.lij518@gmail.com
#### windows 搭建svn服务：https://blog.csdn.net/tojohnonly/article/details/70090619
#### 机器学习网址：https://github.com/RedstoneWill/MachineLearningInAction-Camp
#### powerdisigner博客笔记：https://blog.csdn.net/xieqingcheng4000/article/details/7357866?locationNum=2&fps=1
<br>
http://www.cnblogs.com/Luouy/archive/2011/01/14/1935669.html

SpringBoot视频教程 百度云

史上最全最精辟的SpringBoot视频教程

B站视频地址

https://www.bilibili.com/video/av33985898

百度云保存地址

链接：https://pan.baidu.com/s/1c1hPI1_13He6wguJUrlivg 密码：jidq

附件教程：

Redis中高级课程视频在线观看地址：https://www.bilibili.com/video/av34900337/

更多分布式微服务视频教程

http://www.majiaxueyuan.com/<br>

idea开发工具快捷<br>
main函数    psvm<br>
输出        sout<br>
for循环     fori<br>
#### mac 将本地文件上传服务器使用scp命令
scp /users/lijun/downloads/jdk-8u181-linux-x64.tar.gz lijun@192.168.0.19:/home/lijun/app/ <br>
#### 将本地文件上传下载hdfs  使用命令hadoop
hadoop fs -put jdk-8u181-linux-x64.tar.gz hdfs://service1:9000/<br>
hadoop fs -get hdfs://service1:9000/jdk-8u181-linux-x64.tar.gz<br>
#### 误将大文件上传，导致objects一直存在
git fetch -f -p <br>
git checkout master <br>
git reset origin/master --hard  <br>
git reflog expire --expire=now --all <br>
git gc --prune=now
#### sublimeText3安装sublimeREPL插件（控制台输入）
设置快捷键：<br>
```
Preferences -> Key Bindings

[   
    {"keys":["f1"],
    "caption": "SublimeREPL: Python - RUN current file",
    "command": "run_existing_window_command", "args":
    {"id": "repl_python_run",
    "file": "config/Python/Main.sublime-menu"}},

    {"keys":["f2"],
    "caption": "SublimeREPL: Python",
    "command": "run_existing_window_command", "args":
    {"id": "repl_python",
    "file": "config/Python/Main.sublime-menu"}}
]
```
这里我设置的 F1 运行代码，F2 打开终端。<br>
按 F2 运行终端，发现默认集成的是 python2，手动改成 pyhton3，方法如下：<br>
Preferences -> Browse Packages->SublimeREPL->config->Python->Main.sublime-menu<br>
将Main.sublime-menu文件所有的python改为python3<br>
```
"cmd": ["python3", "-i", "-u"],
"cmd": ["python3", "-i", "-u", "-m", "pdb", "$file_basename"],
"cmd": ["python3", "-u", "$file_basename"],
"cmd": {
    "osx": ["python3", "-u", "${packages}/SublimeREPL/config/Python/ipy_repl.py"],
    "linux": ["python3", "-u", "${packages}/SublimeREPL/config/Python/ipy_repl.py"],
    "windows": ["python3", "-u", "${packages}/SublimeREPL/config/Python/ipy_repl.py"]
},
```
#### github密码修改后的操作
- git config --global user.name "lij518"
- git config --global user.email "770811765@qq.com"




#### requests库的7个主要方法
- requests.request() 构造一个请求，支撑一下各方法的基础方法
- requests.get() 获取html网页的主要方法，对应于http的get
- requests.head() 获取html网页头信息的方法，对应于http的head
- request.post()  向html网页提交post请求的方法，对应于http的post
- requests.put()    向html网页提交put请求的方法，对应于http的put
- requests.patch()   向html网页提交局部修改请求，对应于http的patch
- requests.delete()   向html页面提交删除请求，对应于http的delete

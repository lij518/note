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
hadoop fs -put jdk-8u181-linux-x64.tar.gz hdfs://service1:9000/
hadoop fs -get hdfs://service1:9000/jdk-8u181-linux-x64.tar.gz
#### 误将大文件上传，导致objects一直存在
lijundeMacBook-Pro:github lijun$ git reset origin/master --hard
HEAD is now at 9a7f6b2 java
lijundeMacBook-Pro:github lijun$ git reflog expire --expire=now --all
lijundeMacBook-Pro:github lijun$ git gc --prune=now

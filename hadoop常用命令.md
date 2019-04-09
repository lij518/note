#### mapReduce
找到share文件夹，，该文件夹主要存有jar包，，进入mapReduce包下，有个<br>
example的jar包，该jar包存放了mapReduce的案例用来测试<br>
首先在hdfs创建目录：hadoop fs -mkdir <font style="color:red">(hdfs://service1:9000)</font>/wordcount<br>
hadoop fs -mkdir /wordcount/input <br>
需要将文件传入hdfs集群才能分布式计算<br>
hadoop fs -put test.txt /wordcount/input<br>
执行example.jar包<br>
hadoop jar example.jar wordcount /wordcount/input /wordcount/output
#### 删除文件夹命令
hadoop fs -rm -r -skipTrash /test
#### 在根目录下创建目录
hadoop fs -mkdir /test
#### 上传下载
hadoop fs -put(-get) /test/test.txt
#### 复制
hadoop fs -cp /test/test/txt




#### 安装CentOs图形界面
sudo yum groupinstall "GNOME Desktop" "Graphical Administration Tools"<br>
进入后登录账号密码   startx切换到图形界面  init 5 需要重启<br>

#### CentOs 7.0防火墙
查看防火墙状态 firewall-cmd --state<br>
停止firewall  systemctl stop firewall.service<br>
禁止firewall开机启动  systemctl disable firewall.service<br>
#### 修改主机名
修改文件/etc/hostname 不能立马生效<br>
可以使用hostname命令查看  hostname service1及时修改<br>
#### 添加密钥免密码登录
首先建立公钥和私钥：ssh-keygen -t rsa <br>
生成.ssh的隐藏文件，使用ll -a查看<br>
将公钥上传到需要登录的服务器上，scp id_isa.pub servie1:/home/lijun<br>
将公钥的内容复制给authorized_keys文件，若没有改文件自己在.ssh目录下创建<br>
touch authorized_keys 需要修改该文件的权限chmod 600 authorized_keys<br>
cat id_isa.pub >> authorized_keys

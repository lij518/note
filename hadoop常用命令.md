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





#### CentOs 7.0防火墙
查看防火墙状态 firewall-cmd --state<br>
停止firewall  systemctl stop firewall.service
禁止firewall开机启动  systemctl disable firewall.service
#### 修改主机名
修改文件/etc/hostname 不能立马生效
可以使用hostname命令查看  hostname service1及时修改

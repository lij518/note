高可用集群副本数据最好是>=3的奇数
* apiserver:所有服务访问统一入口
* controllerManager:维持副本期望数目
* Scheduler:负责介绍任务，选择合适的节点进行分配任务
* etcd:键值对数据库，存储k8s集群所有重要信息（3版本持久化）
* kubelet:直接跟容器引擎交互实现容器的生命周期管理
* kube-proxy：负责写入规则至IPTABLES、IPVS实现服务映射访问的
* coredns: 可以为集群中的SVC创建一个域名ip的对应关系解析
* dashboard:给k8s集群提供一个B/S结构访问体系
* ingress controller:官方只能实现四层代理，ingress 可以实现七层代理
* fedetation:提供一个可以跨集群中心多k8s统一管理功能
* prometheus：提供一个k8s集群的监控能力
* elk:提供k8s集群日志统一分析介入平台
#### 设置系统主机名以及host文件
```
hostnamectl set-hostname k8s-master01
```
#### 安装依赖包
```
yum install -y conntrack ntpdate ntp ipvsadm ipset jq iptables curl sysstat libseccomp wget vim net-tools git
```
#### 设置防火墙为Iptables并设置空规则
```
systemctl stop firewalld && systemctl disable firewalld
yum -y install iptables-services && systemctl start iptables && systemctl enable iptables && iptables -F && service iptables save
```
#### 关闭selinux
```
swaoff -a && sed -i '/ swap / s/^\(.*\)$/#\l\g' /etc/fstab
setenforce 0 && sed -i 's/^SELINUX=.*/SELINUX=disabled/' /etc/selinux/config
```

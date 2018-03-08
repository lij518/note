#### 进程
程序的执行过程<br>
持有资源（共享内存， 共享文件）和线程<br>
#### 线程
线程是系统中最小的执行单元<br>
同一进程中有多个线程<br>
线程共享进程的资源<br>
#### java中线程的常用方法介绍
![aa](assets/markdown-img-paste-20180308112659462.png)
```JAVA
package com.imooc.concurrent;

public class Actor extends Thread{

  public void run(){
    System.out.println(getName()+"是一个演员！");
    int count=0;
    boolean keepRunning=true;
    while(keepRunning){
    System.out.println(getName()+"登台演出："+（++count）);
    if(count==100){
      keepRunning=false;
    }
    if(count%10==0){
      Thread.sleep(1000);
    }
    }
    System.out.println(getName()+"的演出结束了！");

  }
  public static void main(String[] args){
    Thread actor=new Actor();
    actor.setName("Mr.Thread");
    actor.start();
    Thread actressThread=new Thread(new Actress(),"Ms.Runnable");
    actressThread.start();
  }
}
class Actress implements Runnable{
  public void run(){
    System.out.println(Thread.currnetTread().getName()+"是一个演员！");
    int count=0;
    boolean keepRunning=true;
    while(keepRunning){
    System.out.println(Thread.currnetTread().getName()+"登台演出："+（++count）);
    if(count==100){
      keepRunning=false;
    }
    if(count%10==0){
      Thread.sleep(1000);
    }
    }
    System.out.println(Thread.currnetTread().getName()+"的演出结束了！");
  }
}
```
#### java中Thread和Runnable实现多线程的区别和联系
java有两种方式实现多线程，第一个是继承Thread类，第二个是实现Runnable接口。他们之间的联系：<br>
1、Thread类实现了Runnable接口。<br>
2、都需要重写里面Run方法。<br>
他们之间的区别：<br>
1、实现Runnable的类更具有健壮性，避免了单继承的局限。<br>
2、Runnable更容易实现资源共享，能多个线程同时处理一个资源。
```JAVA
package com.imooc.comcurrent.base;

//军队线程
//模拟作战双方的行为
public class ArmyRunnable implements Runnable{

//volatile保证了线程可以正确的读取其它线程写入的值
//可见性ref jMM ,happens-before原则
  volatile boolean keepRunning=true;
  public void run(){
    while(keepRunning){
      //发动5连击
      for(int i=0;i<5;i++){
        System.out.println(Thread.currentThread().getName()+"进攻对方["+i+"]");
        //让出了处理器时间，下次该谁进攻还不一定！
        Thread.yield();
      }
    }
    System.out.println(Thread.currentThread().getName()+"结束了战斗！");
  }

}
//隋唐演义大舞台
public class Stage extends Thread{

  public void run(){

    ArmyRunnable armyTaskOfSuiDynasty=new ArmyRunnable();
    ArmyRunnable armyTaskOfRevol=new ArmyRunnable();
    //使用Runnable接口创建线程
    Thread armyTaskOfSuiDynasty=new Thread(armyTaskOfSuiDynasty,"隋朝军队");
    Thread armyTaskOfRevol=new Thread(armyTaskOfRevol,"农民起义军");
    //启动线程，让军队开始作战
    armyOfSuiDynasty.start();
    armyOfRevol.start();
    //舞台线程休眠
    Thread.sleep(50);
    armyTaskOfSuiDynasty.keepRunning=false;
    armyTaskOfRevol.keepRunning=false;

    armyTaskOfRevol.join();
  }
  public static void main(String[] args){
    new Stage().start();
  }
}


```

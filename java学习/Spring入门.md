### 简介
Spring 是为解决企业应用程序开发发杂性而创建的一个java开源框架，业内流行的SSH架构中的其中一个"S"指的就是Spring.
#### 框架
框架就是指定一套规范或者规则，大家在该规范或者规则下工作。或者说是使用别人大号的舞台，你来表演
#### 特点
半成品，分装了特定的处理流程和控制逻辑，成熟的、不断升级改进的软件
#### 框架与类库的区别
框架一般是封装了逻辑、高内聚的，类库则是松散的工具组合，框架专注于某一领域，类库是更通用的。
### 专题一IOC
#### 什么是IOC
IOC：控制反转，控制权的转移，应用程序本身不负责依赖对象的创建和维护，而是由外部容器负责创建和维护<br>
DI(依赖注入)是其中一种实现方式<br>
目的：创建对象并且组装对象之间的关系<br>
```java
package com.imooc.ioc.interfaces;

public interface OneInterface{

  String hello(String word);

}
public class OneInterfaceImpl implements OneInterface{

  public String hello(String word){
    return "Word from interface\"OneInnterface\":"+word;
  }
}

public class Main{
  public static void main(String[] args){
    OneInterface oif=new OneInterfaceImpl();
    System.out.println(oif.hello("word."));
  }

}
```
#### Spring 的Bean配置

刚才的接口在Spring中的配置方式<br>
``` xml
<?xml version="1.0"enconding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.springframework.org/schema/beans
    http://www.springframework.org/chema/beans/spring-beans.xsd">

    <bean id="oneInterface" class="com.imooc.ioc.interfaces.OneInterfaceImpl"></bean>
  </beans>
```
``` java
package com.imooc.test.ioc.interfaces;

import org.junit.Test;
@RunWith(BlockJUnit4ClassRunner.class)
public class TestOneInterface extends UnitTestBase{

  public TestOneInterface(){
    super("classpath*:spring-ioc.xml");
  }
  @Test
  public void testHello(){
    OneInterface oneInterface=super.getBean("oneInterface");
    System.out.println(oneInterface.hello("我的输入参数"));
  }
}



```

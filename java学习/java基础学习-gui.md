#### java基础学习
java的三大特征：抽象、封装和继承<br>
#### 图形用户界面（gui）
AWT SWING SWT JFACE <br>
#### 布局管理器-介绍
概念：组件在容器（比如JFrame）中的位置和大小是由布局管理器来决定的<br>
所有的容器都会使用一个布局管理器，通过他来自动进行组件的布局管理。<br>
种类：java共提供了五种布局管理器：流式布局管理器（FlowLayout）,<br>
边界布局管理器（BorderLayout），网格布局管理器(GridLayout),<br>
 卡片布局管理器（CardLayout）,网格包布局管理器(GridBagLayout).<br>
 其中前三种是最常见的布局管理器。<br>
<b>边界布局BorderLayout-注意事项</b><br>
1、不是五个部分都必须添加<br>
2、中部组件会自动的调节大小<br>
3、Frame,JDialog 默认布局管理器就是BorderLayout<br>
<B>流式布局FlowLayout -介绍</B><br>
FlowLayout布局，按照组件的添加次序将按钮组件（当然也可以是别的组件）<br>从左到右放置容器中，当达到容器的边界时，组件将放置在下一行中。<br>FrowLayout可以以左对齐、居中对齐、以右对齐的方式排列组件。<br>
<b>流式布局FlowLayout-注意事项</b><br>
1、不限制他所管理的组件大小，允许他们有最佳大小<br>
2、当容器被缩放时，组件的位置可能变化，但组件的大小不变。<br>
3、默认组件是居中对齐，可以通过FlowLayout(int align)函数来指定对齐方式<br>
<b>网格布局(GridLayout)</b><br>
GridLayout布局，听其名而知其意，它将容器分割成多行多列，组件被填充到<br>每个网格中，添加到容器中的组件首先放置在左上角的网格中，然后
<br>从左到右放置其他的组件，当占满该行的所有网格后，接着继续在下一行从左<br>到右放置组件<br>
<b>网格布局GridLayout-注意事项</b><br>
1、组件的相对位置不随容器的缩放而变化，但大小会变化<br>
2、所有组件的大小相同<br>
3、可以通过GridLayout(int rows,int cols,int hgap,int vgap)<br>
来指定网格的行/列，水平间隙/垂直间隙。<br>
#### 开发GUI程序步骤
1、继承JFrame<br>
2、定义需要的组件<br>
3、创建组件<br>
4、设置布局管理器<br>
5、添加组件<br>
6、显示窗体<br>
<b>面板组件（Jpanel）</b><br>
在图形用户界面编程中，如果只是普通的组件布局，我们用前面讲的三种布局管理<br>器就可以解决，但是在比较复杂的布局要求时，就需要使用布局管理器的<br>组合使用。<br>
``` java
/**
 * 功能：gui界面开发演示
 */


package com.test;
//引入包
import java.awt.*;

import javax.swing.*;

public class Demo extends JFrame{
	//把需要的swing组件，定义到这
	JButton jb1;
	public static void main(String[] args){
		Demo demo=new Demo();
	}
	//构造函数
	public Demo() {
		//JFrame是一个顶层容器类（可以添加其他swing组件的类）
				this.jb1=new JButton("我是按钮");		
				//添加JButton组件
				this.add(jb1);
				//给窗体设置标题
				this.setTitle("hello world");
				//设置大小,按像素
				this.setSize(500,500);
				//设置初始位置
				this.setLocation(100,200);
				//窗口关闭后JVM也关闭
				this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				//显示
				this.setVisible(true);

	}
}
/**
 * BorderLayout演示
 * 1、继承jframe
 * 2、定义你需要的组件
 * 3、创建组件（构造函数）
 * 4、添加组件
 * 5、对窗体设置
 * 6、显示窗体
 */

package com.test;
import java.awt.*;
import javax.swing.*;
public class Demo1 extends JFrame{

	//定义组件
	JButton jb1,jb2,jb3,jb4,jb5;
	public static void main(String[] args) {
		Demo1 demo1=new Demo1();

	}
	public Demo1() {
		//创建组件
		jb1=new JButton("中部");
		jb2=new JButton("北部");
		jb3=new JButton("东部");
		jb4=new JButton("南部");
		jb5=new JButton("西部");
		//添加各个组件
		this.add(jb1,BorderLayout.CENTER);
		this.add(jb2,BorderLayout.NORTH);
		this.add(jb3, BorderLayout.EAST);
		this.add(jb4, BorderLayout.SOUTH);
		this.add(jb5,BorderLayout.WEST);
		//设置窗体属性
		this.setTitle("边界布局演示");
		this.setSize(300, 200);
		this.setLocation(200, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}
/**
 * 功能：流式布局案例
 */

package com.test;

import javax.swing.*;
import java.awt.*;

public class Demo2 extends JFrame {

	JButton jb1,jb2,jb3,jb4,jb5,jb6;
	public static void main(String[] args) {
		Demo2 demo2=new Demo2();
	}
	//构造韩式
	public Demo2() {
		//创建组件
		jb1=new JButton("关羽");
		jb2=new JButton("张飞");
		jb3=new JButton("赵云");
		jb4=new JButton("马超");
		jb5=new JButton("黄忠");
		jb6=new JButton("魏延");
		//添加组件
		this.add(jb1);
		this.add(jb2);
		this.add(jb3);
		this.add(jb4);
		this.add(jb5);
		this.add(jb6);
		//设置布局管理器
		this.setLayout(new FlowLayout(FlowLayout.LEFT));

		//设置窗体大小
		this.setTitle("流式布局案例");
		this.setSize(300, 200);
		this.setLocation(200, 200);
		//禁止用户改变窗体大小
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//显示
		this.setVisible(true);

	}
}
/**
 * 网格布局
 */

package com.test;

import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Demo3 extends JFrame {

	//定义组件
	JButton[] jbs=new JButton[9];
	public static void main(String[] args) {
		Demo3 demo3=new Demo3();
	}

	//构造
	public Demo3() {

		// 创建组件
		for(int i=0;i<9;i++) {
			jbs[i]=new JButton(String.valueOf(i));
		}
		//设置网格布局
		this.setLayout(new GridLayout(3,3,10,10));
		//添加组件
		for(int i=0;i<jbs.length;i++) {
			this.add(jbs[i]);
		}
		//设置窗体属性
		this.setTitle("网格布局案例");
		this.setSize(300, 200);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLocation(200, 200);
		this.setVisible(true);
	}
}

```

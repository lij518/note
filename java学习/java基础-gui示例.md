#### JAVA示例-gui
<b>坦克大战</b><br>
``` java
package com.test1;
import java.awt.*;
import javax.swing.*;
/**
 * @author lijun
 * @time 2018年4月19日  下午6:08:46
 * @todo 坦克游戏的1.0
 */
public class MyTankGame1 extends JFrame{

	MyPanel1 mp;
	public static void main(String[] args) {
		new MyTankGame1();
	}
	//构造函数
	public MyTankGame1() {
		mp=new MyPanel1();

		this.add(mp);
		this.setSize(400,300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}
//我的面板
class MyPanel1 extends JPanel{
	//定义一个我的坦克
	Hero hero=null;
	//构造函数
	public MyPanel1() {
		hero=new Hero(100,100);
	}
	//重写paint函数
	public void paint(Graphics g) {
		super.paint(g);
		g.fillRect(0, 0, 400, 300);
		this.drawTank(hero.getX(), hero.getY(), g, 0, 1);

	}
	//画出坦克的函数
	public void drawTank(int x,int y,Graphics g,int direct, int type) {
		//判断是什么类型的坦克
		switch(type){
			case 0:
				g.setColor(Color.yellow);
				break;
			case 1:
				g.setColor(Color.CYAN);
				break;
		}
		//判断方向
		switch(direct) {
		//向上
		case 0:

			//画出我的坦克（到时候再封装成一个函数）
			//1、画出左侧的矩形
			g.fill3DRect(x, y, 5, 30,false);
			//2、 画出右边矩形
			g.fill3DRect(x+15, y, 5, 30,false);
			//3、画出中间矩形
			g.fill3DRect(x+5, y+5, 10, 20,false);
			//4、画出圆形
			g.fillOval(x+4, y+10,10, 10);
			//5、画出线
			g.drawLine(x+10, y, x+10, y+15);
		}

	}
}
//坦克类
class Tank {
	private int x=0;//表示坦克的横坐标
	private int y=0;//坦克的纵坐标
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}

	public Tank(int x,int y) {
		this.x=x;
		this.y=y;

	}


}
//我的坦克
class Hero extends Tank{
	public Hero(int x,int y) {
		super(x,y);
	}

}
```

#### C++的开发工具
- 记事本（Notepad++) +命令行
- Visual C++6.0
- VS 2015
- Code::Blocks
- 其他开发工具：DEV C++、CLion、C-Free、Xcode、C4droid
#### 记事本运行cpp
- g++ -o [文件名] [.cpp文件]
#### atom编辑动态效果
- setting->install->activate-power-mode
#### cpp代码
- #include <iostream>  以#开头的语句为预处理指令
iostream中包含了有关输入输出语句的函数
- using namespace std;    std::cout <<" "<< std::endl;
- endl是控制符，表示重启一行(\n)  <<符号是插入运算符
- endl和\n的区别：\n-纯洁，endl-换行、清除缓存区fflush(stdin)
#### 编码规范
- 每条语句占一行
- 每个函数都有一个开始和结束花括号，花括号各占一行
- 函数中的语句对相对于花括号进行缩紧
- 与函数名称相关的小括号周围没有空白
#### 注释
- 有助于对代码的阅读
- 注视语言应准确、易懂、简介
- 单行注释：以“//”开头
- 多行注释：以”/\*”开头，“\*/”结尾
#### 编译执行过程
- g++ -o HelloWorld.ii -E HelloWorld.cpp  将c++代码预编译，也就是读入#include的文件
- g++ -o HelloWorld.s -S HelloWorld.ii  将预处理文件编译汇编语言
- g++ -o HelloWorld.o -c HelloWorld.s 转为计算机识别的二进制代码
- g++ -o HelloWorld.exe HelloWorld.o 与函数库连接，生成可执行文件

#### python 学习
课程内容<br>
1、爬虫简介<br>
2、简单爬虫架构<br>
3、URL管理器<br>
4、网页下载器（urllib2）<br>
5、网页解析器（BeautifulSoup）<br>
6、完成实例：爬取百度百科Python词条相关的1000个页面数据<br>  
爬虫：一段自动抓取互联网信息的程序<br>
简单的爬虫架构<br>
运行流程：调度器、URL管理器、下载器、解析器、应用<br>
urllib2下载网页方法1：最简洁方法<br>
``` python
import urllib2
#直接请求
response=urllib2.urlopen('http://www.baidu.com')

#获取状态码，如果是200表示获取成功
print response.getcode()

#读取内容
cont=response.read()
```
urllib2下载网页方法2：添加data、http header
``` python
import urllib2
#创建Request对象
request =urllib2.Request(url)
#添加数据
request.add_data('a','1')
#添加http的header
request.add_header('User-Agent','Mozilla/5.0')
#发送请求获取结果
response=urllib2.urlopen(request)
```
urllib2下载网页方法3：添加特殊情景的处理器
``` python
import  urllib2,cookielib
#创建cookie容器
cj=cookielib.CookieJar()
#创建1个opener
opener=urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
#给urllib2安装opener
urllib2.install_opener(opener)
#使用带有cookie的urllib2访问网页
response=urllib2.urlopen("http://www.baidu.com")
```
网页解析器：正则表达式、html.parser 、Beautiful Soup 、lxml<br>
Beautiful Soup :python 第三方库，用于从HTML或XML中提取数据<br>
官网：http://www.crummy.com/software/BeautifulSoup/<br>
pip install beautifulsoup4<br>
创建BeautifulSoup对象<br>
``` python
from bs4 import BeautifulSoup
#根据HTML网页字符串创建BeautifulSoup对象
soup=BeautifulSoup(
	html_doc,   #HTML文档字符串
	'html.parser' #HTML解析器
	from_encoding='utf8' #HTML文档的编码
)
```
搜索节点（find_all,find）<br>
``` python
	#方法：find_all(name,attrs,string)
	#查找所有标签为a的节点
	soup.find_all('a')
	#查找所有标签为a,链接符合/view/123.htm形式的节点
	soup.find_all('a',href='/view/123.htm')
	soup.find_all('a',href=re.compiler(r'/view/\d+\.htm'))
	#查找所有标签为div，class为abc，文字为python的节点
	soup.find_all('div',class_='abc',string='python')
```
访问节点信息<br>
``` python
	#得到节点：<a href="1.html">python</a>
	#获取查找到的节点的标签名称
	node.name
	#获取查找到的a节点的href属性
	node['href']
	#获取查找到的a节点的链接文字
	node.get_text()
```
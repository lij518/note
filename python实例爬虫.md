
#coding:utf8
#### 入口
``` python
'''
Created on 2018年6月24日

@author: Administrator
功能：爬取百度百科1000个网页的数据
'''
from baike_spider import url_manager, html_downloader, html_outputer,\
    html_parser



class SpiderMain(object):
    
    def __init__(self):
        self.urls=url_manager.UrlManger()# url管理器创建对象
        self.downloader=html_downloader.HtmlDownloader()#网页下载器创建对象
        self.parser=html_parser.HtmlParser()#网页解析器创建对象
        self.outputer=html_outputer.HtmlOutputer()#输出html创建对象
    def craw(self, root_url):#定义一个抓取网页的函数
        count=1         #对抓取网页计数
        self.urls.add_new_url(root_url)
        while self.urls.has_new_url():
            try:
                new_url=self.urls.get_new_url() #获取网页
                print 'craw %d :%s'%(count,new_url)#提示信息
                html_cont=self.downloader.download(new_url)#下载网页
                new_urls,new_data=self.parser.parse(new_url,html_cont)#解析网页
                self.urls.add_new_urls(new_urls)#将解析出的网页加入到网页解析器
                self.outputer.collect_data(new_data)#将解析出的数据加入到数据收集器中
                
                if count ==1000:#判断如果循环1000次跳出循环
                    break
                count=count+1
            except:
                print 'craw failed'#异常，打印抓取失败
        self.outputer.output_html()#以html形式将数据输出


if __name__=="__main__":
    root_url="https://baike.baidu.com/item/Python/407313"#爬取的首网址
    obj_spider=SpiderMain()
    obj_spider.craw(root_url)
```

#### url管理器
``` python


#coding:utf8
'''
Created on 2018年6月24日

@author: Administrator
功能：url管理器
'''


class UrlManger(object):
    
    def __init__(self):
        self.new_urls=set()
        self.old_urls=set()
    def add_new_url(self,url):
        if url is None:
            return
        if url not in self.new_urls and url not in self.old_urls:
            self.new_urls.add(url)
    def add_new_urls(self,urls):
        if urls is None or len(urls)==0:
            return 
        for url in urls:
            self.add_new_url(url)
    def get_new_url(self):
        new_url=self.new_urls.pop()
        self.old_urls.add(new_url)
        return new_url
    def has_new_url(self):
        return len(self.new_urls)!=0
 

```
``` python 

#coding:utf8
'''
Created on 2018年6月24日

@author: Administrator
功能:下载器
'''
import urllib2


class HtmlDownloader(object):
    
    
    def download(self,url):
        if url is None:
            return None
        response=urllib2.urlopen(url)
        if response.getcode()!=200:
            return None
        return response.read()




```
``` python

#coding:utf8
'''
Created on 2018年6月24日

@author: Administrator
功能：解析器
'''
from bs4 import BeautifulSoup
import urlparse
import re


class HtmlParser(object):
    
    
    def _get_new_urls(self, page_url, soup):
        new_urls=set()
        links=soup.find_all('a',href=re.compile(r"/item/."))
        for link in links:
            new_url=link['href']
            new_full_url=urlparse.urljoin(page_url,new_url)
            new_urls.add(new_full_url)
        return new_urls
    
    def _get_new_data(self, page_url, soup):
        res_data={}
        res_data['url']=page_url
        #<dd class="lemmaWgt-lemmaTitle-title"><h1>Python</h1>
        title_node=soup.find('dd',class_="lemmaWgt-lemmaTitle-title").find('h1')
        
        res_data['title']=title_node.get_text()
        #<div class="lemma-summary" label-module="lemmaSummary">

        summary_node=soup.find('div',class_="lemma-summary")
        res_data['summary']=summary_node.get_text()
        return res_data
    def parse(self,page_url,html_cont):
        if page_url is None or html_cont is None:
            return
        soup=BeautifulSoup(html_cont,'html.parser',from_encoding='utf-8')
        new_urls=self._get_new_urls(page_url,soup)
        new_data=self._get_new_data(page_url,soup)
        
        return new_urls,new_data
  

```
```  python

#coding:utf8
'''
Created on 2018年6月24日

@author: Administrator
功能：以html形式输出
'''


class HtmlOutputer(object):
    def __init__(self):
        self.datas=[]
    
    def collect_data(self,data):
        if data is None:
            return
        self.datas.append(data)

    
    def output_html(self):
        fout=open('output.html','w')
        fout.write("<html>")
        fout.write('<meta charset="UTF-8">')
        fout.write("<body>")
        fout.write("<table>")
        
        for data in self.datas:
            fout.write("<tr>")
            fout.write("<td>%s</td>"% data['url'])
            fout.write("<td>%s</td>"% data['title'].encode('UTF-8'))
            fout.write("<td>%s</td>"% data['summary'].encode('UTF-8'))
            fout.write("</tr>")
        fout.write("</table>")
        fout.write("</body>")
        fout.write("</html>")
        
        fout.close()


```
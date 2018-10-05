
#coding:utf8
#### ���
``` python
'''
Created on 2018��6��24��

@author: Administrator
���ܣ���ȡ�ٶȰٿ�1000����ҳ������
'''
from baike_spider import url_manager, html_downloader, html_outputer,\
    html_parser



class SpiderMain(object):
    
    def __init__(self):
        self.urls=url_manager.UrlManger()# url��������������
        self.downloader=html_downloader.HtmlDownloader()#��ҳ��������������
        self.parser=html_parser.HtmlParser()#��ҳ��������������
        self.outputer=html_outputer.HtmlOutputer()#���html��������
    def craw(self, root_url):#����һ��ץȡ��ҳ�ĺ���
        count=1         #��ץȡ��ҳ����
        self.urls.add_new_url(root_url)
        while self.urls.has_new_url():
            try:
                new_url=self.urls.get_new_url() #��ȡ��ҳ
                print 'craw %d :%s'%(count,new_url)#��ʾ��Ϣ
                html_cont=self.downloader.download(new_url)#������ҳ
                new_urls,new_data=self.parser.parse(new_url,html_cont)#������ҳ
                self.urls.add_new_urls(new_urls)#������������ҳ���뵽��ҳ������
                self.outputer.collect_data(new_data)#�������������ݼ��뵽�����ռ�����
                
                if count ==1000:#�ж����ѭ��1000������ѭ��
                    break
                count=count+1
            except:
                print 'craw failed'#�쳣����ӡץȡʧ��
        self.outputer.output_html()#��html��ʽ���������


if __name__=="__main__":
    root_url="https://baike.baidu.com/item/Python/407313"#��ȡ������ַ
    obj_spider=SpiderMain()
    obj_spider.craw(root_url)
```

#### url������
``` python


#coding:utf8
'''
Created on 2018��6��24��

@author: Administrator
���ܣ�url������
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
Created on 2018��6��24��

@author: Administrator
����:������
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
Created on 2018��6��24��

@author: Administrator
���ܣ�������
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
Created on 2018��6��24��

@author: Administrator
���ܣ���html��ʽ���
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
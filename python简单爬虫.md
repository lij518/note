#### python ѧϰ
�γ�����<br>
1��������<br>
2��������ܹ�<br>
3��URL������<br>
4����ҳ��������urllib2��<br>
5����ҳ��������BeautifulSoup��<br>
6�����ʵ������ȡ�ٶȰٿ�Python������ص�1000��ҳ������<br>  
���棺һ���Զ�ץȡ��������Ϣ�ĳ���<br>
�򵥵�����ܹ�<br>
�������̣���������URL������������������������Ӧ��<br>
urllib2������ҳ����1�����෽��<br>
``` python
import urllib2
#ֱ������
response=urllib2.urlopen('http://www.baidu.com')

#��ȡ״̬�룬�����200��ʾ��ȡ�ɹ�
print response.getcode()

#��ȡ����
cont=response.read()
```
urllib2������ҳ����2�����data��http header
``` python
import urllib2
#����Request����
request =urllib2.Request(url)
#�������
request.add_data('a','1')
#���http��header
request.add_header('User-Agent','Mozilla/5.0')
#���������ȡ���
response=urllib2.urlopen(request)
```
urllib2������ҳ����3����������龰�Ĵ�����
``` python
import  urllib2,cookielib
#����cookie����
cj=cookielib.CookieJar()
#����1��opener
opener=urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
#��urllib2��װopener
urllib2.install_opener(opener)
#ʹ�ô���cookie��urllib2������ҳ
response=urllib2.urlopen("http://www.baidu.com")
```
��ҳ��������������ʽ��html.parser ��Beautiful Soup ��lxml<br>
Beautiful Soup :python �������⣬���ڴ�HTML��XML����ȡ����<br>
������http://www.crummy.com/software/BeautifulSoup/<br>
pip install beautifulsoup4<br>
����BeautifulSoup����<br>
``` python
from bs4 import BeautifulSoup
#����HTML��ҳ�ַ�������BeautifulSoup����
soup=BeautifulSoup(
	html_doc,   #HTML�ĵ��ַ���
	'html.parser' #HTML������
	from_encoding='utf8' #HTML�ĵ��ı���
)
```
�����ڵ㣨find_all,find��<br>
``` python
	#������find_all(name,attrs,string)
	#�������б�ǩΪa�Ľڵ�
	soup.find_all('a')
	#�������б�ǩΪa,���ӷ���/view/123.htm��ʽ�Ľڵ�
	soup.find_all('a',href='/view/123.htm')
	soup.find_all('a',href=re.compiler(r'/view/\d+\.htm'))
	#�������б�ǩΪdiv��classΪabc������Ϊpython�Ľڵ�
	soup.find_all('div',class_='abc',string='python')
```
���ʽڵ���Ϣ<br>
``` python
	#�õ��ڵ㣺<a href="1.html">python</a>
	#��ȡ���ҵ��Ľڵ�ı�ǩ����
	node.name
	#��ȡ���ҵ���a�ڵ��href����
	node['href']
	#��ȡ���ҵ���a�ڵ����������
	node.get_text()
```
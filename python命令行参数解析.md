#### 命令行参数解析模块argparse
```
import argparse
parser = argparse.ArgumentParser()
parser.description="喂我两个数字，我就吐出他们的积"
parse.add_argument('ParA',help='我是A',type=int)
parse.add_argument('ParB',help='我是B',type=int)
args=parser.parse_args("echo")
print(args.echo)
```
<font color=red>如果不想输入某些参数怎么办？<br>
直接在他们的名字前面添加--就好了</font><br>
```
parseradd_argument("--PartA",help="我是A",type=int)
parseradd_argument("--PartB",help="我是B",type=int)
```
<font color=red>每次需要输入--PartA麻烦，因此进行改进
```
parse.add_argument('-a','--ParA',help="我是A",type=int)
```

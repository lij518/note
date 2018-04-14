#### ActiveRecord
概述：ActiveRecord是JFinal最核心的组成部分之一，通过ActiveRecord来操作数据库,
将极大地减少代码量
,极大地提升开发效率.<br>
ActiveRecord是作为JFinal的Plugin而存在的，所以使用时需要在
JFinalConfig中配置ActiveRecordPlugin。<br>
以下是Plugin配置示例代码：<br>
``` JAVA
public class DemoConfig extends JFinalConfig{
    public void configPlugin(Plugins me){
        C3poPlugin cp=new C3p0Plugin("jdbc:mysql://localhost/db_name",
        "userName","password");
        me.add(cp);
        ActiveRecordPlugin arp=new ActiveRecordPlugin(cp);
        me.add(arp);
        arp.addMapping("user",User.class);
        arp.addMapping("article","article_id",Article.class);
    }
}

```
以上代码配了两个插件：C3p0Plugin与ActiveRecordPlugin,前者是c3p0数据源插件，后者是<br>
ActiveRecord支持插件。<br>
ActiveRecord定义了addMapping(String tableName,Class
<?extends Model>modelClass)方法，该方法建立了数据库表名到Model的映射关系。<br>
另外，以上代码中arp.addMappring("user",User.class),表的主键名为默认为“id”,如果
主键名称为“user_id”则需要手动指定，如arp:addMapping("user","user_id",User.class).
<br>
#### Model
Model是ActiveRecord中最重要的组件之一，它充当MVC模式中的Model部分。
<br>
以下是Model定义示例代码：
``` JAVA
public class User extends Model<User>{

    public static final User dao=new User();

}
```
以上代码中的User通过继承Model,便立即拥有的众多方便的操作数据库的方法。
在User中声明的dao静态对象是为了方便查询操作而定义的，该对象并不是必须的。
<br>
基于ActiveRecord的Model无需定义属性，无需定义getter.setter方法，无需XML配置，
<br>
无需Annotation配置，极大降低了代码量。<br>
以下为Model的一些常见用法：
``` java
  //常见name属性为James,age属性为25的User对象并添加到数据库
  new User().set("name","James").set("age",25).save();

  //删除id值为25的User User.dao.deleteById(25);

  //查询id值为25的User将其name属性改为James并更新到数据库
  User.dao.findByIdLoadColums(25).set("name","James").update();

  //查询id值为25的user,且仅仅取name与age两个字段的值
  User user=User.dao.findByIdLoadColums(25,"name,age");

  //获取user的name属性
  String userName=user.getStr("name");

  //获取user的age属性
  Integer userAge=user.getInt("age");

  //查询所有年龄大于18岁的user
  List<User> users=User.dao.find("select * from user where age>18");

  //分页查询年龄大于18的user,当前页号为1，每页10个user
  Page<User>  userPage=User.dao.paginate(1,10,"select *","from user where age >?",18);
```
特别注意：User中定义的public static final User dao 对象是全局共享的，只能用于数据库查询，
不能用于<br>
数据承载对象。数据承载需要使用new User().set(...)来实现。

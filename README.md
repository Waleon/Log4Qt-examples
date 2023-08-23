# 系列介绍

日志是一个优秀系统不可或缺的组成部分，利用它我们可以记录系统中所产生的所有行为。

对于很多人来说，日志的作用仅限于调试。其实不然，它在很多方面都非常有用：

- 日志是最好的的诊断工具
- 日志让我们有机会检测模块的瓶颈
- 日志有助于我们了解用户行为
- ……

在编写代码时，使用日志框架是一种很好的实践。即使像《代码整洁之道》这样的书籍，也建议学习像 Log4j 这样的框架进行日志记录。

本系列将主要围绕 Log4Qt，探索 C++ 中的 Log4j 技术。通过分享的知识，读者可以快速了解 Log4j 内部工作机制，并能熟练使用其各个衍生品 - Log4cpp、log4cplus、log4cxx、Log4Qt。

# 系列内容

以下是本系列的具体内容，以及示例源码：

课程地址 | 示例源码
:--- | :--- 
[1. 一文详解 C++ 日志框架](https://waleon.blog.csdn.net/article/details/109153251)  | ---
[2. Log4Qt 基本介绍](https://waleon.blog.csdn.net/article/details/78775354)  | ---
[3. 获取 Log4Qt 中的 Logger](https://waleon.blog.csdn.net/article/details/78779000)  | RequestLogger
[4. 深入理解 rootLogger、logLogger、qtLogger](https://waleon.blog.csdn.net/article/details/115436024)  | UnderstandLogger
[5. 使用环境变量配置 Log4Qt](https://waleon.blog.csdn.net/article/details/116810951) | EnvVarInit
[6. 使用 QSettings 配置 Log4Qt](https://waleon.blog.csdn.net/article/details/117393591)  | QSettingsInit
[7. 使用 log4qt.properties 配置 Log4Qt](https://waleon.blog.csdn.net/article/details/117936586)  | PropertiesInit
[8. Log4Qt 初始化过程](https://waleon.blog.csdn.net/article/details/119363354)  | ---
[9. Log4Qt 日志级别](https://waleon.blog.csdn.net/article/details/78845511)  | LogLevel
[10. Log4Qt 日志格式化（PatternLayout）](https://waleon.blog.csdn.net/article/details/119769780)  | PatternLayout
[11. Log4Qt 日志格式化（SimpleLayout）](https://waleon.blog.csdn.net/article/details/120124604)  | SimpleLayout
[12. Log4Qt 日志格式化（TTCCLayout）](https://waleon.blog.csdn.net/article/details/120340711)  | TTCCLayout
[13. Log4Qt 输出重定向（控制台）](https://waleon.blog.csdn.net/article/details/120715083)  | ConsoleAppender
[14. Log4Qt 输出重定向（滚动多个文件）](https://gitbook.cn/gitchat/column/5b2c5b29072e851cae4299f3/topic/5b2c6489072e851cae42a33e)  | RollingFileAppender
[15. Log4Qt 输出重定向（以指定的频率滚动文件）](https://gitbook.cn/gitchat/column/5b2c5b29072e851cae4299f3/topic/5b2c649f072e851cae42a34f) | DailyRollingFileAppender
[16. Log4Qt 输出重定向（数据库）](https://gitbook.cn/gitchat/column/5b2c5b29072e851cae4299f3/topic/5b2c64bb072e851cae42a360)  | DatabaseAppender
[17. 使用自己的 Logger](https://gitbook.cn/gitchat/column/5b2c5b29072e851cae4299f3/topic/5b67f32847a22a6d0f656aa8)  | MyLogger

# 适宜人群

- 希望快速掌握日志框架的初学者
- 想要熟练使用 Log4Qt 的开发者
- 对 Log4j（及其衍生品）感兴趣的工程师

# 系列地址

各位小伙伴们，欢迎猛戳：

- 系列地址：[Log4j for C++ 实用指南](http://gitbook.cn/gitchat/column/5b2c5b29072e851cae4299f3 "Log4j for C++ 实用指南")

# 关于作者

作者：[一去、二三里](https://waleon.blog.csdn.net/)，爱编程、爱学习、爱生活！

- [个人博客](https://waleon.blog.csdn.net/)
- 个人微信：iwaleon（加我微信，邀请入 500 人微信群）
- 个人 QQ：550755606
- QQ 技术交流群：242790253

更多干货，请扫码关注我的微信公众号，不要太惊喜哦~

![微信公众号](https://raw.githubusercontent.com/Waleon/DesignPatterns/master/assets/qrcode.jpg)

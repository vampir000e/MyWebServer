## MyWebServer

---

Linux下基于C++的轻量级Web服务器

> * 使用线程池 + 非阻塞socket + epoll(ET和LT) + 事件处理(Reactor和Proactor) 的并发模型
> * 使用状态机解析HTTP请求报文，支持解析GET和POSt请求
> * 访问服务器数据库实现web端用户注册、登录功能，可以请求播放服务器图片和视频文件
> * 实现同步/异步日志系统，记录服务器运行状态
> * 经Webbench压力测试可以实现上万的并发连接数据交换




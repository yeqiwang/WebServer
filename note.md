study the webserver!

# lesion 2

## 编程语言发展
高级语言 -编译-> 汇编语言 -汇编-> 机器语言 -运行-> 可执行程序

## GCC工作流程
1. 源代码 进行预处理 展开头文件、注释、宏替换 .i结尾
2. 预处理后源代码 编译器
3. 汇编代码 汇编器
4. 机器代码 链接器
5. 可执行文件


## GCC G++
1. GCC和G++都是GNU的一个编译器
2. GCC和G++可以编译c代码和c++代码

## GCC常用选项
- g++ test.cpp -E -o test.i 预处理
- g++ test.i -S -o test.s 编译
- g++ test.s -s -o test.o 汇编链接
- g++ -c xxx.cpp xxx.cpp 只汇编不连接

- g++ test.cpp -o test -DDEBUG
```c++
int main() {
#ifdef DEBUG
    cout << "test" << endl;
#endif
}
```

# lession 3

## 库
- 静态库：在链接阶段复制到了程序中
    - 命名规则 
        - linux: libxxx.a
        - windows: libxxx.lib
    - 制作过程
        1. gcc 获得.o文件
            gcc -c a.o b.o
        2. 生成静态库
            ar rcs libxxx.a xxx.o xxx.o
            r 将文件插入备存文件中
            c 创建备存文件
            s 索引


- 动态库：运行时由系统加载到内容中供程序调用
  - 命名规则
    - linux: libxxx.so
    - windows: libxxx.dll
  - 制作过程
    1.  gcc 获得.o文件，得到与位置无关的代码
        gcc -c -fpic a.o b.o
    2. 生成动态库
        gcc -shared a.o b.o -o libcalc.so

- 库的优点
    1. 代码保密
    2. 方便部署和分发

## 项目目录内容
- main.cpp 入口文件
- include 头文件目录
- lib 库文件目录
- src 源文件

## 静态库示例(lession03代码)
1. 使用src中的源文件，制作静态库
g++ -c add.cpp minis.cpp -I ../include/
ar rcs libcalc.a minis.o add.o

2. 将创建的静态库移动到lib中
mv libcalc.a ../lib/

3. 使用静态库编译main.cpp
g++ main.cpp -o mian -I include/ -L lib/ -l calc

ps. g++中，-I 指定头文件位置，-L 指定库文件位置，-l 指定库文件

## 动态库示例(lession04代码)

1. 使用src中的源文件，制作动态库
g++ -c -fpic add.cpp minis.cpp -I ../include/
g++ -shared *.o -o libcalc.so

1. 将创建的动态库移动到lib中
mv libcalc.a ../lib/

3. 使用动态库编译main.cpp
g++ main.cpp -o mian -I include/ -L lib/ -l calc

4. 添加动态库路径
    - 临时配置
        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/root/workspace/WebServr/lession04/lib 
    - 永久配置 用户级
        在.bashrc中加入上述指令
        source .bashrc
    - 永久配置 系统级
        在/etc/profile中加入上述指令
        source /etc/profile
    - 永久配置 系统级
        在/etc/ld.so.conf中加入路径
        ldconfig

- dll 查询依赖关系

## 静态库与动态库的对比
静态库和动态库的区别在于链接阶段如何处理、链接成可执行程序

分别成为**静态链接方式**和**动态链接方式**

静态库
- 优点
  - 加载速度快
  - 发布程序无需提供静态库、移植方便
- 缺点
  - 消耗系统资源、浪费内存
  - 更新、部署、发布麻烦

动态库
- 优点
  - 可以实现进程间资源共享
  - 更新、部署、发布简单
  - 可以控制何时加载动态库
- 缺点
  - 加载速度慢
  - 发布时需要提供依赖的动态库

# lession 4 

## Makefile
定义一系列的规则来指导项目的编译过程

## 虚拟内存空间
- 用户区 0-3G
  - .text 代码段
  - .data 已初始化的全局变量
  - .bss 未初始化的全局变量
  - 堆空间 低地址 -> 高地址
  - 共享库
  - 栈空间 高地址 -> 低地址
- 内核区 3-4G

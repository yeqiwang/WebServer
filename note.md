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
g++ test.cpp -E -o test.i 预处理
g++ test.i -S -o test.s 编译
g++ test.s -s -o test.o 汇编链接
g++ -c xxx.cpp xxx.cpp 只汇编不连接

g++ test.cpp -o test -DDEBUG
```c++
int main() {
#ifdef DEBUG
    cout << "test" << endl;
#endif
}
```

## 库
- 静态库：在链接阶段复制到了程序中
    - 命名规则 
        - linux: libxxx.a
        - windows: libxxx.lib
    - 制作
        1. gcc 获得.o文件
        2. ar rcs libxxx.a xxx.o xxx.o
            r 将文件插入备存文件中
            c 创建备存文件
            s 索引


- 动态库：运行时由系统加载到内容中供程序调用
- 库的优点
    1. 代码保密
    2. 方便部署和分发


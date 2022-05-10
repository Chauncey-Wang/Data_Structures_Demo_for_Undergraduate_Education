#include "stdio.h"

// /*
// struct tag { 
//     member-list
//     member-list 
//     member-list  
//     ...
// } variable-list ;

// tag 是结构体标签。
// member-list 是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。
// variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。
// */

// //方法1
// struct{
//     char a;
//     short b;
//     int c;
//     } var1;
// struct {
//     char a;
//     short b;
//     int c;
//     } var2;
// /*
// 上述方法定义了两个结构体变量var1、与var2，两个变量的构造方式相同。
// 但是，这种定义方式有着很大的不变，因为反复重写相同的东西。对此做一下修改，于是有定义方法2。
// */

// //方法2：
// struct {
// char a;
// short b;
// int c;
// } var1,var2;
// /*
// 这种方式少写了一次结构体，同时还能够实现两个变量的定义。不过，
// 如果定义的结构体变量过多的时候代码就会有可读性以及维护性上的问题。
// 对此改进有两种可选方式，也就是方法3-结构体tag以及方法4-结构体数据类型。
// */

// //方法3：
// struct demo_tag {
// char a;
// short b;
// int c;
// } var1;

// struct demo_tag var2;
// /*
// 上述代码同样实现了两个结构体变量的定义，但是第二种方式采用了结构体的tag用以代替了结构体的描述。
// 这种定义方式每次需要些struct关键字，因为tag只是代表了结构体的描述信息。不过，如果出现大量的变量定义需要时，
// 这种方式显然要比第二种方式好得多。
// */

//方法4：
typedef struct demo_tag {
    char a;
    short b;
    int c;
} demo_t, demo_test;

demo_test var1,var2;
/*代码中的结构体tag其实是没有用了的，可以去掉。只需要构造一个结构体数据类型，
接下来的结构体对象构建起来就简单很多了。而且，当出现大量的结构体数据时，
代码需要维护的时候工作量也会小很多。
不仅仅在于代码的字符会看着少一些，同时这种方式也比较适合最基本的C语言定义规则。
当然，这得建立在你对这种技术有一定的熟知的基础上。
*/

int main(){
    var1.a='a';
    var1.c=1;
    printf( "subject : %c\n", var1.a);
    printf( "%d\n", var1.c);
    
    return 0;
}



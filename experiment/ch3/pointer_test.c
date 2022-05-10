#include <stdio.h>
 
int main ()
{
   int  var = 20;   /* 实际变量的声明 */
   int  *ip;        /* 指针变量的声明 */
 
   ip = &var;  /* 在指针变量中存储 var 的地址 */

//    int *ip = &var;
 
   printf("var address: %p\n", &var  );
 
   /* 在指针变量中存储的地址 */
   printf("ip address: %p\n", ip );
 
   /* 使用指针访问值 */
   printf("*ip value: %d\n", *ip );
 
   return 0;
}
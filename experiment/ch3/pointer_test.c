#include <stdio.h>
 
int main ()
{
   int  var = 20;   /* ʵ�ʱ��������� */
   int  *ip;        /* ָ����������� */
 
   ip = &var;  /* ��ָ������д洢 var �ĵ�ַ */

//    int *ip = &var;
 
   printf("var address: %p\n", &var  );
 
   /* ��ָ������д洢�ĵ�ַ */
   printf("ip address: %p\n", ip );
 
   /* ʹ��ָ�����ֵ */
   printf("*ip value: %d\n", *ip );
 
   return 0;
}
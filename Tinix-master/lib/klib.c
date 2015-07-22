
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            klib.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"


/*======================================================================*
                               is_alphanumeric
 *======================================================================*/
PUBLIC t_bool is_alphanumeric(char ch)
{
	return ((ch >= ' ') && (ch <= '~'));
}


/*======================================================================*
                               itoa
 *======================================================================*/
PUBLIC char * itoa(char * str, int num)/* ����ǰ��� 0 ������ʾ����, ���� 0000B800 ����ʾ�� B800 */
{
	char *	p = str;
	char	ch;
	int	i;
	t_bool	flag = FALSE;

	*p++ = '0';
	*p++ = 'x';

	if(num == 0){
		*p++ = '0';
	}
	else{	
		for(i=28;i>=0;i-=4){
			ch = (num >> i) & 0xF;
			if(flag || (ch > 0)){
				flag = TRUE;
				ch += '0';
				if(ch > '9'){
					ch += 7;
				}
				*p++ = ch;
			}
		}
	}

	*p = 0;

	return str;
}

PRIVATE int power(int base, int index)
{
	int result = 1, i;
	if (index < 0) return -1;
	for ( i = 0 ; i < index ; ++i )
	{
		result *= base;
	}
	return result;
}

PUBLIC char * itoa_dec(char * str, int num)
{
	char *	p = str;
	char	ch;
	int	i;
	t_bool	flag = FALSE;

	if(num == 0){
		*p++ = '0';
	}
	else{
		if (num < 0)
		{
			*p++ = '-';
			num = -num;
		}
		for(i=10;i>=0;i--){
			int pow = power(10, i);
			ch = num / pow % 10;
			if(flag || (ch > 0)){
				flag = TRUE;
				ch += '0';
				*p++ = ch;
			}
		}
	}

	*p = 0;

	return str;
}
/*******************************************/

/*======================================================================*
                               disp_int
 *======================================================================*/
PUBLIC void disp_int(int input)
{
	char output[16];
	itoa(output, input);
	disp_str(output);
}

/*======================================================================*
                               delay
 *======================================================================*/
PUBLIC void delay(int time)
{
	int i, j, k;
	for(k=0;k<time;k++){
		/*for(i=0;i<10000;i++){	for Virtual PC	*/
		for(i=0;i<10;i++){/*	for Bochs	*/
			for(j=0;j<10000;j++){}
		}
	}
}
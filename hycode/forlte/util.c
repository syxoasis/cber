/****************************************************************************** 

��Ȩ���У�C����2001-2015�꣬����Ƽ��ɷ����޹�˾

******************************************************************************
�ļ���:       util.c
�����ʽ:     ASCII
����:         chenbin
����:         Nov 24, 2015
��ʷ:
    1.����    :Nov 24, 2015
      ����    :cb
      �޸�    :Created file
******************************************************************************/
#ifndef UTIL_C_
#define UTIL_C_
#include "util.h"

uint8_t asc_to_hex(uint8_t ch)
{
    if( ch >= '0' && ch <= '9')
        ch -= '0';
    else if( ch >= 'A' && ch <= 'Z' )//��д��ĸ
        ch -= 0x37;
    else if( ch >= 'a' && ch <= 'z' )//Сд��ĸ
        ch -= 0x57;
    else ch = 0xff;
    return ch;
}
cb_code_t str_to_proto(const uint8_t *src, int slen, uint8_t *dst)
{
    uint8_t stmp[128] ={0};
    uint8_t low  = 0;
    uint8_t high = 0;
    int  i       = 0;

    int supply = 0;
    if( NULL == dst || NULL == src || slen > 126)
    {
        return CB_NULL_POINT;
    }
    memcpy(stmp, src, slen);
    if( slen % 2 )
    {
        stmp[slen] = 'f';
    }
    supply = strlen((char *)stmp);
    supply = supply >> 1;
    for( i = 0; i < supply ; i++ )
    {
        low = asc_to_hex(stmp[2*i]);
        high = asc_to_hex(stmp[2*i+1]);
        *(dst+i) = (high << 4) + low;
    }
    return CB_OK;
}

/* ���ڴ�С��ת�� */
cb_code_t exchange(uint8_t * buf, int n)
{
    int i = 0 ;
    uint8_t tmp[16] = {0};
    if( n < 1 || n > 16)
    {
        return CB_FUN_PARAM_ERR;
    }
    memcpy(tmp, buf, n);
    for(i = 0 ; i < n ; i++)
    {
        buf[i] = tmp[n-i-1];
    }
    return CB_OK;
}

cb_code_t parse_head(uint8_t src[],pkt_head_t *head)
{
    uint16_t tmp = src[0] & 0x3f;
//    tmp = tmp << 6;
//    head->fin = src[1] & 0x01;
//    head->fir = (src[1] & 0x02) >> 1;
//    head->len = (src[1] >> 2) + tmp;
    head->fin = src[0] >> 7;
    head->fir = (src[0] >> 6) & 0x01;
    head->len = (tmp<<8) + src[1];
    return CB_OK;
}
#endif /* UTIL_C_ */
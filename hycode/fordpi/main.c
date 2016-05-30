#include    <stdio.h>
#include    <stdlib.h>
#include    <time.h>
#include    <string.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <stdarg.h>
#include    <signal.h>
#include    <sys/wait.h>
#include    <pthread.h>
#include    <fcntl.h>
#include    <errno.h>
#include    <dirent.h>
#include    <ctype.h>

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>

#include "semp_comm_dpi.h"
#include "dpi.h"

#define IP_SET(d1, d2, d3, d4) ((d1)*246*256*256 + (d2)*256*256 + (d3)*256 + (d4))

//------------------------------------------------------------
//-----------       Created with 010 Editor        -----------
//------         www.sweetscape.com/010editor/          ------
//
// File    : Y:\cbpck\gtpu-510byte.pcap
// Address : 54 (0x36)
// Size    : 496 (0x1F0)
//------------------------------------------------------------
unsigned char gtpu_pkt[496] = {
    0x45, 0x00, 0x01, 0xF0, 0xDC, 0xCE, 0x00, 0x00, 0xFE, 0x11, 0x53, 0x71, 0x64, 0x40, 0x40, 0x65,
    0xC8, 0x01, 0x1E, 0x16, 0x08, 0x68, 0x08, 0x68, 0x01, 0xDC, 0x3D, 0x09, 0x32, 0xFF, 0x01, 0xCC,
    0x06, 0x16, 0x93, 0xDE, 0x09, 0xB2, 0x00, 0x00, 0x45, 0x00, 0x01, 0xC8, 0x4C, 0x98, 0x40, 0x00,
    0x40, 0x06, 0x39, 0x81, 0x0A, 0x15, 0x47, 0xD2, 0x78, 0xC6, 0xE8, 0x69, 0x05, 0x5D, 0x00, 0x50,
    0x86, 0xBA, 0x71, 0x7B, 0xBE, 0x82, 0x5C, 0xA6, 0x50, 0x18, 0x7F, 0xA2, 0xE0, 0x83, 0x00, 0x00,
    0x47, 0x45, 0x54, 0x20, 0x2F, 0x70, 0x6F, 0x72, 0x74, 0x61, 0x6C, 0x2F, 0x30, 0x30, 0x38, 0x2F,
    0x41, 0x2F, 0x63, 0x6D, 0x31, 0x39, 0x32, 0x38, 0x2E, 0x6A, 0x73, 0x20, 0x48, 0x54, 0x54, 0x50,
    0x2F, 0x31, 0x2E, 0x31, 0x0D, 0x0A, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x3A, 0x20, 0x2A, 0x2F,
    0x2A, 0x0D, 0x0A, 0x52, 0x65, 0x66, 0x65, 0x72, 0x65, 0x72, 0x3A, 0x20, 0x68, 0x74, 0x74, 0x70,
    0x3A, 0x2F, 0x2F, 0x70, 0x69, 0x61, 0x6E, 0x6B, 0x75, 0x2E, 0x78, 0x6D, 0x70, 0x2E, 0x6B, 0x61,
    0x6E, 0x6B, 0x61, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x78, 0x6D, 0x70, 0x5F, 0x6E, 0x65, 0x77,
    0x73, 0x2F, 0x3F, 0x64, 0x74, 0x68, 0x3D, 0x32, 0x30, 0x31, 0x33, 0x31, 0x31, 0x32, 0x31, 0x31,
    0x35, 0x0D, 0x0A, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2D, 0x4C, 0x61, 0x6E, 0x67, 0x75, 0x61,
    0x67, 0x65, 0x3A, 0x20, 0x7A, 0x68, 0x2D, 0x63, 0x6E, 0x0D, 0x0A, 0x41, 0x63, 0x63, 0x65, 0x70,
    0x74, 0x2D, 0x45, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x3A, 0x20, 0x67, 0x7A, 0x69, 0x70,
    0x2C, 0x20, 0x64, 0x65, 0x66, 0x6C, 0x61, 0x74, 0x65, 0x0D, 0x0A, 0x49, 0x66, 0x2D, 0x4D, 0x6F,
    0x64, 0x69, 0x66, 0x69, 0x65, 0x64, 0x2D, 0x53, 0x69, 0x6E, 0x63, 0x65, 0x3A, 0x20, 0x54, 0x68,
    0x75, 0x2C, 0x20, 0x32, 0x31, 0x20, 0x4E, 0x6F, 0x76, 0x20, 0x32, 0x30, 0x31, 0x33, 0x20, 0x30,
    0x30, 0x3A, 0x35, 0x37, 0x3A, 0x34, 0x37, 0x20, 0x47, 0x4D, 0x54, 0x0D, 0x0A, 0x55, 0x73, 0x65,
    0x72, 0x2D, 0x41, 0x67, 0x65, 0x6E, 0x74, 0x3A, 0x20, 0x4D, 0x6F, 0x7A, 0x69, 0x6C, 0x6C, 0x61,
    0x2F, 0x34, 0x2E, 0x30, 0x20, 0x28, 0x63, 0x6F, 0x6D, 0x70, 0x61, 0x74, 0x69, 0x62, 0x6C, 0x65,
    0x3B, 0x20, 0x4D, 0x53, 0x49, 0x45, 0x20, 0x37, 0x2E, 0x30, 0x3B, 0x20, 0x57, 0x69, 0x6E, 0x64,
    0x6F, 0x77, 0x73, 0x20, 0x4E, 0x54, 0x20, 0x35, 0x2E, 0x31, 0x3B, 0x20, 0x54, 0x72, 0x69, 0x64,
    0x65, 0x6E, 0x74, 0x2F, 0x34, 0x2E, 0x30, 0x3B, 0x20, 0x53, 0x56, 0x31, 0x3B, 0x20, 0x2E, 0x4E,
    0x45, 0x54, 0x20, 0x43, 0x4C, 0x52, 0x20, 0x32, 0x2E, 0x30, 0x2E, 0x35, 0x30, 0x37, 0x32, 0x37,
    0x3B, 0x20, 0x2E, 0x4E, 0x45, 0x54, 0x20, 0x43, 0x4C, 0x52, 0x20, 0x33, 0x2E, 0x30, 0x2E, 0x34,
    0x35, 0x30, 0x36, 0x2E, 0x32, 0x31, 0x35, 0x32, 0x3B, 0x20, 0x2E, 0x4E, 0x45, 0x54, 0x20, 0x43,
    0x4C, 0x52, 0x20, 0x33, 0x2E, 0x35, 0x2E, 0x33, 0x30, 0x37, 0x32, 0x39, 0x29, 0x0D, 0x0A, 0x48,
    0x6F, 0x73, 0x74, 0x3A, 0x20, 0x62, 0x69, 0x7A, 0x35, 0x2E, 0x73, 0x61, 0x6E, 0x64, 0x61, 0x69,
    0x2E, 0x6E, 0x65, 0x74, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E,
    0x3A, 0x20, 0x4B, 0x65, 0x65, 0x70, 0x2D, 0x41, 0x6C, 0x69, 0x76, 0x65, 0x0D, 0x0A, 0x0D, 0x0A
};




void test()
{
    five_tuple_t ft = {};
    ft.dip.ip.v4 = IP_SET(10,21,71,210);
    ft.sip.ip.v4 = IP_SET(120,198,232,105);
    ft.dst_port = 1373;
    ft.dst_port = 80;
    ft.protocol = 6;

    dpi_skb_t skb = {};
    skb.care_pkt = PKT_CARE;
    skb.network_header = gtpu_pkt;
    skb.network_header_len = 510;

    dataplane_dpi_processs(&skb, &ft);
}

int main(int argc,char * argv[])
{
    dataplane_dpi_init();
    printf(">>>>>>>>>>>>>test start :\n");
    test();

    return 0;
} 



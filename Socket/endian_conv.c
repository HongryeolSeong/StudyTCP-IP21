// 가상머신 터미널에서 실행할 것
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	unsigned short host_port = 0x1234;
	unsigned short net_port;
	unsigned long host_addr = 0x12345678;
	unsigned long net_addr;

	net_port = htons(host_port);
	net_addr = htonl(host_addr);

	printf("Host ordered port: %#x \n", host_port);
	printf("Network ardered port: %#x \n", net_port);
	printf("Host ordered address: %#1x \n", host_addr);
	printf("Network ordered address: %#1x \n", net_addr);
	return 0;
}
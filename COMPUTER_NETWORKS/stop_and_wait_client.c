#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "crc.h"

int main() 
{
	int socket_file_descriptor, returnvalue, length = 100, n, i;
	unsigned short sequnce_no = 1, crc, shift_crc;
	unsigned int address_length;
	unsigned short server_port = 25000;
	char server_ip[] = "127.0.0.1";
	char *text[3] = { "abcde", "fghij", "klmno" };
	unsigned char text_message[100];
	char rtext[100];
	int text_length;
	struct sockaddr_in server_address;
	address_length = sizeof(server_address);
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(server_port);
	inet_aton(server_ip, &server_address.sin_addr);
	socket_file_descriptor = socket(PF_INET, SOCK_DGRAM, 0);

	for (i = 1; i < 4; i++) 
	{
		memcpy(text_message, &sequnce_no, sizeof(sequnce_no));
		memcpy(&text_message[2], text[i - 1], 5);
		crc = crc_16(text_message, sizeof(unsigned short) + strlen(text[i - 1]));
		shift_crc = crc;
		shift_crc = (shift_crc << 8) ^ (0x0000);
		crc = (crc >> 8) ^ (0x0000);
		crc = (shift_crc) ^ (crc);
		memcpy(&text_message[7], &crc, sizeof(unsigned short));
		text_message[9] = '\0';
		text_length = sizeof(sequnce_no) + strlen(text[i - 1]) + sizeof(crc);
		returnvalue = sendto(socket_file_descriptor, text_message, text_length, 0, (struct sockaddr *) &server_address, sizeof(server_address));
		
		if (returnvalue != -1)
			printf("\n\t message %d sent successfully.....\n", i);
		else
			printf("\n\t message %d sent failure.....\n", i);
			
		n = recvfrom(socket_file_descriptor, rtext, length, 0, (struct sockaddr *) &server_address, &address_length);
		if (n != -1) 
		{
			rtext[n] = '\0';
			if (memcmp(&rtext[2], "ACK", 3) == 0) 
			{
				printf("\n\t ACK.....\n");
				sequnce_no++;
				sleep(3);
			} 
			else 
			{
				i = sequnce_no;
				printf("  NAK  ");
				sleep(3);
			}
		}
	}
	close(socket_file_descriptor);
	return 0;
}

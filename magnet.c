#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<linux/i2c-dev.h>

int main(){
	int file;
	int addr = 0x1E; //0b001 1110 i2c address for magnet
	char filename[20];
	uint8_t buf[3];

//open device
	snprintf(filename, 19, "/dev/i2c-%d", 0);
	if ((file = open(filename, O_RDWR)) < 0) //check i2c exists
		exit(1);
//specify device address
	if (ioctl(file, I2C_SLAVE, addr) < 0) //change slave address to addr
		exit(2);

}

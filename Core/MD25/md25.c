/*
 * MD25.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Jakub
 */
#include "md25.h"

uint8_t get_speed1(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_SPEED1);
	return a;
}
uint8_t get_speed2(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_SPEED2);
	return a;
}
void get_speed_Both(uint8_t* speed){
	speed[0] =UART_ReceiveByte(MD25_GET_SPEED1);
	speed[1] =UART_ReceiveByte(MD25_GET_SPEED2);
	return;
}
uint8_t get_Battery(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_VOLTS);
	return a;
}
uint8_t get_current1(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_CURRENT1);
	return a;
}
uint8_t get_current2(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_CURRENT2);
	return a;
}
uint8_t get_version(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_VERSION);
	return a;
}
uint8_t get_mode(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_MODE);
	return a;
}
uint8_t get_accel(void){
	uint8_t a=UART_ReceiveByte(MD25_GET_ACCELERATION);
	return a;
}


void get_encoder1(int32_t encoder){
	uint8_t encoder_data[4];
	UART_ReceiveMultypleByte(MD25_GET_ENCODER1,encoder_data);
	encoder=(int32_t) encoder_data[0]<<24;
	encoder=encoder + (int32_t)encoder_data[1]<<16;
	encoder=encoder + (int32_t)encoder_data[2]<<8;
	encoder=encoder + (int32_t)encoder_data[3];
	return;
}

void get_encoder2(int32_t encoder){
	uint8_t encoder_data[4];
	UART_ReceiveMultypleByte(MD25_GET_ENCODER2,encoder_data);
	encoder=(int32_t) encoder_data[0]<<24;
	encoder=encoder + (int32_t)encoder_data[1]<<16;
	encoder=encoder + (int32_t)encoder_data[2]<<8;
	encoder=encoder + (int32_t)encoder_data[3];
	return;
}

void get_encoders(int32_t encoder1,int32_t encoder2 ){
	uint8_t encoder_data[8];
	UART_ReceiveMultypleByte(MD25_GET_ENCODERS,encoder_data);
	encoder1=(int32_t) encoder_data[0]<<24;
	encoder1=encoder1 + (int32_t)encoder_data[1]<<16;
	encoder1=encoder1 + (int32_t)encoder_data[2]<<8;
	encoder1=encoder1 + (int32_t)encoder_data[3];
	encoder2=(int32_t) encoder_data[4]<<24;
	encoder2=encoder2 + (int32_t)encoder_data[5]<<16;
	encoder2=encoder2 + (int32_t)encoder_data[6]<<8;
	encoder2=encoder2 + (int32_t)encoder_data[7];
	return;
}

void get_electric_data(uint8_t battery, uint8_t current1, uint8_t current2){
	uint8_t data[3];
	UART_ReceiveMultypleByte(MD25_GET_VOLTS_CURRENT,data);
	battery=data[0];
	current1=data[1];
	current2=data[2];
	return;
}


void set_speed_1(uint8_t speed){
	UART_SendByte(MD25_SET_SPEED1,speed);
}

void set_speed_2(uint8_t speed){
	UART_SendByte(MD25_SET_SPEED2,speed);
}

void set_speed_Both(uint8_t speed1, uint8_t speed2){
	UART_SendByte(MD25_SET_SPEED1,speed1);
	UART_SendByte(MD25_SET_SPEED2,speed2);
}
void set_accel(uint8_t accel){
	UART_SendByte(MD25_SET_ACCEL,accel);
}
uint8_t set_mode(uint8_t MODE){
	if(MODE>4||MODE<0){
		return 1;
	}
	UART_SendByte(MD25_SET_MODE,MODE);
	return 0;
}
void reset_encoders(void){
	UART_SendControlByte(MD25_RESET_ENCODERS);
}

void disable_reg(void){
	UART_SendControlByte(MD25_DISABLE_REGULATOR);
}

void enable_reg(void){
	UART_SendControlByte(MD25_ENABLE_REGULATORS);
}
void disable_timeout(void){
	UART_SendControlByte(MD25_DISABLE_TIMEOUT);
}

void enable_timeout(void){
	UART_SendControlByte(MD25_ENABLE_TIMEOUT);
}

uint8_t MD25_init(){
	uint8_t version=get_version();
	if(version!=3){
		return 1;
	}
	uint8_t battery=get_Battery();
	if(battery<90){
		return 1;
	}
	reset_encoders();
	enable_timeout();
	disable_reg();
	set_mode(1);
	set_accel(5);
	set_speed_Both(0,0);
	return 0;
}

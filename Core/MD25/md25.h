/*
 * MD25.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Jakub
 */

#include "main.h"
#include "usart.h"

#ifndef MD25_MD25_H_
#define MD25_MD25_H_
#endif /* MD25_MD25_H_ */

#define 	MD25_DEVICE_ADDRESS		0xB0U
#define 	MD25_GET_SPEED1			0x21U
#define 	MD25_GET_SPEED2			0x22U
#define 	MD25_GET_ENCODER1		0x23U
#define 	MD25_GET_ENCODER2		0x24U
#define 	MD25_GET_ENCODERS		0x25U
#define 	MD25_GET_VOLTS			0x26U
#define 	MD25_GET_CURRENT1		0x27U
#define 	MD25_GET_CURRENT2		0x28U
#define 	MD25_GET_VERSION		0x29U
#define 	MD25_GET_ACCELERATION	0x2AU
#define 	MD25_GET_MODE			0x2BU
#define 	MD25_GET_VOLTS_CURRENT	0x2CU
#define 	MD25_SET_SPEED1			0x31U
#define 	MD25_SET_SPEED2			0x32U
#define 	MD25_SET_ACCEL			0x33U
#define 	MD25_SET_MODE			0x34U
#define 	MD25_RESET_ENCODERS		0x35U
#define 	MD25_DISABLE_REGULATOR	0x36U
#define 	MD25_ENABLE_REGULATORS	0x37U
#define 	MD25_DISABLE_TIMEOUT	0x38U
#define 	MD25_ENABLE_TIMEOUT		0x39U


uint8_t get_speed1(void);
uint8_t get_speed2(void);
uint8_t get_Battery(void);
uint8_t get_current1(void);
uint8_t get_current2(void);
uint8_t get_version(void);
uint8_t get_mode(void);
uint8_t get_accel(void);
void get_encoder1(int32_t encoder);
void get_encoder2(int32_t encoder);
void get_encoders(int32_t encoder1,int32_t encoder2 );
void get_electric_data(uint8_t battery, uint8_t current1, uint8_t current2);
void set_speed_1(uint8_t speed);
void set_speed_2(uint8_t speed);
void set_speed_Both(uint8_t speed1, uint8_t speed2);
void set_accel(uint8_t accel);
uint8_t set_mode(uint8_t MODE);
void reset_encoders(void);
void disable_reg(void);
void enable_reg();
void disable_timeout(void);
void enable_timeout(void);
uint8_t MD25_init(void);
void get_speed_Both(uint8_t* speed);


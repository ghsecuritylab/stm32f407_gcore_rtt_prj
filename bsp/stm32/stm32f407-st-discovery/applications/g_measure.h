/*
 * Copyright (c) 2019-present, Guolz
 *
 * Date           Author       Notes
 * 2019-11-28     guolz     first version
 */

#ifndef __G_MEASUER_H__
#define __G_MEASUER_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RT_CONFIG_USB_CDC               0
#define RT_CONFIG_UART3                 1

#define RT_MANAGER_THREAD_STACK_SZ      1024
#define RT_MANAGER_THREAD_PRIO          5
#define MANAGER_MQ_MSG_SZ               16
#define MANAGER_MQ_MAX_MSG              8

typedef struct {
	rt_uint8_t autoChecktype;
	rt_uint16_t autoCheckbyte;
}MesureManager;

typedef enum{
	uart3_rx_signal = 0,
	uart1_rx_signal,
	uart6_rx_signal
}msg_type;

#define hal_SetBit(data, offset)      data |= 1 << offset      //置位某位为1
#define hal_ResetBit(data, offset)    data &= ~(1 << offset)   //复位某位为0
#define hal_GetBit(data, offset)      ((data >> offset) &0x01) //获取某位

void g_MeasureQueue_send(rt_uint8_t type, const char *content);
rt_uint8_t g_MeasureAuto_Check_Get();
rt_uint16_t g_MeasureAuto_Checkbyte_Get();
rt_err_t g_measure_manager_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __AT_H__ */

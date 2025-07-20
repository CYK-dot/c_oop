/**
 * @file basic_oop/father.h
 * @author CYK-Dot
 * @brief 基本面向对象/父类的声明
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

#include <stddef.h>
#include <stdint.h>

/**
 * @brief 对象类型
 * 
 */
typedef example_base_internal_t* example_base_t;

/**
 * @brief 类接口的签名
 * 
 */
typedef int (*example_send_fptr) (example_base_t obj,const void *data,size_t len);
typedef int (*example_recv_fptr) (example_base_t obj,const void *data,size_t len);

/**
 * @brief 类的public接口底层实现，以实现多态
 * 
 */
typedef struct {
    example_send_fptr send;
    example_recv_fptr recv;
}example_base_if_t;

/**
 * @brief 类的private成员
 * 
 */
typedef struct {
    uint16_t tx_cnt;
    uint16_t rx_cnt;
}example_base_mbr_t;

/**
 * @brief 类的底层实现
 * 
 */
typedef struct {
    example_base_if_t ifx;
    example_base_mbr_t mbr;
    void *user;
}example_base_internal_t;

/**
 * @brief 类的public接口声明
 * 
 */
example_base_t example_construct_base(void);
int example_send(example_base_t obj,const void *data,size_t len);
int example_recv(example_base_t obj,void *data,size_t len);
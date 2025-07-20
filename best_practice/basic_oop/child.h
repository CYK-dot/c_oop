/**
 * @file basic_oop/child.h
 * @author CYK-Dot
 * @brief 基本面向对象/子类的声明
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright Copyright (c) 2025
 */

#include "father.h"


/**
 * @brief 子类的新方法
 * 
 */
typedef struct {

}example_chid1_if_t;

/**
 * @brief 子类的新成员
 * 
 */
typedef struct {

}example_child1_mbr_t;

/**
 * @brief 子类的用户数据
 * 
 */
typedef struct {
    example_chid1_if_t ifx;
    example_child1_mbr_t mbr;
    void *user;
}example_child1_user_t;


example_base_t example_construct_child1(void);
/**
 * @file basic_oop/child.h
 * @author CYK-Dot
 * @brief 基本面向对象/子类的声明
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright Copyright (c) 2025
 */
#include "child.h"

/**
 * @brief 父类发送函数
 * 
 * @param obj 
 * @param data 
 * @param len 
 * @return int 
 */
static int example_child_send(example_base_t obj,const void *data,size_t len)
{
    (example_base_internal_t *)this = obj;
    if (this == NULL)
    {
        return -1;
    }
    this->mbr.tx_cnt += len;
    printf("father send!cnt=%hd\n",this->mbr.tx_cnt);
    return 1;
}

example_base_t example_construct_child1(void)
{

}
/**
 * @file basic_oop/father.h
 * @author CYK-Dot
 * @brief 基本面向对象/父类的实现
 * @version 0.1
 * @date 2025-07-20
 *
 * @copyright Copyright (c) 2025
 */


/**
 * @brief 父类发送函数
 * 
 * @param obj 
 * @param data 
 * @param len 
 * @return int 
 */
static int example_father_send(example_base_t obj,const void *data,size_t len)
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

/**
 * @brief 父类接收函数
 * 
 * @param this 
 * @param data 
 * @param len 
 * @return int 
 */
static int example_father_recv(example_base_t obj,void *data,size_t len)
{
    (example_base_internal_t *)this = obj;
    if (this == NULL)
    {
        return -1;
    }
    this->mbr.rx_cnt += len;
    printf("father recv!cnt=%hd\n",this->mbr.rx_cnt);
    return 1;
}

/**
 * @brief 父类构造函数
 * 
 * @return example_base_t 父类对象
 */
example_base_t example_construct_base(void)
{
    example_base_t this = malloc(sizeof(example_base_internal_t));
    if (this == NULL)
    {
        return NULL;
    }
    this->mbr.cnt = 0;
    this->ifx.send = example_father_send;
    this->ifx.recv = example_father_recv;
    return (example_base_t)this;
}

 /**
  * @brief 父类公开接口的实现
  * 
  * @param obj 多态对象
  * @param data 需要发送的数据
  * @param len 数据长度
  * @return int 
  */
int example_send(example_base_t obj,const void *data,size_t len)
{
    (example_base_internal_t *)this = obj;
    if (obj == NULL || this->ifx.send == NULL)
    {
        return -1;
    }
    return this->ifx.send(this,data,len);
}

/**
 * @brief 父类公开接口的实现
 * 
 * @param obj 多态对象
 * @param data 接收数据缓存
 * @param len 数据长度
 * @return int 
 */
int example_recv(example_base_t obj,void *data,size_t len)
{
    (example_base_internal_t *)this = obj;
    if (obj == NULL || this->ifx.recv == NULL)
    {
        return -1;
    }
    return this->ifx.recv(this,data,len);
}
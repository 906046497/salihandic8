/***********************************************************************//** 
 * \file  iwdt_demo.c
 * \brief  IWDT_DEMO description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-5-13 <td>V0.0 <td>ZJY    <td>initial
 * </table>
 * *********************************************************************
*/
/* Includes ---------------------------------------------------------------*/
#include <string.h>
#include "drv/etb.h"
#include "drv/pin.h"
#include "demo.h"
/* externs function--------------------------------------------------------*/
/* externs variablesr------------------------------------------------------*/
/* Private macro-----------------------------------------------------------*/
/* Private variablesr------------------------------------------------------*/


/** \brief etcb one trg one 
 * 
 *  \param[in] none
 *  \return error code
 */
int etcb_one_trg_one_demo(void)
{
	int iRet = 0;
	volatile uint8_t ch;
	csi_etb_config_t tEtbConfig;				//ETB 参数配置结构体	
		
	tEtbConfig.byChType = ETB_ONE_TRG_ONE;  		//单个源触发单个目标
	tEtbConfig.bySrcIp  = ETB_ETP0_TRGOUT0 ;  	//EPT0 触发输出0作为触发源
	tEtbConfig.bySrcIp1 = 0xff;      
	tEtbConfig.bySrcIp2 = 0xff;
	tEtbConfig.byDstIp =  ETB_EPT0_SYNCIN2;   	//EPT0 同步输入2作为目标事件
	tEtbConfig.byDstIp1 = 0xff;
	tEtbConfig.byDstIp2 = 0xff;
	tEtbConfig.byTrgMode = ETB_HARDWARE_TRG;
   
	csi_etb_init();
	ch = csi_etb_ch_alloc(tEtbConfig.byChType);	//自动获取空闲通道号,ch >= 0 获取成功
	if(ch < 0)
		return -1;								//ch < 0,则获取通道号失败
		
	iRet = csi_etb_ch_config(ch, &tEtbConfig);
		
	return iRet;
}

/** \brief etcb one trg more 
 * 
 *  \param[in] none
 *  \return error code
 */
int etcb_one_trg_more_demo(void)
{
	int iRet = 0;
	volatile uint8_t ch;
	csi_etb_config_t tEtbConfig;				//ETB 参数配置结构体	
	
	//para config
	tEtbConfig.byChType = ETB_ONE_TRG_MORE;		//单个源触发多个目标
	tEtbConfig.bySrcIp 	= ETB_EXI_TRGOUT0;		//外部中断组0作为触发源
	tEtbConfig.bySrcIp1 = 0xff;						
	tEtbConfig.bySrcIp2 = 0xff;
	tEtbConfig.byDstIp 	= ETB_BT0_SYNCIN0;		//BT0 同步输入0作为目标事件
	tEtbConfig.byDstIp1 = ETB_ADC_SYNCIN0;
	tEtbConfig.byDstIp2 = ETB_EPT0_SYNCIN1;
	tEtbConfig.byTrgMode = ETB_HARDWARE_TRG;	//通道触发模式采样硬件触发
	
	csi_etb_init();								//初始化(使能)ETB
	ch = csi_etb_ch_alloc(tEtbConfig.byChType);	//获取ETB空闲通道，ch >= 0 获取成功
	if(ch < 0)
		return -1;								//ch < 0,则获取通道号失败
	iRet = csi_etb_ch_config(ch,&tEtbConfig);	//配置并启动ETB通道
			
	return iRet;
}

/** \brief etcb more trg one 
 * 
 *  \param[in] none
 *  \return error code
 */
int etcb_more_trg_one_demo(void)
{
		int iRet = 0;
	volatile uint8_t ch;
	csi_etb_config_t tEtbConfig;				//ETB 参数配置结构体	
	
	//para config
	tEtbConfig.byChType = ETB_MORE_TRG_ONE;		//单个源触发多个目标
	tEtbConfig.bySrcIp 	= ETB_EXI_TRGOUT0;		//外部中断组0作为触发源
	tEtbConfig.bySrcIp1 = ETB_BT_TRGOUT0;						
	tEtbConfig.bySrcIp2 = ETB_ETP0_TRGOUT0;
	tEtbConfig.byDstIp 	= ETB_BT0_SYNCIN0;		//BT0 同步输入0作为目标事件
	tEtbConfig.byDstIp1 = 0xff;
	tEtbConfig.byDstIp2 = 0xff;
	tEtbConfig.byTrgMode = ETB_HARDWARE_TRG;	//通道触发模式采样硬件触发
	
	csi_etb_init();								//初始化(使能)ETB
	ch = csi_etb_ch_alloc(tEtbConfig.byChType);	//获取ETB空闲通道，ch >= 0 获取成功
	if(ch < 0)
		return -1;								//ch < 0,则获取通道号失败
		
	iRet = csi_etb_ch_config(ch,&tEtbConfig);	//配置并启动ETB通道
			
	return iRet;
}
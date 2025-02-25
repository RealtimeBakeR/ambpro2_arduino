/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __COMMON_H2C_H__
#define __COMMON_H2C_H__

/* ---------------------------------------------------------------------------------------------------------
 * ----------------------------------    H2C CMD DEFINITION    ------------------------------------------------
 * ---------------------------------------------------------------------------------------------------------
 * 88e, 8723b, 8812, 8821, 92e use the same FW code base */
enum h2c_cmd {
	/* Common Class: 000 */
	H2C_RSVD_PAGE = 0x00,
	H2C_MEDIA_STATUS_RPT = 0x01,
	H2C_SCAN_ENABLE = 0x02,
	H2C_KEEP_ALIVE = 0x03,
	H2C_DISCON_DECISION = 0x04,
	H2C_PSD_OFFLOAD = 0x05,
	H2C_TCP_KEEP_ALIVE = 0x07,
	H2C_AP_OFFLOAD = 0x08,
	H2C_BCN_RSVDPAGE = 0x09,
	H2C_PROBERSP_RSVDPAGE = 0x0A,
	H2C_FCS_RSVDPAGE = 0x10,
	H2C_FCS_INFO = 0x11,
	H2C_AP_WOW_GPIO_CTRL = 0x13,
#ifdef CONFIG_MCC_MODE
	H2C_MCC_UPDATE_PARAM = 0x15,
	H2C_MCC_MACID_BITMAP = 0x16,
	H2C_MCC_LOCATION = 0x10,
	H2C_MCC_CTRL = 0x18,
	H2C_MCC_NOA_PARAM = 0x19,
	H2C_MCC_IQK_PARAM = 0x1A,
#endif /* CONFIG_MCC_MODE */
	H2C_CHNL_SWITCH_OPER_OFFLOAD = 0x1C,

	/* PoweSave Class: 001 */
	H2C_SET_PWR_MODE = 0x20,
	H2C_PS_TUNING_PARA = 0x21,
	H2C_PS_TUNING_PARA2 = 0x22,
	H2C_P2P_LPS_PARAM = 0x23,
	H2C_P2P_PS_OFFLOAD = 0x24,
	H2C_PS_SCAN_ENABLE = 0x25,
	H2C_SAP_PS_ = 0x26,
	H2C_INACTIVE_PS_ = 0x27, /* Inactive_PS */
	H2C_FWLPS_IN_IPS_ = 0x28,
#ifdef CONFIG_LPS_PG
	H2C_LPS_PG_INFO = 0x2B,
#endif
	H2C_DEFAULT_PORT_ID = 0x2C,
	/* Dynamic Mechanism Class: 010 */
	H2C_MACID_CFG = 0x40,
	H2C_TXBF = 0x41,
	H2C_RSSI_SETTING = 0x42,
	H2C_AP_REQ_TXRPT = 0x43,
	H2C_INIT_RATE_COLLECT = 0x44,
	H2C_IQ_CALIBRATION	= 0x45,

	H2C_RA_MASK_3SS = 0x46,/* for 8814A */
	H2C_RA_PARA_ADJUST = 0x47,/* CONFIG_RA_DBG_CMD */
	H2C_DYNAMIC_TX_PATH = 0x48,/* for 8814A */

	H2C_FW_TRACE_EN = 0x49,

	/* BT Class: 011 */
	H2C_B_TYPE_TDMA = 0x60,
	H2C_BT_INFO = 0x61,
	H2C_FORCE_BT_TXPWR = 0x62,
	H2C_BT_IGNORE_WLANACT = 0x63,
	H2C_DAC_SWING_VALUE = 0x64,
	H2C_ANT_SEL_RSV = 0x65,
	H2C_WL_OPMODE = 0x66,
	H2C_BT_MP_OPER = 0x67,
	H2C_BT_CONTROL = 0x68,
	H2C_BT_WIFI_CTRL = 0x69,
	H2C_BT_FW_PATCH = 0x6A,

	/* WOWLAN Class: 100 */
	H2C_WOWLAN = 0x80,
	H2C_REMOTE_WAKE_CTRL = 0x81,
	H2C_AOAC_GLOBAL_INFO = 0x82,
	H2C_AOAC_RSVD_PAGE = 0x83,
	H2C_AOAC_RSVD_PAGE2 = 0x84,
	H2C_D0_SCAN_OFFLOAD_CTRL = 0x85,
	H2C_D0_SCAN_OFFLOAD_INFO = 0x86,
	H2C_CHNL_SWITCH_OFFLOAD = 0x87,
	H2C_AOAC_RSVDPAGE3 = 0x88,
	H2C_P2P_OFFLOAD_RSVD_PAGE = 0x8A,
	H2C_P2P_OFFLOAD = 0x8B,
	H2C_BA_OFFLOAD = 0x90,
	H2C_DHCP_RENEW = 0x91,
	H2C_DYNAMIC_TX_PWR = 0x92,
#ifdef CONFIG_WOWLAN_SSL_KEEP_ALIVE
	H2C_SSL_OFFLOAD = 0x93,
#endif
	H2C_PNO = 0x94,
	H2C_TIMER_WDT = 0x95,
	H2C_BCN_TRACK = 0x96,
	H2C_RESET_TSF = 0xC0,
	H2C_BCNHWSEQ = 0xC5,
	H2C_TSF_LATCH = 0xC9,
#if defined(CONFIG_UNSUPPORT_PLCPHDR_RPT) && (CONFIG_UNSUPPORT_PLCPHDR_RPT)
	H2C_UNSUPPORT_PLCPHDR_RPT = 0xCC,
#endif
	H2C_MAXID,
};

#define H2C_INACTIVE_PS_LEN		3
#define H2C_RSVDPAGE_LOC_LEN		5
#define H2C_MEDIA_STATUS_RPT_LEN		3

#define H2C_KEEP_ALIVE_CTRL_LEN	6
#define H2C_DISCON_DECISION_LEN		3
#define H2C_PNO_LEN		        4
#define H2C_TCP_KEEP_ALIVE_CTRL_LEN 7
#define H2C_DHCP_RENEW_CTRL_LEN 6

#define H2C_AP_OFFLOAD_LEN		3
#define H2C_AP_WOW_GPIO_CTRL_LEN	4
#define H2C_AP_PS_LEN			2
#define H2C_PWRMODE_LEN			7
#define H2C_PSTUNEPARAM_LEN			4
#define H2C_MACID_CFG_LEN		7
#define H2C_BTMP_OPER_LEN			5
#define H2C_WOWLAN_LEN			5
#define H2C_REMOTE_WAKE_CTRL_LEN	3
#define H2C_BA_OFFLOAD_LEN          2
#define H2C_AOAC_GLOBAL_INFO_LEN	2
#define H2C_AOAC_RSVDPAGE_LOC_LEN	7
#define H2C_SCAN_OFFLOAD_CTRL_LEN	4
#define H2C_BT_FW_PATCH_LEN			6
#define H2C_RSSI_SETTING_LEN		4
#define H2C_AP_REQ_TXRPT_LEN		2
#define H2C_FORCE_BT_TXPWR_LEN		3
#define H2C_BCN_RSVDPAGE_LEN		5
#define H2C_PROBERSP_RSVDPAGE_LEN	5
#define H2C_P2PRSVDPAGE_LOC_LEN	5
#define H2C_P2P_OFFLOAD_LEN	3
#define H2C_TSF_LATCH_LEN		2
#define H2C_DEFAULT_PORT_LEN	2
#define H2C_B_TYPE_TDMA_LEN	5
#define H2C_DYNAMIC_TX_PWR_LEN	5
#define H2C_TIMER_WDT_LEN 6
#define H2C_BCN_TRACK_LEN 7

#ifdef CONFIG_MCC_MODE
#define H2C_MCC_CTRL_LEN			7
#define H2C_MCC_LOCATION_LEN		3
#define H2C_MCC_MACID_BITMAP_LEN	6
#define H2C_MCC_UPDATE_INFO_LEN		4
#define H2C_MCC_NOA_PARAM_LEN		4
#define H2C_MCC_IQK_PARAM_LEN		7
#endif /* CONFIG_MCC_MODE */
#ifdef CONFIG_LPS_PG
#define H2C_LPS_PG_INFO_LEN		2
#define H2C_LPSPG_LEN			16
#endif
#define eq_mac_addr(a, b)						(((a)[0] == (b)[0] && (a)[1] == (b)[1] && (a)[2] == (b)[2] && (a)[3] == (b)[3] && (a)[4] == (b)[4] && (a)[5] == (b)[5]) ? 1 : 0)
#define cp_mac_addr(des, src)					((des)[0] = (src)[0], (des)[1] = (src)[1], (des)[2] = (src)[2], (des)[3] = (src)[3], (des)[4] = (src)[4], (des)[5] = (src)[5])
#define cpIpAddr(des, src)					((des)[0] = (src)[0], (des)[1] = (src)[1], (des)[2] = (src)[2], (des)[3] = (src)[3])


#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
/*
* ARP packet
*
* LLC Header */
#define GET_ARP_PKT_LLC_TYPE(__pHeader)					ReadLE2Byte(((u8 *)(__pHeader)) + 6)

/* ARP element */
#define GET_ARP_PKT_OPERATION(__pHeader)				ReadLE2Byte(((u8 *)(__pHeader)) + 6)
#define GET_ARP_PKT_SENDER_MAC_ADDR(__pHeader, _val)	cp_mac_addr((u8 *)(_val), ((u8 *)(__pHeader))+8)
#define GET_ARP_PKT_SENDER_IP_ADDR(__pHeader, _val)		cpIpAddr((u8 *)(_val), ((u8 *)(__pHeader))+14)
#define GET_ARP_PKT_TARGET_MAC_ADDR(__pHeader, _val)	cp_mac_addr((u8 *)(_val), ((u8 *)(__pHeader))+18)
#define GET_ARP_PKT_TARGET_IP_ADDR(__pHeader, _val)	cpIpAddr((u8 *)(_val), ((u8 *)(__pHeader))+24)

#define SET_ARP_PKT_HW(__pHeader, __Value)					WriteEF2Byte(((u8 *)(__pHeader)) + 0, __Value)
#define SET_ARP_PKT_PROTOCOL(__pHeader, __Value)			WriteEF2Byte(((u8 *)(__pHeader)) + 2, __Value)
#define SET_ARP_PKT_HW_ADDR_LEN(__pHeader, __Value)			WriteEF1Byte(((u8 *)(__pHeader)) + 4, __Value)
#define SET_ARP_PKT_PROTOCOL_ADDR_LEN(__pHeader, __Value)	WriteEF1Byte(((u8 *)(__pHeader)) + 5, __Value)
#define SET_ARP_PKT_OPERATION(__pHeader, __Value)			WriteEF2Byte(((u8 *)(__pHeader)) + 6, __Value)
#define SET_ARP_PKT_SENDER_MAC_ADDR(__pHeader, _val)	cp_mac_addr(((u8 *)(__pHeader))+8, (u8 *)(_val))
#define SET_ARP_PKT_SENDER_IP_ADDR(__pHeader, _val)		cpIpAddr(((u8 *)(__pHeader))+14, (u8 *)(_val))
#define SET_ARP_PKT_TARGET_MAC_ADDR(__pHeader, _val)	cp_mac_addr(((u8 *)(__pHeader))+18, (u8 *)(_val))
#define SET_ARP_PKT_TARGET_IP_ADDR(__pHeader, _val)		cpIpAddr(((u8 *)(__pHeader))+24, (u8 *)(_val))

#define FW_WOWLAN_FUN_EN				BIT(0)
#define FW_WOWLAN_PATTERN_MATCH			BIT(1)
#define FW_WOWLAN_MAGIC_PKT				BIT(2)
#define FW_WOWLAN_UNICAST				BIT(3)
#define FW_WOWLAN_ALL_PKT_DROP			BIT(4)
#define FW_WOWLAN_GPIO_ACTIVE			BIT(5)
#define FW_WOWLAN_REKEY_WAKEUP			BIT(6)
#define FW_WOWLAN_DEAUTH_WAKEUP			BIT(7)

#define FW_WOWLAN_GPIO_WAKEUP_EN		BIT(0)
#define FW_FW_PARSE_MAGIC_PKT			BIT(1)

#define FW_REMOTE_WAKE_CTRL_EN			BIT(0)
#define FW_REALWOWLAN_EN				BIT(5)

#define FW_WOWLAN_KEEP_ALIVE_EN			BIT(0)
#define FW_ADOPT_USER					BIT(1)
#define FW_WOWLAN_KEEP_ALIVE_PKT_TYPE	BIT(2)

#define FW_REMOTE_WAKE_CTRL_EN			BIT(0)
#define FW_ARP_EN						BIT(1)
#define FW_REALWOWLAN_EN				BIT(5)
#define FW_WOW_FW_UNICAST_EN			BIT(7)

#endif /* CONFIG_WOWLAN */

/* _RSVDPAGE_LOC_CMD_0x00 */
#define SET_H2CCMD_RSVDPAGE_LOC_PROBE_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_PSPOLL(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_NULL_DATA(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_QOS_NULL_DATA(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_BT_QOS_NULL_DATA(__pH2CCmd, __Value)SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)

/* _MEDIA_STATUS_RPT_PARM_CMD_0x01 */
#define SET_H2CCMD_MSRRPT_PARM_OPMODE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 0, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID_IND(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 1, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MIRACAST(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 2, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 3, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_ROLE(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 4, 4, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 1, 0, 8, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID_END(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 2, 0, 8, (__Value))

#define GET_H2CCMD_MSRRPT_PARM_OPMODE(__pH2CCmd)		LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 0, 1)
#define GET_H2CCMD_MSRRPT_PARM_MIRACAST(__pH2CCmd)		LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 2, 1)
#define GET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK(__pH2CCmd)	LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 3, 1)
#define GET_H2CCMD_MSRRPT_PARM_ROLE(__pH2CCmd)			LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 4, 4)

#define H2C_MSR_ROLE_RSVD	0
#define H2C_MSR_ROLE_STA	1
#define H2C_MSR_ROLE_AP		2
#define H2C_MSR_ROLE_GC		3
#define H2C_MSR_ROLE_GO		4
#define H2C_MSR_ROLE_TDLS	5
#define H2C_MSR_ROLE_ADHOC	6
#define H2C_MSR_ROLE_MAX	7

extern const char *const _h2c_msr_role_str[];
#define h2c_msr_role_str(role) (((role) >= H2C_MSR_ROLE_MAX) ? _h2c_msr_role_str[H2C_MSR_ROLE_MAX] : _h2c_msr_role_str[(role)])

#define H2C_MSR_FMT "%s %s%s"
#define H2C_MSR_ARG(h2c_msr) \
	GET_H2CCMD_MSRRPT_PARM_OPMODE((h2c_msr)) ? " C" : "", \
	h2c_msr_role_str(GET_H2CCMD_MSRRPT_PARM_ROLE((h2c_msr))), \
	GET_H2CCMD_MSRRPT_PARM_MIRACAST((h2c_msr)) ? (GET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK((h2c_msr)) ? " MSINK" : " MSRC") : ""

s32 rtw_hal_set_FwMediaStatusRpt_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid, bool macid_ind, u8 macid_end);
s32 rtw_hal_set_FwMediaStatusRpt_single_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid);
s32 rtw_hal_set_FwMediaStatusRpt_range_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid, u8 macid_end);

/* _KEEP_ALIVE_CMD_0x03 */
#define SET_H2CCMD_KEEPALIVE_PARM_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_ADOPT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_PKT_TYPE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_CHECK_PERIOD(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_KEEPALIVE_WATCHDOG_RFE_CTRL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 7, __Value)
#define SET_H2CCMD_KEEPALIVE_WATCHDOG_PULL_CTRL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 7, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_WATCHDOG_INTERVAL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define SET_H2CCMD_KEEPALIVE_WATCHDOG_PULSE_DURATION(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)

/* _DISCONNECT_DECISION_CMD_0x04 */
#define SET_H2CCMD_DISCONDECISION_PARM_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_ADOPT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_TRY_OK_BCN_FAIL_COUNT_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_CHECK_PERIOD(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_TRY_PKT_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)

/* _PNO_CMD_0x94 */
#define SET_H2CCMD_PNO_PARM_ENABLE(__pH2CCmd, __Value)						SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_PNO_PARM_DTIM(__pH2CCmd, __Value)					    SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 4, __Value)
#define SET_H2CCMD_PNO_PARM_INTERVAL_L(__pH2CCmd, __Value)					SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_PNO_PARM_INTERVAL_H(__pH2CCmd, __Value)					SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define SET_H2CCMD_PNO_PARM_FORCE_WAKEUP(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)

/* _TIMER_WDT_CMD_0x95 */
#define SET_H2CCMD_TIMER_WDT_EN_CTRL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 5, __Value)
#define SET_H2CCMD_TIMER_WDT_PULL_CTRL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_TIMER_WDT_INTERVAL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_TIMER_WDT_PULSE_DURATION(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)

/* _BCN_TRACK_CMD_0x96 */
#define SET_H2CCMD_BCN_TRACK_EN_CTRL(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_BCN_TRACK_START_WINDOW(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_BCN_TRACK_MAX_WINDOW(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define SET_H2CCMD_BCN_TRACK_INCREMENTSTEP(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define SET_H2CCMD_BCN_TRACK_DURATION(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)

/* _TCP_KEEP_ALIVE_CMD_0x07 */
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_ADOPT(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_DTIMTO_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_DTIMTO_RETRY_INC(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_DTIMTO_SSL_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_CHECK_PERIOD(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_LOC(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_RESEND_INTERVAL(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_FIRST_PKT_TIME(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_ACK_TIMEOUT(__pH2CCmd, __Value)       SET_BITS_TO_LE_1BYTE(__pH2CCmd+5, 0, 8, __Value)
#define SET_H2CCMD_TCP_KEEPALIVE_PARM_RESEND_COUNT(__pH2CCmd, __Value)      SET_BITS_TO_LE_1BYTE(__pH2CCmd+6, 0, 8, __Value)

/* _DHCP_RENEW_CMD_0x91 */
#define SET_H2CCMD_DHCP_RENEW_PARM_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define	SET_H2CCMD_DHCP_RENEW_PARM_LOC(__pH2CCmd, __Value)                      SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define	SET_H2CCMD_DHCP_RENEW_PARM_T1_H(__pH2CCmd, __Value)              SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define	SET_H2CCMD_DHCP_RENEW_PARM_T1_L(__pH2CCmd, __Value)              SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define	SET_H2CCMD_DHCP_RENEW_PARM_LEASE_H(__pH2CCmd, __Value)        SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)
#define	SET_H2CCMD_DHCP_RENEW_PARM_LEASE_L(__pH2CCmd, __Value)        SET_BITS_TO_LE_1BYTE(__pH2CCmd+5, 0, 8, __Value)

/* _DYNAMIC_TX_PWR_CMD_0x92 */
#define SET_H2CCMD_DYNAMIC_TX_PWR_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define	SET_H2CCMD_DYNAMIC_TX_PWR_THS_L(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define	SET_H2CCMD_DYNAMIC_TX_PWR_THS_H(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define	SET_H2CCMD_DYNAMIC_TX_PWR_OFS_L(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define	SET_H2CCMD_DYNAMIC_TX_PWR_OFS_H(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)
/* _AP_Offload 0x08 */
#define SET_H2CCMD_AP_WOWLAN_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _BCN_RsvdPage	0x09 */
#define SET_H2CCMD_AP_WOWLAN_RSVDPAGE_LOC_BCN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _Probersp_RsvdPage 0x0a */
#define SET_H2CCMD_AP_WOWLAN_RSVDPAGE_LOC_ProbeRsp(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _Probersp_RsvdPage 0x13 */
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_INDEX(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 4, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_C2H_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_PLUS(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_HIGH_ACTIVE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 6, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_DURATION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_C2H_DURATION(__pH2CCmd, __Value)SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
/* _AP_PS 0x26 */
#define SET_H2CCMD_AP_WOW_PS_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_32K_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_RF(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_DURATION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)

#ifdef CONFIG_MCC_MODE
/* MCC LOC CMD 0x10 */
#define SET_H2CCMD_MCC_RSVDPAGE_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)

/* MCC MAC ID CMD 0x16 */
#define SET_H2CCMD_MCC_MACID_BITMAP_L(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_MCC_MACID_BITMAP_H(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)

/* MCC INFO CMD 0x18 */
#define SET_H2CCMD_MCC_CTRL_ORDER(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 4, __Value)
#define SET_H2CCMD_MCC_CTRL_TOTALNUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 4, __Value)
#define SET_H2CCMD_MCC_CTRL_CHIDX(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_MCC_CTRL_BW(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 2, __Value)
#define SET_H2CCMD_MCC_CTRL_BW40SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 2, 3, __Value)
#define SET_H2CCMD_MCC_CTRL_BW80SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 5, 3, __Value)
#define SET_H2CCMD_MCC_CTRL_DURATION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_MCC_CTRL_ROLE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 3, __Value)
#define SET_H2CCMD_MCC_CTRL_INCURCH(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 3, 1, __Value)
#define SET_H2CCMD_MCC_CTRL_RSVD0(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 4, 4, __Value)
#define SET_H2CCMD_MCC_CTRL_RSVD1(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)
#define SET_H2CCMD_MCC_CTRL_RFETYPE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 0, 4, __Value)
#define SET_H2CCMD_MCC_CTRL_DISTXNULL(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 4, 1, __Value)
#define SET_H2CCMD_MCC_CTRL_C2HRPT(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 5, 2, __Value)
#define SET_H2CCMD_MCC_CTRL_CHSCAN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 7, 1, __Value)

/* MCC NoA CMD 0x19 */
#define SET_H2CCMD_MCC_NOA_FW_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_MCC_NOA_TSF_SYNC_OFFSET(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 7, __Value)
#define SET_H2CCMD_MCC_NOA_START_TIME(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_MCC_NOA_INTERVAL(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_MCC_EARLY_TIME(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)

/* MCC IQK CMD 0x1A */
#define SET_H2CCMD_MCC_IQK_READY(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_MCC_IQK_ORDER(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 4, __Value)
#define SET_H2CCMD_MCC_IQK_PATH(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 2, __Value)
#define SET_H2CCMD_MCC_IQK_RX_L(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_MCC_IQK_RX_M1(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 2, __Value)
#define SET_H2CCMD_MCC_IQK_RX_M2(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 2, 6, __Value)
#define SET_H2CCMD_MCC_IQK_RX_H(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 4, __Value)
#define SET_H2CCMD_MCC_IQK_TX_L(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)
#define SET_H2CCMD_MCC_IQK_TX_M1(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 3, __Value)
#define SET_H2CCMD_MCC_IQK_TX_M2(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 3, 5, __Value)
#define SET_H2CCMD_MCC_IQK_TX_H(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 0, 6, __Value)
#endif /* CONFIG_MCC_MODE */

/* CHNL SWITCH OPER OFFLOAD 0x1C */
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_CH_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_MODE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 0, 2, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_40M_SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 2, 3, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_80M_SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 5, 3, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_RFE_TYPE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 2, 0, 4, __Value)

/* _WoWLAN PARAM_CMD_0x80 */
#define SET_H2CCMD_WOWLAN_FUNC_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_PATTERN_MATCH_ENABLE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_WOWLAN_MAGIC_PKT_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_WOWLAN_UNICAST_PKT_ENABLE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_WOWLAN_ALL_PKT_DROP(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_ACTIVE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_WOWLAN_REKEY_WAKE_UP(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 6, 1, __Value)
#define SET_H2CCMD_WOWLAN_DISCONNECT_WAKE_UP(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIONUM(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 7, __Value)
#define SET_H2CCMD_WOWLAN_DATAPIN_WAKE_UP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 7, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_DURATION(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_PULSE_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_PULSE_COUNT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 1, 7, __Value)
#define SET_H2CCMD_WOWLAN_LOWPR_RX(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_CHANGE_UNIT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 2, 1, __Value)
/* _REMOTE_WAKEUP_CMD_0x81 */
#define SET_H2CCMD_REMOTE_WAKECTRL_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NDP_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_GTK_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NLO_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_FW_UNICAST_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_P2P_OFFLAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NBNS_FILTER_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 2, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_TKIP_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 3, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_ACTION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_FW_PARSING_UNTIL_WAKEUP(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 4, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_POWER_BIT_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 7, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_REQ_OFLD_EN(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 3, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_REQ_PWR_BIT(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 4, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_REQ_DTIM1TO_EN(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 5, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_REQ_LOC(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)

/* AOAC_GLOBAL_INFO_0x82 */
#define SET_H2CCMD_AOAC_GLOBAL_INFO_PAIRWISE_ENC_ALG(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_AOAC_GLOBAL_INFO_GROUP_ENC_ALG(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)

/* AOAC_RSVDPAGE_LOC_0x83 */
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_REMOTE_WAKE_CTRL_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd), 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_ARP_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_NEIGHBOR_ADV(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_INFO(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)
#ifdef CONFIG_GTK_OL
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_EXT_MEM(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)
#endif /* CONFIG_GTK_OL */

/* AOAC_RSVDPAGE_2_0x84 */

/* AOAC_RSVDPAGE_3_0x88 */
#ifdef CONFIG_PNO_SUPPORT
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_NLO_INFO(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd), 0, 8, __Value)
#endif
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_AOAC_REPORT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 0, 8, __Value)

#ifdef CONFIG_PNO_SUPPORT
/* D0_Scan_Offload_Info_0x86 */
#define SET_H2CCMD_AOAC_NLO_FUN_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd), 3, 1, __Value)
#define SET_H2CCMD_AOAC_NLO_IPS_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd), 4, 1, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_PROBE_PACKET(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_SCAN_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_SSID_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#endif /* CONFIG_PNO_SUPPORT */

#ifdef CONFIG_P2P_WOWLAN
/* P2P_RsvdPage_0x8a */
#define SET_H2CCMD_RSVDPAGE_LOC_P2P_BCN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_P2P_PROBE_RSP(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_P2P_NEGO_RSP(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_P2P_INVITE_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_P2P_PD_RSP(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)
#endif /* CONFIG_P2P_WOWLAN */

/* BA_offload 0x90 */
#define SET_H2CCMD_BA_OFFLOAD_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_BA_OFFLOAD_BA_RSP_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)

#ifdef CONFIG_LPS_PG
#define SET_H2CCMD_LPSPG_SEC_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)/*SecurityCAM_En*/
#define SET_H2CCMD_LPSPG_MBID_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)/*BSSIDCAM_En*/
#define SET_H2CCMD_LPSPG_PMC_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)/*PatternMatchCAM_En*/
#define SET_H2CCMD_LPSPG_MACID_SEARCH_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)/*MACIDSearch_En*/
#define SET_H2CCMD_LPSPG_TXSC_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)/*TXSC_En*/
#define SET_H2CCMD_LPSPG_MU_RATE_TB_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)/*MURateTable_En*/
#define SET_H2CCMD_LPSPG_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)/*Loc_LPS_PG*/
#endif

#ifdef CONFIG_WOWLAN_SSL_KEEP_ALIVE
#define SET_H2CCMD_MQTT_SSL_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)/*SSL EN*/
#define SET_H2CCMD_MQTT_PATTERN_MATCH_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)/*PATTERN_MATCH_EN EN*/
#define SET_H2CCMD_MQTT_PUBLISH_WAKE(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)/*PUBLISH_WAKE EN*/
#define SET_H2CCMD_TCP_SSL_MODE(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)/*Header ignore*/
#define SET_H2CCMD_SSL_INFO_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)/*SSL_INFO_LOC*/
#define SET_H2CCMD_SSL_PATTERN_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)/*SSL_PATTERN_LOC*/
#define SET_H2CCMD_TCP_PARM_SERVERTO_EN(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_TCP_PARM_SERVER_TIMEOUT_L(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define SET_H2CCMD_TCP_PARM_SERVER_TIMEOUT_H(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)
#define SET_H2CCMD_SSL_COUNTER_REPORT(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_SSL_PATTERN_OFFSET(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)
#endif

/* DEFAULT_PORT_CMD_0x2c */
#define SET_H2CCMD_DEFAULT_PORTNUM(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 4, __Value)

/* _TSF_LATCH_CMD_0xc6 */
#define SET_H2CCMD_TSFLATCH_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_TSFLATCH_GPIO_DEFAULT_VAL(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_TSFLATCH_PORTNUM(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 4, __Value)
#define SET_H2CCMD_TSFLATCH_GPIONUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)

/* ---------------------------------------------------------------------------------------------------------
 * -------------------------------------------    Structure    --------------------------------------------------
 * --------------------------------------------------------------------------------------------------------- */
typedef struct _RSVDPAGE_LOC {
	u8 LocProbeRsp;
	u8 LocPsPoll;
	u8 LocNullData;
	u8 LocQosNull;
	u8 LocBTQosNull;
#ifdef CONFIG_WOWLAN
	u8 LocRemoteCtrlInfo;
	u8 LocArpRsp;
	u8 LocAddbaRsp;
	u8 LocNbrAdv;
	u8 LocGTKRsp;
	u8 LocGTKInfo;
#ifdef CONFIG_GTK_OL
	u8 LocGTKEXTMEM;
#endif /* CONFIG_GTK_OL */
	u8 LocProbeReq;
	u8 LocNetList;
#ifdef CONFIG_WOWLAN_AOAC_RPT
	u8 LocAOACReport;
#endif
#ifdef CONFIG_PNO_SUPPORT
	u8 LocPNOInfo;
	u8 LocScanInfo;
	u8 LocSSIDInfo;
	u8 LocProbePacket;
#endif /* CONFIG_PNO_SUPPORT */
#endif /* CONFIG_WOWLAN	 */
	u8 LocApOffloadBCN;
#ifdef CONFIG_P2P_WOWLAN
	u8 LocP2PBeacon;
	u8 LocP2PProbeRsp;
	u8 LocNegoRsp;
	u8 LocInviteRsp;
	u8 LocPDRsp;
#endif /* CONFIG_P2P_WOWLAN */
} RSVDPAGE_LOC, *PRSVDPAGE_LOC;

#endif
void dump_TX_FIFO(PADAPTER padapter, u8 page_num, u16 page_size);
u8 rtw_hal_set_fw_media_status_cmd(_adapter *adapter, u8 mstatus, u8 macid);
#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
/* WOW command function */
void rtw_hal_set_fw_wow_related_cmd(_adapter *padapter, u8 enable);
#ifdef CONFIG_P2P_WOWLAN
/* H2C 0x8A */
u8 rtw_hal_set_FwP2PRsvdPage_cmd(_adapter *adapter, PRSVDPAGE_LOC rsvdpageloc);
/* H2C 0x8B */
u8 rtw_hal_set_p2p_wowlan_offload_cmd(_adapter *adapter);
#endif /* CONFIG_P2P_WOWLAN */
#endif

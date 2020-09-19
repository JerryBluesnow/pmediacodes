#ifndef _HSHB_PUB_H_
#define _HSHB_PUB_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "hshb_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STAT_OFF 		0
#define STAT_USE		1
#define STAT_OK 		2
#define STAT_ERR 		3

#define TYPE_SVC_SWITCH 	1
#define TYPE_SVC_PUB 		2
#define TYPE_SVC_DB 		3
#define TYPE_SVC_SW 		4
#define TYPE_SVC_ZDK 		5
#define TYPE_SVC_HY 		6
#define TYPE_SVC_FT 		7
#define TYPE_SVC_DMR 		8
#define TYPE_REC_REC 		9
#define TYPE_REC_HDL 		10
#define TYPE_SVC_CMD_SYNC	11
#define TYPE_SVC_HF			12
#define TYPE_SVC_HF_SND		13

#define VOICE_TIME_OUT 	1

#define FT_VOICE_ARM_PCM 	100
#define FT_VOICE_SIZE_PCM 	800

#define YF_VOICE_ARM_PCM 	50
#define YF_VOICE_ARM_SIP 	20

#define YF_VOICE_SIZE_ARM 	50
#define YF_VOICE_PKT_SIZE 	YF_VOICE_SIZE_ARM +10
#define YF_VOICE_SIZE_GSM 	33
#define SWITCH_VOICE_SIZE 	100
#define YF_VOICE_SIZE_PCM 	800

#define FILE_NAME_SIZE  64

#define INVAILD_ID  0
#define cmd_type_cmd  0
#define cmd_type_ptt  1
#define cmd_type_exc  2
#define cmd_type_set  3
#define ptu_size 1500

#define fun_free  	0
#define fun_hbt 	2
#define fun_swhbt 	3
#define fun_voice  	3
#define fun_useradio  5
#define fun_usr_info	7
#define fun_usrvoice	8
#define fun_dhvoice		9
#define fun_info		10
#define fun_dh_info	12
#define fun_hf_info	13
#define fun_sw_info	14
#define fun_swoff	15
#define fun_swon	16
#define fun_noplay	17
#define fun_play	18
#define fun_chk		19
#define fun_switch	20

#define fun_pvoes_com_req		21
#define fun_pvoes_com_ack		22
#define fun_pvoes_com_update	23
#define fun_pvoes_com_delete	24

#define fun_pvoes_gps_req	25
#define fun_pvoes_gps_rpl	26

#define fun_pvoes_ctrl_req		27
#define fun_pvoes_ctrl_ack		28
#define fun_pvoes_ctrl_update	29
#define fun_pvoes_ctrl_delete	30

#define fun_pvoes_boat_req		31

#define fun_yf_voice_radio		32
#define fun_yf_voice_switch		33
#define fun_yf_on		34
#define fun_yf_off		35
#define fun_info_swstat		36
#define fun_info_dmrstat	37
#define fun_info_yfstat		38
#define fun_info_swcmd		39
#define fun_info_opinfo		40

#define type_svr_usr_update		1
#define type_svr_usr_op_au		2
#define type_svr_obj_update		3
#define type_svr_usr_op_stat	4
#define type_svr_usr_delete		5
#define type_svr_obj_delete		6

#define fun_usr_add		6
#define fun_usr_update	7
#define fun_usr_delete	8
#define fun_usr_au		9

#define fun_usrop_add		10
#define fun_usrop_update	11
#define fun_usrop_delete	12
#define fun_usrop_rpl		13


#define fun_obj_act		16

#define fun_set_svr 	48
#define fun_local_reg 49
#define fun_local_hbt 50
#define fun_local_voice 51
#define fun_local_pkt  52
#define fun_alience	77
#define fun_grp	88
#define fun_stat	99
#define fun_swvoice  255

#define fun_swlocal_reg  49
#define fun_swlocal_hbt 51
#define fun_swlocal_pkt  52
#define fun_swlocal_useradio  53
#define fun_swlocal_ctrl  54
#define fun_swlocal_voice  55
#define fun_jqlocal_voice  56
#define fun_dhlocal_voice  57
#define fun_rhlocal_voice  58
	
#define fun_main_call  1000
#define fun_set_focus  1001
#define fun_disp_locate  1002
#define fun_hdl_sms  1003
#define fun_show_track  1004
#define fun_play_record  1005
#define fun_set_conf  1006
#define fun_system_set  1007
#define fun_cng_passwd  1008
#define fun_chk_admin  1009
#define fun_set_passwd  1010
#define fun_phone_book  1201
#define fun_item_book  1202
#define fun_edit_book  1203
#define fun_addr_book  1204
#define fun_edit_lb  1301
#define fun_update_lb  1302
#define fun_edit_team  1303
#define fun_get_dst  1304
#define fun_send_sms  1401
#define fun_draft_sms  1402
#define fun_recv_sms  1403
#define fun_edit_sms  1404
#define fun_del_sms  1405
#define fun_item_sms  1406
#define fun_hdl_record  1500
#define fun_item_record  1501
#define fun_del_record  1502
#define fun_chk_exit  1600
#define fun_chk_usr  1601
#define fun_chk_reg  1602
#define fun_get_reg  1603
#define fun_chk_menu  1700

#define fun_set_radio = 1070
#define fun_cng_radio = 1071
#define fun_cng_channel = 1072
#define fun_cng_freq = 1073
#define fun_cng_mode = 1074
#define fun_cng_noice = 1075
#define fun_cng_power = 1076

#define cng_type_radio  21
#define cng_type_channel  22
#define cng_type_freq  23
#define cng_type_mode  24
#define cng_type_noice  25
#define cng_type_power  26
#define cng_type_useradio  27
#define cng_type_freeradio  28
#define cng_type_ptt  29

#define fun_re_reg  1019
#define fun_disp_radio  1800
#define fun_get_map  1801

#define fun_chk_au  1900
#define fun_svr_au  1901
#define fun_pwd_au  1902

#define err_err  1
#define err_ok  0
	
#define FLG_OK  2
#define FLG_USE  1
#define FLG_FREE  0

#define type_radio_use_err 2
#define type_radio_use_au  3

#define PVOES_HDR_SIZE  	8
#define PVOES_DATA_SIZE  	1306

#define PVOES_ERR_OK  		0
#define PVOES_ERR_CMD  		1
#define PVOES_ERR_NOEXIST  	2
#define PVOES_ERR_BUSY  	3

#define OP_TYPE_FREE  		0
#define OP_TYPE_DEL  		1
#define OP_TYPE_ADD 		2
#define OP_TYPE_UPDATE  	3
#define OP_TYPE_REQ  		4

#define OBJ_TYPE_FREE  0
#define OBJ_TYPE_JQ  1
#define OBJ_TYPE_SIP  2
#define OBJ_TYPE_USR  3
#define OBJ_TYPE_TEAM  4
#define OBJ_TYPE_DH  5
#define OBJ_TYPE_SW  6
#define OBJ_TYPE_HF  7
#define OBJ_TYPE_YF  8
#define OBJ_TYPE_QT  9
#define OBJ_TYPE_DMRTM 10
#define OBJ_TYPE_SWTM 11
#define OBJ_TYPE_YFTM 12
#define OBJ_TYPE_DHTM 13

#define OBJ_TYPE_SW_ZDK 61
#define OBJ_TYPE_SW_BL  62

#define OBJ_TYPE_YF_FT 81
#define OBJ_TYPE_YF_HY 82

#define AU_TYPE_FREE  		0
#define AU_TYPE_MON  		1
#define AU_TYPE_SPEAK  		2
#define AU_TYPE_RETRY  		3
#define AU_TYPE_RETRY_MON  4
#define AU_TYPE_ADMIN  		5

#define MODE_TX  1
#define MODE_RX  2

#define idx_hdr_usr_id  6
#define idx_hdr_src_id   8
#define idx_hdr_dst_id  14

#define hf_idx_stat_id  	2	
#define hf_idx_sx  		3	
#define hf_idx_voice_id  	4	
#define hf_idx_voice_type  7
#define hf_idx_voice_size  8
#define sw_idx_voice_id  2	
#define sw_idx_voice_type  4
#define sw_idx_voice_mode  5	
#define sw_idx_voice_size  6

#define voice_len_G711  80
#define voice_len_PCM  160
#define voice_len_FRAME  80
#define voice_head_size  10
#define sw_voice_head_size  8
#define hf_voice_head_size  10
#define voice_len_G729A_ARM  10
#define G729A_ARM_voice_pkt_len  22 //voice_head_size+voice_len_G729A_ARM+2;
	
#define	BIG_END			0
#define	SMALL_END			1
#define FLAG_NEA_FREE          0 
#define FLAG_NEA_RUN		0x10
#define FLAG_NEA_KILL  		0x40   
#define FLAG_NEA_DEC		0x66
#define FLAG_NEA_INC		0x88
#define	CMD_TYPE_CMD		0
#define	CMD_TYPE_DATA		5
#define	RADIO_DES_LEN			16
#define	SIGN_DATA_LEN			16
#define	OBJ_ID_LEN				6
#define	SIGN_DATA_NUM			10
#define	SVR_TYPE_WINDOWS		0
#define	SVR_TYPE_LINUX			1
#define	CTRL_TYPE_ARM			0
#define	CTRL_TYPE_COMM		1
#define	LOG_TYPE_DEBUG		0
#define	LOG_TYPE_INFO			1
#define	LOG_TYPE_WARNING		2
#define	LOG_TYPE_ERROR		3
#define	LOG_TYPE_URGENT		4
#define BUF_LEN 				1024
#define HSHB_SHARED_MEM_SIZE 128
#define MAX_CMD_SIZE 128
#define MAX_CMD_NUM 10
#define MAX_PTU_SIZE 1500
#define MAX_CMD_ITEM_LEN 1024
#define MAX_CMD_LINE_LEN 4096
#define MAX_PROC_ITEM 	100
#define MAX_FILE_NAME_LEN 	64
#define MAX_NAME_LEN 	64
#define MAX_VAL_LEN 	64
#define MAX_LINE_LEN 	4096
#define MAX_CNL_NUM 	16
#define MAX_NO_VOICE_CNT 10

#define LVS_SVC_ID    	4
#define hbt_arp_send		0
#define hbt_arp_recv		1
#define hbt_ping_send	2
#define hbt_ping_recv	3
#define hbt_ping_chk		4
#define hbt_send_hbt		5
#define hbt_recv_hbt		6
#define hbt_chk_hdl		7
#define hbt_chk_local		8
#define hbt_chk_remote	9
#define hbt_vip_mng		10
#define hbt_obj_mng		11	
#define hbt_svc_mng		12 
#define hbt_sys_up		13
#define hbt_svc_stop		14
#define hbt_vip_req		15
#define hbt_vip_chk		16	
#define hbt_vip_start		17
#define hbt_svc_chk		18
#define hbt_svc_failure	19
#define hbt_svc_run		20	
#define hbt_svc_kill		21
#define hbt_vip_kill		22 
#define hbt_chk_main	23

#define STAT_FREE 		-1
#define STAT_STOP 		0
#define STAT_RUN   		1	
#define STAT_REQ   		2
#define STAT_FORBID   	3
#define PING_DST_NUM 0xf 
#define FLAG_UNUSE     	0
#define FLAG_USE     		1
#define FLAG_OK     		0
#define FLAG_ERR    		-1 
#define FLAG_TIME_OUT   1
#define FLAG_HSHB_FREE		0x00
#define FLAG_HSHB_CLEAN	0x20
#define FLAG_HSHB_RUN		0x10
#define FLAG_HSHB_KILL  		0x40   
#define FLAG_HSHB_EXIT  	0x40
#define MAX_WAIT_TIME  3
#define HA_ALARM_VERSION "HITV_HA_ALARM-1.0.0.0"
#define WORK_DIR "/usr/local/fountain"
#define HA_SERVICE_SHARED_MEM_SIZE    128
#define HSHB_MAX_DST_NUM 16
#define IP_LENGTH 16
#define NODE_LENGTH 18
#define IFC_LENGTH 6
#define RSC_LENGTH 16
#define BUF_LENGTH 256
#define ERR_NODE -1
#define PRI_NODE 1
#define SEC_NODE 2
#define IS_MON 1
#define NOT_RUN 0
#define IS_RUN 1
#define REQ_RUN 2
#define ERR_STR_LEN 20
#define DEAD_COUNT 20
#define NAME_LENGTH 20
#define VALUE_LENGTH 20
#define MAX_CONF_NUM 40

#define ARM_VOICE_DATA_LEN 100
#define SW_VOICE_DATA_LEN 110

#define BUF_VOICE_DATA_LEN 200

#define HF_VOICE_DATA_LEN 1200
#define HF_PTT_DATA_LEN 19

#define FT_VOICE_DATA_LEN 3200

#define TKR_SHR_KEY 	't'
#define HBT_SHR_KEY 	'h'
#define SVR_SHR_KEY 	's'
#define NEA_SHR_KEY 	'k'
#define MAIN_SHR_KEY 	'm'

#define ID_CHK_SVR	0
#define ID_CHK_TKR	1
#define ID_CHK_HBT	2
#define ID_CHK_MAX	3

#define id_pkt_data  8
#define id_pkt_start  9
#define id_pkt_end  10
#define id_pkt_sgl  11

#define MAX_GIS_ITEM_NUM	16

#define BAS_HASH_ID 	67
#define MAX_HASH_OBJ_NUM 	137

#define MAX_SS_OBJ_NUM 	256
#define MAX_SW_SS_NUM 		67
#define MAX_YF_SS_NUM 		127
#define MAX_SDMR_SS_NUM 	131
#define MAX_DH_SS_NUM 		31
#define MAX_JQ_SS_NUM 		17
#define MAX_USR_SS_NUM 	631
#define MAX_SIP_SS_NUM 	67
#define MAX_TM_SS_NUM 	MAX_SW_SS_NUM+MAX_YF_SS_NUM
#define MAX_SYS_SS_NUM 	MAX_SW_SS_NUM+MAX_YF_SS_NUM+MAX_SDMR_SS_NUM+MAX_DH_SS_NUM +MAX_JQ_SS_NUM 
#define MAX_SS_USR_NUM 	MAX_SW_SS_NUM+MAX_YF_SS_NUM+MAX_SDMR_SS_NUM+MAX_DH_SS_NUM +MAX_JQ_SS_NUM +MAX_SIP_SS_NUM+MAX_USR_SS_NUM

/*************通话组成员信息*********************
偏移量	字段			字节数	值	描述
0			成员类型		1			
1			通信信道		1			
2			成员ID			6
8			保留				3
11			状态				1
12			通话开始时间	4
16			最后一次语音	4		
20			临时通话ID 		6
26			创建者ID			6		
*********************************************************/
#define idx_obj_data  	40
#define idx_obj_type  	0
#define idx_obj_xd  		1
#define idx_obj_id  		2
#define idx_obj_name  	8
#define idx_obj_stat  		11
#define idx_obj_begin  	12
#define idx_obj_last  		16
#define idx_obj_tmpid 	20
#define idx_own_id  		26
			
#define MAX_CONF_ITEM_NUM 64
#define ss_tm_out 	300000

#define MAX_ZJT_NUM 32

typedef struct conf_item_s
{
	char key[MAX_NAME_LEN];
	char val[MAX_VAL_LEN];
	U8 flag; 
	U8 hash8;
	U16 hash16;
	U32 hash;
}conf_item_t;

typedef struct stat_info_s
{
	int id;
	int txf;
	int rxf;
	U8 mode;
	U8 err;
	short eq;
	short xd;
	U8 power;
	U8 noice;
	short vtx;
	short vrx;
	short temp;
}stat_info_t;

typedef struct gps_info_s
{
	U8 flag; 
	conf_item_t gis_item[MAX_GIS_ITEM_NUM];
}gps_info_t;

typedef struct radio_name_s
{
	char name[NAME_LENGTH];
}radio_name_t;

typedef struct ip_addr_s
{
	char name[IP_LENGTH];
}ip_addr_t;

typedef struct zjt_stat_s
{
	U8 zjt_sx1;
	U8 zjt_sx2;
	U8 zjt_flg;
	U8 zjt_alarm;
	ip_addr_t zjt_IP;
	U16 zjt_port;
	U32 zjt_id;
	U16 zjt_act;
	U32 zjt_tm;
	radio_name_t zjt_name;
	radio_name_t zjt_svc;
	radio_name_t zjt_stat;
	U8 zjt_alarm_rx;
	U8 zjt_alarm_tx;
	U8 zjt_alarm_tmp;
	U8 zjt_alarm_power;
	U8 zjt_alarm_fan;
	radio_name_t zjt_wk_sx;
	radio_name_t zjt_mode;
}zjt_stat_t;

typedef struct usr_au_info_s
{
	U16 usr_id;
	U8 flg;
	U8 stat;
	U8 s_key[SIGN_DATA_LEN];
	U8 u_key[SIGN_DATA_LEN];
	U8 passwd[SIGN_DATA_LEN];
}usr_au_t;

typedef struct hash_key_s
{
	U8 flg;
	U8 stat;
	U16 dst_id;
	U32 src_id;
}hash_key_t;

typedef struct th_stat_s
{
	U8 fun;
	U8 type;
	U16 data_len;
	U32 tm;
}th_stat_t;

typedef struct xm_item_s
{
	char nm1[BUF_LEN];
	char nm2[BUF_LEN];
	char val[BUF_LEN];
	char in_buf[BUF_LEN];
	char key[NAME_LENGTH];
	char value[NAME_LENGTH];
}xm_item_t;	

typedef struct rec_des_s
{
	U16 id;
	U8 src_type;
	U8 dst_type;
	
	U32 src;
	U32 dst;

	U32 s_tm;
	U32 e_tm;
	
	char file_name[FILE_NAME_SIZE];
}rec_des_t;


typedef struct voice_id_s
{
	U8 size;
	U8 cmd;
	U16 id;
	
	U8 fun;
	U8 idx;
	U8 src_type;
	U8 dst_type;
	
	U32 src;
	U32 dst;

	U32 s_tm;
	U32 e_tm;
	
	U8 data[ptu_size];
	char file_name[FILE_NAME_SIZE];
}voice_id_t;

typedef struct data_buf_s
{
	U8 data[ptu_size];
	U8 fun;
	U8 type;
	U16 data_len;
	U32 tm;
}data_buf_t;

typedef struct cmd_struct_s
{
	U8 cmd[MAX_CMD_SIZE -2];
	U8 len;
	U8 chk;
}cmd_struct_t;

typedef struct str_s
{
	char buf[BUF_LENGTH];
}str_t;

typedef struct voice_info_s
{
	U16 id;
	U16 size;
	U32 tm;
	U8 data[SWITCH_VOICE_SIZE*2];
}voice_info_t;

/*
P,船id,报位(11)/报警(22)/呼叫(33)/其它呼叫(55)[2],n/s[3],纬度[4],e/w[5],经度[6],航向/中心码[7],
航速/前6中心码[8], 定位[9],性质[10],设备[11],频道/频率[12],开机状态/发射类型[13],时间(秒)，
来源名称，备注，
*/
typedef struct opt_info_s
{
	U32 rcv_tm;
	U32 radio_id;
	U32 src_id;
	U8 type;
	U8 ns;
	char lon[NAME_LENGTH];
	U8 ew;
	char lat[NAME_LENGTH];
	U32 dir;
	U32 speed;
	U32 fix;
	U8 xz;
	U32 dev;
	U32 cnl;
	U8 stat;
	U32 tm;
	char src_name[NAME_LENGTH];
	char bz[NAME_LENGTH];
}opt_info_t;

typedef struct ft_voice_info_s
{
	U32 ts;
	U16 head;
	U16 tear;
	U8 data[FT_VOICE_DATA_LEN];
}ft_voice_info_t;

typedef struct rcv_voice_info_s
{
	U8 flg;
	U8 sx;
	U8 type;
	U8 rsv;
	U16 head;
	U16 tear;
	U32 id;
	U32 tm;
	U8 data[BUF_VOICE_DATA_LEN];
}rcv_voice_info_t;

typedef struct ss_hfvoice_info_s
{
	U8 flg;
	U8 sx;
	U8 type;
	U8 rsv;
	U16 head;
	U16 tear;
	U32 id;
	long tm_sec;
	long tm_usec;
	U8 ptt_data[HF_PTT_DATA_LEN];
	U8 data[HF_VOICE_DATA_LEN];
	U16 snd_cnt;
	U16 err_cnt;
	U16 pre;
	U16 next;
}ss_hfvoice_info_t;

typedef struct ss_addr_s
{
	U8 ss_flg;
	U8 ss_stat;
	U8 ss_type;
	U8 ss_rsv;
	U32 ss_tm;
	U16 ss_dstid;
	U16 ss_ownid;
	struct sockaddr_in ss_addr;
}ss_addr_t;

typedef struct usr_obj_info_s
{
	U8 use_flg;
	U8 obj_type;
	U8 obj_id[6];
	U8 obj_lat[4];
	U8 obj_lon[4];
	U8 com1_stat;
	U8 com1_type;
	U8 com1_id[6];
	U8 com2_stat;
	U8 com2_type;
	U8 com2_id[6];
	U8 com3_stat;
	U8 com3_type;
	U8 com3_id[6];
	U8 com4_stat;
	U8 com4_type;
	U8 com4_id[6];
}usr_obj_info_t;

typedef struct ss_usr_s
{
	U8 usr_flg;
	U8 usr_type;
	U8 usr_stat;
	U8 usr_au;
	
	U8 usr_rsv;
	U8 usr_voice;
	U16 usr_id;
	
	U16 tmp_id;
	
	U32 start_tm;
	U32 last_tm;
}ss_usr_t;

typedef struct hash_info_s
{
	U8 ss_flg;
	U8 ss_stat;
	U16 ss_id;
	U32 tm;
}hash_info_t;

typedef struct ss_info_s
{
	U8 ss_flg;
	U8 ss_type;
	U8 ss_stat;
	U8 ss_new; //数据库存在标志
	U8 ss_slot;
	U8 ss_mon;
	U16 ss_num;
	
	U32 ss_id;
	U32 ss_usrid;
	U32 ss_ownid;
	U32 ss_tmpid;
	U32 ss_tm;
	
	U32 ss_speakid;
	U16 ss_idx;
	U8 ss_cnt;
	U8 ss_free;
	
	long tm_sec;
	long tm_usec;
	ss_usr_t ss_usr[MAX_SS_OBJ_NUM];
}ss_info_t;

typedef struct ss_obj_info_s
{
	U8 ss_flg;
	U8 ss_stat;
	U8 ss_id_idx;
	U8 ss_ssrc_idx;

	U32 ss_id;
	U32 ss_ssrc;

}ss_obj_info_t;


typedef struct wt_info_s
{
	int speak_id;
	int wt_sdmr;
	int wt_free;
	int wt_sw;
	int wt_dh;
	int sdmr_time_out;
	int sw_time_out;
	int dh_time_out;
	int free_time_out;
	int act_obj_num;
	U8 speak_obj;
	struct sockaddr_in cliaddr;
}wt_info_t;
volatile wt_info_t wt_info;

typedef struct nea_proc_item_s
{
	char name[MAX_NAME_LEN];
	U16 uid;
	U16 port;
	U16 proc_id;
	char flg_run;
	char restart_flg;
	char ne_name[MAX_NAME_LEN];
	char startup_cmd[MAX_CMD_ITEM_LEN];
	char monitor_cmd[MAX_CMD_ITEM_LEN]; 
	char stop_cmd[MAX_CMD_ITEM_LEN]; 
	U32 start_times;	
	U8 wait_times;	
	U8 check_time;
	char use;
	char stat;
	int gid;
	int pid;             //process id
	U32 ppid;         //parent proccess id
}nea_proc_item_t;

typedef struct hshb_object_s
{
	U64 reg_time;
	U64 *shm_ptr;
	char node_name[NODE_LENGTH]; 	//使用unmae -n获得的机器名
	char vip[IP_LENGTH]; 				//虚拟IP
    char ifc[IFC_LENGTH]; 				//接口名
	char rsc_name[RSC_LENGTH];		//资源名
	char shr_key;					//共享存储键值
	char status;						//目标状态
	char vip_run;					//VIP启动标志
	char flg;							//启用标志0--未启用  1--启用
	char stat;						//服务状态0--停止 1--正常  -1--异常
	char crnt_status;					//当前状态
}hshb_object_t;

typedef struct msg_hdr_s
{
	U8 msg_type;
	U8 msg_fun;
	U8 msg_ver;
	U8 msg_err;
	U32 msg_tm;
	U8 msg_src[6]; 				
    U8 msg_dst[6]; 				
	U32 msg_sn;
	U8 msg_chk[16];
}msg_hdr_t;

typedef enum eHBT_TYPE
{
	HBT_TYPE_PLAY= 1,
	HBT_TYPE_RECORD= 2,
	HBT_TYPE_RECV= 3,
	HBT_TYPE_SEND= 4,
	HBT_TYPE_REG= 5,
	HBT_TYPE_CTRL= 6,
	HBT_AUDIO_DECORD= 7,
	HBT_AUDIO_ENCORD= 8,
	HBT_TYPE_AU= 9,
	HBT_TYPE_CMD= 10,
	HBT_TYPE_HBT= 11,
	HBT_SWITCH_HFSVC= 12,
	HBT_SWITCH_SWSVC= 13,
	HBT_SWITCH_SWITCH= 14,
	HBT_SWITCH_CHK= 15,
	HBT_DB_CHK= 16
} eHBT_TYPE;

typedef struct
{
	union 
	{
		U8 u8_data[8];
		U16 u16_data[4];
		unsigned int u32_data[2];
	};
}rnd_num_t;

typedef struct
{
	union 
	{
		U8 svc_flg[8];
		struct 
		{
			U8 mdc;
			U8 vcc;
			U8 ira;		
			U8 user_agent;
			U8 rsv1;
			U8 dbdds;
			U8 crc;
			U8 mrp;		
		};
		U64 flg_data;
	};
}hshb_svc_flg_t;

typedef struct
{
	union 
	{
		U8 reg_rpl_data[48];
		struct 
		{
			U8 des[MAX_NAME_LEN];
			U8 key[SIGN_DATA_LEN];
			U32 psvr_ip;		
			U16 psvr_port;
			U32 ssvr_ip;
			U16 ssvr_port;
			U8 psvr_stat;
			U8 ssvr_stat;
			U8 psvr_type;
			U8 ssvr_type;
		};
	};
}radio_reg_rpl_t;

typedef struct radio_svr_s
{
	U8 radio_des[RADIO_DES_LEN];
	U8 sign_passwd[SIGN_DATA_LEN];
	struct sockaddr_in paddr;
	struct sockaddr_in saddr;
	U8 p_stat;
	U8 s_stat;
	U8 p_ver;
	U8 s_ver;
}radio_svr_t;

typedef struct
{
	union 
	{
		U8 svc_stat[HSHB_MAX_DST_NUM];
		struct 
		{
			U64 stat_data1;
			U64 stat_data2;
		};
	};
}hshb_svc_stat_t;

typedef struct
{
	union 
	{
		struct 
		{
			U8 flg_send_hbt;
			U8 flg_recv_hbt;
			U8 flg_chk_hdl;		
			U8 flg_chk_local;
			U8 flg_chk_remote;
			U8 flg_vip_mng;
			U8 flg_obj_mng;		
			U8 flg_svc_mng;
		};
		U64 svc_status;
	};
}hshb_svc_status_t;

typedef struct
{
	U8 use;
	U8 flg;
	U8 crnt;		
	U8 old;
}th_hbt_info_t;

typedef struct cnl_item_s
{
	U32 recv_freq;
	U32 send_freq;
	U8   cnl;
	U8   act;
	U8   flg;
	U8   stat;
	U32 rsv;
}cnl_item_t;

typedef struct
{
	union 
	{
		U8 data[SIGN_DATA_LEN];
		struct 
		{
			U32 data1;
			U32 data2;
			U32 data3;
			U32 data4;
		};
	};
}sign_data_t;
sign_data_t sign_data_buf[SIGN_DATA_NUM];

typedef struct obj_des_info_s
{
	U8 obj_type;
	U8 obj_stat;
	U16 obj_id;
	U16 obj_idx;
	U16 radio_id;

	U8 radio_type;
	U8 radio_flg;
	U8 radio_use;
	U8 radio_txrx;
	U8 radio_ab;
	U8 radio_ctl1;
	U8 radio_ctl2;
	U8 radio_rsv;
	
	U32 radio_sn;
	U16 radio_port1;
	U16 radio_port2;
	
	char ext_ip[IP_LENGTH];
	char int_ip[IP_LENGTH];
	char name[NAME_LENGTH];
	char des[NAME_LENGTH];
	char city[NAME_LENGTH];
	char label[NAME_LENGTH];
	
}obj_des_info_t;	

typedef struct radio_para_s
{
	U8 radio_cnl;
	U8 radio_stat;
	U8 radio_mode;
	U8 radio_noice;
	
	U8 radio_pwr;
	U8 radio_voice_code;
	U8 radio_temp;
	U8 v_tx;
	
	U8 v_rx;
	U8 radio_ssl;
	U8 radio_sd;
	U8 freq_cng;

	U32 chk_tm;
	
	U32 tx_freq;
	U32 rx_freq;
}radio_para_t;

boolean sw_flg_long_push;
boolean sw_chk_ptt; 
boolean sdmr_flg_long_push;
boolean sdmr_chk_ptt; 

radio_para_t radio_para;
cnl_item_t cnl_info[MAX_CNL_NUM];
U8 radio_stat;
int radio_cnl_num;
U32 msg_sn;
U8 msg_ver;
int radio_type;
int svr_type;
int ctrl_type;
U8 s_key[SIGN_DATA_LEN];
U8 u_key[SIGN_DATA_LEN];
U8 passwd[SIGN_DATA_LEN];
U8 id_svr[OBJ_ID_LEN];
U8 id_dst[OBJ_ID_LEN];
U8 id_lcl[OBJ_ID_LEN];
U8 radio_des[RADIO_DES_LEN];
U8 audio_type;

struct sockaddr_in db_hdl_addr;
struct sockaddr_in usr_addr;
struct sockaddr_in hfsvc_addr;
struct sockaddr_in hfsvr_addr;
struct sockaddr_in swsvc_addr;
struct sockaddr_in sw_svr_addr;
struct sockaddr_in switch_voice_addr;
struct sockaddr_in enc_voice_addr;
struct sockaddr_in rec_voice_addr;
struct sockaddr_in play_voice_addr;
struct sockaddr_in hfsnd_addr;
struct sockaddr_in yfsvc_addr;
struct sockaddr_in yfsvr_addr;
struct sockaddr_in yf_snd_addr;
struct sockaddr_in ftsvc_addr;
struct sockaddr_in zdksvc_addr;
struct sockaddr_in record_rec_addr;
struct sockaddr_in record_hdl_addr;
struct sockaddr_in cmd_sync_addr;


int sw_id; 
U8 sw_au;
int sw_id_old; 
U8 sw_au_old;
int sdmr_id; 
int sdmr_sx;

U8 switch_get_hf_slot(int dst_id);

void switch_set_hf_slot(int dst_id, U8 sx);

/***********************根据会话索引获取用户会话信息*****************************/
void switch_get_usr_ss(int ss_idx, ss_info_t *info_ss);

/***********************根据会话索引设置用户会话信息*****************************/
void switch_set_usr_ss(int ss_idx, ss_info_t info_ss);

/***********************根据会话索引获取电台名称*****************************/
U32 switch_get_radio_name(int ss_idx, char *radio_name);

/***********************根据会话索引设置电台名称*****************************/
void switch_set_radio_name(int ss_idx, char *radio_name);

/***********************根据会话索引获取电台描述*****************************/
U32 switch_get_radio_des(int ss_idx, char *radio_des);

/***********************根据会话索引设置电台描述*****************************/
void switch_set_radio_des(int ss_idx, char *radio_des);

/***********************根据会话索引获取电台城市*****************************/
U32 switch_get_radio_city(int ss_idx, char *radio_city);

/***********************根据会话索引设置电台城市*****************************/
void switch_set_radio_city(int ss_idx, char *radio_city);

/***********************根据会话索引获取用户密码*****************************/
U32 switch_get_usr_passwd(int ss_idx, char *usr_passwd);

/***********************根据会话索引设置用户密码*****************************/
void switch_set_usr_passwd(int ss_idx, char* usr_passwd);

/* ****************************获取服务的日志级别*************************************
*Function:	get_log_lvl
*descript:       get log level of svc
*input:		type_svc
*output:		none.
* Returns: 	log level of svc
***********************************************************************************************/
int get_log_lvl(U8 type_svc);

/* *****************************设置服务的日志级别************************************
*Function:	set_log_lvl.
*descript:       set log level of svc
*input:		type_svc-the type of svc, log_lvl-the log lvl of svc.
*output:		none.
* Returns: 	none.
***********************************************************************************************/
void set_log_lvl(U8 type_svc, int log_lvl);

char *get_main_ip(void);


void set_main_ip(char *svr_ip);


char *get_node_name(void);


void set_node_name(char *node_name);


U16 get_svc_port(void);


void set_svc_port(U16 svr_port);

char *get_gis_svr_ip(void);
void set_gis_svr_ip(char *svr_ip);
U16 get_gis_svr_port(void);
void set_gis_svr_port(U16 svr_port);

char *get_ft_usr_id(void);
void set_ft_usr_id(char *usr_id);
char *get_ft_usr_passwd(void);
void set_ft_usr_passwd(char *usr_passwd);
char *get_ft_svr_ip(void);
void set_ft_svr_ip(char *svr_ip);
U16 get_ft_svr_port(void);
void set_ft_svr_port(U16 svr_port);

char *get_hy_usr_id(void);
void set_hy_usr_id(char *usr_id);
char *get_hy_usr_passwd(void);
void set_hy_usr_passwd(char *usr_passwd);
char *get_hy_svr_ip(void);
void set_hy_svr_ip(char *svr_ip);
U16 get_hy_svr_port(void);
void set_hy_svr_port(U16 svr_port);


char *get_zdk_usr_id(void);
void set_zdk_usr_id(char *usr_id);
char *get_zdk_usr_passwd(void);
void set_zdk_usr_passwd(char *usr_passwd);
char *get_zdk_svr_ip(void);
void set_zdk_svr_ip(char *svr_ip);
U16 get_zdk_svr_port(void);
void set_zdk_svr_port(U16 svr_port);

char *get_sw_usr_id(void);
void set_sw_usr_id(char *usr_id);
char *get_sw_usr_passwd(void);
void set_sw_usr_passwd(char *usr_passwd);
char *get_sw_svr_ip(void);
void set_sw_svr_ip(char *svr_ip);
U16 get_sw_svr_port(void);
void set_sw_svr_port(U16 svr_port);

char *get_dmr_usr_id(void);
void set_dmr_usr_id(char *usr_id);
char *get_dmr_usr_passwd(void);
void set_dmr_usr_passwd(char *usr_passwd);
char *get_dmr_svr_ip(void);
void set_dmr_svr_ip(char *svr_ip);
U16 get_dmr_svr_port(void);
void set_dmr_svr_port(U16 svr_port);


int str2i(char *str_no);

void short2byte(U8 byte_data[], int byte_offset, short short_data, U8 end_flg);
short byte2short(U8 byte_data[], int byte_offset, U8 big_end_flg);

void  fiber_set_cnl(U8 cnl);

void tkr_chk_hbt(eHBT_TYPE hbt_type);
	
void trim(char * str);

U8 str_chk_only_has_digit(char * str);

void set_level(int log_lvl);	
void inc_level(void);
void dec_level(void);

int hs_log_init(char *log_file);

char *tkr_print_buf(U8 *buf, int len);

int bcd2i(U8 bcd);

int bcd_id2int(U8 *id_buf, int len);

void str_bcd_to_id(char* id_str, U8 *id_buf, int len);

int str_to_id(char *id_str,  int offset);

U8 i2bcd(int i);

void i2bcd6(int ival, U8 bcd[]);
int bcd6i(int offset, U8 bcd[]);

int bcd_id2int(U8 *id_buf, int len);

void bcd_to_str(U8 *buf, int len, char *bcd_str);

int print_to_buf(char *key, char *val, char *dst);

void print_buf(U8 *buf, int len, U8 *str);

void i_b3(U8 *byte_data, int byte_offset, U8 end_flg, int int_data);
int b3_i(U8  *byte_data, int byte_offset, U8 end_flg);

void s2b(U8 *byte_data, int byte_offset, U8 end_flg, short short_data);
short b2s(U8 *byte_data, int byte_offset, U8 end_flg);
void i2b(U8 *byte_data, int byte_offset, U8 end_flg, int int_data);
int b2i(U8  *byte_data, int byte_offset, U8 end_flg);

int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen); 
  
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen); 

void switch_set_sk(U8 type, int sk);

int switch_get_sk(U8 type);


/* ********************************************************************************************
*Function:	log_print.
*descript:       print log info. 
*input:		level--the level of log, fmt_str--the format of log.
*output:		none.
* Returns: 	the length of log.
***********************************************************************************************/
int log_print(int level, const char *fmt_str, ...);

/* ********************************************************************************************
*Function:	hshb_crt_shr_mem.
*descript:       create share_mem. 
*input:		chkey--the share_mem key.
*output:		shm_ptr--the pointer to hare_mem.
* Returns: 	0--succeed   -1--failed.
***********************************************************************************************/
int hshb_crt_shr_mem(char chkey, void **shm_ptr);

/* ********************************************************************************************
*Function:	hshb_chk_shr_mem.
*descript:       atatch  share_mem. 
*input:		chkey--the share_mem key.
*output:		shm_ptr--the pointer to hare_mem.
* Returns: 	0--succeed   -1--failed.
***********************************************************************************************/
int hshb_chk_shr_mem(char chkey, void **shm_ptr);

/* ********************************************************************************************
*Function:	hshb_init_shr_mem.
*descript:       if exist share_mem atatch it, else create it. 
*input:		chkey--the share_mem key.
*output:		shm_ptr--the pointer to hare_mem.
* Returns: 	0--succeed   -1--failed.
***********************************************************************************************/
int hshb_init_shr_mem(char chkey, void **shm_ptr);

/***********************************************************************************************
** function:	hs_ping_reg_icmp_obj
** descript:	register the dest of ping, max 16 dest,must run before hs_ping_start
** input: 		dst_ip--the pointer of dest addres
** output: 	none
** returns: 	succes--FLAG_OK   failure--FLAG_ERR
***********************************************************************************************/
int  hs_ping_reg_icmp_obj(char *dst_ip);

/***********************************************************************************************
** function:	hs_ping_start
** descript:	create the pthread for check  the dest of ping,run ones after hs_ping_reg_icmp_obj
** input: 		none
** output: 	none
** returns: 	succes--FLAG_OK   failure--FLAG_ERR
***********************************************************************************************/
int  hs_ping_start(void);

/***********************************************************************************************
** function:	hs_ping_check
** descript:	get the result of check  the dest of ping, must run after hs_ping_start
** input: 		the ip address of dest
** output: 	none
** returns: 	succes--FLAG_OK   failure--FLAG_TIME_OUT
***********************************************************************************************/
int  hs_ping_check(char *dst_ip);

/***********************************************************************************************
** function:	hshb_init_serial
** descript:	create a serial channel
** input: 		serial_dev--serial device name
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_init_serial(char *serial_dev);

/***********************************************************************************************
** function:	hshb_serial_send
** descript:	send data by a serial channel
** input: 		data--the data to send  data_len--the length of send data
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_serial_send(void *data, int data_len);

/***********************************************************************************************
** function:	hshb_serial_recv
** descript:	recv data from a serial channel
** input: 		data--the data to receive  data_len--the length of receive data
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_serial_recv(void *data, int *data_len);

/***********************************************************************************************
** function:	hshb_svc_start
** descript:	the entry for start hsha
** input: 		none
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_svc_start(void);

/***********************************************************************************************
** function:	hshb_svc_stop
** descript:	the entry for stop hsha
** input: 		stop_flg--FLAG_HSHB_KILL kill svc to exit, FLAG_HSHB_EXIT held svc to exit 
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_svc_stop(int stop_flg);

/***********************************************************************************************
** function:	hshb_mon_start
** descript:	the entry for monitor hshb_svc
** input: 		none
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_mon_start(void);

/***********************************************************************************************
** function:	hshb_mon_stop
** descript:	the entry for stop monitor hshb_svc
** input: 		stop_flg--FLAG_HSHB_KILL kill svc to exit, FLAG_HSHB_EXIT held svc to exit 
** output: 	none
** returns: 	succes--FLAG_OK   failure--other
***********************************************************************************************/
int hshb_mon_stop(int stop_flg);

/* ********************************************************************************************
*Function:	hshb_start_arp
*descript:       start manage for the IP check. 
*input:		local_ip--the IP for send arp local_interface--the interface for send arp. 
*output:		none.
* Returns: 	FLAG_OK--succeed FLAG_TIME_OUT--failure.
***********************************************************************************************/
int hshb_start_arp(char *local_ip, char *local_interface);

/* ********************************************************************************************
*Function:	hshb_arp_chk
*descript:       get the status of IP. 
*input:		dst_ip--the IP for check.
*output:		none.
* Returns: 	FLAG_OK--used FLAG_TIME_OUT--not used.
***********************************************************************************************/
int hshb_arp_chk(char *dst_ip);

/* ********************************************************************************************
*Function:	hshb_arp_run
*descript:       set the IP for check. 
*input:		dst_ip--the IP for check.
*output:		none.
* Returns: 	FLAG_OK--succeed FLAG_TIME_OUT--failure.
***********************************************************************************************/
int hshb_arp_run(char *dst_ip);

/* ********************************************************************************************
*Function:	hshb_arp_stop
*descript:       free the IP for check. 
*input:		dst_ip--the IP for check.
*output:		none.
* Returns: 	FLAG_OK--succeed FLAG_TIME_OUT--failure.
***********************************************************************************************/
int hshb_arp_stop(char *dst_ip);

/* ********************************************************************************************
*Function:	hbt_set.
*descript:       update pthread hbt. 
*input:		hbt_id--the pthread id.
*output:		none
* Returns: 	none
***********************************************************************************************/
void hbt_set(U8 hbt_id);

/* ********************************************************************************************
*Function:	hbt_clr
*descript:       clear pthread hbt. 
*input:		hbt_id--the pthread id.
*output:		none
* Returns: 	none
***********************************************************************************************/
void hbt_clr(U8 hbt_id);

/* ********************************************************************************************
*Function:	hbt_chk_hbt
*descript:       chk pthread hbt. 
*input:		none
*output:		none
* Returns: 	FLAG_OK--hbt ok  FLAG_ERR--hbt failure FLAG_USE--NO hbt
***********************************************************************************************/
int hbt_chk_hbt(void);

/* ********************************************************************************************
*Function:	str_is_eql
*descript:       chk String is same. 
*input:		src,dst
*output:		none
* Returns: 	src<dst -1, src>dst 1, src=dst 0
***********************************************************************************************/
int str_is_eql(char src[], char dst[]);


/* ********************************************************************************************
*Function:	hshb_free_port
*descript:       free port. 
*input:		port --the port to free
*output:		none
* Returns: 	FLAG_OK--run ok  FLAG_ERR--run failure
***********************************************************************************************/
int hshb_free_port(U16 port);

int db_save_obj_info (conf_item_t *gis_item);
int db_get_obj_info (conf_item_t *gis_item); 
int db_get_op_list (int usr_id, U8 buf[]); 

/***********************获取AB状态*****************************/
void switch_set_tm_ab_stat(int ss_idx, U8 ab_stat);


/***********************获取AB 控制状态*****************************/
void switch_set_tm_ab_ctrl(int ss_idx, U8 ab_ctrl);


/***********************获取是否在收音机状态*****************************/
void switch_set_tm_radio_stat(int ss_idx, U8 radio_stat);


/***********************获取是否在发射接收状态*****************************/
void switch_set_tm_txrx_stat(int ss_idx, U8 txrx_stat);


/***********************获取电台工作频道*****************************/
void switch_set_tm_channel(int ss_idx, int channel);


/***********************获取电台静噪状态*****************************/
void switch_set_tm_noice_stat(int ss_idx, U8 noice_stat);
	

/***********************获取电台呼叫类型*****************************/
void switch_set_tm_call_type(int ss_idx, U8 call_type);
	

/***********************获取收音频道*****************************/
void switch_set_tm_radio_cnl(int ss_idx, U8 radio_cnl);
	

/***********************获取电台信号前度*****************************/	
void switch_set_tm_ssl(int ss_idx, U8 ssl);


/***********************获取电台呼叫方向*****************************/
void switch_set_tm_call_dir(int ss_idx, U8 dir);


/********************获取电台扫描/记忆模式*************************/
void switch_set_tm_scan(int ss_idx, U8 scan_stat);


/***********************获取电台呼叫状态*****************************/
void switch_set_tm_call_stat(int ss_idx, U8 call_stat);


/***********************获取电台工作状态*****************************/
void switch_set_tm_work_stat(int ss_idx, U8 work_mode);


/***********************获取收音机音量*****************************/
void switch_set_tm_radio_vol(int ss_idx, U8 radio_vol);


/***********************获取电台ID*****************************/
void switch_set_tm_id(int idx, int id);


/***********************获取电台发射频率*****************************/
void switch_set_tm_tx(int idx,int txf);


/***********************获取电台接收频率*****************************/
void switch_set_tm_rx(int idx,int rxf);


/***********************获取电台工作模式*****************************/
void switch_set_tm_mode(int idx, U8 mode);


/***********************获取电台故障状态***************************/
void switch_set_tm_err(int idx, U8 err);


/***********************获取电台场强*****************************/
void switch_set_tm_eq(int idx, short eq);


/***********************获取电台信道*****************************/
void switch_set_tm_xd(int idx, short xd);


/***********************获取电台功率模式*****************************/
void switch_set_tm_power(int idx, U8 power);


/***********************获取电台静噪值*****************************/
void switch_set_tm_noice(int idx, U8 noice);


/***********************获取电台发射电压*****************************/
void switch_set_tm_vtx(int idx, short vtx);


/***********************获取电台接收电压*****************************/
void switch_set_tm_vrx(int idx, short vrx);


/***********************获取电台温度*****************************/
void switch_set_tm_temp(int idx, short temp);


void switch_get_tm_stat(int idx, stat_info_t *stat_info);	

void switch_print_tm_info(int idx);


/* ********************************************************************************************
*Function:	db_update_op_info
*descript:       update usr op_list. 
*input:		
*      op_type --OP_TYPE_FREE:0, OP_TYPE_DEL:1 OP_TYPE_ADD:2 OP_TYPE_UPDATE:3
*      usr_id-- 用户ID
*      own_type--成员类型
*      own_id--成员ID
*      own_name--成员名称
*      stat--使用状态
*      tmp_id--临时用户ID
*output:		none
* Returns: 	FLG_OK--run ok  FLG_FREE--run failure
***********************************************************************************************/
int db_update_op_info(U8 op_type, int usr_id, U8 own_type, int own_id, char own_name[], U8 stat, int tmp_id);

/* ********************************************************************************************
*Function:	db_get_op_info
*descript:       get usr op_list. 
*input:		
*      usr_id-- 用户ID
*      cliaddr--用户地址
*output:		none
* Returns: 	FLG_OK--run ok  FLG_FREE--run failure
***********************************************************************************************/
int db_get_op_info(int snd_sk, int usr_id, struct sockaddr_in cliaddr);

/* ********************************************************************************************
*Function:	get_str_hash
*descript:       获取字符串的HASH值. 
*input:		
*      str-- 字符串
*      sed--最大HASH值
*output:		none
* Returns: 	字符串HASH值
***********************************************************************************************/
U32 get_str_hash(char *str, U32 sed);

/* ********************************************************************************************
*Function:	get_usr_hash
*descript:       获取用户名称的HASH值. 
*input:		
*      str-- 字符串
*output:		none
* Returns: 	字符串HASH值
***********************************************************************************************/
U32 get_usr_hash(char *str);

/* ********************************************************************************************
*Function:	get_item_hash
*descript:       获取配置项中关键字字符串的HASH值. 
*input:		
*      item-- 带KEY值得配置项
*output:		
*      item--hash8 8bithash, hash16 16bithash hash 32bithash
* Returns: 	关键字字符串HASH值
***********************************************************************************************/
U32 get_item_hash(conf_item_t item);

/* ********************************************************************************************
*Function:	get_html_item
*descript:       获取缓冲区中的指定开始位置的XML项. 
*input:		
*      rcv_data-- 数据缓冲区
*      idx_start--开始位置
*      idx_end--结束位置
*      item--保存结果信息缓冲区
*output:		none
* Returns: 	获取项后的位置
***********************************************************************************************/
int get_html_item(U8 rcv_data[], int idx_start, int idx_end, conf_item_t *item);

/* ********************************************************************************************
*Function:	get_hash_idx
*descript:       获取hash_id的位置索引. 
*input:		
*      hash_info-- 数据缓冲区
*      hash_id--ID信息
*output:		none
* Returns: 	ID位置索引
***********************************************************************************************/
int get_hash_idx(hash_info_t hash_info[], U16 hash_id);

/* ********************************************************************************************
*Function:	get_ss_type
*descript:       获取ss_id的对象类型. 
*input:		
*      ss_id--ID对象ID
*output:		none
* Returns: 	ID对应的类型
***********************************************************************************************/
int get_ss_type(int ss_id);


/* ********************************************************************************************
*Function:	get_ss_idx
*descript:       获取ss_id的位置索引. 
*input:		
*      ss_type-- 对象类型
*      ss_id--ID对象ID
*output:		none
* Returns: 	ID位置索引
***********************************************************************************************/
int get_ss_idx(int ss_type, int ss_id);


/* ********************************************************************************************
*Function:	chk_running
*descript:      获取系统运行标志
*input:	none	
*output:		none
* Returns: 	系统运行标志
***********************************************************************************************/
boolean chk_running();

/* ********************************************************************************************
*Function:	switch_get_addr
*descript:      获取指定服务的地址
*input:	type-服务类型	
*output:		none
* Returns: 	指定服务的地址
***********************************************************************************************/
struct sockaddr_in switch_get_addr(U8 type);

/* ********************************************************************************************
*Function:	switch_set_addr
*descript:      设置指定服务的地址
*input:	type-服务类型
*            dst_addr-设置地址 
*output:		none
* Returns: 	无
***********************************************************************************************/
void switch_set_addr(U8 type, struct sockaddr_in dst_addr);

U32 get_tm_str(char *tm_str);

void get_db_passwd(char *db_password);

void set_db_passwd(char *db_password);

#ifdef __cplusplus
}
#endif

#endif 

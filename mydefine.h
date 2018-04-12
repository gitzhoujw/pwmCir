#define True	 1
#define False	 0

#define Step_Normal	5
#define Step_Slow	1
#define Step_Fast	10

#define Reset_CountPWM	1500

#define CountMax_PWM1	2500
#define CountMax_PWM2	2400
#define CountMax_PWM3	2500
#define CountMax_PWM4	2000
#define CountMax_PWM5	2500
#define CountMax_PWM6	2500
#define CountMin_PWM1	600
#define CountMin_PWM2	600
#define CountMin_PWM3	600
#define CountMin_PWM4	600
#define CountMin_PWM5	600
#define CountMin_PWM6	1125

sbit IR=P3^2;  //红外接口标志
unsigned char  irtime;//红外用全局变量

bit irrecieve_ok,irjiema_ok;
unsigned char IRcord[4];
unsigned char irdata[33];

					/*函数声明*/
void init_inter();
void ir_jiema();


sbit OUT1 = P1^0;
sbit OUT2=P1^1;
sbit OUT3=P1^2;
sbit OUT4=P1^3;
sbit OUT5=P1^4;
sbit OUT6=P1^5;


sbit KEY1=P2^0;  //定义按键输入端口
sbit KEY2=P2^1;
sbit KEY3=P2^2;
sbit KEY4=P2^3;

//按键定义：
//sbit change_inc=P2^0;
//sbit change_dec=P2^1;
//sbit circle_inc=P2^2;
//sbit circle_dec=P2^3;

/*//LED灯指示
sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;
sbit led5=P0^4;
sbit led6=P0^5;
*/

//操纵杆定义：
//sbit button1 	= P1^0;	//Steering Engine 2前
//sbit button2 	= P1^1;	//Steering Engine 2后
//sbit button3 	= P1^2;	//Steering Engine 1左旋
//.0sbit button4 	= P1^3;	//Steering Engine 1右旋
//-------------------------
//sbit JS2U 	= P3^2;	//Steering Engine 3前
//sbit JS2D 	= P3^3;	//Steering Engine 3后
//sbit JS2L 	= P1^6;	//Steering Engine 5左旋	
//sbit JS2R 	= P1^7;	//Steering Engine 5右旋
//-------------------------
//sbit JS3U 	= P3^6;	//Steering Engine 4前
//sbit JS3D 	= P3^7;	//Steering Engine 4后
//sbit JS3L 	= P3^4;	//Steering Engine 6夹紧
//sbit JS3R 	= P3^5;	//Steering Engine 6放松
//-------------------------

/*//PWM输出定义：
sbit PWM1 	= P1^0;	//Steering Engine 1
sbit PWM2 	= P1^1;	//Steering Engine 2
sbit PWM3 	= P1^2;	//Steering Engine 3
sbit PWM4 	= P1^3;	//Steering Engine 4
sbit PWM5 	= P1^4;	//Steering Engine 5
sbit PWM6 	= P2^5;	//Steering Engine 6
*/
//-------------------------------------------------
// sbit PWM7 	= P2^6;	//Steering Engine 1
// sbit PWM8 	= P2^7;	//Steering Engine 2
// sbit PWM9 	= P4^4;	//Steering Engine 3
// sbit PWM10 	= P4^5;	//Steering Engine 4
// sbit PWM11 	= P4^6;	//Steering Engine 5
// sbit PWM12 	= P0^7;	//Steering Engine 6
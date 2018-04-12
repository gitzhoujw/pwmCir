/*-----------------------------------------------
  ���ƣ��������	
 
  ��д��shifang
  ���ڣ�2014.6.10
  �޸ģ���
  ���ݣ�ͨ��������������Ƕȣ���������� 20ms���ڣ��ߵ�ƽʱ���0.5ms~2.5ms,���Χ�����ݲ�ͬ�������
------------------------------------------------*/
#include<reg52.h>
#include "delay.h"
#include "mydefine.h"

#define step 5

sbit OUT1 = P1^0;
sbit OUT2=P1^1;
sbit OUT3=P1^2;
sbit OUT4=P1^3;
sbit OUT5=P1^4;
sbit OUT6=P1^5;


sbit KEY1=P2^0;  //���尴������˿�
sbit KEY2=P2^1;
sbit KEY3=P2^2;
sbit KEY4=P2^3;


unsigned char TH_H,TL_H,TH_L,TL_L;//
unsigned char keynum,pwmnum=1,change_flag=0;
unsigned int  temp,count_pwm1=1500,count_pwm2=1500,count_pwm3=1500,count_pwm4=1500,count_pwm5=1500,count_pwm6=1500;
unsigned char countpwm[6],temphh,temphl,templh,templl;

unsigned char KeyScan(void);
void keypro();
void circle(unsigned char);
/*------------------------------------------------
                    ��ʱ����ʼ���ӳ���
------------------------------------------------*/
void Init_Timer0(void)
{
 TMOD |= 0x10;	  //ʹ��ģʽ1��16λ��ʱ����ʹ��"|"���ſ�����ʹ�ö����ʱ��ʱ����Ӱ��	TOMD = TOMD | 0X01	     
 TH1=0x00;	      //������ֵ������ʹ�ö�ʱ�����ֵ��0��ʼ����һֱ��65535���
 TL1=0x00;
 EA=1;            //���жϴ�
 ET1=1;           //��ʱ���жϴ�
 TR1=1;           //��ʱ�����ش�
}
/*------------------------------------------------
                 ���ݴ���
------------------------------------------------*/
void DataPro(unsigned int temp)
{
 	 TH_H=(65536-temp)/256;
     TL_H=(65536-temp)%256;
	 TH_L=(46536+temp)/256;
	 TL_L=(46536+temp)%256;
}
/*------------------------------------------------
                 ������
------------------------------------------------*/
main()
{
	temp=count_pwm1;
  Init_Timer0();
  DataPro(temp);
  while(1)
     {
		  keynum=KeyScan();
		  if(keynum==1)
		  {
		  	pwmnum++;
			change_flag=1;
			if(pwmnum==7) pwmnum=1;
		  }
		  if(keynum==2)
		  {
		  	pwmnum--;
			change_flag=1;
			if(pwmnum==0) pwmnum=6;
		  }
		  temphh=TH_H;temphl=TH_L;templh=TL_H;templl=TL_L;
	 circle(pwmnum);
	 }
}

/*------------------------------------------------
                 ��ʱ���ж��ӳ���
------------------------------------------------*/
void Timer1_isr(void) interrupt 3
{
	switch(pwmnum)
	{
		case 1:{
			if(OUT1)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT1=!OUT1;
		};break;
		case 2:
		{
             if(OUT2)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT2=!OUT2;			
		}break;
		case 3:
		{
             if(OUT3)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT3=!OUT3;			
		}break;
		case 4:
		{
             if(OUT4)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT4=!OUT4;			
		}break;
		case 5:
		{
             if(OUT5)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT5=!OUT5;			
		}break;
		case 6:
		{
             if(OUT6)
			 {
			 TH1=TH_L;		  //���¸�ֵ
			 TL1=TL_L;
			 }
			else
			 {
			  TH1=TH_H;		  //���¸�ֵ
			  TL1=TL_H;
			  }
			OUT6=!OUT6;			
		}break;
	}
	keynum=0;
}

/*------------------------------------------------
            ����ɨ�躯��������ɨ���ֵ
------------------------------------------------*/
unsigned char KeyScan(void)
{
/********************************************************/  
if(!KEY1)  //�����⵽�͵�ƽ��˵����������
    {
	 DelayMs(10); //��ʱȥ����һ��10-20ms
     if(!KEY1)     //�ٴ�ȷ�ϰ����Ƿ��£�û�а������˳�
	   {
        while(!KEY1);//���ȷ�ϰ��°����ȴ������ͷţ�û�����˳�
	       {
		   return 1;
	 		}
	   }
	}
/********************************************************/  
else if(!KEY2)  //�����⵽�͵�ƽ��˵����������
    {
	 DelayMs(10); //��ʱȥ����һ��10-20ms
     if(!KEY2)     //�ٴ�ȷ�ϰ����Ƿ��£�û�а������˳�
	   {
        while(!KEY2);//���ȷ�ϰ��°����ȴ������ͷţ�û�����˳�
	       {
		   return 2;
	 		}
	   }
	}
/********************************************************/  
else if(!KEY3)  //�����⵽�͵�ƽ��˵����������
    {
	 DelayMs(10); //��ʱȥ����һ��10-20ms
     if(!KEY3)     //�ٴ�ȷ�ϰ����Ƿ��£�û�а������˳�
	   {
 //       while(!KEY3);//���ȷ�ϰ��°����ȴ������ͷţ�û�����˳�
	       {
		   return 3;
	 		}
	   }
	}
/********************************************************/  
else if(!KEY4)  //�����⵽�͵�ƽ��˵����������
    {
	 DelayMs(10); //��ʱȥ����һ��10-20ms
     if(!KEY4)     //�ٴ�ȷ�ϰ����Ƿ��£�û�а������˳�
	   {
    //    while(!KEY4);//���ȷ�ϰ��°����ȴ������ͷţ�û�����˳�
	       {
		   return 4;
	 		}
	   }
	}
else return 0;
}  



void circle(unsigned char pwmnum)
{
	switch(pwmnum)
	{
		case 1: 
		{
			P0=0xfe;
		  if(keynum==3)
		    {
			 if(count_pwm1<CountMax_PWM1)
			   count_pwm1+=step;
			}
		  else if(keynum==4)
		   {
		     if(count_pwm1>CountMin_PWM1)
			   count_pwm1-=step;
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm1);
				}
				change_flag=0;		   		
		};break;
		case 2:
		{
			P0=0xfd;
		  if(keynum==3)
		    {
			 if(count_pwm2<CountMax_PWM2)
			   count_pwm2+=step;
//	         DataPro(count_pwm3);
			}
		  else if(keynum==4)
		   {
		     if(count_pwm2>CountMin_PWM2)
			   count_pwm2-=step;
//			 DataPro(count_pwm3);
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm2);
				}
				change_flag=0;
		};break;
		case 3:
		{
			P0=0xfb;
		  if(keynum==3)
		    {
			 if(count_pwm3<CountMax_PWM3)
			   count_pwm3+=step;
//	         DataPro(count_pwm3);
			}
		  else if(keynum==4)
		   {
		     if(count_pwm3>CountMin_PWM3)
			   count_pwm3-=step;
//			 DataPro(count_pwm3);
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm3);
				}
				change_flag=0;
		}break;
		case 4:
		{
			P0=0xf7;
		  if(keynum==3)
		    {
			 if(count_pwm4<CountMax_PWM4)
			   count_pwm4+=step;
//	         DataPro(count_pwm4);
			}
		  else if(keynum==4)
		   {
		     if(count_pwm4>CountMin_PWM4)
			   count_pwm4-=step;
//			 DataPro(count_pwm4);
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm4);
				}
				change_flag=0;
		};break;
		case 5:
		{
			P0=0xef;
		  if(keynum==3)
		    {
			 if(count_pwm5<CountMax_PWM5)
			   count_pwm5+=step;
//	         DataPro(count_pwm5);
			}
		  else if(keynum==4)
		   {
		     if(count_pwm5>CountMin_PWM5)
			   count_pwm5-=step;
//			 DataPro(count_pwm5);
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm5);
				}
				change_flag=0;
		};break;
		case 6:
		{
			P0=0xdf;
		  if(keynum==3)
		    {
			 if(count_pwm6<CountMax_PWM6)
			   count_pwm6+=step;
//	         DataPro(count_pwm6);
			}
		  else if(keynum==4)
		   {
		     if(count_pwm6>CountMin_PWM6)
			   count_pwm6-=step;
//			 DataPro(count_pwm6);
		   }
			   if(change_flag)
			   {TH_H=temphh;TH_L=temphl;TL_H=templh;TL_L=templl;}
	            else 
				{
				DataPro(count_pwm6);
				}
				change_flag=0;
		};break;
	}

	keynum=0;
}

#include "MyI2C.h"

//#define SLCGPIO GPIOB
//#define SLCGPIOPIN GPIO_PIN_12
//#define SDAGPIO GPIOB
//#define SDAGPIOPIN GPIO_PIN_13




I2C_Device MyI2C_Init(GPIO_TypeDef *SLCGPIO_,GPIO_TypeDef *SDAGPIO_,uint16_t SLCGPIOPIN_,uint16_t SDAGPIOPIN_)
{
	I2C_Device newdevice;
*(newdevice.SLCGPIO_)=*SLCGPIO_;
*(newdevice.SDAGPIO_)=*SDAGPIO_;
newdevice.SLCGPIOPIN_=SLCGPIOPIN_;
newdevice.SDAGPIOPIN_=SDAGPIOPIN_;
	return newdevice;
}

 void MyI2C_W_SCL(int x,I2C_Device* Device )
 {
	 if(x!=0)
	 {
 	 HAL_GPIO_WritePin(Device->SLCGPIO_,Device->SLCGPIOPIN_,GPIO_PIN_SET);//SCL
	 }
	 else{
		  HAL_GPIO_WritePin(Device->SLCGPIO_,Device->SLCGPIOPIN_,GPIO_PIN_RESET);//SCL
	 }
	 delay_us(20);
 }
 

 void MyI2C_W_SDA(int x,I2C_Device* Device) 
 {
	 if(x!=0)
	 {
	 HAL_GPIO_WritePin(Device->SDAGPIO_,Device->SDAGPIOPIN_,GPIO_PIN_SET);//SDA
	 }
	 else{
		  HAL_GPIO_WritePin(Device->SDAGPIO_,Device->SDAGPIOPIN_,GPIO_PIN_RESET);//SDA
	 }
	  delay_us(20);
 }
 
 uint8_t MyI2C_R_SDA(I2C_Device* Device)
 {
	 uint8_t bitvalue;

	 if(HAL_GPIO_ReadPin( Device->SDAGPIO_,Device->SDAGPIOPIN_)==RESET)	{bitvalue=0;}
	 else bitvalue=1;
	delay_us(1);
	 return bitvalue;
 }
 
 
 void MyI2C_Start(I2C_Device* Device)
 {
	 MyI2C_W_SDA(1,Device); 
	MyI2C_W_SCL(1,Device);
	 MyI2C_W_SDA(0,Device); 
	 MyI2C_W_SCL(0,Device);
 }	 
 
 void MyI2C_Stop(I2C_Device* Device)
 {
	 MyI2C_W_SDA(0,Device);
	 MyI2C_W_SCL(1,Device);
	 MyI2C_W_SDA(1,Device);
 }
 
 void MyI2C_SendByte(uint8_t Byte,I2C_Device* Device)
 {
	 uint8_t i;
	 for(i=0;i<8;i++)
	 {
	 if((Byte & (0x80>>i))!=0x00)MyI2C_W_SDA(1,Device);
	 else MyI2C_W_SDA(0,Device);
	
	 MyI2C_W_SCL(1,Device);
	 MyI2C_W_SCL(0,Device);
   }
 }
 
 uint8_t MyI2C_ReceiveByte(I2C_Device* Device)
 {
	 uint8_t i,Byte=0x00;
	 MyI2C_W_SDA(1,Device);
	 for(i=0;i<8;i++)
	 {
	 MyI2C_W_SCL(1,Device);
		 if(MyI2C_R_SDA(Device)==1){Byte|=(0x80>>i);}
		 MyI2C_W_SCL(0,Device);
	 }
	 return Byte;
 }
 
 
 void MyI2C_SendAck(uint8_t AckByte,I2C_Device* Device)
 {

   MyI2C_W_SDA(AckByte,Device);
	 MyI2C_W_SCL(1,Device);
	 MyI2C_W_SCL(0,Device);
  
 }
 
 uint8_t MyI2C_ReceiveAck(I2C_Device* Device)
 {
	 uint8_t AckByte;
	 MyI2C_W_SDA(1,Device);
	 MyI2C_W_SCL(1,Device);
	 AckByte=MyI2C_R_SDA(Device);
	 MyI2C_W_SCL(0,Device);
	 return AckByte;
 }
 

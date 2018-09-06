/*************************************************
   MotorCar测试程序
   5、6引脚控制前进后退
   9、10引脚控制左右转向
   8脚控制舵机

   前进2s
   后退2s
   左前进2s
   左后退2s
   右前进2s
   右后退2s
   停止2s

   created 2018.8.26
   by xulei
*************************************************/

#include "MotorCar.h"   //包含头文件
#include "Ultrasonic.h"
#include <Servo.h>
#include <MsTimer2.h> //定时器库的 头文件

Servo myservo;
MotorCar Motor(5, 6, 3, 11); //定义MotorCar类的对象
Ultrasonic Ultrasonic(A0, A1);

int i = 0;
int flag = 0;
int count = 0;
float dist[3] = {0};
int data[4] = {0, 1, 2, 1};

#define LEFT 		0
#define STRAGHT 	1
#define RIGHT 		2

#define DELAY_TIME 200

void flash();
void display_data(int drctn);
int judge_direction();
void motor_run(int drctn);


void setup()
{
	Serial.begin(9600);
	myservo.attach(9);  // 舵机控制信号引脚
	myservo.writeMicroseconds(1300);  // set servo to mid-point
	delay(1000);
	Motor.stopCar();

	pinMode(13, OUTPUT);
	// 中断设置函数，每 500ms 进入一次中断
	MsTimer2::set(500, flash);
	//开始计时
	MsTimer2::start();
}

void loop()
{
  int drctn = 0;
  
  serial_deal();

	dist[data[i]] = Ultrasonic.distance();

  drctn = judge_direction();
  display_data(drctn);
  motor_run(drctn);
  
	delay(DELAY_TIME);
}


//中断处理函数，改变灯的状态
void flash()
{
  static boolean output = HIGH;
  digitalWrite(13, output);
  output = !output;

  i++;
  if (i > 3) i = 0;
  
  switch (data[i])
  {
    case LEFT:
      myservo.writeMicroseconds(1800);  // set servo to end-point（指向左边）
      break;
    case STRAGHT:
      myservo.writeMicroseconds(1300);  // set servo to mid-point（指向中间）
      break;
    case RIGHT:
      myservo.writeMicroseconds(900);  // set servo to end-point（指向右边）
      break;
    default:
      break;
  }

  count = 0;
  dist[data[i]] = 0;
}

void serial_deal()
{
  if (Serial.available())
  {
    char val = Serial.read();
    if (val == 's')
    {
      MsTimer2::stop();
      Serial.println(val);
    } else if (val == 'r')
    {
      MsTimer2::start();
      Serial.println(val);
    }
  } 
}

int judge_direction()
{
  float tmp = 0;
  int drctn = STRAGHT;
  if (dist[0] > tmp)
  {
    tmp = dist[0];
    drctn = LEFT;
  }
  if (dist[1] > tmp)
  {
    tmp = dist[1];
    drctn = STRAGHT;
  }
  if (dist[2] > tmp)
  {
    tmp = dist[2];
    drctn = RIGHT;
  }

   return drctn;
}

void motor_run(int drctn)
{
  if (dist[0] < 10 || dist[1] < 10 || dist[2] < 10)
  {
    Motor.forward(0);
    return;
  }

  if (drctn == 0)
  {
    Motor.left(180);
    Motor.forward(80); //前进
  }

  if (drctn == 1)
  {
    Motor.forwardLine(); //方向
    Motor.forward(100); //前进
  }

  if (drctn == 2)
  {
    Motor.right(150);
    Motor.forward(100); //前进
  }
}

void display_data(int drctn)
{
  switch (data[i])
  {
    case LEFT:
      Serial.print("左：");
      break;
    case STRAGHT:
      Serial.print("前：");
      break;
    case RIGHT:
      Serial.print("右：");
      break;
    default:
      break;
  }
  Serial.print(dist[data[i]]);
  Serial.print(" ");
  switch (drctn)
  {
    case LEFT:
      Serial.println("左转");
      break;
    case STRAGHT:
      Serial.println("前进");
      break;
    case RIGHT:
      Serial.println("右转");
      break;
    default:
      break;
  }
}


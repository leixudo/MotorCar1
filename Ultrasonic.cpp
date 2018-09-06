#include "Ultrasonic.h"
#include "Arduino.h"
/***************************************************
   Ultrasonic类构造函数
   函数功能：定义用于控制超声波的引脚
   入口参数：_trig,表示控制触发的引脚
             _echo.表示控制接收的引脚

    created  2018.8.26
    by xulei
 ***************************************************/
Ultrasonic::Ultrasonic(int _trig, int _echo)
{
  _trigPin = _trig;
  _echoPin = _echo;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}
/***************************************************
   distance子函数
   函数功能：测量距离函数
   入口参数：无
   返回参数：distance
 ***************************************************/
float Ultrasonic::distance()
{
  float distance;
  //测量距离，返回数值
  digitalWrite(_trigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  distance = float( pulseIn(_echoPin, HIGH) * 17 )/1000; //将回波时间换算成cm
  //读取一个引脚的脉冲（HIGH或LOW）。例如，如果value是HIGH，pulseIn()会等待引脚变为HIGH，开始计时，再等待引脚变为LOW并停止计时。
  //返回脉冲的长度，单位微秒。如果在指定的时间内无脉冲函数返回。
  //此函数的计时功能由经验决定，长时间的脉冲计时可能会出错。计时范围从10微秒至3分钟。（1秒=1000毫秒=1000000微秒）
  //接收到的高电平的时间（us）* 340m/s / 2 = 接收到高电平的时间（us） * 17000 cm / 1000000 us = 接收到高电平的时间 * 17 / 1000  (cm)
  if (distance > 100)
    distance = 100;
  return distance;
}

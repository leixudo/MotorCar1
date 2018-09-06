#include "motorCar.h"
#include "Arduino.h"
/***************************************************
   MotorCar类构造函数
   函数功能：定义用于控制电机的引脚
   入口参数：_spa,表示控制前进后退的引脚A
             _spb.表示控制前进后退的引脚B 
             _apa,表示控制转向的引脚A
             _apb,表示控制转向的引脚B

    created  2018.8.26
    by xulei 
 ***************************************************/
 MotorCar::MotorCar(int _spa, int _spb, int _apa, int _apb)
{
     _speedPinA=_spa;
     _speedPinB=_spb;
     _anglePinA=_apa;
     _anglePinB=_apb;
     pinMode(_speedPinA,OUTPUT);
     pinMode(_speedPinB,OUTPUT);
     pinMode(_anglePinA,OUTPUT);
     pinMode(_anglePinB,OUTPUT);
}
/***************************************************
   forward子函数----前进子函数
   函数功能：控制车前进
   入口参数：_speed----前进速度，范围53---255
 ***************************************************/
void MotorCar::forward(int _speed)
{
  //正转，速度可调整
  analogWrite(_speedPinA, _speed);
  digitalWrite(_speedPinB, LOW);
}
/***************************************************
   back子函数----后退子函数
   函数功能：控制车后退
   入口参数：_speed----后退速度，范围53---255
 ***************************************************/
void MotorCar::back(int _speed)
{
  //正转，速度可调整
  analogWrite(_speedPinB, _speed);
  digitalWrite(_speedPinA, LOW);
}

/***************************************************
   left子函数----车轮左转车不动子函数
   函数功能：控制车轮左转
   入口参数：_angle----左转角度，范围60---150
 ***************************************************/
void MotorCar::left(int _angle)
{
  //左转，角度可调整
  analogWrite(_anglePinA, _angle);
  digitalWrite(_anglePinB, LOW);
}

/***************************************************
   turnLeft子函数----左转子函数
   函数功能：控制车左转
   入口参数：_angle----左转角度，范围60---150
             _speed----前进速度，范围53---255
 ***************************************************/
void MotorCar::turnLeft(int _angle, int _speed)
{
  //左转，角度可调整
  analogWrite(_anglePinA, _angle);
  digitalWrite(_anglePinB, LOW);
  //正转，速度可调整
  analogWrite(_speedPinA, _speed);
  digitalWrite(_speedPinB, LOW);
}

/***************************************************
   right子函数----车轮右转子函数
   函数功能：控制车轮右转，车不动
   入口参数：_angle----右转角度，范围60---150
 ***************************************************/
void MotorCar::right(int _angle)
{
  //右转，角度可调整
  analogWrite(_anglePinB, _angle);
  digitalWrite(_anglePinA, LOW);
}

void MotorCar::forwardLine()
{
  //右转，角度可调整
  digitalWrite(_anglePinB, LOW);
  digitalWrite(_anglePinA, LOW);
}
/***************************************************
   turnRight子函数----右转子函数
   函数功能：控制车右转
   入口参数：_angle----右转角度，范围60---150
             _speed----前进速度，范围53---255
 ***************************************************/
void MotorCar::turnRight(int _angle, int _speed)
{
  //右转，角度可调整
  analogWrite(_anglePinB, _angle);
  digitalWrite(_anglePinA, LOW);
  //正转，速度可调整
  analogWrite(_speedPinA, _speed);
  digitalWrite(_speedPinB , LOW);
}

/***************************************************
   backLeft子函数----左后退子函数
   函数功能：控制车左后退
   入口参数：_angle----左转角度，范围60---150
             _speed----前进速度，范围53---255
 ***************************************************/
void MotorCar::backLeft(int _angle, int _speed)
{
  //左转，角度可调整
  analogWrite(_anglePinA, _angle);
  digitalWrite(_anglePinB, LOW);
  //反转，速度可调整
  analogWrite(_speedPinB, _speed);
  digitalWrite(_speedPinA, LOW);
}


/***************************************************
   backRight子函数----右后退子函数
   函数功能：控制车右后退
   入口参数：_angle----左转角度，范围60---150
             _speed----前进速度，范围53---255
 ***************************************************/
void MotorCar::backRight(int _angle, int _speed)
{
  //右转，角度可调整
  analogWrite(_anglePinB, _angle);
  digitalWrite(_anglePinA, LOW);
  //反转，速度可调整
  analogWrite(_speedPinB, _speed);
  digitalWrite(_speedPinA, LOW);
}

/***************************************************
   stopCar子函数----停止子函数
   函数功能：控制车停止
   入口参数：无
 ***************************************************/
void MotorCar::stopCar()
{
  //角度归零，待机
  digitalWrite(_anglePinA, LOW);
  digitalWrite(_anglePinA, LOW);
  //前进/后退停止
  digitalWrite(_speedPinA, LOW);
  digitalWrite(_speedPinB, LOW);
}

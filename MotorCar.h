/**************************************************
   文件名：MotorCar.h
   越野车控制类库

   created 2018.8.25
   by xulei
 **************************************************/
#ifndef MotorCar_h
#define MotorCar_h

class MotorCar
{
  private:    //定义为私有
    int _speedPinA;  //定义控制前进后退的引脚A
    int _speedPinB;  //定义控制前进后退的引脚B
    int _anglePinA;  //定义控制转向的引脚A
    int _anglePinB;  //定义控制转向的引脚B
  public:    //定义为公有
    MotorCar(int _spa, int _spb, int _apa, int _apb);  //构造函数
    void forward(int _speed);              //前进函数
    void back(int _speed);                 //后退函数
    void turnLeft(int _angle, int _speed); //左转函数
    void turnRight(int _angle, int _speed); //右转函数
    void backLeft(int _angle, int _speed);  //左后退函数
    void backRight(int _angle, int _speed); //右后退函数
    void left(int _angle);                  //轮子左转函数，车不动
    void right(int _angle);                 //轮子右转函数，车不动
    void forwardLine();
    void stopCar();                         //停止
};

#endif

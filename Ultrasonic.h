/**************************************************
 * 文件名：Ultrasonic.h
 * 超声波控制类库
 * 
 * created 2018.8.26
 * by xulei
 **************************************************/
 #ifndef Ultrasonic_h
 #define Ultrasonic_h

 class Ultrasonic
 {
  private:               //定义为私有
          int _trigPin;  //定义触发的引脚
          int _echoPin;  //定义接收的引脚
  public:     //定义为公有
          Ultrasonic(int _trig, int _echo);  //构造函数
          float distance();                   //距离函数
 };  

 #endif

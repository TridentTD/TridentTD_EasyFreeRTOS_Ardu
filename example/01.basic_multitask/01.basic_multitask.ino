#include <TridentTD_EasyFreeRTOS_Ardu.h>

TridentOS   task1, task2;            // ประกาศตัวแปร task
void myblink(void*), myprint(void*); // ฟังกชั่นที่ task จะเรียกทำงาน

//----พื้นที่ส่วนนี้สำหรับประกาศตัวแปรที่ใช้แชร์ข้อมูลกันระหว่าง task ------

//---------------------------------------------------------

void setup() {
  Serial.begin(115200); Serial.println();
  task1.start( myblink );     // เริ่ม task แรก ให้ไปเรียก myblink ทำงาน
  task2.start( myprint );     // เริ่ม task สอง ให้ไปเรียก myprint ทำงาน
}

void loop() {}                // ไม่ต้องใช้อีกต่อไปแต่มีไว้


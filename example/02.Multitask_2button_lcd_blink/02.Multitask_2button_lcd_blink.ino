#include <TridentTD_EasyFreeRTOS_Ardu.h>

// กำหนดตัวแปร task และ function ที่จะเรียกทำงาน
TridentOS   BT1_task, BT2_task, Blink_task, LCD_task;
void  BT1_func(void*), BT2_func(void*), Blink_func(void*), LCD_func(void*);

//---พื้นที่สำหรับตัวแปรที่ใช้ share กันระหว่าง task-----
uint8_t   xBlink_type;   // 0: กระพริบช้า, 1: กระพริบเร็ว
//--------------------------------------------

void setup() {  // setup หลัก ตัวพิมพ์เล็ก
  Serial.begin(115200); Serial.println();

  BT1_task.start(BT1_func,NULL,56);      // task สำหรับ จัดการรับค่ากดปุ่ม แรก
  BT2_task.start(BT2_func,NULL,56);      // task สำหรับ จัดการรับค่ากดปุ่ม สอง
  Blink_task.start(Blink_func,NULL,48);  // task สำหรับ จัดการ ไฟกระพริบ
  LCD_task.start(LCD_func,NULL,128);     // task สำหรับ จัดการ หน้าจอ LCD
}

void loop() {}  // loop() หลักตัวพิมพ์เล็ก ห้ามใช้ แต่ให้มีไว้


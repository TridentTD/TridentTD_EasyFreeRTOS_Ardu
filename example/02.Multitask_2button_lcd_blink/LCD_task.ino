/*********************************************************
 * 
 * Task สำหรับ จัดการ หน้าจอ LCD
 * 
 *********************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

void LCD_func(void*) {    // void ใช้พิมพ์เล็ก
  //---พื้นที่สำหรับใช้ใน task นี้เท่านั้น-----
  LiquidCrystal_I2C lcd(0x27,16,2); // ตัวแปร lcd แบบหน้าจอ 16x2 โดยใช้ I2C address 0x27
  //--------------------------------
  
  VOID SETUP(){   // VOID SETUP ใน task ใช้พิมพ์ใหญ่
    lcd.init();
    lcd.backlight();
    lcd.print("Hello, MultiTask!");
    DELAY(2000);  // DELAY(..) ใน task ใช้พิมพ์ใหญ่
  }
  VOID LOOP(){    // VOID LOOP ใน task ใช้พิมพ์ใหญ่
    lcd.clear();
    switch( xBlink_type){  // blink_type เป็นตัวแปรที่ใช้ share ระหว่าง task
      case 0: //กระพริบช้า
        lcd.print("Blink Slow...");
        break;
      case 1: //กระพริบเร็ว
        lcd.print("Blink Fast!");
        break;
    }
    DELAY(50);    // DELAY(..) ใน task ใช้พิมพ์ใหญ่
  }
}

/*
 * หมายเหตุ หากมีการใช้ delay() ใน task ในเปลี่ยนเป็น DELAY(..) พิมพ์ใหญ่ทั้งหมด
 */


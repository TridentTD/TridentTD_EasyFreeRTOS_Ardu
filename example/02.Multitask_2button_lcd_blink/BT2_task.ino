/*********************************************************
 * 
 * Task สำหรับ จัดการ การกดปุ่ม สอง
 * 
 *********************************************************/

void BT2_func(void*) {    // void ใช้พิมพ์เล็ก
  //---พื้นที่สำหรับใช้ใน task นี้เท่านั้น-----
  #define BT2     11      // ปุ่มสอง ใช้ขา pin 11
  //--------------------------------
  VOID SETUP(){   // VOID SETUP ใน task ใช้พิมพ์ใหญ่
    pinMode( BT2, INPUT);
  }
  VOID LOOP(){    // VOID LOOP ใน task ใช้พิมพ์ใหญ่
    if( digitalRead (BT2) == HIGH ){
      xBlink_type = 1;  // blink_type เป็นตัวแปรที่ใช้ share ระหว่าง task
      Blink_task.start(Blink_func);
    }
  }
}

/*
 * หมายเหตุ หากมีการใช้ delay() ใน task ในเปลี่ยนเป็น DELAY(..) พิมพ์ใหญ่ทั้งหมด
 */


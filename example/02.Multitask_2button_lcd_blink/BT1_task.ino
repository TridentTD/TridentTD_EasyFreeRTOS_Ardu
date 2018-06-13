/*********************************************************
 * 
 * Task สำหรับ จัดการ การกดปุ่ม แรก
 * 
 *********************************************************/

void BT1_func(void*) {    // void ใช้พิมพ์เล็ก
  //---พื้นที่สำหรับใช้ใน task นี้เท่านั้น-----
  #define BT1     10      // ปุ่มแรก ใช้ขา pin 10
  //--------------------------------
  VOID SETUP(){   // VOID SETUP ใน task ใช้พิมพ์ใหญ่
    pinMode( BT1, INPUT);
  }
  VOID LOOP(){    // VOID LOOP ใน task ใช้พิมพ์ใหญ่
    if( digitalRead (BT1) == HIGH ){
      xBlink_type = 0;  // blink_type เป็นตัวแปรที่ใช้ share ระหว่าง task
      Blink_task.start(Blink_func);
    }
  }
}

/*
 * หมายเหตุ หากมีการใช้ delay() ใน task ในเปลี่ยนเป็น DELAY(..) พิมพ์ใหญ่ทั้งหมด
 */


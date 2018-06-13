/*********************************************************
 * 
 * Task สำหรับ จัดการ ไฟกระพริบ
 * 
 *********************************************************/

void Blink_func(void*) {    // void ใช้พิมพ์เล็ก
  //---พื้นที่สำหรับใช้ใน task นี้เท่านั้น-----
  #define Blink_LED     13
  int blink_delay = 1000;
  //--------------------------------
  
  VOID SETUP(){   // VOID SETUP ใน task ใช้พิมพ์ใหญ่
    pinMode( Blink_LED, OUTPUT);
    switch( xBlink_type){  // xBlink_type เป็นตัวแปรที่ใช้ share ระหว่าง task
      case 0: //กระพริบช้า
        blink_delay = 1000;
        break;
      case 1: //กระพริบเร็ว
        blink_delay = 80;
        break;
    }
  }
  VOID LOOP(){    // VOID LOOP ใน task ใช้พิมพ์ใหญ่
    digitalWrite( Blink_LED, HIGH);
    DELAY( blink_delay);    // DELAY(..) ใน task ใช้พิมพ์ใหญ่
    digitalWrite( Blink_LED, LOW);
    DELAY( blink_delay);    // DELAY(..) ใน task ใช้พิมพ์ใหญ่
  }
}

/*
 * หมายเหตุ หากมีการใช้ delay() ใน task ในเปลี่ยนเป็น DELAY(..) พิมพ์ใหญ่ทั้งหมด
 */


#include <TridentTD_EasyFreeRTOS_Ardu.h>

EasyFreeRTOS_Ardu task1, task2, task3, task4, task5; //จะเพิ่มกี่ task ให้เพิ่มตรงนี้

void  task1_func(void*), task2_func(void*),       // ฟังกชั่นที่ task จะเรียกทำงาน
      task3_func(void*), task4_func(void*), task5_func(void*);

//----พื้นที่ส่วนนี้สำหรับประกาศตัวแปรที่ใช้แชร์ข้อมูลกันระหว่าง task ------


//---------------------------------------------------------

void setup(){  // setup() หลัก ใช้ตัวพิมพ์เล็ก
  Serial.begin(115200); Serial.println();

  task1.start( task1_func );  // เรียก task1_func ขึ้นมาทำงาน
  task2.start( task2_func );	// เรียก task2_func ขึ้นมาทำงาน
}

void loop(){}  // loop() หลักใช้ตัวพิมพ์เล็ก

/*
 * หมายเหตุ
 *   - ใน setup() หลัก ไม่พึงให้มีการทำงานอย่างอื่นใด
 *     นอกจาก เรียก task ที่ต้องการขึ้นมาทำงาน
 *   - ใน loop() หลัก  ไม่พึงให้มีการทำงานอย่างอื่นใดๆเลย
 *   - ใน task นึงๆ สามารถเรียก task อื่นๆ ขึ้นมาทำงาน ก็ได้
 *     เช่น สามารถเรียก task3.begin( task3_func); ขึ้นมาทำงานจากภายใน task1 ได้
 *   - หากจะหยุด task หลังทำงานไปแล้ว
 *     เช่น หยุดการทำงาน task3  ก็ใช้คำสั่ง  task3.stop();
 *   - หากจะให้กลับมาทำงานใหม่ ก็เรียก task3.resume();
 */

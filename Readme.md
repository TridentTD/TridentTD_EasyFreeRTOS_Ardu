TridentTD_EasyFreeRTOS_Ardu Library
===

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
ไลบรารี่สำหรับ เขียนแบบ Multitasking แบบ TridentTD บนเพรตฟอร์ม Arduino  
อาทิ Arduino UNO , Arduino Mega เป็นต้น

<p align="center">
  <img src="Picture.png" alt="image"/>
</p>  

### วิธีการใช้งาน  

1. เรียกใช้ไลบรารี่  
```c  
     #include <TridentTD_EasyFreeRTOS_Ardu.h>
``` 
2. ประกาศตัวแปร task ย่อยๆ และ ฟังกชั่น ที่ task จะเรียกขึ้นทำงาน  
```c  
     EasyFreeRTOS_Ardu  task1, task2, task3;
     void task1_func(void*), task2_func(void*), task3_func(void*);
```
3. รูปแบบมาตรฐาน ฟังก์ชั่น task ย่อยๆ ที่จะถูกเรียกใช้งาน เป็นดังนี้  
```c
    void task1_func(void*)  {   // ฟังกชั่นที่ task1 เรียกทำงาน  - void ใช้ตัวพิมพ์เล็ก
          //----พื้นที่สำหรับประกาศตัวแปรที่ใช้ภายใน task นี้เท่านั้น----

          //-----------------------------------------------

          VOID SETUP() {  // VOID SETUP() ใน task ให้ใช้ตัวพิมพ์ใหญ่

          }
          VOID LOOP() {   // VOID LOOP() ใน task ให้ใช้ตัวพิมพ์ใหญ่

          }
    }

```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
**หมายเหตุ**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
ภายในฟังกชั่น task ให้ใช้ delay ด้วยคำสั่ง DELAY(..) ตัวพิมพ์ใหญ่เท่านั้น  

4. หากจะเรียก task ไหนทำงาน เช่น สำหรับ task1 ใช้คำสั่ง  
```c
     task1.start(task1_func);
```
5. หากจะหยุด task ไหนทำงาน เช่น สำหรับ task1 ใช้คำสั่ง  
```c
     task1.stop();
```
6. หากจะใช้งานต่อ task ไหนทำงาน เช่น สำหรับ task1 ใช้คำสั่ง  
```c
     task1.resume();
```

### การจูนพื้นที่เม็มโมรี่สำหรับ task นึงๆ ใน Arduino UNO
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
เนื่องจาก Arduino Uno เป็น MCU ขนาด 8bit มีพื้นที่เม็มโมรี่ในการทำงานที่มีขนาดเล็ก   
บางคราวเราจึงมีความจำเป็นต้องมีการปรับจูนพื้นที่เม็มสำหรับ task นึงๆให้เหมาะสม  
เพื่อให้หลายๆ task สามารถทำงานร่วมกันได้อย่างมีประสิทธิภาพ  
  
วิธีการปรับจูนพื้นที่เม็มโมมี่ สำหรับ task นึงๆสามารถปรับได้ด้วยคำสั่งดังนี้  
```c
     task1.start(task1_func, NULL, 64);  // ขอใช้พื้นที่ขนาดเพียง 64bytes
```



-----
**TridentTD**  
29 พฤษภาคม 2561 (ปีแห่งฤดูฝนตกชุก)  
วันวิสาขบูชา ขึ้น ๑๕ ค่ำเดือน ๗  
แห่งปีอธิกมาส ปีที่มีเดือนแปดสองหน  

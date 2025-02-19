# **Group 2 - DeepDive SIMD**
## **GROUP 2 - S11**

**MEMBERS:**

- Alfred Bastin S. Agustines
- Allan David C. De Leon
- Michael Angelo Depasucat
- Kai Hiori J. Padilla

---

## **Project Overview**
This project involves implementing and comparing the performance of four versions of a kernel:
1. **C Program**
2. **x86-64 Assembly Language (non-SIMD)**
3. **x86 SIMD AVX2 Assembly Language using XMM register**
4. **x86 SIMD AVX2 Assembly Language using YMM register**

The program initializes vectors of size `n = {2^20, 2^26, 2^30}` (or smaller if memory constraints exist) and handles boundary conditions for SIMD operations. Each kernel is executed 30 times, and the average execution time is recorded. Correctness is checked against the C program.

---

### **i.) Screenshot of the Program Output with Execution Time for All Cases**
## **Debug**
  - **C**
    
| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474755074_1768305043952008_2711861187529911297_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475272895_1325767355289146_1545542814377239726_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269360_2164573430681115_1307590721420646016_n.png) |

  - **x86-64 Non-SIMD Assembly**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475194725_1736496846911762_735406358650725671_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475442694_1125300672399420_2517737751647477588_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475385528_1508077773913869_8691960589247389294_n.png) |
      
  - **XMM (SIMD 128-bit)**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/55d76759b54ee4c7d862e49f8a48868a1d99c0c6/BUILD/475723788_2370893926580143_8187849500300075197_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269690_635886395663300_4058106138543798378_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/475038963_599770142770932_4623282796854049379_n.png) |
      
  - **YMM (SIMD 256-bit)**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475446949_2391484044535579_3452130950553545406_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475236189_2430262020654696_1652702669333535164_n.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474723815_549255591483961_3357579152647604848_n.png) |
    
## **Release**
  - **C**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/8142a23e1828befeee5964648c95207c7c509f22/BUILD/C%20Release%2020.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/C%20Release%2026.jpg) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/8142a23e1828befeee5964648c95207c7c509f22/BUILD/C%20Release%2030.jpg) |
    
  - **x86-64 Non-SIMD Assembly**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/x86%20Release%2020.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/x86%20Release%2026.jpg) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/x86%20Release%2030.jpg) |
      
  - **XMM (SIMD 128-bit)**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/XMM%20Release%2020.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/XMM%20Release%2026.jpg) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/XMM%20Release%2030.jpg) |
      
  - **YMM (SIMD 256-bit)**

| Array size (1<<20) | Array size (1<<26) | Array size (1<<30) |
| ------------------ | ------------------ | ------------------ |
| ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/YMM%20Release%2020.png) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/YMM%20Release%2026.jpg) | ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/YMM%20Release%2030.jpg) |

---

### **ii.) Comparative Table of Execution Time and Performance Analysis**

**Debug**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) |
|----------------------|---------------------------|---------------------------|---------------------------|
| **C**                |          5.081043 ms      |        223.711563 ms      |      34487.541990 ms      |
| **x86-64**           |          1.40957 ms       |        71.309053 ms       |      14103.381637 ms      |
| **XMM (128-bit)**    |          1.41296 ms       |        65.470357 ms       |      489.248630 ms        |
| **YMM (256-bit)**    |          1.352737 ms      |        63.203943 ms       |      453.486163 ms        |

**Performance Analysis for Debug (in Comparison to C)**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) |
|----------------------|---------------------------|---------------------------|---------------------------|
| **C**                |          1x      |        1x      |      1x      |
| **x86-64**           |          3.605x      |        3.137x       |      2.445x      |
| **XMM (128-bit)**    |          3.596x      |        3.417x       |      70.491x        |
| **YMM (256-bit)**    |          3.756x      |        3.54x       |      76.05x        |

**Release**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) |
|----------------------|---------------------------|---------------------------|---------------------------|
| **C**                |          1.185313 ms      |        111.227407 ms      |      3002.768260 ms      |
| **x86-64**           |          0.951970 ms       |       106.111647 ms       |      769.962460 ms      |
| **XMM (128-bit)**    |          0.618627 ms       |        80.076593 ms       |      516.745833 ms        |
| **YMM (256-bit)**    |          0.529633 ms      |        71.036623 ms       |      432.863150 ms        |

**Performance Analysis for Release (in Comparison to C)**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) |
|----------------------|---------------------------|---------------------------|---------------------------|
| **C**                |          1x      |        1x      |      1x      |
| **x86-64**           |          1.25×      |        	1.05×       |      3.90×      |
| **XMM (128-bit)**    |          1.92×      |        1.39×       |      	5.81×        |
| **YMM (256-bit)**    |          	2.24×      |        	1.57×       |      6.94×        |

## Performance Analysis

### **How Many Times Faster?**  

The results show that **YMM (256-bit) is the fastest implementation**, with a **6.94x speedup over C for large inputs (n = 2³⁰)**.  
**XMM (128-bit) also performs good, reaching 5.81x speedup**, while **x86-64 is faster but only a bit compared to the other SIMD implementations by 3.90x at n = 2³⁰**.  
These improvements come from **SIMD’s ability to process multiple data points at once**, unlike **C which processes them one at a time**.  

With regards to **Debug mode and Release mode**, **Debug mode is slower than Release mode** because **optimizations are turned off**.  
However, **for smaller inputs, Debug mode can sometimes appear faster** because it **doesn’t apply certain optimizations that may cause alignment issues in Release mode**.  
When **SIMD instructions in Release mode assume proper memory alignment but the code might not be optimized**, **performance can suffer**.  

---

### **Why Is It Faster?**  

**SIMD is much faster than C because it can process multiple numbers at the same time**.  
While **C goes through one multiplication at a time**, **XMM can handle two, and YMM can do four in a single step**.  
This means **the loop runs fewer times**, there's **less overhead**, and **everything is done much faster**.  


Another big reason is **memory access**.  
The C version **keeps reading and writing data from memory**, which slows things down because of **cache misses and waiting for data to load**.  
SIMD avoids this by **doing most of its calculations inside CPU registers**, so **it doesn’t have to wait for memory**.  
**C spends a lot of time just moving data**, while **SIMD gets straight to the calculations, making it way more efficient**.  

---

### **Boundary Handling**

A limitation of **SIMD is that it only works efficiently when the data size is a perfect multiple of its register width** (**2 for XMM, 4 for YMM**). If the dataset **doesn’t fit into the chunks**, there will be **leftover values that can’t be processed in SIMD instructions**. These need to be **handled separately using scalar operations**, which are **slower**.

---

### **iii.) Screenshot of the Program Output with Correctness Check**

### **C Implementation**

  <img src="https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/994562fb12fc836ea42b077cd0c33300f6dceeec/BUILD/c_dotproduct.png" alt="image alt" width="600"/>
    
The program to compute for the dot product in C is a simple for loop that iterates through all the values in the a and b array and gets the sum of the products of both.

---

### **iv.) Screenshot of the Program Output with Correctness Check**
#### **x86-64 Implementation**

   <img src="https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/x86_dotproduct.png" alt="image alt" width="400"/>

The x86-64 program computes for the dot product by loading vector a and b into registers r10 and r11.After that, the r10 and r11 are multiplied to each other, with the results getting added into rax. 8 is then added to r8 and r9 to increment the array index by 1, which is 8 bytes. this whole block of code is then put into a loop for an amount initialized onto rcx.

---

### **v.) Screenshot of the Program Output with Correctness Check**
#### **XMM (SIMD 128-bit) Implementation**

  <img src="https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/082c429005d2d267dd87e09d30aa7e90860aac5c/BUILD/xmm_dotproduct.png" alt="image alt" width="400"/>

The XMM program computes the dot product in a similar way to the x86-64, but with the xmm syntaxes for each instruction. The main difference is that the xmm implementation allows it to compute multiple values at once. The xmm register can process 2 indexes at once, which is why the rbx is subtracted by 2 after each iteration in L1. Following that, the "REMAINING" code block is for the values in vector a and b that do not fit into the xmm register. These values are simply multiplied and added into the overall sum.

---

### **vi.) Screenshot of the Program Output with Correctness Check**
#### **YMM (SIMD 256-bit) Implementation**

  <img src="https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/ymm_dotproduct.png" alt="image alt" width="600"/>

The AVX256 program computes the dot product similarly to the XMM implementation. The way that the L1 loop is set up and the REMAINING block right after are similar in function. The key difference for the AVX256 implementation is that the ymm registers are larger than the xmm registers and can hold twice the value of the xmm register. This means that the iterations can handle up to 4 indexes and the values subtracted to the rcx is now changed to 4. There is also a loop introduced to the REMAINING block since there are more remaining index values that the ymm register cannot process fully. 

---

#### ---**Error Checking**---

  <img src="https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/error__checking.png" alt="image alt" width="500"/>

The error checking for all the programs is done after the execution of all the programs. To verify if the results are correct, the values in C, x86-64, XMM, and YMM are compared to the results from the C program. A print statement is done based on the results of the comparison.

---
### **vii.) Discussion**

We had an "Aha!" moment when we learned how difficult it was to deal with the remaining elements (butal) during SIMD initialization. Because XMM and YMM registers handle fixed-width elements, we needed to load as many elements as possible into YMM (4 for 64-bit values) and XMM (2 for 64-bit values). We made use of scalar multiplication to process the remaining elements. For example, out of 10 values, 8 were processed using YMM (4 values per YMM register), while the remaining 2 were handled using scalar (x86) operations.

Another "Aha!" moment occurred in release mode when we discovered a potential infinite loop. We observed that registers were incorrectly saved, resulting in overwrites and instability. We avoided overwrites by employing push-and-pop instructions to preserve non-volatile registers, which stabilized the execution flow.

What surprised me the most was how much faster C got in release mode as a result of compiler optimizations, but debug mode was slower.


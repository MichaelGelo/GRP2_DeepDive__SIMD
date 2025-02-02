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
## **Debugged**
  - **C**
    
      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474755074_1768305043952008_2711861187529911297_n.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475272895_1325767355289146_1545542814377239726_n.png)

      Array size (1<<30)
      
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269360_2164573430681115_1307590721420646016_n.png)
    
  - **x86-64 Non-SIMD Assembly**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475194725_1736496846911762_735406358650725671_n.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475442694_1125300672399420_2517737751647477588_n.png)

      Array size (1<<30)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475385528_1508077773913869_8691960589247389294_n.png)
      
  - **XMM (SIMD 128-bit)**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/55d76759b54ee4c7d862e49f8a48868a1d99c0c6/BUILD/475723788_2370893926580143_8187849500300075197_n.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269690_635886395663300_4058106138543798378_n.png)

      Array size (1<<30)
      
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/475038963_599770142770932_4623282796854049379_n.png)
      
  - **YMM (SIMD 256-bit)**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475446949_2391484044535579_3452130950553545406_n.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475236189_2430262020654696_1652702669333535164_n.png)

      Array size (1<<30)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474723815_549255591483961_3357579152647604848_n.png)
    
## **Release**
  - **C**
    
      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/8142a23e1828befeee5964648c95207c7c509f22/BUILD/C%20Release%2020.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/C%20Release%2026.jpg)

      Array size (1<<30)
      
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/8142a23e1828befeee5964648c95207c7c509f22/BUILD/C%20Release%2030.jpg)
    
  - **x86-64 Non-SIMD Assembly**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/x86%20Release%2020.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/x86%20Release%2026.jpg)

      Array size (1<<30)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/x86%20Release%2030.jpg)
      
  - **XMM (SIMD 128-bit)**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/XMM%20Release%2020.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/XMM%20Release%2026.jpg)

      Array size (1<<30)
      
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/XMM%20Release%2030.jpg)
      
  - **YMM (SIMD 256-bit)**

      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/YMM%20Release%2020.png)

      Array size (1<<26)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/60d3544279e246df24da745c40ae7c945aad6450/BUILD/YMM%20Release%2026.jpg)

      Array size (1<<30)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/3737c41a0b4c012eff76a2462217dc072788375e/BUILD/YMM%20Release%2030.jpg)

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
| **C**                |          1.306817 ms      |        111.227407 ms      |      3002.768260 ms      |
| **x86-64**           |          1.761937 ms       |       106.111647 ms       |      769.962460 ms      |
| **XMM (128-bit)**    |          1.134067 ms       |        80.076593 ms       |      516.745833 ms        |
| **YMM (256-bit)**    |          0.902483 ms      |        71.036623 ms       |      432.863150 ms        |

**Performance Analysis for Release (in Comparison to C)**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) |
|----------------------|---------------------------|---------------------------|---------------------------|
| **C**                |          1x      |        1x      |      1x      |
| **x86-64**           |          0.74×      |        	1.05×       |      3.90×      |
| **XMM (128-bit)**    |          1.15×      |        1.39×       |      	5.81×        |
| **YMM (256-bit)**    |          	1.45×      |        	1.57×       |      6.94×        |

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
    
  ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/994562fb12fc836ea42b077cd0c33300f6dceeec/BUILD/c_dotproduct.png)
    

---

### **iv.) Screenshot of the Program Output with Correctness Check**
#### **x86-64 Implementation**

   ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/x86_dotproduct.png)

   
---

### **v.) Screenshot of the Program Output with Correctness Check**
#### **XMM (SIMD 128-bit) Implementation**

  ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/082c429005d2d267dd87e09d30aa7e90860aac5c/BUILD/xmm_dotproduct.png)


---

### **vi.) Screenshot of the Program Output with Correctness Check**
#### **YMM (SIMD 256-bit) Implementation**

  ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/ymm_dotproduct.png)

    
---

#### ---**Error Checking**---

  ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/d88dcf769a3944ccb5e90f4668c62ecfbe2cd415/BUILD/error__checking.png)


---
### **vii.) Discussion**

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
**DEBUGGED**
  - **C**
    
      Array size (1<<20)
    
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474755074_1768305043952008_2711861187529911297_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475272895_1325767355289146_1545542814377239726_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269360_2164573430681115_1307590721420646016_n.png)
    
  - **x86-64 Non-SIMD Assembly**

      Array size (1<<20)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475194725_1736496846911762_735406358650725671_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475442694_1125300672399420_2517737751647477588_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475385528_1508077773913869_8691960589247389294_n.png)
      
  - **XMM (SIMD 128-bit)**

      Array size (1<<20)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/55d76759b54ee4c7d862e49f8a48868a1d99c0c6/BUILD/475723788_2370893926580143_8187849500300075197_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475269690_635886395663300_4058106138543798378_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/475038963_599770142770932_4623282796854049379_n.png)
      
  - **YMM (SIMD 256-bit)**

      Array size (1<<20)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475446949_2391484044535579_3452130950553545406_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/572476b601bcd9711d1ef485ef715be3f31cd290/BUILD/475236189_2430262020654696_1652702669333535164_n.png)
      ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/03cc7ce30d35a979dbded7e1edc7cfbbef8de4fc/BUILD/474723815_549255591483961_3357579152647604848_n.png)
**RELEASE**
---

### **ii.) Comparative Table of Execution Time and Performance Analysis**

**Debug**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) | Performance Analysis |
|----------------------|---------------------------|---------------------------|---------------------------|----------------------|
| **C**                |          5.081043 ms      |        223.711563 ms      |      34487.541990 ms      |                      |
| **x86-64**           |          1.40957 ms       |        71.309053 ms       |      14103.381637 ms      |                      |
| **XMM (128-bit)**    |          1.41296 ms       |        65.470357 ms       |      489.248630 ms        |                      |
| **YMM (256-bit)**    |          1.352737 ms      |        63.203943 ms       |      453.486163 ms        |                      |

**Release**
| Implementation       | Execution Time (n = 2^20) | Execution Time (n = 2^26) | Execution Time (n = 2^30) | Performance Analysis |
|----------------------|---------------------------|---------------------------|---------------------------|----------------------|
| **C**                |                           |                           |                           |                      |
| **x86-64**           |                           |                           |                           |                      |
| **XMM (128-bit)**    |                           |                           |                           |                      |
| **YMM (256-bit)**    |                           |                           |                           |                      |

- **How many times faster**: 

- **Why is it faster**: 

- **Boundary handling**: 

---

### **iii.) Screenshot of the Program Output with Correctness Check**

#### **C Implementation**

---

### **iv.) Screenshot of the Program Output with Correctness Check**
#### **x86-64 Implementation**

---

### **v.) Screenshot of the Program Output with Correctness Check**
#### **XMM (SIMD 128-bit) Implementation**

---

### **vi.) Screenshot of the Program Output with Correctness Check**
#### **YMM (SIMD 256-bit) Implementation**

---

### **vii.) Discussion**

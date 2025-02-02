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
- **C**
 
- **x86-64 Non-SIMD Assembly**
- **XMM (SIMD 128-bit)**

   ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/55d76759b54ee4c7d862e49f8a48868a1d99c0c6/BUILD/475723788_2370893926580143_8187849500300075197_n.png)
- **YMM (SIMD 256-bit)**

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

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
  ![image alt](https://github.com/MichaelGelo/GRP2_DeepDive__SIMD/blob/2490d1ce6876ac6ca6e035f4c169b10eaeffe4e7/475723788_2370893926580143_8187849500300075197_n.png)
- **x86-64 Non-SIMD Assembly**
- **XMM (SIMD 128-bit)**
- **YMM (SIMD 256-bit)**

---

### **ii.) Comparative Table of Execution Time and Performance Analysis**

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

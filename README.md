*This project has been created as part of the 42 curriculum by `adraji`.* # PUSH_SWAP

## 📝 Description

### Mandatory Part:
This project is an intensive exercise in sorting algorithms and performance optimization. The goal is to sort data stored in **Stack A** using an auxiliary **Stack B**, adhering to a specific set of operations and achieving the result with the minimum number of moves. My implementation relies on the **Turk Algorithm** paired with an advanced **Cost Analysis** system.

---

### Bonus Part:
A **Checker** program has been developed to read the executed operations and verify the final sorting integrity. This ensures the algorithm's accuracy and handles all edge cases.

---

## 🛠 Implemented Operations
- **Swap:** `sa`, `sb`, `ss`
- **Push:** `pa`, `pb`
- **Rotate:** `ra`, `rb`, `rr`
- **Reverse Rotate:** `rra`, `rrb`, `rrr`

---

## 🚀 Instructions

* **To compile the push_swap program:**
    * `make`
* **To compile the checker program:**
    * `make bonus`
* **To test the push_swap program:**
    ```bash
    ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
    ```

---

## 📊 Performance Analysis
The algorithm has been optimized to meet the highest efficiency standards of 42. The results are as follows:
- **100 Numbers:** Average moves range between **500 to 600** maximum.
- **500 Numbers:** Average moves range between **5000 to 5100** approximately.

---

## 💡 Algorithm & Data Structure

### 1. Parsing & Special Cases
- **Validation:** Uses `ft_atoi_ilimit` and `ft_check_duplicates` to ensure input integrity and handle large integers.
- **Hard-coded Sort (Small Cases):** To minimize operations, cases with **5 numbers or fewer** are handled separately via the `sort_small` function, which uses hard-coded logic for maximum speed.
- **Retention Strategy:** When pushing elements to Stack B, **5 elements** are kept in Stack A to be sorted locally before initiating the cost-based return process.



### 2. Cost Logic
The algorithm follows the **"Cheapest Move First"** principle:
- **Cost Calculation:** Uses the `t_op` structure to store the number of moves required for each operation, prioritizing shared rotations (`rr`, `rrr`).
- **Reverse Rotate:** Reverse rotation cases are handled with fixed logic to ensure elements reach the top via the shortest path possible.

---

## 📚 Resources
* [Medium - Turk Algorithm Explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
* [Medium - Push Swap Guide](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* [Push_swap Visualizer](https://push-swap42-visualizer.vercel.app/)

### 🤖 Use of AI Disclaimer
Artificial Intelligence was used as a **Thought Partner** to:
- Simplify and understand complex algorithmic concepts and their programmatic implementation.
- Assist in structuring and formatting the **README** file for clarity and professionalism.
- **Note:** AI was NOT used to write the actual **Source Code**. The logic was manually implemented to ensure compliance with **Norminette v4** standards and the use of **Tabs** for indentation.

---

## 💻 Core Structures

```c
/* t_node: Represents an element in the doubly linked list with cost and rank data */
typedef struct s_node {
    int             value;
    int             rank;
    int             pos;
    int             target_dist;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

/* t_op: Dedicated structure to store and calculate the optimal shared operations */
typedef struct s_operations {
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int cost;
}   t_op;
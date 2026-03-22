# 🧠 Distributed Shared Memory (DSM) System in C

## 📌 Overview
This project implements a **Distributed Shared Memory (DSM)** system in C. It allows multiple processes (or nodes) to share memory over a network, simulating how distributed systems maintain consistency and synchronization.

---

## 🚀 Features
- Shared memory abstraction across nodes  
- Page-based memory management  
- Network communication using sockets  
- Page invalidation for consistency  
- Modular and scalable architecture  

---

## 🏗️ Project Structure

DSM_Project/
│
├── main.c
├── dsm.h
├── dsm.c
│
├── memory.h
├── memory.c
│
├── network.h
├── network.c
│
├── page_table.h
├── page_table.c
│
├── consistency.h
├── consistency.c
│
├── utils.h
├── utils.c
│
└── Makefile


---

## ⚙️ Working
- Each node maintains a **page table** for shared memory.
- Memory is divided into **pages**.
- When a node accesses a page:
  - If local → access directly  
  - If remote → fetch via network  
- On write:
  - Other nodes' copies are **invalidated** to maintain consistency  

---

## 🔁 Invalidation Example
```c
void invalidate_others(int page) {
    send_invalidation(page, OTHER_PORT);
}

🛠️ Compilation
make

▶️ Execution

Run two nodes on different ports:

./dsm_node 5000 5001
./dsm_node 5001 5000

🧪 Testing
Run multiple nodes
Perform read/write operations
Observe:
Page transfers
Invalidation messages
Consistency behavior

📚 Concepts Used
Distributed Systems
Virtual Memory
Page Tables
Cache Coherence
Socket Programming

👨‍💻 Author

Manjeet Saini

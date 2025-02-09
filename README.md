🌳 Word Range Analyzer -- Efficient Lexicographic Queries
========================================================

🚀 **Fast Insertions & Range Queries on Words Using a Self-Balancing BST!**

This project implements an **efficient data structure** to store words and process **lexicographic range queries**. It is designed to handle large-scale datasets with millions of insertions and queries in minimal time.

* * * * *

📌 Features
-----------

✅ **Custom Self-Balancing BST (AVL Tree) for fast word insertions & queries**\
✅ **Lexicographic Range Queries** -- Find words between any two given strings\
✅ **Handles large datasets** -- Optimized for millions of operations\
✅ **Efficient Querying** -- Uses subtree sizes for O(log n) range queries\
✅ **Command-Line Interface (CLI) for flexible input/output**\
✅ **Makefile for seamless compilation & execution**

* * * * *

🎯 Purpose of the Program
-------------------------

The **Word Range Analyzer** is built for efficient **word storage and searching**. It allows inserting words into a custom **AVL Tree** and performing **range queries** to count the number of words that exist lexicographically between two given words.

It can be used for:\
📖 **Text processing** -- Searching words within dictionaries or literature\
🔍 **Database-like queries** -- Fast lookups in structured text datasets\
📚 **Lexical analysis** -- Identifying words falling within a range in large text corpora

* * * * *

🛠 How It Works
---------------

### 🔹 **Input Format**

Each line of the input file follows one of these formats:

-   **`i <WORD>`** -- Inserts the word into the AVL Tree. If it already exists, it is ignored.
-   **`r <WORD1> <WORD2>`** -- Returns the count of words in the tree that are **lexicographically between** `WORD1` and `WORD2`.

### 🔹 **Processing Steps**

1️⃣ Words are inserted into a **self-balancing AVL Tree**, ensuring **O(log n) insertions**\
2️⃣ Each node maintains a **subtree size** to enable **O(log n) range queries**\
3️⃣ Query results are written to an output file

* * * * *

🔍 Example Input & Output
-------------------------

### **📂 Sample Input (`simple-input.txt`)**

`i 10`  
`i 20`  
`i 30`  
`i 40`  
`i 50`  
`i 60`  
`i 70`  
`i 80`  
`i 90`  
`i 99`  
`i 15`  
`i 14`  
`i 12`  
`i 25`  
`i 28`  
`i 95`  
`i 35`  
`i 38`  
`i 11`  
`i 23`  
`i 22`  
`r 10 20`  
`r 10 99`  
`r 45 87`  
`r 21 39`  
`r 21 79`  
`r 29 79`  

### **📂 Expected Output (`simple-output.txt`)**

`6`  
`21`  
`4`  
`7`  
`11`  
`7`  

**Explanation:**\
✔️ `r 10 20` → 6 words exist lexicographically between "10" and "20"\
✔️ `r 10 99` → 21 words exist lexicographically between "10" and "99"\
✔️ And so on...

* * * * *

🚀 Performance & Constraints
----------------------------

⚡ **Optimized Execution**:

-   Handles **millions of insertions and queries in under a minute**
-   Self-balancing **AVL Tree ensures O(log n) efficiency**
-   **Memory-efficient** -- Uses subtree sizes to speed up range queries

🔹 **Error Handling**:

-   If a word is already present, it **is not inserted again**
-   If the range query has **no valid words**, returns `0`

* * * * *

📦 Installation & Usage
-----------------------

### 📥 1. Clone the Repository

`git clone https://github.com/your-repo/N-Queens-Solver.git`  
`cd N-Queens-Solver`  

### 🏗 2. Build the Program

`make`

This creates an executable named **`wordrange`**.

### ▶️ 3. Run the Program

`./wordrange simple-input.txt simple-output.txt`

-   **`simple-input.txt`** contains the word insertion and query commands.
-   **`simple-output.txt`** will store the results of the queries.

🔹 To use your **own dataset**, simply replace `simple-input.txt` with a custom input file following the same format.

* * * * *

📂 File Structure
-----------------

- 📂 WordRangeAnalyzer
- ├── 📄 Makefile               # Automates compilation
- ├── 📄 wordrange.cpp          # Main program logic (AVL Tree)
- ├── 📄 bst.h                  # Header file for the BST structure
- ├── 📄 simple-input.txt       # Sample input queries
- ├── 📄 simple-output.txt      # Generated output
- ├── 📄 README.md              # This file`

* * * * *

🎯 Algorithm Overview
---------------------

1️⃣ **Insertion** -- Adds words to an AVL Tree with subtree size tracking\
2️⃣ **Balancing** -- Rotations maintain O(log n) operations\
3️⃣ **Range Queries** -- Uses subtree sizes for efficient counting\
4️⃣ **Optimized Output** -- Retrieves and writes results in O(log n)

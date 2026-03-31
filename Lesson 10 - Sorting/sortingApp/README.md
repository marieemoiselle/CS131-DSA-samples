<h1 align = "center">˖⁺‧₊˚ sorting algorithms ˚₊‧⁺˖</h1>
<p align = "center">A simple C++ program demonstrating <strong>sorting algorithms</strong>.

<h2>‧₊˚ ┊ project structure </h2>

```
📂 sortingApp/
├─ 📂 src/
│  ├─ main.cpp
│  ├─ bubble.cpp
│  ├─ insertion.cpp
│  ├─ selection.cpp
│  ├─ quick.cpp
│  ├─ merge.cpp
│  └─ display.cpp
├─ 📂 include/
│  ├─ sorting.h
│  └─ menu.h
```

<h2>‧₊˚ ┊ sorting algorithms mentioned</h2>
<ul type = "none">
<li>♡<strong> bubble sort</strong>. A sorting algorithm that works repeatedly swapping the adjacent elements if they are in the wrong order.</li>
<li>♡<strong> insertion sort</strong>. Works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list, similar to playing cards.</li>
<li>♡<strong> selection sort</strong>. It repeatedly selects the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element.</li>
<li>♡<strong> merge sort</strong>. A sorting algorithm that follows the <em>divide and conquer</em> approach, by recursively dividing the input array into two halves, recursively sorting the two halves, merging them back together to obtain the sorted array.</li>
<li>♡<strong> quick sort</strong>. A sorting algorithm that follows the <em>divide and conquer</em> that picks a <em>pivot</em> by placing the pivot in its correct position in the sorted array.</li>
</ul>

<h2>‧₊˚ ┊ compile and run</h2>
The headers are in the <strong>include</strong> folder, so:

```bash
g++ -Iinclude src/*.cpp -o sortingApp
```
Then run: `./sortingApp`

<h2>‧₊˚ ┊ references</h2>

- [GFG - Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [Learn C++](https://www.learncpp.com/)
## If..
You build in windows, you should run the binary with `.exe`. For example, `./maze_solver_program.exe MazeSolver/MazeSample.dat`  
You build with vscode, modify the path in [tasks.json](../.vscode/tasks.json) and `Ctrl + F5`  
You want to launch the binary with arguments, modify the path in [launch.json](../.vscode/launch.json) and `Ctrl + Shift + B` to build binary and `Ctrl + F5` to launch the binary with arguments.

## Build
- `gcc -o bubble_sort BubbleSort/BubbleSort.c`
- `gcc -o insertion_sort InsertionSort/InsertionSort.c`
- `gcc -o quick_sort QuickSort/QuickSort.c`
- `gcc -o quick_sort2 QuickSort2/QuickSort2.c`
- `gcc -o binary_search BinarySearch/BinarySearch.c`
- `gcc -o binary_search2 BinarySearch2/BinarySearch2.c`
- `gcc -o binary_search_tree BinarySearchTree/BinarySearchTree.c BinarySearchTree/Test_BinarySearchTree.c`
- `gcc -o red_black_tree RedBlackTree/RedBlackTree.c RedBlackTree/Test_RedBlackTree.c`
- `gcc -o heap Heap/Heap.c Heap/Test_Heap.c`
- `gcc -o priority_queue PriorityQueue/PriorityQueue.c PriorityQueue/Test_PriorityQueue.c`
- `gcc -o simple_hash_table SimpleHashTable/SimpleHashTable.c SimpleHashTable/Test_SimpleHashTable.c`
- `gcc -o chaining Chaining/Chaining.c Chaining/Test_Chaining.c`
- `gcc -o open_addressing_hash_table OpenAddressing/OpenAddressing.c OpenAddressing/Test_OpenAddressing.c`
- `gcc -o graph Graph/Graph.c Graph/Test_Graph.c`
- `gcc -o graph_traversal GraphTraversal/LinkedQueue.c Graph/Graph.c GraphTraversal/GraphTraversal.c GraphTraversal/Test_GraphTraversal.c`
- `gcc -o topological_sort TopologicalSort/LinkedList.c Graph/Graph.c TopologicalSort/TopologicalSort.c TopologicalSort/Test_TopologicalSort.c`
- `gcc -o minimum_spanning_tree ../data_structure/DisjointSet/DisjointSet.c PriorityQueue/PriorityQueue.c Graph/Graph.c MinimumSpanningTree/MST.c MinimumSpanningTree/Test_MST.c`
- `gcc -o dijkstra PriorityQueue/PriorityQueue.c Graph/Graph.c ShortestPath/ShortestPath.c ShortestPath/Test_ShortestPath.c`
- `gcc -o brute_force BruteForce/BruteForce.c BruteForce/Test_BruteForce.c`
- `gcc -o karp_rabin KarpRabin/KarpRabin.c KarpRabin/Test_KarpRabin.c`
- `gcc -o knuth_moriss_pratt KnuthMorrisPratt/KnuthMorrisPratt.c KnuthMorrisPratt/Test_KnuthMorrisPratt.c`
- `gcc -o boyer_moore BoyerMoore/BoyerMoore.c BoyerMoore/Test_BoyerMoore.c`
- `gcc -o merge_sort MergeSort/MergeSort.c`
- `gcc -o fast_exponentiation FastExponentiation/FastExponentiation.c`
- `gcc -o fibonacci_divide_and_conquer FibonacciDnc/FibonacciDnc.c`
- `gcc -o fibonacci_dynamic_programming FibonacciDP/FibonacciDP.c`
- `gcc -o longest_common_subsequence_dynamic_programming LCSDP/LCSDP.c`
- `gcc -o making_change_program Greedy/MakingChange.c Greedy/Test_MakingChange.c`
- `gcc -o huffman PriorityQueue/PriorityQueue.c Huffman/Huffman.c Huffman/Test_Huffman.c`
- `gcc -o maze_solver_program MazeSolver/MazeSolver.c MazeSolver/Test_MazeSolver.c`
- `gcc -o n_queens_program NQueens/NQueens.c NQueens/Test_NQueens.c`

## Run
- `./bubble_sort`
- `./insertion_sort`
- `./quick_sort`
- `./quick_sort2`
- `./binary_search`
- `./binary_search2`
- `./binary_search_tree`
- `./red_black_tree`
- `./heap`
- `./priority_queue`
- `./simple_hash_table`
- `./chaining`
- `./open_addressing_hash_table`
- `./graph`
- `./graph_traversal`
- `./topological_sort`
- `./minimum_spanning_tree`
- `./dijkstra`
- `./brute_force BruteForce/kjv.txt Faithful`
- `./karp_rabin BruteForce/kjv.txt Righteousness`
- `./knuth_moriss_pratt BruteForce/kjv.txt "The Prince of Peace"`
- `./boyer_moore BruteForce/kjv.txt "Get wisdom"`
- `./merge_sort`
- `./fast_exponentiation`
- `./fibonacci_divide_and_conquer`
- `./fibonacci_dynamic_programming`
- `./longest_common_subsequence_dynamic_programming`
- `./making_change_program`
- `./huffman`
- `./maze_solver_program MazeSolver/MazeSample.dat`
- `./n_queens_program 4`
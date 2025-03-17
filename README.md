To build the project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/bogdann29/VK_Test.git
   cd VK_Test
   ```

2. Build the project:
    ```bash
    cmake -S . -B build
    cmake --build build
    ```

3. Run tests:
    ```bash
    ctest --test-dir build
    ```

4. Run the executable:
    ```bash
    ./build/main --graph graph.txt --output result.txt
    ```

    Options:
    * --graph <filename> or -g <filename> — specifies the input file containing the graph description(default: gr.txt)
    * --output <filename> or -o <filename> — specifies the output file (default: result.txt)
    * --help or -h — displays the help message
    
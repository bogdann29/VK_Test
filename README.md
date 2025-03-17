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

3. Run tests
    ```bash
    ctest --test-dir build
    ```

4. Run the executable:
    ```bash
    ./build/main
    ```
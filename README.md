# Cron Parser

Cron Parser is a C++ command line application which parses a cron string and expands each field
to show the times at which it will run.

It parses cron expression of format `minute, hour, day of
month, month, and day of week` and describes this expression in below format;

```
minute        0 15 30 45
hour          0
day of month  1 15
month         1 2 3 4 5 6 7 8 9 10 11 12
day of week   1 2 3 4 5
command       /usr/bin/find
```

### Pre-requisites

1. GCC compiler installed in your system
2. or any C++ IDE to run the program


### How to run it?

1. Checkout in `cron-parser` directory in your terminal.
2. Compile the code. Use following command in your terminal
    ```
    g++ Main.cpp utils/StringUtil.cpp -o parse
    ```

3. Now run your cron expression to get the details of each part as follows;
    ```
    ./parser "<cron-expression> <file-name>"
    ```
    For example
    ```
    ./parser "*/15 0 1,15 * 1-5 /usr/bin/find"
    ```

#### Sample output

<img width="780" alt="Screenshot 2024-03-18 at 10 03 45" src="https://github.com/mani87/cron-parser/assets/88872955/e5208ed9-0673-4b35-91d8-5132d12c8f18">

### Flow Diagram
<img width="634" alt="Screenshot 2024-03-18 at 15 41 43" src="https://github.com/mani87/cron-parser/assets/88872955/4ef11890-2f57-4492-a498-d2d85e477d7c">


### How to run test cases?

1. Compile the test cases
   ```
   g++ tests/CronExpressionTests.cpp utils/StringUtil.cpp -o test
   ```
2. Run test cases
   ```
   ./test
   ```
#### Sample output
<img width="706" alt="Screenshot 2024-03-18 at 14 07 04" src="https://github.com/mani87/cron-parser/assets/30254676/bdf17f74-266f-4335-80d4-4d2810136e3a">



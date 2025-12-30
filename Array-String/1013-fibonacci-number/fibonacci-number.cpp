class Solution {
public:
    int fibonacci(int n)
    {
        if(n == 0 || n == 1)
            return n;
        int fib = fibonacci(n-1) + fibonacci(n-2);
        return fib;
    }
    int fib(int n) {
        return fibonacci(n);

    }
};
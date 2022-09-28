func fib(n: i32): i32 {
  if n <= 2 ret 1;
  ret fib(n - 1) + fib(n - 2);
}
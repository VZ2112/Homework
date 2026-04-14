unsigned fact(unsigned n) {
  return n ? n * fact(n - 1) : 1;
}

unsigned fib(unsigned n) {
  return n > 1 ? fib(n - 1) + fib(n - 2) : n;
}

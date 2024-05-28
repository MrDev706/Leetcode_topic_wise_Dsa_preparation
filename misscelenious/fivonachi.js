

function fivonacki(n){
    console.log(n)
    if(n<2) return n
    return fivonacki(n-1) + fivonacki(n-2)
}
function fib(n){
    console.log(n)
    if (n < 0)
        return fib(n * -1) * -1;
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

console.log(fib(-6))
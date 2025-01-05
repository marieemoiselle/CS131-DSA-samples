const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.question("Enter value for n: ", (input) => {
    let n = parseInt(input);
    let factorial = 1;
    let i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    console.log("Factorial: " + factorial);
    rl.close();
});

/*
    To run this code, make sure that you are in its directory. 
    After that, use the command: node getFactorial.js

*/
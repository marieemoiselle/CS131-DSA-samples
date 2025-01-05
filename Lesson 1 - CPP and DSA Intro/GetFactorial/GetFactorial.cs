using System;

int n, factorial = 1, i = 1;

Console.Write("Enter value for n: ");
n = int.Parse(Console.ReadLine());

while (i <= n) {
    factorial *= i;
    i++;
}

Console.WriteLine("Factorial: " + factorial);

/*
    To run this code, use the following commands in the terminal:
    cd Lesson 1 - CPP and DSA Intro
    cd get factorial
    dotnet-script GetFactorial.cs

*/
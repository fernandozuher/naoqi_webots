'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');
let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;
process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    // Enter your code here
    const [i, d, s] = [4, 4.0, "HackerRank "]
    const [i2, d2, s2] = [parseInt(readLine()), parseFloat(readLine()), readLine()]

    console.log(i + i2)
    console.log((d + d2).toFixed(1))
    console.log(s + s2)
}
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
    
    const n = +readLine()

    for (let flag = true, [word1, word2] = ["", ""]; currentLine <= n; flag = true, [word1, word2] = ["", ""]) {

        [...readLine()].forEach((ch, i) => {
            flag ? (word1 += ch) : (word2 += ch)
            flag = !flag
        })
        console.log(`${word1} ${word2}`);
    }
}
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

class Person {
    
    private age: number

    constructor(initialAge: number) {
        if (initialAge < 0) {
            this.age = 0
            console.log("Age is not valid, setting age to 0.")
        }
        else
            this.age = initialAge

        this.amIOld()
    } 
    
    public amIOld() : void {
        if (this.age < 13)
            console.log("You are young.")
        else if (this.age >= 13 && this.age < 18)
            console.log("You are a teenager.")
        else
            console.log("You are old.")
    }
    
    public yearPasses() : void {
        ++this.age
   }
}

function main() {
    const ages = parseInt(readLine())
    for (let i = 0; i < ages; ++i) {
        const person = new Person(parseInt(readLine()))
        person.yearPasses()
        person.yearPasses()
        person.yearPasses()
        person.amIOld()
        console.log("")
    }
}
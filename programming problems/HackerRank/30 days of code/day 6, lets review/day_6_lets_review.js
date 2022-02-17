function processData(input) {
    
    const words = input.split("\n")
    words.shift()

    for (let word of words) {
        
        let word1, word2 = word1 = "";
        let flag = true;

        [...word].forEach((ch, i) => {
            flag ? (word1 += ch) : (word2 += ch)
            flag = !flag
        })
        console.log(`${word1} ${word2}`);
    }
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

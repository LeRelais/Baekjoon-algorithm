const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    
    //console.log(str.length);
    let resultString = '';
    for(let i = 0; i < str.length; i++){
        if(str.charCodeAt(i) >= 97 && str.charCodeAt(i) <= 123){
            resultString += str[i].toUpperCase();
        }
        else if (str[i] >= 'A' && str[i] <= 'Z'){
            resultString += str[i].toLowerCase();
        }
    }
    
    //console.log(str);
    console.log(resultString);
});
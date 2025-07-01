function solution(babbling) {
    var answer = 0;
    
    for(const word of babbling){
        let newWord = word
            .split("aya").join("*")
            .split("ye").join("*")
            .split("woo").join("*")
            .split("ma").join("*");
        
        newWord = newWord.replaceAll("*", "");
        // console.log(newWord);
        
        if(newWord.length === 0){
            answer++;
        }
    }
    
    return answer;
}
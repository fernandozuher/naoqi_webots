n = gets.chomp.to_i
for i in 1..n do

    word, word1, word2 = gets.chomp, "", ""
    flag = true
    
    word.each_char.with_index do |ch, i|
        flag ? (word1 << ch) : (word2 << ch)
        flag = !flag
    end

    puts "#{word1} #{word2}"
end
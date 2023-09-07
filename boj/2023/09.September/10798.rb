txt = $<.map{|line| line.chomp}
maxi = txt.map{|line| line.length}.max
txt = txt.map{|line| line.ljust(maxi)}

answer = ""
maxi.times { |i|
    txt.each { |line|
        answer += line[i]
    }
}
puts answer.gsub(" ","")
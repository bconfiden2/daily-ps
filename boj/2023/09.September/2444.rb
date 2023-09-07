N = gets.to_i
1.upto(N) { |i|
    puts ("*"*(2*i-1)).rjust(i+N-1)
}
(N-1).downto(1) { |i|
    puts ("*"*(2*i-1)).rjust(i+N-1)
}
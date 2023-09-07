tb = {"A+":4.5,"A0":4.0,"B+":3.5,"B0":3.0,"C+":2.5,"C0":2.0,"D+":1.5,"D0":1.0,"F":0,}

total_crd, total_scr = 0, 0
20.times {
    _, crd, scr = gets.split
    if scr != "P"
        total_crd += crd.to_i
        total_scr += tb[scr.to_sym] * crd.to_i
    end
}
puts total_scr / total_crd

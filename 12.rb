#!/usr/bin/ruby -Ku

def yakusuu(y)
  total = 1
  i = 2
  x = Hash.new(0)

  while i <= y do 
    if (y % i) == 0
      x[i] += 1
      y /= i
    else
      i += 1
    end
  end

  x.each do |key, value|
    total *= (value + 1)
#    total = total * (value + 1)
  end

  return total
end

num = 1
tmp = 1

while 1 do
  if yakusuu(tmp) >= 501
    puts tmp
    break
  end

  num += 1
  tmp += num
end

=begin

def yakusuu(num)
  total = 1
  i = 1
  x = Hash.new(0)

  while i <= num
    if (i % num) == 0
      x[i] += 1
    else
      i += 1
    end
  end

  x.each do |xx|
    total *= (xx + 1)
  end

  return total + 2
end
=end

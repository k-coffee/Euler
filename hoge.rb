class Integer
  def pentagon?
    x = ((1 + 24 * self) ** 0.5 + 1) / 6.0
    if x == x.to_i then
      return x.to_i
    else
      return false
    end
  end
 
  # * 六角数を求める。
  def hexagon
    return 2 * self * self - self
  end
end
 
144.upto(1/0.0) do |i|
  h = i.hexagon
  if h.pentagon?
    puts h
    exit
  end
end

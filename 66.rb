#!/usr/bin/ruby -Ku

max = 0
maxd = 1
for d in 2..1000 do
puts d
	x = 2
	unless Math::sqrt(d).ceil == Math::sqrt(d).truncate
		while x do
			y = x * x - 1
			tmp = y / d.to_f
			tmp = Math::sqrt(tmp)
			if tmp.ceil == tmp.truncate
				if max < x
					max = x
					maxd = d
				end
				break
			end
			x += 1
		end
	end
end

puts max, maxd

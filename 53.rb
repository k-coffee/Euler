#!/usr/bin/ruby -Ku

def ncr(n, r)
	sum = 1
	i = n - r

	while n > i
		sum *= n
		n -= 1
	end

	while r >= 1
		sum /= r
		r -= 1
	end

	return sum
end

sum = 0

for i in 1..100
	for j in 1..i
		if ncr(i, j) >= 1000000
			sum += 1
		end
	end
end

puts sum

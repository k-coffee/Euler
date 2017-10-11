!#/usr/bin/ruby -Ku

x = Array.new()

open('22.num', 'r') do |f|
	f.each do |line|
		x = line.gsub(/"/, '').split(",")
	end
end

puts x.sort

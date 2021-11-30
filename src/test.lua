local input = "in/1.in"
local output = "out/1.out"

local function lines_from(file)
  local lines = {}
  for line in io.lines(file) do
    lines[#lines + 1] = tonumber(line)
  end
  return lines
end

local function contains(list, x)
	for _, v in pairs(list) do
		if v == x then return true end
	end
	return false
end

local result = nil

local lines = lines_from(input)

for i = 1, #lines do
    if contains(lines, 2020 - lines[i]) then result = lines[i] * (2020 - lines[i]) end
end

io.open(output, "w"):write(result):close()

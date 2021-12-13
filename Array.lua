arr = {1,2,3,4,5,"hello"}

-- for key, value in pairs(arr) do
--     print(key, value)
-- end

for var = 1, 100 do
    table.insert(arr, 1, var)
end

for key, value in pairs(arr) do
    print(key, value)
end

print(table.maxn(arr))
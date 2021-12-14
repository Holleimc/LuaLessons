config = {time = "10点05分"}
config.words = "hello"
config.num = 100
config.name = "lisi"

-- print(config["words"])
-- print(config.name)
-- print(config.time)

for key, var in pairs(config) do
    print(key, var)
end

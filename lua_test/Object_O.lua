People = {}

People.sayHi = function (p)
    print("People say hi: "..p.name)
end

function People.isMe()
    print("My name is People")
end

function Clone(P)
    local INS = {}
    for key, value in pairs(P) do
        INS[key] = value
    end
    return INS
end

function Copy(p, table)
    for key, value in pairs(table) do
        p[key] = value
    end
end

People.new = function (name)
    local p = Clone(People)
    p.name = name
    return p
end

-- local p = clone(People)
-- p.isMe()
-- p.sayHi()

local p = People.new("lisi")
-- p.sayHi(p)
p:sayHi()


man = {}
man.new = function (name)
    local self = People.new(name)
    Copy(self, man)
    return self
end

man.sayHello = function ()
    print("man say Hello")
end

man.sayHi = function (p)
    print("man sayHi: " ..p.name)
end
man.isMe = function (p)
    print(p.name.." is me")
end

local m = man.new("wangwu")
m:sayHi()
m.sayHello()
m:isMe()
local p = People.new("zhaosi")
p:sayHi()
